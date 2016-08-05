#ifndef COMPUTED_INDIVIDUAL_H
#define COMPUTED_INDIVIDUAL_H
#include "Genetics/geneticIndividual.hpp"
#include <string>

class ComputedIndividual : public GeneticIndividual {
    public:
        ComputedIndividual(const std::string& desiredChromosome, double (*fitness)(const std::string&));
        ComputedIndividual(const ComputedIndividual& parentA, const ComputedIndividual& parentB, double (*fitness)(const std::string&));
        ComputedIndividual(const std::string& geneticElements, int chromosomeLength, double (*fitness)(const std::string&));
        double getFitnessScore() const;
        void setFitnessScore(double newScore);
        virtual bool mutate(double mutationRate, const std::string& geneticElements, double (*fitness)(const std::string&));
    private:
        double fitnessScore;
        void updateFitness(double (*fitness)(const std::string&));
};

#endif
