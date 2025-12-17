//
// Created by Lilian Noacco on 17/12/2025.
//

#ifndef TP_EXAM_ROUTER_HPP
#define TP_EXAM_ROUTER_HPP

#include "NetworkDevice.hpp"

class Router : public NetworkDevice {
private:
    int routingTableSize;

public:
    // Constructors
    Router();
    Router(const string& hostname, const string& ipAddress, const string& location,
           const string& vendor, const string& osVersion, int year,
           double powerConsumption, bool isCritical, int routingTableSize);
    Router(const Router& other);

    // Getter
    int getRoutingTableSize() const;

    // Setter
    void setRoutingTableSize(int routingTableSize);

    // Override method
    void printInfo() const override;
};

#endif //TP_EXAM_ROUTER_HPP