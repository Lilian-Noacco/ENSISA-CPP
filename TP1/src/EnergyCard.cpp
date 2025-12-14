//
// Created by Lilian Noacco on 11/12/2025.
//

#include "EnergyCard.hpp"

EnergyCard::EnergyCard(const string &type) : Card("Energy"), energyType(type)
{
}

EnergyCard::~EnergyCard()
{
}

string EnergyCard::getEnergyType() const
{
    return energyType;
}

void EnergyCard::setEnergyType(const string &type)
{
    energyType = type;
}

ostream &EnergyCard::PrintOn(ostream &os) const
{
    os << "Energy Card - Type: " << energyType;
    return os;
}