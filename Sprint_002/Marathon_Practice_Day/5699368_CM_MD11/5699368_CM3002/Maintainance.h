#ifndef MAINTAINANCE_H
#define MAINTAINANCE_H

class Maintainance{
    private:
        float m_oilChangeCost;
        float m_tireRotationCost;
        float m_repairCost;
    public:
        Maintainance() = default;
        Maintainance(float oilCost_, float tireCost_, float repairCost_);

        // getters
        float getOilChangeCost() const;
        float getTireRotationCost() const;
        float getRepairCost() const;
        
        // setters
        void setOilChangeCost(float oilCost_);
        void setTireRotationCost(float tireCost_);
        void setRepairCost(float repairCost_);
};

#endif // MAINTAINANCE_H
