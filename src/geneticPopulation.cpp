#include "Genetics/geneticPopulation.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

GeneticPopulation::GeneticPopulation(const std::string& geneticElements, const std::vector<GeneticIndividual>& initialPopulation, double mutationRate,
    double (*fitness)(const GeneticIndividual&)) {
    srand(time(0));
    this -> fitness = fitness;
    this -> geneticElements = geneticElements;
    this -> individuals = initialPopulation;
    this -> mutationRate = mutationRate;
    // Calculate fitness scores if an initial population is provided.
    if (!individuals.empty()) {
        for (std::vector<GeneticIndividual>::iterator individual = individuals.begin(); individual != individuals.end(); individual++) {
            updateFitness(*individual);
        }
    }
}

GeneticPopulation::GeneticPopulation(const std::string& geneticElements, const int& populationSize, const int& chromosomeLength, double mutationRate,
    double (*fitness)(const GeneticIndividual&)) {
    srand(time(0));
    this -> fitness = fitness;
    this -> geneticElements = geneticElements;
    this -> mutationRate = mutationRate;
    // Empty the population.
    individuals.clear();
    // Temporary chromosome.
    std::string chromosome;
    // Iterate over the number of desired individuals and generate a chromosome for each. Then calculate fitness score.
    for (int i = 0; i < populationSize; i++) {
        chromosome.clear();
        // Generate a new chromosome with the specified parameters.
        for (int i = 0; i < chromosomeLength; i++) {
            chromosome.push_back(geneticElements[rand() % geneticElements.size()]);
        }
        GeneticIndividual individual = GeneticIndividual(chromosome);
        updateFitness(individual);
        individuals.push_back(individual);
    }
}

bool GeneticPopulation::evolve() {
    bool populationAlive = false;
    std::vector<GeneticIndividual>::iterator populationEndpoint = individuals.end();
    // Stop when we reach the end of the old generation or when the population is destroyed (i.e. one or fewer individuals remaining).
    for (std::vector<GeneticIndividual>::iterator individual = individuals.begin(); individual != populationEndpoint && individuals.size() > 1; individual++) {
        populationAlive = true;
        // Remove unfit individuals according to probability of survival.
        if (((double) rand() / RAND_MAX) > (individual -> getFitnessScore())) {
            individuals.erase(individual);
        }
        // Choose two distinct individuals to cross.
        int a = rand() % individuals.size();
        int b = rand() % individuals.size();
        // if b is the same as a, set b to something else.
        if (b == a) {
            b = (a + 1) % individuals.size();
        }
        // Crossover the survivors if they are fit enough.
        if (((double) rand() / RAND_MAX) < (individuals[a].getFitnessScore() * individuals[b].getFitnessScore())) {
            GeneticIndividual child = GeneticIndividual((*crossoverMethod)(individuals[a], individuals[b]));
            updateFitness(child);
            individuals.push_back(child);
        }
        // Apply mutations.
        if (mutate(*individual, mutationRate)) {
            updateFitness(*individual);
        }
    }
    return populationAlive;
}

void GeneticPopulation::display(void (*displayIndividual)(const GeneticIndividual&)) const {
    std::cout << "Population Size: " << individuals.size() << std::endl;
    for (std::vector<GeneticIndividual>::const_iterator individual = individuals.begin(); individual != individuals.end() && individuals.size() > 1; individual++) {
        (*displayIndividual)(*individual);
    }
}

void GeneticPopulation::setFitnessFunction(double (*fitness)(const GeneticIndividual&)) {
    this -> fitness = fitness;
}

bool GeneticPopulation::mutate(GeneticIndividual& individual, double mutationRate) {
    if (mutationRate == 0) {
        return false;
    }
    bool mutated = false;
    std::string chromosome = individual.getChromosome();
    // Replace genes accorrding to mutation rate.
    for (int i = 0; i < chromosome.size(); i++) {
        if (((double) rand() / RAND_MAX) < mutationRate) {
            mutated = true;
            chromosome[i] = geneticElements[rand() % geneticElements.size()];
        }
    }
    individual.setChromosome(chromosome);
    return mutated;
}

void GeneticPopulation::setCrossoverMethod(CrossoverFunction newMethod) {
    crossoverMethod = newMethod;
}

void GeneticPopulation::updateFitness(GeneticIndividual& individual) {
    individual.setFitnessScore((*fitness)(individual));
}

// Crosses two chromosomes into a single one.
std::string onePointCrossover(const GeneticIndividual& parentA, const GeneticIndividual& parentB) {
    // The crossover point cannot be the first or last element of the chromosome.
    int crossoverPoint = (rand() % (parentA.getChromosome().size() - 2)) + 1;
    std::string newChromosome = "";
    if (rand() % 2) {
        newChromosome += parentA.getChromosome().substr(0, crossoverPoint) + parentB.getChromosome().substr(crossoverPoint);
    } else {
        newChromosome += parentB.getChromosome().substr(0, crossoverPoint) + parentA.getChromosome().substr(crossoverPoint);
    }
    return newChromosome;
}
