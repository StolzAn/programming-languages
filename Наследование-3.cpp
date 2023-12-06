#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

class Array {
public:
    int* Arr;
    int size1;
    
    Array() : Arr(nullptr), size1(0) {}

    ~Array() {
        delete[] Arr;
    }

    int operator[](int i) {
        return Arr[i];
    }

    void create(int size) {
        size1 = size;
        Arr = new int[size1];
    }

    void fillArray() {
        for (int i = 0; i < size1; i++)
            std::cin >> Arr[i];
    }

    void displayArray(int num) {
        std::cout << "Array" << num << ' ';
        for (int i = 0; i < size1; i++)
            std::cout << std::dec << Arr[i] << " ";
    }

    void change() {
        int index;
        std::cin >> index;
        int value;
        std::cin >> value;
        Arr[index] = value;
    }

    void sum(int* a, int* b) {
        std::cout << "Array1+Array2 ";
        for (int i = 0; i < size1; i++) {
            std::cout << a[i] + b[i] << " ";
        }
        std::cout << std::endl;
    }
};

class Decimal : public Array {
public:
    char mas[100];
    int size;

    Decimal(int b) : size(b) {}

    void fill() {
        for (int i = size - 1; i >= 0; i--)
            std::cin >> mas[i];
    }

    void display(int num) {
        std::cout << "Decimal" << num << ' ';
        for (int i = 0; i < size; i++)
            std::cout << std::dec << mas[i];
        std::cout << " ";
    }

    void operationDecimal(char* str1, char* str2) {
        long long a = atoll(str1);
        long long b = atoll(str2);
        char itog[100];
        int len = strlen(itog);
        std::cout << std::endl;
        std::cout << "Decimal1+Decimal2" << " " << a + b << std::endl;
        std::cout << "Decimal1-Decimal2" << " " << a - b << std::endl;
        std::cout << "Decimal1*Decimal2" << " " << a * b << std::endl;
        std::cout << "Decimal1/Decimal2" << " " << static_cast<int>(a / b) << std::endl;
    }
};

class Hex : public Array {
public:
    char* mass_char;
    int* mass_int;
    int len3;
    long long int itog;

    Hex() {}

    Hex(bool value, int this_len) {
        itog = 0;

        if (value) {
            long long exp = 1;

            if (this_len == 20)
                std::cin >> len3;
            else
                len3 = this_len;

            mass_char = new char[len3];
            mass_int = new int[len3];

            for (int i = 0; i < len3; i++) {
                std::cin >> mass_char[i];
                mass_int[i] = charToInt(mass_char[i]);

                itog += exp * mass_int[i];
                exp *= 16;
            }
        }
        else {
            mass_char = new char[this_len];
            mass_int = new int[this_len];

            len3 = this_len;
            for (int i = 0; i < this_len + 1; i++) {
                mass_int[i] = 0;
                mass_char[i] = '0';
            }
        }
    }

    void print(Hex x) {
        long long int temp;

        std::cout << "Hex1 ";
        for (int i = len3 - 1; i > -1; i--)
            std::cout << mass_char[i];
        std::cout << " Hex2 ";
        for (int i = x.len3 - 1; i > -1; i--)
            std::cout << x.mass_char[i];
        std::cout << std::endl;

        temp = (itog + x.itog);
        std::cout << "Hex1+Hex2  ";
        std::cout << std::dec << std::hex << temp << std::endl;

        std::cout << "Hex1-Hex2  ";
        temp = (itog - x.itog);
        if (temp < 0)
            std::cout << "-";
        std::cout << std::dec << std::hex << std::abs(temp) << std::endl;

        temp = (itog * x.itog);
        std::cout << "Hex1*Hex2  ";
        std::cout << std::dec << std::hex << temp << std::endl;

        temp = (itog / x.itog);
        std::cout << "Hex1/Hex2 ";
        std::cout << std::dec << std::hex << temp << std::dec;
        std::cout << std::endl;
    }

    int charToInt(char t) {
        switch (t) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'A': return 10;
        case 'B': return 11;
        case 'C': return 12;
        case 'D': return 13;
        case 'E': return 14;
        case 'F': return 15;
        }
        return 0;
    }
};

int main() {
    int sizeArray;
    int sizeDecimal;
    std::cin >> sizeArray;

    Array a1;
    Array a2;

    a1.create(sizeArray);
    a1.fillArray();
    a1.displayArray(1);

    a2.create(sizeArray);
    a2.fillArray();
    a2.displayArray(2);

    std::cout << std::endl;
    a1.sum(a1.Arr, a2.Arr);

    Hex hexFirst(true, 20);
    Hex hexSecond(true, hexFirst.len3);
    hexFirst.print(hexSecond);

    std::cin >> sizeDecimal;

    Decimal d1(sizeDecimal);
    Decimal d2(sizeDecimal);

    d1.fill();
    d1.display(1);

    d2.fill();
    d2.display(2);

    d1.operationDecimal(d1.mas, d2.mas);

    int k;
    long long exp;

    while (true) {
        std::cin >> k;
        switch (k) {
        case 1:
            a1.change();
            a1.displayArray(1);
            a2.displayArray(2);
            std::cout << std::endl;
            a1.sum(a1.Arr, a2.Arr);
            break;
        case 2:
            a2.change();
            a1.displayArray(1);
            a2.displayArray(2);
            std::cout << std::endl;
            a1.sum(a1.Arr, a2.Arr);
            break;
        case 3:
            hexFirst.itog = 0;
            exp = 1;
            for (int i = 0; i < hexFirst.len3; i++) {
                std::cin >> hexFirst.mass_char[i];
                hexFirst.mass_int[i] = hexFirst.charToInt(hexFirst.mass_char[i]);
            }
            for (int i = 0; i < hexFirst.len3; i++) {
                hexFirst.itog += exp * hexFirst.mass_int[i];
                exp *= 16;
            }
            hexFirst.print(hexSecond);
            continue;
        case 4:
            hexSecond.itog = 0;
            exp = 1;
            for (int i = 0; i < hexSecond.len3; i++) {
                std::cin >> hexSecond.mass_char[i];
                hexSecond.mass_int[i] = hexSecond.charToInt(hexSecond.mass_char[i]);
            }
            for (int i = 0; i < hexSecond.len3; i++) {
                hexSecond.itog += exp * hexSecond.mass_int[i];
                exp *= 16;
            }
            hexFirst.print(hexSecond);
            continue;
        case 5:
            d1.fill();
            d1.display(1);
            d2.display(2);
            d1.operationDecimal(d1.mas, d2.mas);
            break;
        case 6:
            d2.fill();
            d1.display(1);
            d2.display(2);
            d1.operationDecimal(d1.mas, d2.mas);
            break;
        case 0:
            return 0;
        }
    }
    return 0;
}