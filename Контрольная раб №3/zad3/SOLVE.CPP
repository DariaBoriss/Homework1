#include <float.h>
#include <stddef.h>
#include "task.h"
/* Функция загружает тестовый массив в качестве текущего массива
*/
errCode TestArray(double* &pArray, int &Size)
{
static double test[] =
{ 2.1,4.2,8.4,16.8,33.6,67.2,134.4,268.8,537.6,1075.2,2150.4,4300.8 };
if(pArray != NULL) delete[] pArray;
Size = sizeof(test) / sizeof(double);
pArray = new double[Size];
for(int i=0 ; i < Size ; i++)
pArray[i] = test[i];
return errOK;
}

/* Функция вычисляет сумму последовательности элементов
в заданном массиве arr от индекса left до индекса right
*/
double CalcCriteria(double *arr, int left, int right)
{
double sum = 0;
for(int j=left ; j <= right ; j++)
sum += arr[j];
return sum;
}
/* Функция ищет в массиве arr размерностью size такую непрерывную
последовательность элементов, начинающуюся с индекса begin и
заканчивающуюся индексом end, которая имеет максимальную при
opt = true или минимальную при opt = false сумму элементов.
*/
void Search(double *arr, int size, bool opt, int& begin, int& end)
{
int i,m;
double sum;
double criteria = ((opt) ? -DBL_MAX : DBL_MAX);
for(i=0 ; i <= size-2 ; i++)
{
for(m=2 ; m <= size-i ; m++)
{
sum = CalcCriteria(arr, i, (i + m - 1));
if((opt) ? sum > criteria : sum < criteria)
{
criteria = sum;
begin = i;
end = i + m - 1;
}
}
}
}