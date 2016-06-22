#include "geneticIndividual.h"
#include <time.h>
#include <cstdlib>

GeneticIndividual::GeneticIndividual(std::string geneticElements, const int& chromosomeLength) {
    srand(time(0));
    chromosome.clear();
    // Generate a new chromosome with the specified parameters.
    for (int j = 0; j < chromosomeLength; j++) {
        chromosome.push_back(geneticElements[rand() % geneticElements.size()]);
    }
}

GeneticIndividual::GeneticIndividual(const GeneticIndividual& parentA, const GeneticIndividual& parentB, const std::string& crossoverMethod) {
    if (crossoverMethod.compare("single") == 0) {
        chromosome = onePointCrossover(parentA, parentB);
    }
}

GeneticIndividual::GeneticIndividual(const std::string& desiredChromosome) {
    chromosome = desiredChromosome;
}

std::string GeneticIndividual::getChromosome() const {
    return chromosome;
}

void GeneticIndividual::setChromosome(std::string desiredChromosome) {
    chromosome = desiredChromosome;
}

double GeneticIndividual::getFitnessScore() const {
    return fitnessScore;
}

// The fitness score of the individual is calculated every time the fitness function or chromosome is changed.
void GeneticIndividual::setFitnessScore(double newScore) {
    fitnessScore = newScore;
}

// Crosses two chromosomes into a single one.
std::string GeneticIndividual::onePointCrossover(const GeneticIndividual& parentA, const GeneticIndividual& parentB) {
    srand(time(0));
    // The crossover point cannot be the first or last element of the chromosome.
    int crossoverPoint = (rand() % (parentA.getChromosome().size() - 2)) + 1;
    std::string newChromosome;
    if (rand() % 2) {
        newChromosome += parentA.getChromosome().substr(0, crossoverPoint) + parentB.getChromosome().substr(crossoverPoint);
    } else {
        newChromosome += parentB.getChromosome().substr(0, crossoverPoint) + parentA.getChromosome().substr(crossoverPoint);
    }
    return newChromosome;
}

bool GeneticIndividual::mutate(double mutationRate, const std::string& geneticElements) {
    bool mutated = false;

    return mutated;
}
