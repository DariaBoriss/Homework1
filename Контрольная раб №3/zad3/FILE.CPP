#include <fstream>
#include <io.h>
#include "task.h"

using namespace std;
/* Функция проверяет корректность имени файла filename, и
Возвращает true – если имя корректно, или false – если нет.
*/
bool CheckFileName(char *name)
{
char ch;
int i;

for(i=0,ch=name[0] ; ch != '\0' ; i++,ch=name[i])
{
if(ch == ':' && i != 1) return false;
if(ch == '\\' && (name[i+1] == '\0' || name[i+1] == '\\'))
return false;
if(ch == '<' || ch == '>' || ch == '*' || ch == '?' ||
ch == '|' || ch == '\"') return false;
}
return true;
}

/* Функция загружает массив из файла с именем filename и
диагностирует ошибки. pArray – ссылка на текущий массив,
который должен быть перезаписан, Size – ссылка на его размер
*/
errCode LoadArray(double* &pArray, int &Size, char *filename)
{
double* tmpArray = NULL;
int idx, tmpSize = 0;
if(CheckFileName(filename) == false) return errFileName;
if(_access(filename,0) != 0) return errFileNotFound;
ifstream in(filename);
if(!in) return errCanNotOpenFile;
in >> tmpSize;
if(!in) tmpSize = 0;
if(tmpSize < 1 || tmpSize > 1000) return errArraySize;
tmpArray = new double[tmpSize];
if(tmpArray == NULL) return errNotMemory;
for(idx=0 ; idx < tmpSize ; idx++)
{
in >> tmpArray[idx];
if(!in)
{
delete[] tmpArray;
return ((in.eof()) ? errAbsentElements : errArrayElement);
}
}
if(pArray != NULL) delete[] pArray;
pArray = tmpArray;
Size = tmpSize;
return errOK;
}

/* Функция сохраняет массив pArray размеров Size в файле с
именем filename в режиме перезаписи rw = true или отмены
записи в случае его существования rw = false.
*/

errCode SaveArray(double *pArray, int Size, char *filename, bool rw)
{
if(CheckFileName(filename) == false) return errFileName;
if(_access(filename,0) == 0)
{
if(_access(filename,6) != 0) return errFileIsReadOnly;
if(rw == false) return errFileExists;
else if((rw = IsRewrite()) == false) return errFileExists;
}
ofstream out(filename);
if(!out) return errCanNotOpenFile;
out << Size << endl;
if(!out) return errCanNotSaveValue;
for(int idx=0 ; idx < Size ; idx++)
{
out << pArray[idx] << endl;
if(!out) return errCanNotSaveValue;
}
return errOK;
}