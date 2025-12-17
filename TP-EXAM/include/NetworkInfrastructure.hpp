//
// Created by Lilian Noacco on 17/12/2025.
//

#ifndef TP_EXAM_NETWORKINFRASTRUCTURE_HPP
#define TP_EXAM_NETWORKINFRASTRUCTURE_HPP

#include <string>
#include <vector>
#include "NetworkDevice.hpp"

using namespace std;

class NetworkInfrastructure {
private:
    string name;
    vector<NetworkDevice*> devices;

public:
    static int MAX_DEVICES;

    explicit NetworkInfrastructure(string name);

    ~NetworkInfrastructure();

    void listDevices() const;
    void addDevice(NetworkDevice* device);
    NetworkDevice* searchDeviceByHostname(const string& hostname) const;
    void removeDeviceByHostname(const string& hostname);
    void averagePowerConsumptionByType() const;
};

#endif //TP_EXAM_NETWORKINFRASTRUCTURE_HPP