#include "Genetics/computedPopulation.hpp"
#include <cstdlib>
#include <iostream>

ComputedPopulation::ComputedPopulation(const std::string& geneticElements, const std::vector<std::string>& initialPopulationChromosomes,
    double (*fitness)(const std::string&), double mutationRate) : GeneticPopulation(geneticElements, mutationRate) {
    this -> fitness = fitness;
    // Calculate fitness scores if an initial population is provided.
    for (std::vector<std::string>::const_iterator chromosome = initialPopulationChromosomes.begin(); chromosome != initialPopulationChromosomes.end(); chromosome++) {
        individuals.push_back(ComputedIndividual(*chromosome, fitness));
    }
    populationAlive = individuals.size() > 2;
}

ComputedPopulation::ComputedPopulation(const std::string& geneticElements, int populationSize, int chromosomeLength, double (*fitness)(const std::string&),
    double mutationRate) : GeneticPopulation(geneticElements, mutationRate) {
    this -> fitness = fitness;
    // Empty the population.
    individuals.clear();
    // Iterate over the number of desired individuals and generate a chromosome for each. Then calculate fitness score.
    for (int i = 0; i < populationSize; i++) {
        individuals.push_back(ComputedIndividual(geneticElements, chromosomeLength, fitness));
    }
    populationAlive = individuals.size() > 2;
}

bool ComputedPopulation::evolve() {
    if (!populationAlive) {
        return populationAlive;
    }
    std::vector<ComputedIndividual> newIndividuals;
    // Stop when we reach the end of the old generation or when the population is destroyed (i.e. one or fewer individuals remaining).
    for (std::vector<ComputedIndividual>::iterator individual = individuals.begin(); individual != individuals.end(); individual++) {
        // Choose two distinct individuals to cross.
        int a = rand() % individuals.size();
        int b = rand() % individuals.size();
        // if b is the same as a, set b to something else.
        b = (b == a) ? (a + 1) % individuals.size() : b;
        // Crossover the survivors if they are fit enough.
        if ((float(rand()) / RAND_MAX) < (individuals.at(a).getFitnessScore()) * (individuals.at(b).getFitnessScore())) {
            newIndividuals.push_back(ComputedIndividual(individuals.at(a), individuals.at(b), fitness));
        }
        // Apply mutations.
        individual -> mutate(mutationRate, geneticElements, fitness);
        // Remove unfit individuals according to probability of survival.
        if (((double) rand() / RAND_MAX) > (individual -> getFitnessScore())) {
            individuals.erase(individual);
            individual--;
            if (individuals.size() < 2) {
                populationAlive = false;
                return populationAlive;
            }
        }
    }
    // Append the new individuals to the main population.
    individuals.insert(individuals.end(), newIndividuals.begin(), newIndividuals.end());
    return populationAlive;
}

void ComputedPopulation::display(void (*displayIndividual)(const ComputedIndividual&)) const {
    std::cout << "Population Size: " << individuals.size() << std::endl;
    for (std::vector<ComputedIndividual>::const_iterator individual = individuals.begin(); individual != individuals.end() && individuals.size() > 1; individual++) {
        (*displayIndividual)(*individual);
    }
}

void ComputedPopulation::setFitnessFunction(double (*fitness)(const std::string&)) {
    this -> fitness = fitness;
}
