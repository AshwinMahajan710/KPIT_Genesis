#ifndef DETECTEDVEHICLE_H
#define DETECTEDVEHICLE_H

class DetectedVehicle{
    private:
        int m_id;
        float m_distanceMeters;
        float m_relativeSpeedMps;
        bool m_isBreaking;
    
    public:
        // constructors
        DetectedVehicle();
        DetectedVehicle(int id_, float distanceMeters_, float relativeSpeed_, bool isBreaking_);

        // all getters
        int getId() const;
        float getDistanceMeters() const;
        float getRelativeSpeedMps() const;
        bool getIsBreaking() const;

        // All setters
        void setId(int id_) ; // should not accept non-negative values : exception
        void setDistanceMeters(float distanceMeters_); // if negative set to 0.0 : cap
        void setRelativeSpeedMps(float relativeSpeed_) ; 
        void setIsBreaking(bool isBreaking_) ; 

};

#endif // DETECTEDVEHICLE_H