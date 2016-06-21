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
void GeneticIndividual::setFitnessScore(double newScore) {
    fitnessScore = newScore;
}

double GeneticIndividual::getFitnessScore() {
    return fitnessScore;
}

bool GeneticIndividual::mutate(double mutationRate) {
    bool mutated = false;

    return mutated;
}
