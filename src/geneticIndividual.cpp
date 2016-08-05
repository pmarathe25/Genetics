#include "Genetics/geneticIndividual.hpp"
#include <cstdlib>

GeneticIndividual::GeneticIndividual(const std::string& desiredChromosome) {
    chromosome = desiredChromosome;
}

GeneticIndividual::GeneticIndividual(const GeneticIndividual& parentA, const GeneticIndividual& parentB) {
    // The crossover point cannot be the first or last element of the chromosome.
    int crossoverPoint = (rand() % (parentA.getChromosome().size() - 2)) + 1;
    chromosome.clear();
    if (rand() % 2) {
        chromosome = parentA.getChromosome().substr(0, crossoverPoint) + parentB.getChromosome().substr(crossoverPoint);
    } else {
        chromosome = parentB.getChromosome().substr(0, crossoverPoint) + parentA.getChromosome().substr(crossoverPoint);
    }
}

GeneticIndividual::GeneticIndividual(const std::string& geneticElements, int chromosomeLength) {
    chromosome.clear();
    // Generate a new chromosome with the specified parameters.
    for (int i = 0; i < chromosomeLength; i++) {
        chromosome.push_back(geneticElements[rand() % geneticElements.size()]);
    }
}

std::string GeneticIndividual::getChromosome() const {
    return chromosome;
}

void GeneticIndividual::setChromosome(const std::string& desiredChromosome) {
    chromosome = desiredChromosome;
}

bool GeneticIndividual::mutate(double mutationRate, const std::string& geneticElements) {
    if (mutationRate == 0) {
        return false;
    }
    bool mutated = false;
    // Replace genes accorrding to mutation rate.
    for (int i = 0; i < chromosome.size(); i++) {
        if (((double) rand() / RAND_MAX) < mutationRate) {
            mutated = true;
            chromosome[i] = geneticElements[rand() % geneticElements.size()];
        }
    }
    return mutated;
}
