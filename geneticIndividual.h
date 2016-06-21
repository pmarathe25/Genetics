#ifndef GENETIC_INDIVIDUAL_H
#define GENETIC_INDIVIDUAL_H
#include <string>

class GeneticIndividual {
    private:
        std::string chromosome;
        double fitnessScore;
    public:
        GeneticIndividual(const std::string& desiredChromosome);
        double getFitnessScore();
        void setFitnessScore(double newScore);
        std::string getChromosome();
        void setChromosome(std::string desiredChromosome);
        bool mutate(double mutationRate);
};

#endif
