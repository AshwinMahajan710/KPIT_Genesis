#include<iostream>
#include<string>

struct book
{
    std::string m_name;
    double m_price;
    std::string m_author;    
    int m_pages;
};

int main(){

    book b1{"Harry Potter",100.0,"K. WIlson", 100};
    book b2{"Garudzhep", 234.2,"K. Patil", 334};
    book b3{"Bhagwadgita", 1000,"M. Vyas", 700};

    std::cout<<"\nBook 1 Details: "<<std::endl;
    std::cout<<"Name: "<<b1.m_name<<"  Price: "<<b1.m_price<<"  Author: "<<b1.m_author<<"  Pages: "<<b1.m_pages<<std::endl;
    std::cout<<"\nBook 2 Details: "<<std::endl;
    std::cout<<"Name: "<<b2.m_name<<"  Price: "<<b2.m_price<<"  Author: "<<b2.m_author<<"  Pages: "<<b2.m_pages<<std::endl;
    std::cout<<"\nBook 3 Details: "<<std::endl;
    std::cout<<"Name: "<<b3.m_name<<"  Price: "<<b3.m_price<<"  Author: "<<b3.m_author<<"  Pages: "<<b3.m_pages<<std::endl;
    
    auto [Name, price, author, pages] = b1;
    
    std::cout<<"\nBook 1 Details: "<<std::endl;
    std::cout<<"Name: "<<Name<<"  Price: "<<price<<"  Author: "<<author<<"  Pages: "<<pages<<std::endl;
    return 0;
}

/*
#include <iostream>
#include <string>
 
 
struct Sensor
{
    int id;
    float reading;
    std::string type;
};
 
Sensor getSensorData()
{
    return Sensor{101, 55.7f, "Temperature"};
}
 
int main()
{
    Sensor s{200, 72.5f, "Pressure"};
 
 
    auto [sid, sreading, stype] = s;// Structured binding
    //sid=s.id; sreading=s.reading; stype=s.type;
 
    std::cout << "=== Structured Binding (Copy) ===\n";
    std::cout << "id      : " << sid << std::endl;
    std::cout << "reading : " << sreading << std::endl;
    std::cout << "type    : " << stype << std::endl;
 
    // Modifying structured binding variables does NOT affect original struct
    sid = 999;
    std::cout << "After modifying sid = 999\n";
    std::cout << "Original struct id still = " << s.id << "\n";
 
 
   
    auto& [rid, rreading, rtype] = s;//reference binding
 
    rid = 500; // Changes the real struct
    rtype = "Pressure-Updated";
 
    std::cout << "=== Structured Binding (Reference) ===\n";
    std::cout << "id      : " << s.id << std::endl;
    std::cout << "reading : " << s.reading << std::endl;
    std::cout << "type    : " << s.type << std::endl << std::endl;
   
    std::cout << "=== CONST REFERENCE STRUCTURED BINDING ===\n";
   
    const auto& [cid, creading, ctype] = s;//
     std::cout << "cid      : " << cid << std::endl;
    std::cout << "creading : " << creading << std::endl;
    std::cout << "ctype    : " << ctype << std::endl;
    //cid = 123;
   
 
 
    auto [id2, reading2, type2] = getSensorData();
 
    std::cout << "=== Structured Binding from Function ===\n";
    std::cout << "id      : " << id2 <<std::endl;
    std::cout << "reading : " << reading2 << std::endl;
    std::cout << "type    : " << type2 << std::endl;
 
    return 0;
}
 
 
*/

/*
//Uppala Karthikeya
#include <tuple>
#include <string>
#include <iostream>
 
//before Structured binding
//std::get<0>(getStudent)
 
//syntax for Tuple
std::tuple<int, std::string> getStudent() {
    return {101, "Karthik"};
}
 
int main() {
 
 
    auto [id, name] = getStudent();
    std::cout << id << " " << name;
}
 
*/

/*
 
//Amuljot Singh
#include <utility>
#include <string>
#include <map>
 
std::pair<std::string, double> getPair()
{
    std::pair<std::string, double> pair = {"Hello", 10.5};
    return pair;
}
 
int main()
{
    // 1)Structure Binding using pair
    std::pair<int, std::string> pair1 = {5, "KPIT"};
 
    auto [num, text] = pair1; // Structured Binding
 
    // It unpacks the pair and assign the values as
    //  num=pair1.first && text=pair1.second
 
    std::cout << "Pair: " << num << ", " << text << "\n";
 
    // --------------------------------------------------
    // 2) using function
    auto [str, doubleVal] = getPair();
 
    // str="Hello" doubleVal=1.2
 
    std::cout << "\nStructured Binding using function: \n";
    std::cout << str << ", " << doubleVal << "\n";
 
    // We can modify them easily using structured binding
    str = "Changed";
    doubleVal = 2.6;
 
    std::cout << "\nUpdating values of pair using structured binding: \n";
    std::cout << str << ", " << doubleVal << "\n";
 
    // ---------------------------------------------------------
 
    // 3)Structured Binding using reference
    std::pair<int, int> pair2 = {10, 20};
 
    auto &[num1, num2] = pair2; // Structured Binding using reference
 
    // Now changes value
    num1 = 100; // It will affect pair2 as it changes pair2.first
    num2 = 500; // It will affect pair2 as it changes pair2.second
 
    std::cout << "\nReference Structured Binding\n";
    std::cout << "Pair2= " << pair2.first << ", " << pair2.second << "\n";
 
    // 4)Structured Binding in Maps
    std::map<int, std::string> map1 = {{1, "Hi"}, {2, "Hello"}, {3, "Bye"}};
 
    // Structure Binding used inside loop
    for (const auto &[key, value] : map1)
    {
        std::cout << "Key: " << key << " ->Value: " << value << "\n";
    }
}
 

*/