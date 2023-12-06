#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Pair {
public:
    int p1;
    int p2;
    double p3;

    Pair() {}

    int areEqual(Pair x2) {
        return (p1 == x2.p1) && (p2 == x2.p2);
    }

    void display(Pair x2) {
        cout << "(" << p1 << "," << p2 << ")  (" << x2.p1 << "," << x2.p2 << ")  " << endl;
    }
};

class Money : public Pair {
public:
    long int p1;

    Money() {}

    Money(int result) {
        if (result == 1) {
            cin >> p1 >> p2;
            p3 = p1 + 0.01 * p2;
        } else {
            p1 = 0;
            p2 = 0;
            p3 = 0;
        }
    }

    Money add(Money x2) {
        Money x3(0);
        p3 = p1 + 0.01 * p2;
        x2.p3 = x2.p1 + 0.01 * x2.p2;
        x3.p3 = p3 + x2.p3;
        x3.p1 = static_cast<long int>(x3.p3);
        x3.p2 = static_cast<int>(round((x3.p3 - x3.p1) * 100));
        return x3;
    }

    Money subtract(Money x2) {
        Money x3(0);
        p3 = p1 + 0.01 * p2;
        x2.p3 = x2.p1 + 0.01 * x2.p2;
        x3.p3 = p3 - x2.p3;
        x3.p1 = static_cast<long int>(x3.p3);
        x3.p2 = static_cast<int>(abs(round((x3.p3 - x3.p1) * 100)));
        return x3;
    }

    Money multiply(double value, double c) {
        Money x3(0);
        x3.p3 = value * c;
        x3.p1 = static_cast<long int>(x3.p3);
        x3.p2 = static_cast<int>((x3.p3 - x3.p1) * 100);
        return x3;
    }

    double divide(Money x2) {
        return floor((p3 / x2.p3)*100000)/100000;
    }

    void display(Money x2, double c) {
        Money resultAdd = add(x2);
        Money resultSubtract = subtract(x2);
        p3 = p1 + 0.01 * p2;
        x2.p3 = x2.p1 + 0.01 * x2.p2;
        Money resultMultiply = multiply(p3,c);
        Money resultMultiply2 = multiply(x2.p3, c);
        double resultDivide = divide(x2);

        cout << fixed << setprecision(2);
        cout << "Money1 (" << p1 << "."<< setw(2) << setfill('0')  << p2 <<" u.e) Money2 ("
             << x2.p1 << "." << setw(2) << setfill('0') << x2.p2 << " u.e)" << endl;
        cout << "Money1+Money2 (" << resultAdd.p3 << setw(2) << setfill('0') << " u.e)" << endl;
        cout << "Money1-Money2 (" << resultSubtract.p1 << "." << setw(2) << setfill('0')
             << resultSubtract.p2 << " u.e)" << endl;
        cout << "Money1*chislo (" << resultMultiply.p1 << "." << setw(2) << setfill('0')
             << resultMultiply.p2 << " u.e)" << endl;
        cout << "Money2*chislo (" << resultMultiply2.p1 << "." << setw(2) << setfill('0')
             << resultMultiply2.p2 << " u.e)" << endl;
        cout << "Money1/Money2 (" << setprecision(5) << resultDivide << ")" << endl;
    } 
};

class Fraction : public Pair {
public:
    long long p1;

    Fraction() {}

    Fraction(int result) {
        if (result == 1) {
            cin >> p1 >> p2;
            p3 = p1 + p2 / 100.00;
        } else {
            p1 = 0;
            p2 = 0;
            p3 = 0;
        }
    }

    Fraction add(Fraction x2) {
        Fraction x3(0);
        p3 = p1 + p2 / 100.00;
        x2.p3 = x2.p1 + 0.01 * x2.p2;
        x3.p3 = p3 + x2.p3;
        x3.p1 = static_cast<long long>(x3.p3);
        x3.p2 = static_cast<int>(round((x3.p3 - x3.p1) * 100));
        return x3;
    }

    Fraction subtract(Fraction x2) {
        Fraction x3(0);
        p3 = p1 + p2 / 100.00;
        x2.p3 = x2.p1 + 0.01 * x2.p2;
        x3.p3 = p3 - x2.p3;
        x3.p1 = static_cast<long long>(x3.p3);
        x3.p2 = static_cast<int>(abs(round((x3.p3 - x3.p1) * 100)));
        return x3;
    }

    Fraction multiply(Fraction x2) {
        Fraction x3(0);
        p3 = p1 + (p2 / 100.00);
        x2.p3 = x2.p1 + 0.01 * x2.p2;
        x3.p3 = floor(p3 * x2.p3 * 100000000) / 100000000; // изменение этой строки
        x3.p1 = static_cast<long long>(x3.p3);
        x3.p2 = static_cast<int>(floor((x3.p3 - x3.p1) * 100));
        return x3;
    }

    Fraction divide(Fraction x2) {
        Fraction x3(0);
        x2.p3 = x2.p1 + 0.01 * x2.p2;
        x3.p3 = p3 / x2.p3;
        x3.p1 = static_cast<long long>(x3.p3);
        x3.p2 = static_cast<int>((x3.p3 - x3.p1) * 100);
        return x3;
    }

    void display(Fraction x2) {
        Fraction resultAdd = add(x2);
        Fraction resultSubtract = subtract(x2);
        Fraction resultMultiply = multiply(x2);
        Fraction resultDivide = divide(x2);

        cout << fixed << setprecision(2);
        cout << "Fraction1 " << p1 << "." << setw(2) << setfill('0') << p2 << " Fraction2 "
             << x2.p1 << "." << setw(2) << setfill('0') << x2.p2 << endl;
        cout << "Fraction1+Fraction2 " << resultAdd.p3 << endl;
        cout << "Fraction1-Fraction2 " << resultSubtract.p1 << "." << setw(2) << setfill('0')
             << resultSubtract.p2<< endl;
        cout << "Fraction1*Fraction2 " << resultMultiply.p1 << "." << setw(2) << setfill('0')
             << resultMultiply.p2<< endl;
        cout << "Fraction1/Fraction2 " << resultDivide.p1 << "." << setw(2) << setfill('0')
             << resultDivide.p2 << " " << endl;
    }
};

int main() {
    double c;
    Pair pair;
    Money x1(1);
    Money x2(1);
    cin >> c;
    x1.display(x2, c);

    Fraction y1(1);
    Fraction y2(1);
    y1.display(y2);

    int user_choice = 1;
    
    while (user_choice != 0) {
        cin >> user_choice;
        switch(user_choice){
            case 0:
                break;
            case 1:
                cin >> x1.p1 >> x1.p2;
                x1.display(x2, c);
                break;
            case 2:
                cin >> x2.p1 >> x2.p2;;
                x1.display(x2, c);
                break;
            case 3:
                cin >> y1.p1 >> y1.p2;
                y1.display(y2);
                break;
            case 4:
                cin >> y2.p1 >> y2.p2;;
                y1.display(y2);
                break;
            case 5:
                cin >> c;
                x1.display(x2, c);
                break;
        }
    }

    return 0;
}