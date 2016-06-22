#ifndef GENETIC_INDIVIDUAL_H
#define GENETIC_INDIVIDUAL_H
#include <string>

class GeneticIndividual {
    private:
        std::string chromosome;
        double fitnessScore;
    public:
        GeneticIndividual(const std::string& desiredChromosome = "");
        GeneticIndividual(std::string geneticElements, const int& chromosomeLength);
        double getFitnessScore() const;
        void setFitnessScore(double newScore);
        std::string getChromosome() const;
        void setChromosome(std::string desiredChromosome);
        bool mutate(double mutationRate, const std::string& geneticElements);
};

#endif
