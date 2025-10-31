#ifndef GPSMODULE_H
#define GPSMODULE_H

class GPSModule{
    private:
        double m_latitude;
        double m_longitude;
        double m_speed;
        double m_heading; // angle between 0 - 360
    
    public:
        //constructors
        GPSModule();  
        GPSModule(double latitude_, double longitude, double speed_, double heading_);
        
        // updatePosition(double lat, double lon) --> to update new position
        void updatePosition(double lat_, double lon_);

        // updateSpeed(double spd) --> to update the speed
        void updateSpeed(double speed_);

        // getters
        double getLatitude() const;
        double getLongitude() const;
        double getSpeed() const;
        double getHeading() const;
};

#endif // GPSMODULE_H
