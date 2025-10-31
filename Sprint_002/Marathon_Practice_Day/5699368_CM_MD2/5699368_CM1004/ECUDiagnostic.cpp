#include "ECUDiagnostic.h"

ECUDiagnostic::ECUDiagnostic(const std::string& moduleName_) : m_moduleName(moduleName_) {}

bool ECUDiagnostic::run() const {
    return (m_moduleName.length() % 2 == 0);
}

Severity ECUDiagnostic::getSeverity() const noexcept {
    return Severity::CRITICAL;
}
