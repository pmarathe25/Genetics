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
        void evolve(const int& mutationRate);
        void setFitnessFunction(double (*fitness)(const GeneticIndividual&));
        void generatePopulation(const int& populationSize, const int& chromosomeLength);
        std::string generateChromosome(const int& chromosomeLength);
        std::string onePointCrossover(const std::string& parentAChromosome, const std::string& parentBChromosome);
};

#endif
