//
// Created by Lilian Noacco on 17/12/2025.
//

#ifndef TP_EXAM_NETWORKDEVICE_HPP
#define TP_EXAM_NETWORKDEVICE_HPP

#include <string>
#include <iostream>

using namespace std;

class NetworkDevice {
private:
    string hostname;
    string ipAddress;
    string location;
    string vendor;
    string osVersion;
    int year;
    double powerConsumption;
    bool isCritical;

public:
    // Constructors
    NetworkDevice();
    NetworkDevice(string hostname, string ipAddress, string location,
                  string vendor, string osVersion, int year,
                  double powerConsumption, bool isCritical);
    NetworkDevice(const NetworkDevice& other);

    // Destructor
    virtual ~NetworkDevice() = default;

    // Getters
    string getHostname() const;
    string getIpAddress() const;
    string getLocation() const;
    string getVendor() const;
    string getOsVersion() const;
    int getYear() const;
    double getPowerConsumption() const;
    bool getIsCritical() const;

    // Setters
    void setHostname(const string& hostname);
    void setIpAddress(const string& ipAddress);
    void setLocation(const string& location);
    void setVendor(const string& vendor);
    void setOsVersion(const string& osVersion);
    void setYear(int year);
    void setPowerConsumption(double powerConsumption);
    void setIsCritical(bool isCritical);

    // Methods
    void ping() const;
    virtual void printInfo() const;
};

#endif //TP_EXAM_NETWORKDEVICE_HPP