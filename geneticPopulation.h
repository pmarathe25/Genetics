#ifndef GENETIC_POPULATION_H
#define GENETIC_POPULATION_H
#include <vector>
#include <string>

class GeneticPopulation {
    private:
        std::vector<GeneticIndividual> individuals;
    public:
        GeneticPopulation(const std::vector<GeneticIndividual>& initialPopulation);
        void evolve(double (*fitness)(std::string), const int& crossoverRate, const int& mutationRate);
};

#endif
