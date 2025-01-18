#pragma once
#ifndef TASK_H
#define TASK_H

// Функция проверки, является ли сумма цифр числа квадратом числа
bool isSumOfDigitsSquare(int num);

// Функция проверки разности между соседними цифрами
bool hasConstantDifference(int num, int k);

// Функция, которая проверяет, удовлетворяет ли число всем условиям
bool satisfiesConditions(int num, int k);

// Функция для печати чисел в диапазоне [n, m]
void printNumbersInRange(int n, int m, int k);

// Функция для ввода чисел с подсчётом
void countNumbersWithConditions();

#endif
