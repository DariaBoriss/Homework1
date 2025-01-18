/*********************************************************************
* Содержание модуля LAB3.CPP *
*********************************************************************/
#include <iostream>
#include "task.h"


using namespace std;
/* Функция делает запрос на перезапись файла.
*/
bool IsRewrite()
{
char ch;
cout << endl
<< "File already exists. Do you want to overwrite it [Y/N]?";
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
cout << endl << "";
cout << endl << "Program Borisova Dasha, zadanie3, variant3, 2025";	
cout << endl << "";
	
cout << endl << "[I] Input a new array";
cout << endl << "[T] Create the test array";
cout << endl << "[S] Save the array in a file";
cout << endl << "[L] Load the array from a file";
cout << endl << "[D] Display the current array";
//cout << endl << "[R] Search the sequence for criteria";
cout << endl << "[Q] Quit the program" << endl << "?>";
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
cout << "Entry the filename:>";
cin >> filename;
if (Error("Saving", SaveArray(wrkArray, wrkSize, filename, true)) == errOK)
cout << endl << "Array is saved successfully" << endl;
break;
case 'L':
case 'l':
cout << "Entry the filename to be loaded:>";
cin >> filename;
if (Error("Loading", LoadArray(wrkArray, wrkSize, filename)) == errOK)
cout << "Array is loaded successfully" << endl;
break;
case 'R':
case 'r':
if(wrkArray == NULL)
{
cout << "Array is not entered";
break;
}
cout << "Select criteria:" << endl
<< "[I]-max(sum) , [D]-min(sum) ?>";
cin >> ch;
if(ch == 'I' || ch == 'i') bCriteria = true;
else if(ch == 'D' || ch == 'd') bCriteria = false;

else { cout << "Incorrect option: " << ch;
ch = ' ';
break;
}
Search(wrkArray, wrkSize, bCriteria, idxLeft, idxRight);
ShowArray(wrkArray, wrkSize);
cout << endl << "Left index = " << idxLeft
<< endl << "Right index = " << idxRight;
break;
default:
cout << "Incorrect menu item";
}
cin.sync();
}
while(ch != 'Q' && ch != 'q');
}

void main(void) // Главная функция, если не работает то void main(void)
{
double* myArray = NULL; // Текущий рабочий массив
int arrSize = 0; // Размер текущего массива
MainMenu(myArray, arrSize);
}