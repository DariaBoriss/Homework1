#include "Task.h"
#include <iostream>
#include <cmath>

// Проверка, является ли сумма цифр числа квадратом числа
bool isSumOfDigitsSquare(int num) {
    int sum = 0;

    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    // Проверяем, является ли сумма цифр квадратом числа
    int root = static_cast<int>(sqrt(sum));
    return root * root == sum;
}

// Проверка, есть ли постоянная разность между соседними цифрами
bool hasConstantDifference(int num, int k) {
    // Обрабатываем число как положительное
    num = std::abs(num);

    // Извлекаем последнюю цифру
    int prev_digit = num % 10;
    num /= 10;

    if (num <= 0)
        return false;

    // Проверяем разницу между каждой цифрой числа
    while (num > 0) {
        int curr_digit = num % 10;  // Текущая цифра
        if (std::abs(curr_digit - prev_digit) != k) {  // Если разница не равна k, возвращаем false
            return false;
        }
        prev_digit = curr_digit;  // Обновляем предыдущую цифру
        num /= 10;  // Убираем последнюю цифру
    }

    return true;  // Все цифры удовлетворяют условию
}

// Проверка, удовлетворяет ли число всем условиям
bool satisfiesConditions(int num, int k) {
    return isSumOfDigitsSquare(num) && hasConstantDifference(num, k);
}

// Печать чисел в диапазоне [n, m] с проверкой условий
void printNumbersInRange(int n, int m, int k) {
    for (int i = n; i <= m; ++i) {
        if (satisfiesConditions(i, k)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

// Функция для ввода чисел с подсчётом
void countNumbersWithConditions() {
    int num;
    int count = 0;


    while (true) {
        std::cout << "Введите число (для завершения введите 0): ";
        std::cin >> num;

        if (num == 0) {
            break;
        }

        // Проверка и подсчёт числа
        if (satisfiesConditions(num, 0)) {  // Для подсчёта проверяем без разницы k
            ++count;
        }
    }
    std::cout << "Количество чисел, удовлетворяющих условиям: " << count << std::endl;
}


