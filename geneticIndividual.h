#ifndef GENETIC_INDIVIDUAL_H
#define GENETIC_INDIVIDUAL_H
#include <string>

class GeneticIndividual {
    private:
        std::string chromosome;
        double fitnessScore;
        double (*fitness)(std::string);
    public:
        GeneticIndividual(const std::string& parentAChromosome);
        void setFitnessFunction(double (*fitness)(std::string));
        double getFitnessScore();
        void updateFitnessScore();
        std::string getChromosome();
        void setChromosome(std::string desiredChromosome);
        bool mutate(double mutationRate);
};

#endif
