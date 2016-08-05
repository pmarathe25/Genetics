#ifndef COMPUTED_POPULATION_H
#define COMPUTED_POPULATION_H
#include "Genetics/geneticPopulation.hpp"
#include "Genetics/computedIndividual.hpp"
#include <vector>
#include <string>
#include <memory>

class ComputedPopulation : public GeneticPopulation {
    public:
        // Constructors.
        ComputedPopulation(const std::string& geneticElements, const std::vector<std::string>& initialPopulationChromosomes, double (*fitness)(const std::string&),
            double mutationRate = 0);
        ComputedPopulation(const std::string& geneticElements, int populationSize, int chromosomeLength, double (*fitness)(const std::string&), double mutationRate = 0);
        // Methods.
        virtual bool evolve();
        void display(void (*displayIndividual)(const ComputedIndividual&)) const;
        void setFitnessFunction(double (*fitness)(const std::string&));
    private:
        // Data members.
        bool populationAlive;
        double (*fitness)(const std::string&);
        std::vector<ComputedIndividual> individuals;
};

#endif
