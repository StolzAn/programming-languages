#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct WordCard 
{
    string strok1, strok2;
};


class Arr
{

public:
    static const int Size = 80;
    int ar[Size];
    int tmp, i;

    Arr() {
        tmp = 0;
        for (i = 0; i < Size; i++)
            ar[i] = 0;
    }


    Arr(int h) {
        tmp = h;
        for (i = 0; i < tmp; ++i)
            cin >> ar[i];
    }


    unsigned char operator [](int index) {
        if (index < tmp && index >= 0)
            return ar[index];
        else if (index >= tmp) {
            cout << "nedopustimy index" << endl;
            return ' ';
        }
    }

public:
    void display() {
        for (i = 0; i < tmp; i++)
            cout << ar[i] << " ";
        cout << endl;
    }


    void get(int index) {
        if (index >= tmp)
            cout << "nedopustimy index" << endl;
        else
            cout << "mas[" << index << "]=" << ar[index] << endl;
    }

};


class Dictionary : public Arr
{

public:
    string Name;
    WordCard ar[Size];

    Dictionary() {
        Name = "";
        tmp = 0;
        for (i = 0; i < Size; i++) {
            ar[i].strok1 = "";
            ar[i].strok2 = "";
        }
    }

    Dictionary(int n) {
        tmp = n;
        cin >> Name;
        string eng, ru;


        if (tmp > 0)
            cin >> ar[0].strok1 >> ar[0].strok2;
        for (i = 1; i < tmp; ++i) {
            bool check = true;
            cin >> eng >> ru;
            for (int j = 0; j < i; ++j)
                if (eng == ar[j].strok1 && ru == ar[j].strok2)
                    check = false;
            if (check == true) {
                ar[i].strok1 = eng;
                ar[i].strok2 = ru;
            }
        }
    }


    Dictionary(char tmp) {
        Name = "";
        tmp = 0;

        for (i = 0; i < tmp; i++) {
            ar[i].strok1 = "";
            ar[i].strok2 = "";
        }
    }


    Dictionary(WordCard arr[], int newa) {
        Name = "";
        tmp = newa;

        for (i = 0; i < tmp; i++)
            ar[i] = arr[i];
    }

    Dictionary operator+ (Dictionary x) {
        int size = tmp;
        WordCard arr[Size * 2];
        for (i = 0; i < tmp; ++i) {
            arr[i].strok1 = ar[i].strok1;
            arr[i].strok2 = ar[i].strok2;
        }

        for (int j = 0; j < x.tmp; ++j) {
            bool check = true;

            for (i = 0; i < tmp; ++i)
                if (x.ar[j].strok1 == arr[i].strok1 && x.ar[j].strok2 == arr[i].strok2)
                    check = false;
            if (check == true) {
                arr[size].strok1 = x.ar[j].strok1;
                arr[size].strok2 = x.ar[j].strok2;
                size++;
            }
        }

        return Dictionary(arr, size);
    }


    Dictionary operator- (Dictionary x) {
        int size = 0;
        WordCard arr[Size];
        for (i = 0; i < tmp; ++i) {
            bool check = true;
            for (int j = 0; j < x.tmp; ++j)
                if (ar[i].strok1 == x.ar[j].strok1 && ar[i].strok2 == x.ar[j].strok2)
                    check = false;
            if (check == true) {
                arr[size].strok1 = ar[i].strok1;
                arr[size].strok2 = ar[i].strok2;
                size++;
            }
        }

        return Dictionary(arr, size);
    }

    Dictionary operator* (Dictionary x) {
        int size = 0;
        WordCard arr[Size];
        for (i = 0; i < tmp; ++i) {
            for (int j = 0; j < x.tmp; ++j)
                if (ar[i].strok1 == x.ar[j].strok1 && ar[i].strok2 == x.ar[j].strok2) {
                    arr[size].strok1 = ar[i].strok1;
                    arr[size].strok2 = ar[i].strok2;
                    size++;
                }
        }

        return Dictionary(arr, size);
    }


public:
    void display(int index, int k, int m = 0) {
        string st = "";

        switch (k) {
        case 0:
            for (i = 0; i < tmp; i++)
                cout << ar[i].strok1 << "-" << ar[i].strok2 << ";\n";
            break;

        case 1:
            cout << "Dictionary" << index << " " << ((m == 0) ? Name : st) << endl;
            for (i = 0; i < tmp; i++)
                cout << ar[i].strok1 << "-" << ar[i].strok2 << ";\n";

            break;
        }
    }

