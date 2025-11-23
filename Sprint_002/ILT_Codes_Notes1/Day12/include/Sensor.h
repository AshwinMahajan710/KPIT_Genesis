#ifndef SENSOR_H
#define SENSOR_H

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

class Sensor{
    private:
        std::string m_name;
        int m_priority;
        double m_reading;

    public:
        Sensor() = default;
        Sensor(const std::string& name_, int priority_, double reading_);
        Sensor(const Sensor&) = default;
        Sensor& operator =(const Sensor&) = default;
        Sensor(Sensor&&) = default;
        Sensor& operator =(Sensor&&) = default;
        ~Sensor() = default;

        // getters
        std::string getName() const;
        int getPriority() const;
        double getReading() const;

        // display
        void display() const;
};

// int main(){

//     // std::vector<int> src = {1,2,3,4,5,6,7,8,9,10};
//     // std::vector<int> dest;

//     // dest.resize(src.size());

//     // // to copy --> all elements
//     // std::copy(src.begin(), src.end(), dest.begin());
//     // for (auto i = src.begin(); i != src.end(); i++)
//     // {
//     //     std::cout<<*i;
//     // }
//     // std::cout<<"\n";

//     // // to copy --> only n elements
//     // std::copy_n(src.begin(), 4, dest.begin());
//     // for (auto i = dest.begin(); i != dest.end(); i++)
//     // {
//     //     std::cout<<*i;
//     // }
//     // std::cout<<"\n";
    
//     // // to copy --> with respect to some condition
//     // std::vector<int> dest_con;
//     // std::copy_if(src.begin(), src.end(), std::back_inserter(dest_con), [](int x){return (x%2 == 0);});
//     // for (auto i = dest_con.begin(); i != dest_con.end(); i++)
//     // {
//     //     std::cout<<*i;
//     // }
//     // std::cout<<"\n";

//     // // finding some elements
//     // std::vector<int >::iterator location = find(src.begin(), src.end(), 7);
//     // if(location != src.end()){std::cout<<"Found"<<std::endl;}
//     // else {std::cout<<"Not Found"<<std::endl;}
    
//     // // finding with some condition
//     // auto oddlocation = find_if(src.begin(), src.end(), [](int x){return (x%2 == 0);});
//     // if(oddlocation != src.end()){
//     //     std::cout<<"No is: "<<*oddlocation<<std::endl;
//     // }

//     // return 0;

    
// }

#endif // SENSOR_H
