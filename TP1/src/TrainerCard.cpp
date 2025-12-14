//
// Created by Lilian Noacco on 14/12/2025.
//

#include "TrainerCard.hpp"
#include "PokemonCard.hpp"

TrainerCard::TrainerCard(const string &name, const string &effect)
    : Card(name), trainerEffect(effect)
{
}

TrainerCard::~TrainerCard()
{
}

string TrainerCard::getTrainerEffect() const
{
    return trainerEffect;
}

void TrainerCard::applyEffect(vector<PokemonCard *> &actionCards)
{
    for (PokemonCard *pokemon : actionCards)
    {
        if (pokemon)
        {
            pokemon->setHP(pokemon->getMaxHP());
        }
    }
}

ostream &TrainerCard::PrintOn(ostream &os) const
{
    os << "Trainer Card - Name: " << cardName << ", Effect: " << trainerEffect;
    return os;
}