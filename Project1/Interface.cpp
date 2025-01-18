#include <iostream>
#include "Task.h"

void printMenu() {
    std::cout << "�������� �����:\n";
    std::cout << "1. ������ ����� � ��������� [n, m], ������� ������������� ��������\n";
    std::cout << "2. ���� ����� ��� �������� (���� ����������, ����� ������ 0)\n";
    std::cout << "3. �����\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;

    while (true) {
        printMenu();
        std::cin >> choice;

        if (choice == 1) {
            int n, m, k;
            std::cout << "������� �������� [n, m] � ������� k ����� ��������� �������: ";
            std::cin >> n >> m >> k;
            if (k < 0) {
                std::cout << "������: k �� ����� ���� �������������. ���������� �����.\n";
              
            }
            else {
                printNumbersInRange(n, m, k);
            }
        }
        else if (choice == 2) {
            countNumbersWithConditions();
        }
        else if (choice == 3) {
            std::cout << "����� �� ���������.\n";
            break;
        }
        else {
            std::cout << "������������ �����. ����������, ���������� �����.\n";
        }
    }

    return 0;
}
