#include "Task.h"
#include <iostream>
#include <cmath>

// ��������, �������� �� ����� ���� ����� ��������� �����
bool isSumOfDigitsSquare(int num) {
    int sum = 0;

    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    // ���������, �������� �� ����� ���� ��������� �����
    int root = static_cast<int>(sqrt(sum));
    return root * root == sum;
}

// ��������, ���� �� ���������� �������� ����� ��������� �������
bool hasConstantDifference(int num, int k) {
    // ������������ ����� ��� �������������
    num = std::abs(num);

    // ��������� ��������� �����
    int prev_digit = num % 10;
    num /= 10;

    if (num <= 0)
        return false;

    // ��������� ������� ����� ������ ������ �����
    while (num > 0) {
        int curr_digit = num % 10;  // ������� �����
        if (std::abs(curr_digit - prev_digit) != k) {  // ���� ������� �� ����� k, ���������� false
            return false;
        }
        prev_digit = curr_digit;  // ��������� ���������� �����
        num /= 10;  // ������� ��������� �����
    }

    return true;  // ��� ����� ������������� �������
}

// ��������, ������������� �� ����� ���� ��������
bool satisfiesConditions(int num, int k) {
    return isSumOfDigitsSquare(num) && hasConstantDifference(num, k);
}

// ������ ����� � ��������� [n, m] � ��������� �������
void printNumbersInRange(int n, int m, int k) {
    for (int i = n; i <= m; ++i) {
        if (satisfiesConditions(i, k)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

// ������� ��� ����� ����� � ���������
void countNumbersWithConditions() {
    int num;
    int count = 0;


    while (true) {
        std::cout << "������� ����� (��� ���������� ������� 0): ";
        std::cin >> num;

        if (num == 0) {
            break;
        }

        // �������� � ������� �����
        if (satisfiesConditions(num, 0)) {  // ��� �������� ��������� ��� ������� k
            ++count;
        }
    }
    std::cout << "���������� �����, ��������������� ��������: " << count << std::endl;
}


