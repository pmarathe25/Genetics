#include "geneticPopulation.h"
#include <time.h>
#include <cstdlib>

GeneticPopulation::GeneticPopulation(double (*fitness)(const GeneticIndividual&), const std::string& geneticElements, const std::vector<GeneticIndividual>& initialPopulation) {
    this -> fitness = fitness;
    this -> geneticElements = geneticElements;
    individuals = initialPopulation;
}

void GeneticPopulation::evolve(const int& mutationRate) {
    for (std::vector<GeneticIndividual>::iterator individual = individuals.begin(); individual != individuals.end(); individual++) {
        // Calculate fitness scores for each individual.
        individual -> setFitnessScore((*fitness) (*individual));
        // Remove unfit individuals according to probability of survival.
        if ((rand() / RAND_MAX) > (individual -> getFitnessScore())) {
            individuals.erase(individual);
        }
    }
    // Crossover the survivors according to their fitness.

    // Apply mutations.
}

void setFitnessFunction(double (*fitness)(const GeneticIndividual&)) {
    this -> fitness = fitness;
}

void GeneticPopulation::generatePopulation(const int& populationSize, const int& chromosomeLength) {
    srand(time(0));
    // Empty the population.
    individuals.clear();
    // Iterate over the number of desired individuals and generate a chromosome for each.
    for (int i = 0; i < populationSize; i++) {
        individuals.push_back(GeneticIndividual(generateChromosome(geneticElements, chromosomeLength)));
    }
}

// Generates a chromosome.
std::string GeneticPopulation::generateChromosome(const int& chromosomeLength) {
    srand(time(0));
    std::string chromosome;
    chromosome.clear();
    for (int j = 0; j < chromosomeLength; j++) {
        chromosome.push_back(geneticElements[rand() % geneticElements.size()]);
    }
    return chromosome;
}

// Crosses two chromosomes into a single one.
std::string GeneticPopulation::onePointCrossover(const std::string& parentAChromosome, const std::string& parentBChromosome) {
    srand(time(0));
    int crossoverPoint = rand() % parentAChromosome.size();
    std::string newChromosome;
    if (rand() % 2) {
        newChromosome += parentAChromosome.substr(0, crossoverPoint) + parentBChromosome.substr(crossoverPoint);
    } else {
        newChromosome += parentBChromosome.substr(0, crossoverPoint) + parentAChromosome.substr(crossoverPoint);
    }
    return newChromosome;
}
