//
// Created by Lilian Noacco on 11/12/2025.
//

#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.hpp"
#include <vector>
#include <tuple>

class PokemonCard : public Card
{
public:
    using Attack = tuple<int, int, string, int>;

    PokemonCard(const string &name, const string &type, const string &family,
                int level, int maxHP,
                int atk1Cost, const string &atk1Desc, int atk1Dmg,
                int atk2Cost, const string &atk2Desc, int atk2Dmg);

    PokemonCard(const string &name, const string &type, const string &family,
                int level, int maxHP);

    virtual ~PokemonCard();

    virtual string getPokemonType() const;
    virtual string getFamilyName() const;
    virtual int getEvolutionLevel() const;
    virtual int getMaxHP() const;
    virtual int getHP() const;

    virtual vector<Attack> &getAttacksMutable();
    virtual const vector<Attack> &getAttacks() const;
    virtual void setHP(int newHP);
    virtual int performAttack(size_t attackIndex);
    virtual void addEnergyToAttack(size_t attackIndex);

    virtual ostream &PrintOn(ostream &) const override;

private:
    string pokemonType;
    string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    vector<Attack> attacks;
};

#endif