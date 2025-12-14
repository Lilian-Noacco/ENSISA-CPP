//
// Created by Lilian Noacco on 11/12/2025.
//

#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include "Card.hpp"

class EnergyCard : public Card
{
public:
    EnergyCard(const string &type);
    virtual ~EnergyCard();

    virtual string getEnergyType() const;
    virtual void setEnergyType(const string &type);

    virtual ostream &PrintOn(ostream &) const override;

private:
    string energyType;
};

#endif