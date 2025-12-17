//
// Created by Lilian Noacco on 17/12/2025.
//

#include "../include/Server.hpp"

// Constructeur default
Server::Server() : NetworkDevice(), cpuCores(0) {}

// Constructeur parametre2
Server::Server(const string& hostname, const string& ipAddress, const string& location,
               const string& vendor, const string& osVersion, int year,
               double powerConsumption, bool isCritical, int cpuCores)
    : NetworkDevice(hostname, ipAddress, location, vendor, osVersion, year, powerConsumption, isCritical),
      cpuCores(cpuCores) {}

// Copie constructeur
Server::Server(const Server& other)
    : NetworkDevice(other), cpuCores(other.cpuCores) {}

// Getter
int Server::getCpuCores() const {
    return cpuCores;
}

// Setter
void Server::setCpuCores(int cpuCores) {
    this->cpuCores = cpuCores;
}

// Method overridde
void Server::printInfo() const {
    cout << "Server:" << endl;
    cout << "  Hostname: " << getHostname() << endl;
    cout << "  IP address: " << getIpAddress() << endl;
    cout << "  Location: " << getLocation() << endl;
    cout << "  Vendor: " << getVendor() << endl;
    cout << "  OS version: " << getOsVersion() << endl;
    cout << "  Installed in: " << getYear() << endl;
    cout << "  Critical: " << (getIsCritical() ? "Yes" : "No") << endl;
    cout << "  Power consumption: " << getPowerConsumption() << " W" << endl;
    cout << "  CPU Cores: " << cpuCores << endl;
}