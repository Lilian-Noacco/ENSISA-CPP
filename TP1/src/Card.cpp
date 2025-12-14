//
// Created by Lilian Noacco on 11/12/2025.
//

#include "Card.hpp"

Card::Card(const string &name) : cardName(name)
{
}

Card::~Card()
{
}

string Card::getCardName() const
{
    return cardName;
}

ostream &operator<<(ostream &os, const Card &c)
{
    return c.PrintOn(os);
}