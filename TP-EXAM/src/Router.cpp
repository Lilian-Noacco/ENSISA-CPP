//
// Created by Lilian Noacco on 17/12/2025.
//

#include "../include/Router.hpp"

// Constructeur par default
Router::Router() : NetworkDevice(), routingTableSize(0) {}

// Constructeur paramétré
Router::Router(const string& hostname, const string& ipAddress, const string& location,
               const string& vendor, const string& osVersion, int year,
               double powerConsumption, bool isCritical, int routingTableSize)
    : NetworkDevice(hostname, ipAddress, location, vendor, osVersion, year, powerConsumption, isCritical),
      routingTableSize(routingTableSize) {}

// Copue du constructeur
Router::Router(const Router& other)
    : NetworkDevice(other), routingTableSize(other.routingTableSize) {}

// Getter
int Router::getRoutingTableSize() const {
    return routingTableSize;
}

// Setter
void Router::setRoutingTableSize(int routingTableSize) {
    this->routingTableSize = routingTableSize;
}

// Methode override
void Router::printInfo() const {
    cout << "Router:" << endl;
    cout << "  Hostname: " << getHostname() << endl;
    cout << "  IP address: " << getIpAddress() << endl;
    cout << "  Location: " << getLocation() << endl;
    cout << "  Vendor: " << getVendor() << endl;
    cout << "  OS version: " << getOsVersion() << endl;
    cout << "  Installed in: " << getYear() << endl;
    cout << "  Critical: " << (getIsCritical() ? "Yes" : "No") << endl;
    cout << "  Power consumption: " << getPowerConsumption() << " W" << endl;
    cout << "  Routing Table Size: " << routingTableSize << endl;
}
