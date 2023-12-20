#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>

#ifndef _MSC_VER
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif

using namespace std;

class EXCEPT : public exception
{
public:
    const char *what() const NOEXCEPT override
    {
        return "My custom exception";
    }
};

class ComplexNumber
{
public:
    double magnitude;
    double angle;

    ComplexNumber(double magnitude, double angle) : magnitude(magnitude), angle(angle) {}

    friend ostream &operator<<(ostream &os, const ComplexNumber &complex)
    {
        os << complex.magnitude << "*(cos(" << complex.angle << ")+ i*sin(" << complex.angle << ")";
        return os;
    }
};

ComplexNumber oper(double a, double b) throw(EXCEPT)
{
    if (a == 0)
        throw EXCEPT();
    
    double magnitude = sqrt(a * a + b * b);
    double angle = atan(b/abs(a));

    return ComplexNumber(magnitude, angle);
}

int main()
{
    setlocale(LC_ALL, "rus");

    int length;
    cin >> length;
    cin.ignore();

    for (int i = 0; i < length; i++)
    {
        double a, b;
        cin >> a >> b;

        try
        {
            ComplexNumber result = oper(a, b);
            cout << result << endl;
        }
        catch (const EXCEPT &)
        {
            cout << "Error №1 - nulevoy znamenatel arcsinus!!!!" << endl;
        }
    }

    system("pause>>null");
    return 0;
}