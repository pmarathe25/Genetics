#include "geneticPopulation.h"
#include <time.h>
#include <cstdlib>

GeneticPopulation::GeneticPopulation(double (*fitness)(const GeneticIndividual&), const std::string& geneticElements, const std::vector<GeneticIndividual>& initialPopulation) {
    this -> fitness = fitness;
    this -> geneticElements = geneticElements;
    this -> individuals = initialPopulation;
    // Calculate fitness scores if an initial population is provided.
    if (!individuals.empty()) {
        for (std::vector<GeneticIndividual>::iterator individual = individuals.begin(); individual != individuals.end(); individual++) {
            individual -> setFitnessScore((*fitness)(*individual));
        }
    }
}

GeneticPopulation::GeneticPopulation(double (*fitness)(const GeneticIndividual&), const std::string& geneticElements, const int& populationSize, const int& chromosomeLength) {
    this -> fitness = fitness;
    this -> geneticElements = geneticElements;
    // Empty the population.
    individuals.clear();
    // Iterate over the number of desired individuals and generate a chromosome for each. Then calculate fitness score.
    for (int i = 0; i < populationSize; i++) {
        GeneticIndividual individual = GeneticIndividual(geneticElements, chromosomeLength);
        individual.setFitnessScore((*fitness)(individual));
        individuals.push_back(individual);
    }
}

void GeneticPopulation::evolve(const int& mutationRate, std::string crossoverMethod) {
    srand(time(0));
    std::vector<GeneticIndividual>::iterator populationEndpoint = individuals.end();
    for (std::vector<GeneticIndividual>::iterator individual = individuals.begin(); individual != populationEndpoint; individual++) {
        // Remove unfit individuals according to probability of survival.
        if ((rand() / RAND_MAX) > (individual -> getFitnessScore())) {
            individuals.erase(individual);
        }
        // Choose two distinct individuals to cross.
        int a = rand() % individuals.size();
        int b = rand() % individuals.size() - 1;
        // if b is the same as a (therefore a cannot be individuals.size()) set b to something else.
        if (b == a) {
            b = individuals.size();
        }
        // Crossover the survivors if they are fit enough.
        if ((rand() / RAND_MAX) > (individuals[a].getFitnessScore() * individuals[b].getFitnessScore())) {
            individuals.push_back(GeneticIndividual(individuals[a], individuals[b]), crossoverMethod);
        }
        // Apply mutations.
        individual -> mutate(mutationRate, geneticElements);
    }
}

void GeneticPopulation::setFitnessFunction(double (*fitness)(const GeneticIndividual&)) {
    this -> fitness = fitness;
}
