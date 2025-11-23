#include <iostream>
#include <memory>
#include "SmartHomeController.h"
#include "Light.h"
#include "Thermostat.h"

int main() {

    // ===== TC1 =====
    SmartHomeController controller;

    controller.registerDevice(std::make_unique<Light>("Living", 75),[](){ std::cout << "[LOG] Living activated\n"; });

    controller.activateDevice("Living");
    // Expected:
    // Light Living is now on at 75%
    // [LOG] Living activated


    // ===== TC2 =====
    controller.registerDevice(
        std::make_unique<Thermostat>("Hall", 22.5),
        [](){ std::cout << "[ALERT] Hall adjusted\n"; }
    );

    controller.activateDevice("Hall");
    // Expected:
    // Thermostat Hall set to 22.5°C [EcoMode: off]
    // [ALERT] Hall adjusted


    // ===== TC3 =====
    SmartHomeController controller3;

    controller3.registerDevice(
        std::make_unique<Light>("L1", 60),
        [](){ std::cout << "[LOG] L1 logged\n"; }
    );

    controller3.registerDevice(
        std::make_unique<Thermostat>("T1", 20.0),
        [](){ std::cout << "[ALERT] T1 alerted\n"; }
    );

    controller3.activateAll();
    // Expected order:
    // Light L1 is now on at 60%
    // [LOG] L1 logged
    // Thermostat T1 set to 20.0°C [EcoMode: off]
    // [ALERT] T1 alerted


    // ===== TC4 =====
    SmartHomeController controller4;

    auto desk = std::make_unique<Light>("Desk", 30);
    Light* deskPtr = desk.get();

    controller4.registerDevice(
        std::move(desk),
        [deskPtr](){
            deskPtr->setBrightness(60);
            std::cout << "[LOG] Desk brightness set to 60\n";
        }
    );

    controller4.activateDevice("Desk");
    controller4.activateDevice("Desk");
    // Expected:
    // Light Desk is now on at 30%
    // [LOG] Desk brightness set to 60
    // Light Desk is now on at 60%
    // [LOG] Desk brightness set to 60


    // ===== TC5 =====
    SmartHomeController controller5;

    auto bed = std::make_unique<Thermostat>("Bedroom", 24.0);
    Thermostat* bedPtr = bed.get();

    controller5.registerDevice(
        std::move(bed),
        [bedPtr](){
            bedPtr->enableEcoMode(true);
            std::cout << "[LOG] Bedroom eco enabled\n";
        }
    );

    controller5.activateDevice("Bedroom");
    controller5.activateDevice("Bedroom");
    // Expected mutating ecoMode on each call


    // ===== TC6 ===== (Move Semantics)
    SmartHomeController controller6;

    controller6.registerDevice(
        std::make_unique<Light>("Porch", 80),
        [](){ std::cout << "[LOG] Porch activated\n"; }
    );

    SmartHomeController controller2 = std::move(controller6);
    controller2.activateDevice("Porch");
    // Expected:
    // Light Porch is now on at 80%
    // [LOG] Porch activated


    // ===== TC7 ===== (Unknown Device)
    controller2.activateDevice("Unknown");
    // Expected:
    // No crash. Optional: print "Device Unknown"


    // ===== TC8 ===== (Duplicate Names)
    SmartHomeController controller8;

    controller8.registerDevice(
        std::make_unique<Light>("X", 20),
        [](){ std::cout << "[LOG] First X\n"; }
    );

    controller8.registerDevice(
        std::make_unique<Light>("X", 90),
        [](){ std::cout << "[LOG] Second X\n"; }
    );

    controller8.activateDevice("X");
    // Behavior depends on your design choice.


    // ===== TC9 ===== (Safe Lambda Capture)
    SmartHomeController controller9;
    auto garden = std::make_unique<Light>("Garden", 40);
    Light* gardenPtr = garden.get();

    controller9.registerDevice(
        std::move(garden),
        [gardenPtr](){
            gardenPtr->setBrightness(90);
            std::cout << "[LOG] Garden brightness set to 90\n";
        }
    );

    controller9.activateDevice("Garden");


    // ===== TC10 ===== (Modify Derived From Callback)
    SmartHomeController controller10;

    auto office = std::make_unique<Thermostat>("Office", 19.0);
    Thermostat* officePtr = office.get();

    controller10.registerDevice(
        std::move(office),
        [officePtr](){
            officePtr->disableEcoMode();
            std::cout << "[LOG] Office eco disabled\n";
        }
    );

    controller10.activateDevice("Office");

    return 0;
}
