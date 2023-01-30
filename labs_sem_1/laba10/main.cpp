#include <iostream>
#include <string>
#include <vector>

class Detail{
private:
    unsigned int m_id;
    std::string m_name;

public:
    Detail(int id, std::string name)
    {
        m_id = id;
        m_name = name;
    }

    std::string Name()
    {
        return m_name;
    }
};

class Vehicle{
private:
    unsigned int m_id;
    std::string m_name;
    std::vector <Detail*> m_details;
public:
    Vehicle(int id, std::string name)
    {
        m_id = id;
        m_name = name;
    }
    void PrintName(){
        std::cout << m_name;
    }
    void AddDetail(Detail* detail){
        m_details.push_back(detail);
    }
    void PrintDetails(){
        for(size_t i = 0; i < m_details.size();++i){
            std::cout << m_details[i] -> Name() << std::endl;
        }
    };
};

int main(){
    Detail detail1(0,"engine");
    Vehicle car(0,"VAZ 2101");
    Detail detail2(1,"wheel");
    car.AddDetail(&detail1);
    car.AddDetail(&detail2);
    car.PrintDetails();
    car.PrintName();
    return 0;
}