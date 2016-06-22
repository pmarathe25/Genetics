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
    srand(time(0));
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
    std::vector<GeneticIndividual>::iterator populationEndpoint = individuals.end();
    for (std::vector<GeneticIndividual>::iterator individual = individuals.begin(); individual != populationEndpoint; individual++) {
        // Remove unfit individuals according to probability of survival.
        if ((rand() / RAND_MAX) > (individual -> getFitnessScore())) {
            individuals.erase(individual);
        }
        // Crossover the survivors according to their fitness.

    }

    // Apply mutations.
}

void GeneticPopulation::setFitnessFunction(double (*fitness)(const GeneticIndividual&)) {
    this -> fitness = fitness;
}
