#include "Genetics/geneticIndividual.hpp"

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

void GeneticIndividual::setFitnessScore(double newScore) {
    fitnessScore = newScore;
}
