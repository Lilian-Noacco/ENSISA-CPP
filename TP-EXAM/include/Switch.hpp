//
// Created by Lilian Noacco on 17/12/2025.
//

#ifndef TP_EXAM_SWITCH_HPP
#define TP_EXAM_SWITCH_HPP

#include "NetworkDevice.hpp"

class Switch : public NetworkDevice {
private:
    int portCount;

public:
    // Constructors
    Switch();
    Switch(const string& hostname, const string& ipAddress, const string& location,
           const string& vendor, const string& osVersion, int year,
           double powerConsumption, bool isCritical, int portCount);
    Switch(const Switch& other);

    // Getter
    int getPortCount() const;

    // Setter
    void setPortCount(int portCount);

    // Overridden method
    void printInfo() const override;
};

#endif //TP_EXAM_SWITCH_HPP