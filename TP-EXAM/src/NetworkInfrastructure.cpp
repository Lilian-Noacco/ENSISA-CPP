//
// Created by Lilian Noacco on 17/12/2025.
//

#include "../include/NetworkInfrastructure.hpp"
#include "../include/Server.hpp"
#include "../include/Router.hpp"
#include "../include/Switch.hpp"
#include <iostream>
#include <utility>
#include <algorithm>
#include <numeric>

int NetworkInfrastructure::MAX_DEVICES = 100;

NetworkInfrastructure::NetworkInfrastructure(string name) : name(move(name)) {}

NetworkInfrastructure::~NetworkInfrastructure() {
    for (NetworkDevice* device : devices) {
        delete device;
    }
}

void NetworkInfrastructure::listDevices() const {
    cout << "Infrastructure: " << name << endl;
    cout << "---------------------" << endl;
    if (devices.empty()) {
        cout << "No devices in the infrastructure." << endl;
    } else {
        for (const auto& device : devices) {
            device->printInfo();
            cout << endl;
        }
    }
}

void NetworkInfrastructure::addDevice(NetworkDevice* device) {
    if (devices.size() >= MAX_DEVICES) {
        cout << "Cannot add device: infrastructure is full." << endl;
        delete device; // Clean up the passed pointer
        return;
    }

    // Check for duplicates
    auto it = lower_bound(devices.begin(), devices.end(), device->getHostname(),
        [](NetworkDevice* d, const string& h) {
            return d->getHostname() < h;
        });

    if (it != devices.end() && (*it)->getHostname() == device->getHostname()) {
        cout << "Cannot add device: a device with hostname '" << device->getHostname() << "' already exists." << endl;
        delete device; // Clean up
        return;
    }

    // Insert and maintain sort order
    devices.insert(it, device);
}

NetworkDevice* NetworkInfrastructure::searchDeviceByHostname(const string& hostname) const {
    auto it = lower_bound(devices.begin(), devices.end(), hostname,
        [](NetworkDevice* d, const string& h) {
            return d->getHostname() < h;
        });

    if (it != devices.end() && (*it)->getHostname() == hostname) {
        return *it;
    }

    return nullptr;
}

void NetworkInfrastructure::removeDeviceByHostname(const string& hostname) {
    auto it = lower_bound(devices.begin(), devices.end(), hostname,
        [](NetworkDevice* d, const string& h) {
            return d->getHostname() < h;
        });

    if (it != devices.end() && (*it)->getHostname() == hostname) {
        delete *it; // Free the memory
        devices.erase(it);
        cout << "Device with hostname '" << hostname << "' removed." << endl;
    } else {
        cout << "Device with hostname '" << hostname << "' not found." << endl;
    }
}

void NetworkInfrastructure::averagePowerConsumptionByType() const {
    double serverPower = 0, routerPower = 0, switchPower = 0;
    int serverCount = 0, routerCount = 0, switchCount = 0;

    for (const auto& device : devices) {
        if (dynamic_cast<Server*>(device)) {
            serverPower += device->getPowerConsumption();
            serverCount++;
        } else if (dynamic_cast<Router*>(device)) {
            routerPower += device->getPowerConsumption();
            routerCount++;
        } else if (dynamic_cast<Switch*>(device)) {
            switchPower += device->getPowerConsumption();
            switchCount++;
        }
    }

    cout << "Average Power Consumption:" << endl;
    if (serverCount > 0) {
        cout << "  - Servers: " << serverPower / serverCount << " W" << endl;
    }
    if (routerCount > 0) {
        cout << "  - Routers: " << routerPower / routerCount << " W" << endl;
    }
    if (switchCount > 0) {
        cout << "  - Switches: " << switchPower / switchCount << " W" << endl;
    }
}