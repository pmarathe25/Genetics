#ifndef GENETIC_POPULATION_H
#define GENETIC_POPULATION_H
#include "geneticIndividual.h"
#include <vector>
#include <string>

class GeneticPopulation {
    private:
        std::vector<GeneticIndividual> individuals;
        double (*fitness)(const GeneticIndividual&);
        std::string geneticElements;
    public:
        GeneticPopulation(double (*fitness)(const GeneticIndividual&), const std::string& geneticElements, const std::vector<GeneticIndividual>& initialPopulation);
        GeneticPopulation(double (*fitness)(const GeneticIndividual&), const std::string& geneticElements, const int& populationSize, const int& chromosomeLength);
        void evolve(const int& mutationRate = 0, std::string crossoverMethod = "single");
        void setFitnessFunction(double (*fitness)(const GeneticIndividual&));
};

#endif
