#include <iostream>
#include "task.h"

using namespace std;
/* Функция выводит на консоль массив pArray размером Size
*/
void ShowArray(double *pArray, int Size)
{
if(pArray != NULL || Size < 1)
{
cout << "Текущий массив:" << endl;
for(int i=0 ; i < Size ; i++)
cout << pArray[i] << " ";
}
else cout << "Массив не введен";
}
/* Функция вводит массив с консоли и диагностирует ошибки
pArray – ссылка на текущий массив, Size – ссылка на его размер
*/
errCode InputArray(double* &pArray, int &Size)
{
char ch = '\0';
double* newArray = NULL;
int idx, newSize = 0;
double koeff = 0;
bool increasing = false;

cout << "Ввод коэффициента: ";  //  коэффициент на увеличение или уменьшение
cin >> koeff;
cin.sync();


cout << "последовательность чисел по возрастанию: [Y] - да. [N] - нет. "; // "Y" последовательность чисел на увеличение
cin >> ch;
if((ch == 'Y') || (ch == 'y')) increasing = true; // коэффициент принимает значение на увеличение
else if((ch == 'N') || (ch == 'n')) increasing = false;	// коэффициент принимает значение на уменьшение

do
{
cout << "Введите размер массива: "; // сколько элементов в массиве
cin >> newSize;
cin.sync();
if(cin.fail())
{
cin.clear();
newSize = 0;
}
if(newSize < 1 || newSize > 1000)
{
cout << "Недопустимый размер массива. [A] - Прервать. [Enter] - Повторить.";
cin.get(ch);
if((ch == 'A') || (ch == 'a')) return errArraySize;
}
else ch = '\0';
}
while(ch != '\0');
newArray = new double[newSize];
if(newArray == NULL) return errNotMemory;
cout << "Ввод первых элементов массива: "; // первое значений в массиве
for(idx=0 ; idx < newSize ; idx++)
{


if(idx==0) {
cin >> newArray[idx];
cin.sync();
}


else {
if(increasing == true) newArray[idx] =  newArray[idx-1] * koeff;  // заполняем массив на увеличение со 2 элемента
else if(increasing == false) newArray[idx] =  newArray[idx-1] / koeff;	// заполняем массив на уменьшение со 2 элемента
}

while(ch != '\0');
}
if(pArray != NULL) delete[] pArray;
pArray = newArray;
Size = newSize;
return errOK;
}

/* Список описаний ошибок
*/
char *errDescription[] = {
"",
"Недостаточно памяти",
"Неверный размер массива",
"Неверное значение элемента",
"Отсутствуют элементы",
"Файл не может быть открыт",
"Значение не может быть сохранено",
"Неверное имя файла",
"Файл уже существует",
"Файл не найден",
"Доступ к файлу открыт только для чтения",
"Доступ к файлу открыт только для записи"
};
/* Функция выводит на консоль описание ошибки
*/
errCode Error(char *Operate, errCode err)
{
if(err) cout << endl << Operate << " Статус: "
<< errDescription[err] << endl;
return err;
}