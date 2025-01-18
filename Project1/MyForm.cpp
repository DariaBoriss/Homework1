#include "MyForm.h"
#include <iostream>
#include <locale.h>
#include <string>
#include < cmath >


using namespace System;
using namespace System::Windows::Forms; //правильный функцианал для главный функции

//[STAThreadAttribute] //создание отдельного потока данный для мэйн

int main(array<String^>^ args) {//стринг, потому что больше функций с отдельной строкой
	// ^-очистка памяти массива автоматом
	Application::SetCompatibleTextRenderingDefault(false); //корректная обработка текста
	Application::EnableVisualStyles(); //подключаем различ визуал стили

	Project1::MyForm form; //создаем наш объект
	Application::Run(% form); //передача по ссылке на объект форм
}

// Уравнение параболы: y = -0.5 * (x - 4) ^ 2 + 8
bool inParabola(double x, double y) {
    return ((y + 0.5 * pow((x - 4), 2)-8) <= 0) ? true : false;
   
}

// Уравнение прямой 1: y = -0.5 * x + 4
bool inLine(double x, double y) {
    return ((y+0.5*x-4) >= 0) ? true : false;
    
}

// Уравнение вертикальной прямой x = 6
bool inVerticalLine(double x) {
    return (x < 6) ? true : false;
}



// Функция для определения, в какую область попала точка
int CheckArea(double x, double y) {
    
    bool bParabola = inParabola (x,y);
    bool bLine = inLine(x, y);
    bool bLine2 = inVerticalLine(x);

    if (bParabola == true && bLine == true && bLine2 == true) {
        return 1;
    }
    else if (bParabola == true && bLine == true && bLine2 == false) {
        return 2;
    }
    else if (bParabola == true && bLine == false && bLine2 == true) {
        return 3;
    }
    else if (bParabola == true && bLine == false && bLine2 == false) {
        return 4;
    }
    else if (bParabola == false && bLine == false && bLine2 == false) {
        return 5;
    }
    else if (bParabola == false && bLine == true && bLine2 == false) {
        return 6;
    }
    else if (bParabola == false && bLine == true && bLine2 == true) {
        return 7;
    }
    return 8;
}



//функция реализации работы кнопки
System::Void Project1::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
    
    if (textBox1->Text == "" || textBox2->Text == "") {
        MessageBox::Show("Внимание! Вы укажите все координаты точки");
    }

    //преобразовываем введеные данные в дабл
    double x = Convert::ToDouble(textBox1->Text);
    double y = Convert::ToDouble(textBox2->Text);

    int result = CheckArea(x, y);
    this->label5->Text = "Область " + result.ToString();

}

System::Void Project1::MyForm::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}
System::Void Project1::MyForm::textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}
System::Void Project1::MyForm::label5_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}