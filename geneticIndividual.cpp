#include "geneticIndividual.h"
#include <time.h>
#include <cstdlib>

// Initializes the fitness function.
GeneticIndividual::GeneticIndividual(const std::string& desiredChromosome) {
    chromosome = desiredChromosome;
}

std::string GeneticIndividual::getChromosome() {
    return chromosome;
}

void GeneticIndividual::setChromosome(std::string desiredChromosome) {
    chromosome = desiredChromosome;
}

// The fitness score of the individual is calculated every time the fitness function or chromosome is changed.
void GeneticIndividual::updateFitnessScore() {
    if (fitness) {
        fitnessScore = (*fitness)(chromosome);
    }
}

double GeneticIndividual::getFitnessScore() {
    return fitnessScore;
}

// Updates the fitness function.
void GeneticIndividual::setFitnessFunction(double (*fitness)(std::string)) {
    this -> fitness = fitness;
}

bool GeneticIndividual::mutate(double mutationRate) {
    bool mutated = false;

    return mutated;
}
