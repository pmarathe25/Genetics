#ifndef GENETIC_POPULATION_H
#define GENETIC_POPULATION_H
#include "geneticIndividual.hpp"
#include <vector>
#include <string>

class GeneticPopulation {
    private:
        std::vector<GeneticIndividual> individuals;
        double (*fitness)(const GeneticIndividual&);
        std::string geneticElements;
        void updateFitness(GeneticIndividual& individual);
    public:
        GeneticPopulation(double (*fitness)(const GeneticIndividual&), const std::string& geneticElements, const std::vector<GeneticIndividual>& initialPopulation);
        GeneticPopulation(double (*fitness)(const GeneticIndividual&), const std::string& geneticElements, const int& populationSize, const int& chromosomeLength);
        bool evolve(const int& mutationRate = 0, std::string crossoverMethod = "single");
        void display(void (*displayIndividual)(const GeneticIndividual&)) const;
        void setFitnessFunction(double (*fitness)(const GeneticIndividual&));
};

#endif
