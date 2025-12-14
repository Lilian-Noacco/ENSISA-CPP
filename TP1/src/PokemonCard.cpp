//
// Created by Lilian Noacco on 11/12/2025.
//

#include "PokemonCard.hpp"

PokemonCard::PokemonCard(const string &name, const string &type, const string &family,
                         int level, int mHP,
                         int atk1Cost, const string &atk1Desc, int atk1Dmg,
                         int atk2Cost, const string &atk2Desc, int atk2Dmg)
    : Card(name), pokemonType(type), familyName(family), evolutionLevel(level), maxHP(mHP), hp(mHP)
{
    attacks.push_back(make_tuple(atk1Cost, 0, atk1Desc, atk1Dmg));
    attacks.push_back(make_tuple(atk2Cost, 0, atk2Desc, atk2Dmg));
}

PokemonCard::PokemonCard(const string &name, const string &type, const string &family,
                         int level, int mHP)
    : Card(name), pokemonType(type), familyName(family), evolutionLevel(level), maxHP(mHP), hp(mHP)
{
}

PokemonCard::~PokemonCard()
{
}

string PokemonCard::getPokemonType() const { return pokemonType; }
string PokemonCard::getFamilyName() const { return familyName; }
int PokemonCard::getEvolutionLevel() const { return evolutionLevel; }
int PokemonCard::getMaxHP() const { return maxHP; }
int PokemonCard::getHP() const { return hp; }

vector<PokemonCard::Attack> &PokemonCard::getAttacksMutable()
{
    return attacks;
}

const vector<PokemonCard::Attack> &PokemonCard::getAttacks() const
{
    return attacks;
}

void PokemonCard::setHP(int newHP)
{
    if (newHP < 0) hp = 0;
    else if (newHP > maxHP) hp = maxHP;
    else hp = newHP;
}

void PokemonCard::addEnergyToAttack(size_t attackIndex)
{
    if (attackIndex < attacks.size())
    {
        get<1>(attacks[attackIndex])++;
    }
}

int PokemonCard::performAttack(size_t attackIndex)
{
    if (attackIndex >= attacks.size()) return 0;

    int cost = get<0>(attacks[attackIndex]);
    int current = get<1>(attacks[attackIndex]);
    int dmg = get<3>(attacks[attackIndex]);

    if (current >= cost) return dmg;
    return 0;
}

ostream &PokemonCard::PrintOn(ostream &os) const
{
    os << "Pokemon Card - Name: " << cardName
       << ", Type: " << pokemonType
       << ", Evolution Level: " << evolutionLevel
       << " of the family \"" << familyName << ", HP: " << hp << "\"";

    os << "\nAttacks:\n";
    for (size_t i = 0; i < attacks.size(); ++i)
    {
        const auto &atk = attacks[i];
        os << "Attack #" << i << ":\n"
           << "Attack cost: " << get<0>(atk) << "\n"
           << "Attack current energy storage: " << get<1>(atk) << "\n"
           << "Attack description: " << get<2>(atk) << "\n"
           << "Attack damage: " << get<3>(atk);
        if (i + 1 < attacks.size()) os << "\n";
    }
    return os;
}