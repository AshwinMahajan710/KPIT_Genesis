#include <iostream>
#include <memory>
#include <array>
#include <string>
#include "5699368_MD2_Task1_SeverityLevel.h"
#include "5699368_MD2_Task1_DTC.h"

constexpr std::size_t kDtcCount = 3;

int main() {
    std::array<std::unique_ptr<DTC>, kDtcCount> dtcArray;

    dtcArray[0] = std::make_unique<DTC>("P0301", "Cylinder 1 Misfire detected", true, 3, 1625247600, SeverityLevel::CRIT, true, false, true, "Engine", "ECU_01");
    dtcArray[1] = std::make_unique<DTC>("P0420", "Catalyst efficiency below zero", false, 1, 1625248600, SeverityLevel::WARN, false, true, false, "Exhaust", "ECU_02");
    dtcArray[2] = std::make_unique<DTC>("P0171", "System too lean (Bank 1)", true, 2, 1625249600, SeverityLevel::INFO, true, false, true, "Fuel", "ECU_03");

    for (std::size_t i = 0; i < dtcArray.size(); ++i) {
        std::cout << "\nGetting description for object " << i + 1 << ": " << dtcArray[i]->getDescription() << '\n';
        std::cout << "Getting Risk score for object " << i + 1 << ": " << dtcArray[i]->computeRiskScore() << '\n';
        std::cout << "Action recommended for object " << i + 1 << ": " << dtcArray[i]->recommendAction() << '\n';
        std::cout << "Getting occurrence count for object " << i + 1 << ": " << dtcArray[i]->getOccurenceCount() << '\n';
    }

    for (std::size_t i = 0; i < dtcArray.size(); ++i) {
        std::cout << "\nInfo for object " << i + 1 << ":\n";
        dtcArray[i]->printDTCInfo();
    }

    return 0;
}
