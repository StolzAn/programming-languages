#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Figure {
public:
    double x1, x2, x3, y1, y2, y3, Per, Sqr;
    string str;

    virtual void PerimeterAndSquare(double &Per, double &Sqr) {
        double side1 = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
        double side2 = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
        double side3 = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
        Per = side1 + side2 + side3;
        double half_perimetr = Per / 2;
        Sqr = sqrt(half_perimetr * (half_perimetr - side1) * (half_perimetr - side2) * (half_perimetr - side3));
    }
    
    virtual void Display_Characteristics(Figure &other){
        cout << str << " (" << x1 << "," << y1 << ") (" << x2 << "," << y2 << ") (" << x3 << "," << y3 << ") "
             << "Perimetr= " << Per << " Square= " << Sqr << endl;
        cout << other.str << " (" << other.x1 << "," << other.y1 << ") (" << other.x2 << "," << other.y2 << ") ("
             << other.x3 << "," << other.y3 << ") " << "Perimetr= " << other.Per << " Square= " << other.Sqr << endl;
    }
    
    virtual void Compare(Figure &other) {
        if(Sqr < other.Sqr)
             cout << str << " & " << other.str << " Less" << endl;
        else if (Sqr > other.Sqr)
            cout << str << " & " << other.str << " Greate" << endl;
        else
            cout << str << " & " << other.str << " Equal" << endl;
    }

    virtual void Move(double a, double b) {
        x1 += a;
        x2 += a;
        x3 += a;
        y1 += b;
        y2 += b;
        y3 += b;
    }
};

class Quadrilateral : public Figure {
public:
    double x4, y4;

    void PerimeterAndSquare(double &Per, double &Sqr) override {
        double side1 = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
        double side2 = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
        double side3 = sqrt(pow((x4 - x3), 2) + pow((y4 - y3), 2));
        double side4 = sqrt(pow((x1 - x4), 2) + pow((y1 - y4), 2));
        Per = side1 + side2 + side3 + side4;
        Sqr = side1 * side2;
    }
    
    void Display_Characteristics(Figure &other)override{
        cout << str << " (" << x1 << "," << y1 << ") (" << x2 << "," << y2 << ") (" << x3 << "," << y3 << ") ("
             << x4 << "," << y4 << ") " << "Perimetr= " << Per << " Square= " << Sqr << endl;
        cout << other.str << " (" << other.x1 << "," << other.y1 << ") (" << other.x2 << "," << other.y2 << ") ("
             << other.x3 << "," << other.y3 << ") (" << static_cast<Quadrilateral&>(other).x4 << ","
             << static_cast<Quadrilateral&>(other).y4 << ") "
             << "Perimetr= " << other.Per << " Square= " << other.Sqr << endl;
    }
    void Compare(Figure &other) override {
        if(Sqr < other.Sqr)
             cout << str << " & " << other.str << " Less" << endl;
        else if (Sqr > other.Sqr)
            cout << str << " & " << other.str << " Greate" << endl;
        else
            cout << str << " & " << other.str << " Equal" << endl;
    }

    void Move(double a, double b) override {
        x1 += a;
        x2 += a;
        x3 += a;
        x4 += a;
        y1 += b;
        y2 += b;
        y3 += b;
        y4 += b;
    }
};

int main() {
    Figure fig1, fig2;
    Quadrilateral fig3, fig4;
    
    cin >> fig1.str >> fig1.x1 >> fig1.y1 >> fig1.x2 >> fig1.y2 >> fig1.x3 >> fig1.y3;
    cin >> fig2.str >> fig2.x1 >> fig2.y1 >> fig2.x2 >> fig2.y2 >> fig2.x3 >> fig2.y3;
    
    fig1.PerimeterAndSquare(fig1.Per, fig1.Sqr);
    fig2.PerimeterAndSquare(fig2.Per, fig2.Sqr);
    
    fig1.Display_Characteristics(fig2);
    fig1.Compare(fig2);

    
    cin >> fig3.str >> fig3.x1 >> fig3.y1 >> fig3.x2 >> fig3.y2 >> fig3.x3 >> fig3.y3 >> fig3.x4 >> fig3.y4;
    cin >> fig4.str >> fig4.x1 >> fig4.y1 >> fig4.x2 >> fig4.y2 >> fig4.x3 >> fig4.y3 >> fig4.x4 >> fig4.y4;
    
    fig3.PerimeterAndSquare(fig3.Per, fig3.Sqr);
    fig4.PerimeterAndSquare(fig4.Per, fig4.Sqr);
    
    fig3.Display_Characteristics(fig4);
    fig3.Compare(fig4);

    int user_choice = 1;
    
    for(;;){
        cin>>user_choice;
        if(user_choice==0){
            break;
        }
        double a, b;
        cin >> a >> b;
        switch(user_choice){
            case 1:
                fig1.Move(a, b);
                fig1.Display_Characteristics(fig2);
                fig1.Compare(fig2);
                break;
            case 2:
                fig2.Move(a, b);
                fig1.Display_Characteristics(fig2);
                fig1.Compare(fig2);
                break;
            case 3:
                fig3.Move(a, b);
                fig3.Display_Characteristics(fig4);
                fig3.Compare(fig4);
                break;
            case 4:
                fig4.Move(a, b);
                fig3.Display_Characteristics(fig4);
                fig3.Compare(fig4);
                break;
        }
    }

    return 0;
}