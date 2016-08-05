#include "Evolution/blob.hpp"

Blob::Blob(const std::string& chromosome, const sf::Texture& texture, int type, const sf::Vector2f& position) :
    GeneticIndividual(chromosome), DynamicGameObject(texture, type, position) {
    // Decode the chromosome
    speed = std::stoi(chromosome);
}
