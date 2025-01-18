#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel2;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Location = System::Drawing::Point(12, 29);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(409, 232);
			this->panel1->TabIndex = 0;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"XO Caliburn", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(49, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(11, 14);
			this->label5->TabIndex = 7;
			this->label5->Text = L"-";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(124, 97);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(168, 32);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Определить область";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 155);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(181, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Область, соответствующая точке:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(289, 52);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(21, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"y - ";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(198, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(18, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"x -";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(147, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Введите координаты точки:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(307, 44);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(54, 20);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(216, 45);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(54, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::Window;
			this->panel2->Controls->Add(this->label5);
			this->panel2->Location = System::Drawing::Point(124, 186);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(168, 32);
			this->panel2->TabIndex = 8;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(433, 273);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"Контрольная работа №1";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e);
};
}
