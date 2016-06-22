#include "geneticIndividual.h"
#include <time.h>
#include <cstdlib>

// Initializes the fitness function.
GeneticIndividual::GeneticIndividual(const std::string& desiredChromosome) {
    chromosome = desiredChromosome;
}

GeneticIndividual(std::string geneticElements, const int& chromosomeLength) {
    srand(time(0));
    chromosome.clear();
    // Generate a new chromosome with the specified parameters.
    for (int j = 0; j < chromosomeLength; j++) {
        chromosome.push_back(geneticElements[rand() % geneticElements.size()]);
    }
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

bool GeneticIndividual::mutate(double mutationRate, const std::string& geneticElements) {
    bool mutated = false;

    return mutated;
}
