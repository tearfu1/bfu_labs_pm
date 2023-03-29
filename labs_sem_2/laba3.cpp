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
        (*this).real = (*this).real * z.real - (*this).img * z.img;
        (*this).img = (*this).real * z.img + (*this).img * z.real;
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
