#ifndef GENETIC_INDIVIDUAL_H
#define GENETIC_INDIVIDUAL_H
#include <string>

class GeneticIndividual {
    private:
        std::string chromosome;
        double fitnessScore;
        double (*fitness)(std::string);
    public:
        GeneticIndividual(const std::string& parentAChromosome = "", const std::string& parentBChromosome = "");
        void setFitnessFunction(double (*fitness)(std::string));
        void crossover(const std::string& parentAChromosome, const std::string& parentBChromosome);
        double getFitnessScore();
        void calculateFitness();
        bool mutate(double mutationRate);
};

#endif
