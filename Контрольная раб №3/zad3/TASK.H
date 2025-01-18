
typedef enum { /* Список кодов ошибок */
errOK = 0,  // Нет ошибки
errNotMemory = 1, // Ошибка: нет памяти
errArraySize = 2, // Ошибка: размер массива неверный
errArrayElement = 3, // Ошибка: элемент массива неверен
errAbsentElements = 4, // Ошибка: отсутствуют элементы
errCanNotOpenFile = 5, // Ошибка: не удается открыть файл
errCanNotSaveValue = 6, // Ошибка: не удается сохранить значение
errFileName = 7, // Ошибка: неверное имя файла
errFileExists = 8, // Ошибка: файл уже существует
errFileNotFound = 9, // Ошибка: файл не найден
errFileIsReadOnly = 10, // Ошибка: файл только для чтения
errFileIsWriteOnly = 11 // Ошибка: файл только для записи
} errCode;

//функции для работы с ошибками
errCode Error(char *operate, errCode err);
errCode InputArray(double* &pArray, int &Size);
errCode TestArray(double* &pArray, int &Size);
errCode SaveArray(double* pArray, int Size, char *filename, bool rw);
errCode LoadArray(double* &pArray, int &Size, char *filename);


bool IsRewrite();
bool CheckFileName(char *name);
void ShowArray(double *arr, int size);
double CalcCriteria(double *arr, int left, int right);
void Search(double *arr, int size, bool opt, int& begin, int& end); //для поиска значений в массиве