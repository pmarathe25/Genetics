#ifndef GENETIC_POPULATION_H
#define GENETIC_POPULATION_H
#include "geneticIndividual.h"
#include <vector>
#include <string>

class GeneticPopulation {
    private:
        std::vector<GeneticIndividual> individuals;
    public:
        GeneticPopulation(const std::vector<GeneticIndividual>& initialPopulation = {});
        void evolve(double (*fitness)(std::string), const int& crossoverRate, const int& mutationRate);
        std::vector<GeneticIndividual> generatePopulation(const std::string& geneticElements, const int& chromosomeLength, const int& populationSize);
        std::string generateChromosome(const std::string& geneticElements, const int& chromosomeLength);
};

#endif
