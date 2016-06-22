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
        GeneticPopulation(double (*fitness)(const GeneticIndividual&), const std::string& geneticElements = "01", const std::vector<GeneticIndividual>& initialPopulation = {});
        GeneticPopulation(double (*fitness)(const GeneticIndividual&), const std::string& geneticElements, const int& populationSize, const int& chromosomeLength);
        void evolve(const int& mutationRate);
        void setFitnessFunction(double (*fitness)(const GeneticIndividual&));
        std::string generateChromosome(const int& chromosomeLength);
        GeneticIndividual onePointCrossover(const GeneticIndividual& parentA, const GeneticIndividual& parentB);
};

#endif
