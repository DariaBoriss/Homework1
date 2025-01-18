#include <iostream>
#include "Task.h"

void printMenu() {
    std::cout << "Выберите опцию:\n";
    std::cout << "1. Печать чисел в диапазоне [n, m], которые удовлетворяют условиям\n";
    std::cout << "2. Ввод чисел для подсчёта (ввод завершится, когда введёте 0)\n";
    std::cout << "3. Выход\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;

    while (true) {
        printMenu();
        std::cin >> choice;

        if (choice == 1) {
            int n, m, k;
            std::cout << "Введите диапазон [n, m] и разницу k между соседними цифрами: ";
            std::cin >> n >> m >> k;
            if (k < 0) {
                std::cout << "Ошибка: k не может быть отрицательным. Попробуйте снова.\n";
              
            }
            else {
                printNumbersInRange(n, m, k);
            }
        }
        else if (choice == 2) {
            countNumbersWithConditions();
        }
        else if (choice == 3) {
            std::cout << "Выход из программы.\n";
            break;
        }
        else {
            std::cout << "Некорректный выбор. Пожалуйста, попробуйте снова.\n";
        }
    }

    return 0;
}
