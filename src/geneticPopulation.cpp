#include "Genetics/geneticPopulation.hpp"
#include <ctime>
#include <cstdlib>

GeneticPopulation::GeneticPopulation(const std::string& geneticElements, double mutationRate) {
    srand(time(0));
    this -> geneticElements = geneticElements;
    this -> mutationRate = mutationRate;
}

void GeneticPopulation::setMutationRate(double newMutationRate) {
    mutationRate = newMutationRate;
}

double GeneticPopulation::getMutationRate() {
    return mutationRate;
}

const std::string& GeneticPopulation::getGeneticElements() {
    return geneticElements;
}
