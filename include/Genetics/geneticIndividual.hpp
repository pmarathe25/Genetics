#ifndef GENETIC_INDIVIDUAL_H
#define GENETIC_INDIVIDUAL_H
#include <string>

class GeneticIndividual {
    private:
        std::string chromosome;
        double fitnessScore;
    public:
        GeneticIndividual(const std::string& geneticElements, const int& chromosomeLength);
        GeneticIndividual(const std::string& desiredChromosome);
        std::string getChromosome() const;
        void setChromosome(const std::string& desiredChromosome);
        double getFitnessScore() const;
        void setFitnessScore(double newScore);
};

#endif
