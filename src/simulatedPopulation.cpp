#include "Genetics/simulatedPopulation.hpp"
#include <cstdlib>
#include <iostream>

SimulatedPopulation::SimulatedPopulation(const std::string& geneticElements, const std::vector<std::string>& initialPopulationChromosomes, double mutationRate)
    : GeneticPopulation(geneticElements, mutationRate) {
    for (std::vector<std::string>::const_iterator chromosome = initialPopulationChromosomes.begin(); chromosome != initialPopulationChromosomes.end(); chromosome++) {
        individuals.push_back(std::unique_ptr<SimulatedIndividual> (new SimulatedIndividual(*chromosome)));
    }
}

SimulatedPopulation::SimulatedPopulation(const std::string& geneticElements, int populationSize, int chromosomeLength, double mutationRate)
    : GeneticPopulation(geneticElements, mutationRate) {
    // Empty the population.
    individuals.clear();
    // Iterate over the number of desired individuals and generate a chromosome for each. Then calculate fitness score.
    for (int i = 0; i < populationSize; i++) {
        individuals.push_back(std::unique_ptr<SimulatedIndividual> (new SimulatedIndividual(geneticElements, chromosomeLength)));
    }
}
