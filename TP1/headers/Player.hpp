//
// Created by Lilian Noacco on 14/12/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.hpp"
#include "PokemonCard.hpp"

class Player
{
public:
    Player(const string &name);
    virtual ~Player();

    string getPlayerName() const;

    void addCardToBench(Card *card);
    void activatePokemonCard(size_t benchIndex);
    void attachEnergyCard(size_t benchIndex, size_t actionIndex);
    void useTrainer(size_t benchIndex);
    void attack(size_t myIndex, size_t atkIndex, Player &opponent, size_t oppIndex);

    void displayBench() const;
    void displayAction() const;

private:
    string playerName;
    vector<Card *> benchCards;
    vector<PokemonCard *> actionCards;
};

#endif