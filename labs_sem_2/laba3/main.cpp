#include <iostream>

class Complex
{
private:
    double real;
    double img;
public:
    explicit Complex(double a = 0.0, double b = 0.0) : real(a), img(b) {}
    Complex(const Complex& z)
    {
        real = z.real;
        img = z.img;
    }
    Complex& operator=(Complex z)
    {
        std::swap(real,z.real);
        std::swap(img,z.img);
        return *this;
    }
    Complex& operator+=(const Complex& z)
    {
        (*this).real += z.real;
        (*this).img += z.img;
        return *this;
    }
    Complex& operator*=(const Complex& z)
    {
        double temp_real, temp_img;
        temp_real = (*this).real * z.real - (*this).img * z.img;
        temp_img = (*this).real * z.img + (*this).img * z.real;

        (*this).img = temp_img;
        (*this).real = temp_real;

        return *this;
    }
    Complex& operator++()
    {
        this->real+=1;
        return *this;
    }
    Complex& operator++(int)
    {
        Complex temp = *this;
        this->real+=1;
        return temp;
    }
    friend std::ostream& operator<<(std::ostream& out, const Complex& z);
    friend std::istream& operator>>(std::istream& in, Complex& z);
};
Complex operator+(const Complex& z1,const Complex& z2){
    Complex temp = z1;
    temp += z2;
    return temp;
}
Complex operator*(const Complex& z1, const Complex& z2)
{
    Complex temp = z1;
    temp *= z2;
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Complex& z)
{
    out<<z.real << " " << z.img<<"i";
}
std::istream& operator>>(std::istream& in, Complex& z)
{
    in >> z.real >> z.img;
}

int main()
{
    Complex z1(1,1);
    Complex z2(2,2);
    Complex z3 = z1*z2;
    std::cout << z1 << " " << z2 << " " << z3;

    return 0;
}