#ifndef ECUDIAGNOSTIC_H
#define ECUDIAGNOSTIC_H

#include <string>
#include "DiagnosticTask.h"
#include "Severity.h"

class ECUDiagnostic : public DiagnosticTask {
private:
    std::string m_moduleName;

public:
    ECUDiagnostic() = default;
    explicit ECUDiagnostic(const std::string& moduleName_);

    bool run() const override;
    Severity getSeverity() const noexcept override;
};

#endif // ECUDIAGNOSTIC_H
