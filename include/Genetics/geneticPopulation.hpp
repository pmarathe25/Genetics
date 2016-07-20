#ifndef GENETIC_POPULATION_H
#define GENETIC_POPULATION_H
#include "Genetics/geneticIndividual.hpp"
#include <vector>
#include <string>

typedef std::string (*CrossoverFunction)(const GeneticIndividual&, const GeneticIndividual&);
std::string onePointCrossover(const GeneticIndividual& parentA, const GeneticIndividual& parentB);

class GeneticPopulation {
    public:
        // Constructors.
        GeneticPopulation(const std::string& geneticElements, const std::vector<GeneticIndividual>& initialPopulation, double mutationRate = 0,
            double (*fitness)(const GeneticIndividual&) = 0);
        GeneticPopulation(const std::string& geneticElements, const int& populationSize, const int& chromosomeLength, double mutationRate = 0,
            double (*fitness)(const GeneticIndividual&) = 0);
        // Methods.
        virtual bool evolve();
        void display(void (*displayIndividual)(const GeneticIndividual&)) const;
        void setFitnessFunction(double (*fitness)(const GeneticIndividual&));
        void setCrossoverMethod(CrossoverFunction newMethod = &onePointCrossover);
    private:
        // Methods.
        void updateFitness(GeneticIndividual& individual);
        bool mutate(GeneticIndividual& individual, double mutationRate);
        // Data members.
        double mutationRate;
        std::vector<GeneticIndividual> individuals;
        std::string geneticElements;
        double (*fitness)(const GeneticIndividual&);
        CrossoverFunction crossoverMethod = &onePointCrossover;
};

#endif
