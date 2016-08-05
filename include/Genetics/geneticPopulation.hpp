#ifndef GENETIC_POPULATION_H
#define GENETIC_POPULATION_H
#include <string>

class GeneticPopulation {
    public:
        GeneticPopulation(const std::string& geneticElements, double mutationRate = 0);
        // Methods.
        void setMutationRate(double newMutationRate);
        double getMutationRate();
        const std::string& getGeneticElements();
    protected:
        // Data members.
        std::string geneticElements;
        double mutationRate;
};

#endif
