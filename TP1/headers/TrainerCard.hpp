//
// Created by Lilian Noacco on 14/12/2025.
//

#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include "Card.hpp"
#include <vector>

class PokemonCard;

class TrainerCard : public Card
{
public:
    TrainerCard(const string &name, const string &effect);
    virtual ~TrainerCard();

    virtual string getTrainerEffect() const;
    virtual void applyEffect(vector<PokemonCard *> &actionCards);

    virtual ostream &PrintOn(ostream &) const override;

private:
    string trainerEffect;
};

#endif