// Date .h file

#ifndef DATE_H
#define DATE_H

// class date --> to validate dates
class Date{
    private:
        unsigned int m_day, m_month, m_year;
        static const unsigned int s_monthsPerYear = 12;
    public:

        // constructors --> default and parameterized
        Date();
        Date(unsigned int d_, unsigned int m_, unsigned int y_);

        // member function --> checks date is valid or not 
        unsigned int checkDay(unsigned int testDay_) const;

        //setters to reset member variables
        void setDay(int d_);
        void setMonth(int m_);
        void setYear(int y_);

        // print method --> prints date in regular format
        void printDay() const;
};

#endif // DATE_H