    void push(string worone, string wortwo) {
        bool check = false;

        for (i = 0; i < tmp; i++)
            if (ar[i].strok1 == worone && ar[i].strok2 == wortwo)
                check = true;
        if (check == false) {
            ar[tmp].strok1 = worone;
            ar[tmp].strok2 = wortwo;
            tmp++;
        }
    }

    void SH(string word) {
        int index = tmp;
        for (i = 0; i < tmp; i++) {
            if (word == ar[i].strok1) {
                index = i;
                break;
            }
        }

        if (index == tmp - 1 && index >= 0) {
            ar[index].strok1 = "";
            ar[index].strok2 = "";
            tmp--;
        }
        else
            if (index != tmp) {
                for (i = index; i < tmp - 1; i++)
                    ar[i] = ar[i + 1];
                ar[tmp - 1].strok1 = "";
                ar[tmp - 1].strok2 = "";
                tmp--;
            }
    }
};


int main()
{
    int sizeA, sizeone, sizetwo, key, val;
    string eng, ru, word;
    cin >> sizeA;
    Arr a(sizeA);
    a.display();
    cin >> sizeone;
    Dictionary one(sizeone);
    one.display(1, 1);
    cin >> sizetwo;
    Dictionary two(sizetwo);
    Dictionary three('a');
    two.display(2, 1);
    three = one + two;
    cout << "Dictionary1 + Dictionary2  ";
    three.display(0, 0);
    three = one - two;
    cout << "Dictionary1 - Dictionary2  ";
    three.display(0, 0);
    three = one * two;
    cout << "Dictionary1 * Dictionary2  ";
    three.display(0, 0);
    cin >> key;
    while (key != 0) {
        switch (key) {
        case 1:
            cin >> val;
            a.get(val);
            break;

        case 2:
            cin >> eng >> ru;
            one.push(eng, ru);

            one.display(1, 1);
            two.display(2, 1);

            three = one + two;
            cout << "Dictionary1 + Dictionary2  ";
            three.display(0, 0);

            three = one - two;
            cout << "Dictionary1 - Dictionary2  ";
            three.display(0, 0);

            three = one * two;
            cout << "Dictionary1 * Dictionary2  ";
            three.display(0, 0);
            break;

        case 3:
            cin >> eng >> ru;
            two.push(eng, ru);

            one.display(1, 1);
            two.display(2, 1);

            three = one + two;
            cout << "Dictionary1 + Dictionary2  ";
            three.display(0, 0);

            three = one - two;
            cout << "Dictionary1 - Dictionary2  ";
            three.display(0, 0);

            three = one * two;
            cout << "Dictionary1 * Dictionary2  ";
            three.display(0, 0);
            break;

        case 4:
            cin >> word;
            one.SH(word);

            one.display(1, 1, 1);
            two.display(2, 1);

            three = one + two;
            cout << "Dictionary1 + Dictionary2  ";
            three.display(0, 0);

            three = one - two;
            cout << "Dictionary1 - Dictionary2  ";
            three.display(0, 0);

            three = one * two;
            cout << "Dictionary1 * Dictionary2  ";
            three.display(0, 0);
            break;

        case 5:
            cin >> word;
            two.SH(word);

            one.display(1, 1, 1);
            two.display(2, 1, 1);

            three = one + two;
            cout << "Dictionary1 + Dictionary2  ";
            three.display(0, 0);

            three = one - two;
            cout << "Dictionary1 - Dictionary2  ";
            three.display(0, 0);

            three = one * two;
            cout << "Dictionary1 * Dictionary2  ";
            three.display(0, 0);
            break;

        default:
            cout << "ERROR! UNCORRECT KEY " << key << endl;
            break;
        }
        cin >> key;
    }
    return 0;
}