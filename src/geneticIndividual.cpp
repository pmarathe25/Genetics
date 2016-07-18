#include "Genetics/geneticIndividual.hpp"
#include <ctime>
#include <cstdlib>

GeneticIndividual::GeneticIndividual(const std::string& geneticElements, const int& chromosomeLength) {
    chromosome.clear();
    // Generate a new chromosome with the specified parameters.
    for (int i = 0; i < chromosomeLength; i++) {
        chromosome.push_back(geneticElements[rand() % geneticElements.size()]);
    }
}

GeneticIndividual::GeneticIndividual(const std::string& desiredChromosome) {
    chromosome = desiredChromosome;
}

std::string GeneticIndividual::getChromosome() const {
    return chromosome;
}

void GeneticIndividual::setChromosome(const std::string& desiredChromosome) {
    chromosome = desiredChromosome;
}

double GeneticIndividual::getFitnessScore() const {
    return fitnessScore;
}

// The fitness score of the individual is calculated every time the fitness function or chromosome is changed.
void GeneticIndividual::setFitnessScore(double newScore) {
    fitnessScore = newScore;
}
