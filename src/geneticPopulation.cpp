#include "Genetics/geneticPopulation.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

GeneticPopulation::GeneticPopulation(double (*fitness)(const GeneticIndividual&), const std::string& geneticElements, const std::vector<GeneticIndividual>& initialPopulation) {
    srand(time(0));
    this -> fitness = fitness;
    this -> geneticElements = geneticElements;
    this -> individuals = initialPopulation;
    // Calculate fitness scores if an initial population is provided.
    if (!individuals.empty()) {
        for (std::vector<GeneticIndividual>::iterator individual = individuals.begin(); individual != individuals.end(); individual++) {
            updateFitness(*individual);
        }
    }
}

GeneticPopulation::GeneticPopulation(double (*fitness)(const GeneticIndividual&), const std::string& geneticElements, const int& populationSize, const int& chromosomeLength) {
    srand(time(0));
    this -> fitness = fitness;
    this -> geneticElements = geneticElements;
    // Empty the population.
    individuals.clear();
    // Iterate over the number of desired individuals and generate a chromosome for each. Then calculate fitness score.
    for (int i = 0; i < populationSize; i++) {
        GeneticIndividual individual = GeneticIndividual(geneticElements, chromosomeLength);
        updateFitness(individual);
        individuals.push_back(individual);
    }
}

bool GeneticPopulation::evolve(const int& mutationRate) {
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
            GeneticIndividual child = GeneticIndividual(onePointCrossover(individuals[a], individuals[b]));
            updateFitness(child);
            individuals.push_back(child);
        }
        // Apply mutations.
        if (mutate(*individual, mutationRate, geneticElements)) {
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

bool GeneticPopulation::mutate(GeneticIndividual& individual, double mutationRate, const std::string& geneticElements) {
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

void GeneticPopulation::setCrossoverMethod(const std::string& newMethod) {
    if (newMethod.compare("single") == 0) {
        crossoverMethod = &GeneticPopulation::onePointCrossover;
    }
}

void GeneticPopulation::updateFitness(GeneticIndividual& individual) {
    individual.setFitnessScore((*fitness)(individual));
}

// Crosses two chromosomes into a single one.
std::string GeneticPopulation::onePointCrossover(const GeneticIndividual& parentA, const GeneticIndividual& parentB) {
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
