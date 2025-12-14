//
// Created by Lilian Noacco on 11/12/2025.
//

#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

using namespace std;

class Card
{
public:
    Card(const string &name);
    virtual ~Card();

    virtual ostream &PrintOn(ostream &) const = 0;
    
    friend ostream &operator<<(ostream &, const Card &);

    virtual string getCardName() const;

protected:
    string cardName;
};

#endif