#include "Genetics/computedIndividual.hpp"

ComputedIndividual::ComputedIndividual(const std::string& desiredChromosome, double (*fitness)(const std::string&)) : GeneticIndividual(desiredChromosome) {
    updateFitness(fitness);
}

ComputedIndividual::ComputedIndividual(const ComputedIndividual& parentA, const ComputedIndividual& parentB, double (*fitness)(const std::string&)) :
    GeneticIndividual(parentA, parentB) {
    updateFitness(fitness);
}

ComputedIndividual::ComputedIndividual(const std::string& geneticElements, int chromosomeLength, double (*fitness)(const std::string&)) :
    GeneticIndividual(geneticElements, chromosomeLength) {
    updateFitness(fitness);
}

double ComputedIndividual::getFitnessScore() const {
    return fitnessScore;
}

void ComputedIndividual::setFitnessScore(double newScore) {
    fitnessScore = newScore;
}

bool ComputedIndividual::mutate(double mutationRate, const std::string& geneticElements, double (*fitness)(const std::string&)) {
    if (GeneticIndividual::mutate(mutationRate, geneticElements)) {
        updateFitness(fitness);
    }
}

void ComputedIndividual::updateFitness(double (*fitness)(const std::string&)) {
    fitnessScore = (*fitness)(this -> getChromosome());
}
