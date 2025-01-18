#include <iostream>
#include "task.h"


using namespace std;
/* Функция делает запрос на перезапись файла.
*/
bool IsRewrite()
{
char ch;
cout << endl
<< "Файл уже существует. Вы хотите перезаписать его [Y/N]?";
cin >> ch;
return (ch == 'Y' || ch == 'y');
}
/* Функция реализует консольное меню и интерфейс с пользователем.
*/
void MainMenu(double* &wrkArray, int& wrkSize)
{
char ch = ' ';
char filename[66];
bool bCriteria;
int idxLeft, idxRight;

do
{
cout << endl << "[I] Ввести новый массив";
cout << endl << "[T] Создать текстовый массив";
cout << endl << "[S] Сохранить массив в файл";
cout << endl << "[L] Загрузить массив из файла";
cout << endl << "[D] Отобразить текущий массив";
cout << endl << "[R] Выполнить поиск в последовательности по критериям";
cout << endl << "[Q] Выйти из программы" << endl << "?>";
cin >> ch;
switch(ch)
{
case 'I':
case 'i':
InputArray(wrkArray, wrkSize);
break;
case 'T':
case 't':
TestArray(wrkArray, wrkSize);
case 'D':
case 'd':
ShowArray(wrkArray, wrkSize);
break;
case 'S':
case 's':
cout << "Введите имя файла:>";
cin >> filename;
if (Error("Saving", SaveArray(wrkArray, wrkSize, filename, true)) == errOK)
cout << endl << "Массив успешно сохранен" << endl;
break;
case 'L':
case 'l':
cout << "Введите имя файла, который будет загружен:>";
cin >> filename;
if (Error("Loading", LoadArray(wrkArray, wrkSize, filename)) == errOK)
cout << "Массив успешно загружен" << endl;
break;
case 'R':
case 'r':
if(wrkArray == NULL)
{
cout << "Массив не введен";
break;
}
cout << "Выберите критерии:" << endl
<< "[I]-max(sum) , [D]-min(sum) ?>";
cin >> ch;
if(ch == 'I' || ch == 'i') bCriteria = true;
else if(ch == 'D' || ch == 'd') bCriteria = false;

else { cout << "Неверный вариант: " << ch;
ch = ' ';
break;
}
Search(wrkArray, wrkSize, bCriteria, idxLeft, idxRight);
ShowArray(wrkArray, wrkSize);
cout << endl << "Left index = " << idxLeft
<< endl << "Right index = " << idxRight;
break;
default:
cout << "Неправильный пункт меню";
}
cin.sync();
}
while(ch != 'Q' && ch != 'q');
}

void main(void) // Главная функция
{
    std::setlocale(LC_ALL, "ru_RU.UTF-8");  // Устанавливаем локаль для работы с кириллицей
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));  // Настройка для вывода русских символов
double* myArray = NULL; // Текущий рабочий массив
int arrSize = 0; // Размер текущего массива
MainMenu(myArray, arrSize);
}