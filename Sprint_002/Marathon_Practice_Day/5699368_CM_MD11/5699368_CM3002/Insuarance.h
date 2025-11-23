#ifndef INSUARANCE_H
#define INSUARANCE_H

class Insuarance{
    private:
        float m_liabilityCoverage;
        float m_collisionCoverage;
        float m_comprehensiveCoverage;
    public:
        Insuarance() = default;
        Insuarance(float liability_, float collision_, float comprehensive_);

        // getters
        float getLiabilityCoverage() const;
        float getCollisionCoverage() const;
        float getComprehensiveCoverage() const;
        
        // setters
        void setLiabilityCoverage(float liability_);
        void setCollisionCoverage( float collision_);
        void setComprehensiveCoverage(float comprehensive_);
};

#endif // INSUARANCE_H
