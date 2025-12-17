//
// Created by Lilian Noacco on 17/12/2025.
//

#ifndef TP_EXAM_SERVER_HPP
#define TP_EXAM_SERVER_HPP

#include "NetworkDevice.hpp"

class Server : public NetworkDevice {
private:
    int cpuCores;

public:
    // Constructors
    Server();
    Server(const string& hostname, const string& ipAddress, const string& location,
           const string& vendor, const string& osVersion, int year,
           double powerConsumption, bool isCritical, int cpuCores);
    Server(const Server& other);

    // Getter
    int getCpuCores() const;

    // Setter
    void setCpuCores(int cpuCores);

    // Override method
    void printInfo() const override;
};

#endif //TP_EXAM_SERVER_HPP