//
// Created by Lilian Noacco on 17/12/2025.
//

#include "../include/Switch.hpp"

// Conctructeur par default
Switch::Switch() : NetworkDevice(), portCount(0) {}

// Constructeur parametre
Switch::Switch(const string& hostname, const string& ipAddress, const string& location,
               const string& vendor, const string& osVersion, int year,
               double powerConsumption, bool isCritical, int portCount)
    : NetworkDevice(hostname, ipAddress, location, vendor, osVersion, year, powerConsumption, isCritical),
      portCount(portCount) {}

// Copie constructeur
Switch::Switch(const Switch& other)
    : NetworkDevice(other), portCount(other.portCount) {}

// Getter
int Switch::getPortCount() const {
    return portCount;
}

// Setter
void Switch::setPortCount(int portCount) {
    this->portCount = portCount;
}

//  Method override
void Switch::printInfo() const {
    cout << "Switch:" << endl;
    cout << "  Hostname: " << getHostname() << endl;
    cout << "  IP address: " << getIpAddress() << endl;
    cout << "  Location: " << getLocation() << endl;
    cout << "  Vendor: " << getVendor() << endl;
    cout << "  OS version: " << getOsVersion() << endl;
    cout << "  Installed in: " << getYear() << endl;
    cout << "  Critical: " << (getIsCritical() ? "Yes" : "No") << endl;
    cout << "  Power consumption: " << getPowerConsumption() << " W" << endl;
    cout << "  Port Count: " << portCount << endl;
}