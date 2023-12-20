#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

// Функция для вывода массива с заданным форматированием
void printArray(const vector<double> &arr) {
    for (const auto &element : arr) {
        cout << fixed << setprecision(3) << element << " ";
    }
    cout << endl;
}

// Функция для добавления суммы и среднего арифметического в массив
void addSumAndAverage(vector<double> &arr) {
    double sum = accumulate(arr.begin(), arr.end(), 0.0);
    double average = sum / arr.size();
    arr.push_back(sum);
    arr.push_back(average);
}

// Функция для деления элементов массива на половину максимального элемента
void divideByHalfOfMax(vector<double> &arr) {
    double maxElement = *max_element(arr.begin(), arr.end());
    for (auto &element : arr) {
        element /= (maxElement / 2);
    }
}

// Функция для обработки команд пользователя
void processCommand(vector<double> &arr) {
    int command;
    cin >> command;

    if (command == 1) {
        double newElement;
        cin >> newElement;
        arr.push_back(newElement);
        
        cout << "+: " << arr.size() << endl;

        printArray(arr);

        addSumAndAverage(arr);
        printArray(arr);
        divideByHalfOfMax(arr);

        printArray(arr);
    } else if (command == 2 && !arr.empty()) {
        double removedElement = arr.back();
        arr.pop_back();
        
        cout << "-: " <<arr.size() << endl;
        printArray(arr);

        addSumAndAverage(arr);
        printArray(arr);
        divideByHalfOfMax(arr);

        printArray(arr);
    } else if (command == 0) {
        exit(0);
    } else {
        cout << "Некорректная команда. Попробуйте снова." << endl;
    }
}

int main() {
    vector<double> arr;

    int n;
    
    cin >> n;
    
    cout << n << endl;
    
    arr.resize(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    printArray(arr);
    
    addSumAndAverage(arr);
    
    printArray(arr); 
    
    divideByHalfOfMax(arr);
    
    printArray(arr); 
    
    while (true) {
        processCommand(arr);
    }

    return 0;
}