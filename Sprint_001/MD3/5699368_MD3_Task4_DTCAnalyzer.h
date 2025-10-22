#ifndef DTCANALYZER_H
#define DTCANALYZER_H

#include"5699368_MD3_Task4_DTC.h"
#include"5699368_MD3_Task4_SeverityLevel.h"

#include<string>

// class diagnosticSession
class DTCAnalyzer{
    private:
        std::string m_analyzerID;
        std::string m_organization;
        DTC* m_dtcPtrArray[5];
        int m_DTCCount;

    public:
        DTCAnalyzer(const std::string& analyzerID_, const std::string& organization_);
        void addDTC(DTC* dtc);
        void reviewCriticalFaults() const;
        void reportSummary() const;
};


#endif // DIAGNOSTICSESSION_H
