#include "geneticPopulation.h"
#include <time.h>
#include <cstdlib>

GeneticPopulation::GeneticPopulation(const std::vector<GeneticIndividual>& initialPopulation) {
    individuals = initialPopulation;
}

void GeneticPopulation::evolve(double (*fitness)(std::string), const int& crossoverRate, const int& mutationRate) {
    // Calculate fitness scores for every individual.
    std::vector<GeneticIndividual>::iterator individual = individuals.begin();
    while (individual != individuals.end()) {
        individual -> setFitnessFunction(fitness);
        individual -> updateFitnessScore();
    }
    // Remove unfit individuals.

    // Crossover the survivors.

    // Apply mutations.
}

std::vector<GeneticIndividual> GeneticPopulation::generatePopulation(const int& populationSize, const std::string& geneticElements, const int& chromosomeLength) {
    srand(time(0));
    // Empty the population.
    std::vector<GeneticIndividual> individuals;
    individuals.clear();
    // Iterate over the number of desired individuals and generate a chromosome for each.
    for (int i = 0; i < populationSize; i++) {
        individuals.push_back(GeneticIndividual(generateChromosome(geneticElements, chromosomeLength)));
    }
    return individuals;
}

// Generates a chromosome from the given character set.
std::string GeneticPopulation::generateChromosome(const std::string& geneticElements, const int& chromosomeLength) {
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
