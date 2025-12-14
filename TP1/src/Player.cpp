//
// Created by Lilian Noacco on 14/12/2025.
//

#include "Player.hpp"
#include "TrainerCard.hpp"
#include <iostream>
#include "EnergyCard.hpp"

Player::Player(const string &name) : playerName(name)
{
}

Player::~Player()
{
    for (Card *card : benchCards)
    {
        delete card;
    }
    benchCards.clear();

    for (PokemonCard *card : actionCards)
    {
        delete card;
    }
    actionCards.clear();
}

string Player::getPlayerName() const
{
    return playerName;
}

void Player::addCardToBench(Card *card)
{
    benchCards.push_back(card);
}

void Player::activatePokemonCard(size_t benchIndex)
{
    if (benchIndex < benchCards.size())
    {
        Card *card = benchCards[benchIndex];
        PokemonCard *pokemonCard = dynamic_cast<PokemonCard *>(card);

        if (pokemonCard)
        {
            actionCards.push_back(pokemonCard);
            benchCards.erase(benchCards.begin() + benchIndex);
            cout << playerName << " is activating a Pokemon Card: " << pokemonCard->getCardName() << endl;
        }
    }
}

void Player::attachEnergyCard(size_t benchIndex, size_t actionIndex)
{
    if (benchIndex < benchCards.size() && actionIndex < actionCards.size())
    {
        Card *card = benchCards[benchIndex];
        EnergyCard *energyCard = dynamic_cast<EnergyCard *>(card);

        if (energyCard)
        {
            PokemonCard *pokemon = actionCards[actionIndex];
            
            for (size_t i = 0; i < pokemon->getAttacks().size(); ++i)
            {
                pokemon->addEnergyToAttack(i);
            }
            
            cout << playerName << " is attaching Energy Card of type " << energyCard->getEnergyType()
                      << " to the Pokemon " << pokemon->getCardName() << endl;

            delete energyCard;
            benchCards.erase(benchCards.begin() + benchIndex);
        }
    }
}

void Player::useTrainer(size_t benchIndex)
{
    if (benchIndex < benchCards.size())
    {
        Card *card = benchCards[benchIndex];
        TrainerCard *trainerCard = dynamic_cast<TrainerCard *>(card);

        if (trainerCard)
        {
            cout << playerName << " is using the Trainer Card to \"" << trainerCard->getTrainerEffect() << "\"" << endl;
            
            trainerCard->applyEffect(actionCards);
            
            delete trainerCard;
            benchCards.erase(benchCards.begin() + benchIndex);
        }
    }
}

void Player::attack(size_t myIndex, size_t atkIndex, Player &opponent, size_t oppIndex)
{
    if (myIndex < actionCards.size() && oppIndex < opponent.actionCards.size())
    {
        PokemonCard *myPokemon = actionCards[myIndex];
        PokemonCard *oppPokemon = opponent.actionCards[oppIndex];

        cout << playerName << " attacking " << opponent.getPlayerName()
                  << "'s Pokemon " << oppPokemon->getCardName()
                  << " with the Pokemon " << myPokemon->getCardName()
                  << " with its attack: ";
        
        const auto& attacks = myPokemon->getAttacks();
        if (atkIndex < attacks.size()) {
             cout << get<2>(attacks[atkIndex]) << endl;
        }

        int damage = myPokemon->performAttack(atkIndex);
        
        cout << "Reducing " << damage << " from " << opponent.getPlayerName() << "'s Pokemon's HP" << endl;

        int currentHP = oppPokemon->getHP();
        oppPokemon->setHP(currentHP - damage);

        if (oppPokemon->getHP() > 0) {
            cout << "Pokemon " << oppPokemon->getCardName() << " is still alive" << endl;
        } else {
             cout << "Pokemon " << oppPokemon->getCardName() << " is dead" << endl;
        }
    }
}

void Player::displayBench() const
{
    cout << "Bench cards for Player " << playerName << ":" << endl;
    for (const auto &card : benchCards)
    {
        cout << *card << endl;
    }
}

void Player::displayAction() const
{
    cout << "Action cards for Player " << playerName << ":" << endl;
    for (const auto &card : actionCards)
    {
        cout << *card << endl;
    }
}