#ifndef GENETIC_INDIVIDUAL_H
#define GENETIC_INDIVIDUAL_H
#include <string>

class GeneticIndividual {
    public:
        // Constructors.
        GeneticIndividual(const std::string& desiredChromosome);
        GeneticIndividual(const GeneticIndividual& parentA, const GeneticIndividual& parentB);
        GeneticIndividual(const std::string& geneticElements, int chromosomeLength);
        // Methods.
        std::string getChromosome() const;
        void setChromosome(const std::string& desiredChromosome);
        virtual bool mutate(double mutationRate, const std::string& geneticElements);
    private:
        std::string chromosome;
        double fitnessScore;
};

#endif
