#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Decimal {
private:
    vector<unsigned char> digits;

public:
    bool isNegative = false;
    
    Decimal(const string& number) {
        for (int i = number.length() - 1; i >= 0; --i) {
            digits.push_back(number[i] - '0');
        }
    }

    Decimal() {}

    Decimal operator+(const Decimal& other) const {
        Decimal result;
        int carry = 0;

        for (size_t i = 0; i < max(digits.size(), other.digits.size()) || carry; ++i) {
            if (i == result.digits.size())
                result.digits.push_back(0);

            int sum = carry + (i < digits.size() ? digits[i] : 0) + (i < other.digits.size() ? other.digits[i] : 0);
            result.digits[i] = sum % 10;
            carry = sum / 10;
        }

        return result;
    }

    Decimal operator-(const Decimal& other) const {
        Decimal result;
        int borrow = 0;
    
        bool isFirstSmaller = (*this < other);
    
        // Проходим по каждой цифре числа, начиная с младших разрядов
        for (size_t i = 0; i < max(digits.size(), other.digits.size()); ++i) {
            // Вычитаем текущую цифру объекта, заем и соответствующую цифру вычитаемого объекта
            int diff;
            if (isFirstSmaller) {
                // Если первый массив меньше, меняем порядок вычитания и помечаем результат как отрицательный
                diff = (i < other.digits.size() ? other.digits[i] : 0) - borrow - digits[i];
            } else {
                diff = digits[i] - borrow - (i < other.digits.size() ? other.digits[i] : 0);
            }
    
            // Если результат отрицателен, корректируем разность и устанавливаем заем
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                // Иначе сбрасываем заем
                borrow = 0;
            }
    
            result.digits.push_back(diff);
        }
    
        
    
        while (result.digits.size() > 1 && result.digits.back() == 0) {
            result.digits.pop_back();
        }
        
        if (isFirstSmaller) {
            result.isNegative = true;
        }
        
        return result;
    }


    Decimal operator*(const Decimal& other) const {
        Decimal result;
        result.digits.resize(digits.size() + other.digits.size(), 0);

        for (size_t i = 0; i < digits.size(); ++i) {
            int carry = 0;
            for (size_t j = 0; j < other.digits.size() || carry; ++j) {
                long long current = result.digits[i + j] +
                                   static_cast<long long>(digits[i]) * (j < other.digits.size() ? other.digits[j] : 0) +
                                   carry;
                result.digits[i + j] = current % 10;
                carry = current / 10;
            }
        }

        while (result.digits.size() > 1 && result.digits.back() == 0) {
            result.digits.pop_back();
        }

        return result;
    }

    Decimal operator*(int value) const {
        Decimal result;
        result.digits.resize(digits.size(), 0);

        int carry = 0;
        for (size_t i = 0; i < digits.size() || carry; ++i) {
            long long current = result.digits[i] + static_cast<long long>(digits[i]) * value + carry;
            result.digits[i] = current % 10;
            carry = current / 10;
        }

        while (result.digits.size() > 1 && result.digits.back() == 0) {
            result.digits.pop_back();
        }

        return result;
    }

    Decimal operator/(const Decimal& other) const {
        if (other.digits.size() == 1 && other.digits[0] == 0) {
            cerr << "Error: Division by zero\n";
            exit(1);
        }
    
        Decimal result, current;
        for (int i = digits.size() - 1; i >= 0; --i) {
            current.digits.insert(current.digits.begin(), digits[i]);
    
            int x = 0;
            while (current >= other) {
                current = current - other;
                x++;
            }
    
            result.digits.insert(result.digits.begin(), x);
        }
    
        while (result.digits.size() > 1 && result.digits.back() == 0) {
            result.digits.pop_back();
        }
    
        return result;
    }

    Decimal& operator++() {
        *this = *this + Decimal("1");
        return *this;
    }

    Decimal operator++(int) {
        Decimal temp = *this;
        ++(*this);
        return temp;
    }

    Decimal& operator--() {
        if (*this > Decimal("0"))
            *this = *this - Decimal("1");
        *this = *this - Decimal("1");
        return *this;
    }

    Decimal operator--(int) {
        Decimal temp = *this;
        --(*this);
        return temp;
    }

    // Перегруженный оператор меньше или равно
    bool operator<=(const Decimal& other) const {
        return !(other < *this);
    }
    bool operator>=(const Decimal& other) const {
        return !(other > *this);
    }

    bool operator<(const Decimal& other) const {
        if (digits.size() != other.digits.size())
            return digits.size() < other.digits.size();

        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i])
                return digits[i] < other.digits[i];
        }

        return false;
    }

    bool operator==(const Decimal& other) const {
        return digits == other.digits;
    }

    bool operator>(const Decimal& other) const {
        return other < *this;
    }

    friend ostream& operator<<(ostream& os, const Decimal& dec) {
        for (int i = dec.digits.size() - 1; i >= 0; --i) {
            os << static_cast<int>(dec.digits[i]);
        }
        return os;
    }
};

