#include <iostream>
#include "../include/NetworkInfrastructure.hpp"
#include "../include/Server.hpp"
#include "../include/Router.hpp"
#include "../include/Switch.hpp"

using namespace std;

int main() {
    NetworkInfrastructure infra("Corporate Network");

    infra.addDevice(new Server("srv-01", "10.0.0.1", "DC1", "Dell", "Linux", 2023, 350, true, 32));
    infra.addDevice(new Router("rtr-01", "192.168.1.1", "Site A", "Cisco", "IOS", 2022, 150, true, 1000));
    infra.addDevice(new Switch("sw-01", "192.168.1.2", "Site A", "Cisco", "IOS", 2022, 100, false, 48));
    infra.addDevice(new Server("srv-02", "10.0.0.2", "DC1", "HP", "Windows", 2021, 400, true, 16));

    // test duplicate
    infra.addDevice(new Server("srv-01", "10.0.0.99", "DC2", "Dell", "Linux", 2024, 350, true, 32));

    cout << "========================================" << endl;

    // affichage infos
    infra.listDevices();
    cout << "========================================" << endl;

    // test search par hostname
    if (auto* dev = infra.searchDeviceByHostname("rtr-01")) {
        dev->printInfo();
    }
    cout << "========================================" << endl;

    infra.averagePowerConsumptionByType();
    cout << "========================================" << endl;

    infra.removeDeviceByHostname("rtr-01");
    cout << "========================================" << endl;
    
    infra.listDevices();

    return 0;
}