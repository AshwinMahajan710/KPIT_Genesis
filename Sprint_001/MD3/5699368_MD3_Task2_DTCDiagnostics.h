#ifndef DTC_DIAGNOSTICS_H
#define DTC_DIAGNOSTICS_H

#include"5699368_MD3_Task2_SeverityLevel.h"
#include"5699368_MD3_Task2_DTC.h"

// this forward declaration is imp --> else will get 5699368_MD3_Task1_DTCDiagnostics.h:9:33: error: ‘DTC’ does not name a type; did you mean ‘DTC_H’?
// 9 |         void reportStatus(const DTC& dtc); this type of error
class DTC;

class DTCDiagnostics{
    public:
        void reportStatus(const DTC& dtc_);
        
};

#endif