int main() {
    // Ввод размера и элементов первого массива
    size_t size1;
    cin >> size1;

    string input1;
    cin >> input1;
    Decimal num1(input1);

    // Ввод размера и элементов второго массива
    size_t size2 = size1;

    string input2;
    cin >> input2;
    Decimal num2(input2);
    
    Decimal result = num1 - num2;
    
    Decimal tempNum1 = num1;
    Decimal tempNum2 = num2;
    
    // Вывод результатов
    cout << "Decimal1= " << num1 << endl;
    cout << "Decimal2= " << num2 << endl;
    cout << "Decimal1+Decimal2= " << num1 + num2 << endl;
    if(result.isNegative)
    {
        cout << "Decimal1-Decimal2= -" << num1 - num2 << endl;
    }
    else
    {
        cout << "Decimal1-Decimal2= " << num1 - num2 << endl;
    }
    cout << "Decimal1*Decimal2= " << num1 * num2 << endl;
    cout << "Decimal1/Decimal2= " << num1 / num2 << endl;
    cout << "Decimal1++= " << ++tempNum1 << endl;
    cout << "Decimal2++= " << ++tempNum2 << endl;
    cout << "Decimal1--= " << --tempNum1 << endl;
    cout << "Decimal1--= " << --tempNum2 << endl;
    
    // Сравнение массивов
    if (num1 < num2) {
        cout << "Decimal1 less Decimal2\n";
    } else if (num1 == num2) {
        cout << "Decimal1 equal Decimal2\n";
    } else {
        cout << "Decimal1 greater Decimal2\n";
    }
    
    
    int choice;
    do {
        // Меню действий
        cin >> choice;

        switch (choice) {
            case 1: {
                // Добавление элемента в конец первого массива
                unsigned char element = '0';
                cin >> element;
                num1 = num1 * Decimal("10") + Decimal(string(1, element));
                
                result = num1 - num2;
                tempNum1 = num1;
                tempNum2 = num2;
                
                // Вывод результатов
                cout << "Decimal1= " << num1 << endl;
                cout << "Decimal2= " << num2 << endl;
                cout << "Decimal1+Decimal2= " << num1 + num2 << endl;
                if(result.isNegative)
                {
                    cout << "Decimal1-Decimal2= -" << num1 - num2 << endl;
                }
                else
                {
                    cout << "Decimal1-Decimal2= " << num1 - num2 << endl;
                }
                cout << "Decimal1*Decimal2= " << num1 * num2 << endl;
                cout << "Decimal1/Decimal2= " << num1 / num2 << endl;
                cout << "Decimal1++= " << ++tempNum1 << endl;
                cout << "Decimal2++= " << ++tempNum2 << endl;
                cout << "Decimal1--= " << --tempNum1 << endl;
                cout << "Decimal1--= " << --tempNum2 << endl;
                
                // Сравнение массивов
                if (num1 < num2) {
                    cout << "Decimal1 less Decimal2\n";
                } else if (num1 == num2) {
                    cout << "Decimal1 equal Decimal2\n";
                } else {
                    cout << "Decimal1 greater Decimal2\n";
                }
                break;
            }
            case 2: {
                // Добавление элемента в конец второго массива
                unsigned char element;
                cin >> element;
                num2 = num2 * Decimal("10") + Decimal(string(1, element));
                
                result = num1 - num2;
                tempNum1 = num1;
                tempNum2 = num2;
                
                // Вывод результатов
                cout << "Decimal1= " << num1 << endl;
                cout << "Decimal2= " << num2 << endl;
                cout << "Decimal1+Decimal2= " << num1 + num2 << endl;
                if(result.isNegative)
                {
                    cout << "Decimal1-Decimal2= -" << num1 - num2 << endl;
                }
                else
                {
                    cout << "Decimal1-Decimal2= " << num1 - num2 << endl;
                }
                cout << "Decimal1*Decimal2= " << num1 * num2 << endl;
                cout << "Decimal1/Decimal2= " << num1 / num2 << endl;
                cout << "Decimal1++= " << ++tempNum1 << endl;
                cout << "Decimal2++= " << ++tempNum2 << endl;
                cout << "Decimal1--= " << --tempNum1 << endl;
                cout << "Decimal1--= " << --tempNum2 << endl;
                
                // Сравнение массивов
                if (num1 < num2) {
                    cout << "Decimal1 less Decimal2\n";
                } else if (num1 == num2) {
                    cout << "Decimal1 equal Decimal2\n";
                } else {
                    cout << "Decimal1 greater Decimal2\n";
                }
                
                break;
            }
            default:
                break;
        }
    } while (choice != 0);

    return 0;
}