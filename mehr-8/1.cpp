#include <iostream>
#include <cmath>

class Complex
{
  public:
    Complex(float = 0, float = 0);
    void setNumber(float, float);
    float getReal() const;
    float getImg() const;
    void add(const Complex &);
    void subtract(const Complex &);
    void multiply(const Complex &);
    void print() const;

  private:
    float real, img;
};

Complex::Complex(float real, float img) : real(real), img(img) {}

void Complex::setNumber(float real, float img)
{
    this->real = real;
    this->img = img;
}
float Complex::getReal() const { return this->real; }
float Complex::getImg() const { return this->img; }

void Complex::add(const Complex &complex)
{
    this->real += complex.getReal();
    this->img += complex.getImg();
}
void Complex::subtract(const Complex &complex)
{
    this->real -= complex.getReal();
    this->img -= complex.getImg();
}
void Complex::multiply(const Complex &complex)
{

    float previous_real = this->getReal(),
          previous_img = this->getImg();

    this->real = previous_real * complex.getReal() -
                 previous_img * complex.getImg();

    this->img = previous_real * complex.getImg() +
                previous_img * complex.getReal();
}
void Complex::print() const
{
    if (this->getReal() != 0 && this->getImg() != 0)
        std::cout << this->getReal() << (this->getImg() > 0 ? " + " : " - ")
                  << std::abs(this->getImg()) << 'i' << std::endl;

    else if (this->getImg() == 0)
        std::cout << this->getReal() << std::endl;

    else if (this->getReal() == 0)
        std::cout << this->getImg() << 'i' << std::endl;
}
int main()
{

    float real, img;
    std::cin >> real >> img;

    Complex num(real, img);

    while (true)
    {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "print")
            num.print();
        else if (cmd == "add")
        {
            float real, img;
            std::cin >> real >> img;
            num.add(Complex(real, img));
        }
        else if (cmd == "subtract")
        {
            float real, img;
            std::cin >> real >> img;
            num.subtract(Complex(real, img));
        }
        else if (cmd == "multiply")
        {
            float real, img;
            std::cin >> real >> img;
            num.multiply(Complex(real, img));
        }
        else if (cmd == "exit")
        {
            break;
        }
    }
    return 0;
}