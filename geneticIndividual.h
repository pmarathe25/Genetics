#ifndef GENETIC_INDIVIDUAL_H
#define GENETIC_INDIVIDUAL_H
#include <string>

class GeneticIndividual {
    private:
        std::string chromosome;
        double fitnessScore;
    public:
        GeneticIndividual(std::string geneticElements, const int& chromosomeLength);
        GeneticIndividual(const GeneticIndividual& parentA, const GeneticIndividual& parentB, const std::string& crossoverMethod = "single");
        GeneticIndividual(const std::string& desiredChromosome);
        std::string getChromosome() const;
        void setChromosome(std::string desiredChromosome);
        double getFitnessScore() const;
        void setFitnessScore(double newScore);
        std::string onePointCrossover(const GeneticIndividual& parentA, const GeneticIndividual& parentB);
        bool mutate(double mutationRate, const std::string& geneticElements);
};

#endif
