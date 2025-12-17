//
// Created by Lilian Noacco on 17/12/2025.
//

#include "../include/NetworkDevice.hpp"
#include <iostream>
#include <utility>

using namespace std;

// Contructeur defaut
NetworkDevice::NetworkDevice() : year(0), powerConsumption(0.0), isCritical(false) {}

// Conctructeur paramétré
NetworkDevice::NetworkDevice(string hostname, string ipAddress, string location,
                             string vendor, string osVersion, int year,
                             double powerConsumption, bool isCritical)
    : hostname(move(hostname)), ipAddress(move(ipAddress)), location(move(location)),
      vendor(move(vendor)), osVersion(move(osVersion)), year(year),
      powerConsumption(powerConsumption), isCritical(isCritical) {}

// Copie constructeur
NetworkDevice::NetworkDevice(const NetworkDevice& other)
    : hostname(other.hostname), ipAddress(other.ipAddress), location(other.location),
      vendor(other.vendor), osVersion(other.osVersion), year(other.year),
      powerConsumption(other.powerConsumption), isCritical(other.isCritical) {}

// Getters
string NetworkDevice::getHostname() const { return hostname; }
string NetworkDevice::getIpAddress() const { return ipAddress; }
string NetworkDevice::getLocation() const { return location; }
string NetworkDevice::getVendor() const { return vendor; }
string NetworkDevice::getOsVersion() const { return osVersion; }
int NetworkDevice::getYear() const { return year; }
double NetworkDevice::getPowerConsumption() const { return powerConsumption; }
bool NetworkDevice::getIsCritical() const { return isCritical; }

// Setters
void NetworkDevice::setHostname(const string& hostname) { this->hostname = hostname; }
void NetworkDevice::setIpAddress(const string& ipAddress) { this->ipAddress = ipAddress; }
void NetworkDevice::setLocation(const string& location) { this->location = location; }
void NetworkDevice::setVendor(const string& vendor) { this->vendor = vendor; }
void NetworkDevice::setOsVersion(const string& osVersion) { this->osVersion = osVersion; }
void NetworkDevice::setYear(int year) { this->year = year; }
void NetworkDevice::setPowerConsumption(double powerConsumption) { this->powerConsumption = powerConsumption; }
void NetworkDevice::setIsCritical(bool isCritical) { this->isCritical = isCritical; }

// Methods
void NetworkDevice::ping() const {
    cout << "Pinging " << hostname << " (" << ipAddress << ")... Success!" << endl;
}

void NetworkDevice::printInfo() const {
    cout << "Network Device (Unknown Type):" << endl;
    cout << "  Hostname: " << hostname << endl;
    cout << "  IP address: " << ipAddress << endl;
    cout << "  Location: " << location << endl;
    cout << "  Vendor: " << vendor << endl;
    cout << "  OS version: " << osVersion << endl;
    cout << "  Installed in: " << year << endl;
    cout << "  Critical: " << (isCritical ? "Yes" : "No") << endl;
    cout << "  Power consumption: " << powerConsumption << " W" << endl;
}
