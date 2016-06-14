#include "geneticIndividual.h"
#include <time.h>
#include <cstdlib>

// Initializes the fitness function.
GeneticIndividual::GeneticIndividual(const std::string& parentAChromosome, const std::string& parentBChromosome) {
    if (!parentBChromosome.empty()) {
        crossover(parentAChromosome, parentBChromosome);
    } else {
        chromosome = parentAChromosome;
    }
}

double GeneticIndividual::getFitnessScore() {
    return fitnessScore;
}

// Updates the fitness function.
void GeneticIndividual::setFitnessFunction(double (*fitness)(std::string)) {
    this -> fitness = fitness;
}

// Crosses two chromosomes into a single one.
void GeneticIndividual::crossover(const std::string& parentAChromosome, const std::string& parentBChromosome) {

}

std::string GeneticIndividual::getChromosome() {
    return chromosome;
}

// The fitness score of the individual is calculated every time the fitness function or chromosome is changed.
void GeneticIndividual::updateFitnessScore() {
    if (fitness) {
        fitnessScore = (*fitness)(chromosome);
    }
}

bool GeneticIndividual::mutate(double mutationRate) {
    bool mutated = false;

    return mutated;
}
