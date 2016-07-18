#ifndef GENETIC_POPULATION_H
#define GENETIC_POPULATION_H
#include "Genetics/geneticIndividual.hpp"
#include <vector>
#include <string>

class GeneticPopulation {
    public:
        // Constructors.
        GeneticPopulation(double (*fitness)(const GeneticIndividual&), const std::string& geneticElements, const std::vector<GeneticIndividual>& initialPopulation);
        GeneticPopulation(double (*fitness)(const GeneticIndividual&), const std::string& geneticElements, const int& populationSize, const int& chromosomeLength);
        // Methods.
        virtual bool evolve(const int& mutationRate = 0);
        void display(void (*displayIndividual)(const GeneticIndividual&)) const;
        void setFitnessFunction(double (*fitness)(const GeneticIndividual&));
        void setCrossoverMethod(const std::string& newMethod);
    private:
        // Methods.
        void updateFitness(GeneticIndividual& individual);
        std::string onePointCrossover(const GeneticIndividual& parentA, const GeneticIndividual& parentB);
        bool mutate(GeneticIndividual& individual, double mutationRate, const std::string& geneticElements);
        // Data members.
        std::vector<GeneticIndividual> individuals;
        std::string geneticElements;
        double (*fitness)(const GeneticIndividual&);
        std::string (GeneticPopulation::*crossoverMethod)(const GeneticIndividual&, const GeneticIndividual&) = &GeneticPopulation::onePointCrossover;
};

#endif
