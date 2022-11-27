#include <iostream>
#include <cmath>
class Triangle{
    private:
    double m_first_side = 0;
    double m_second_side = 0;
    double m_third_side = 0;

    public:
    Triangle() = default;
    bool SetFirstSide(double fSide){
        if (fSide <= 0){
            std::cout << "Error in value of first side" << std::endl;
            return false;
        }
        m_first_side = fSide;
    }
    bool SetSecondSide(double sSide){
        if (sSide <= 0){
            std::cout << "Error in value of second side" << std::endl;
            return false;
        }
        m_second_side = sSide;
    }
    bool SetThirdSide(double tSide){
        if (tSide <= 0){
            std::cout << "Error in value of third side" << std::endl;
            return false;
        }
        m_third_side = tSide;
    }
    double area(){
        double hPer = (m_first_side + m_second_side + m_third_side)/2;
        double area_sq = hPer * (hPer - m_first_side) * (hPer - m_first_side) * (hPer - m_first_side);
        return pow(area_sq,0.5);
    }
    ~Triangle() = default;

};
int main(){
    Triangle first;
    std::cout << "Input sides of a triangle: ";
    int a,b,c;
    std::cin >> a >> b >> c;
    first.SetFirstSide(a);
    first.SetSecondSide(b);
    first.SetThirdSide(c);
    std::cout << "The area of a triangle: " << first.area();

    return 0;
}