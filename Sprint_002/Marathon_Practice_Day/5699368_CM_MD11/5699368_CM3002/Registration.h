#ifndef REGISTRATION_H
#define REGISTRATION_H

class Registration{
    private:
        float m_licenseFee;
        float m_titleFee;
    public:
        Registration() = default;
        Registration(float licenseFee_, float titleFee_);

        // getters
        float getLicenseFee() const;
        float getTitleFee() const;
        
        // setters
        void setLicenseFee(float licenseFee_);
        void setTitleFee(float titleFee_);
};

#endif // REGISTRATION_H
