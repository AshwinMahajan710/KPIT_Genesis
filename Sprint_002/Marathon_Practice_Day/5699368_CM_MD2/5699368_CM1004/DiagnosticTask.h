#ifndef DIAGNOSTICTASK_H
#define DIAGNOSTICTASK_H

#include "Severity.h"

class DiagnosticTask {
public:
    DiagnosticTask() = default;
    virtual ~DiagnosticTask() = default; // ensure polymorphic deletion
    virtual bool run() const = 0;
    virtual Severity getSeverity() const noexcept = 0;
};

#endif // DIAGNOSTICTASK_H
