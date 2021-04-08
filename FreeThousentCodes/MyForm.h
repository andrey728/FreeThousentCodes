#pragma once
#include <cmath>

namespace FreeThousentCodes {

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
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox3;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(496, 86);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(374, 100);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(496, 228);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(374, 100);
			this->textBox2->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(85, 183);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(183, 45);
			this->button1->TabIndex = 2;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(769, 12);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(101, 51);
			this->textBox3->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1033, 488);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Эта херня переводит число в ебанные биты
		System::String^ ConvertDectoBin(int dec_number) {

			System::String^ binNumber = "00000000";

			char arr[8];


			if (dec_number > 0) {

				for (int i = 0; i < binNumber->Length; i++) {
					arr[i] = binNumber[i];
				}
				while (dec_number > 0) {
					for (int number = dec_number; number > 0; number--) {
						float logNum = log2(number);
						if ((float)(int)logNum == logNum) {
							arr[(int)logNum] = 1;
							dec_number -= number;
							break;
						}
					}
				}

				binNumber = "";
				for each (char var in arr)
				{
					binNumber += var;
				}
			}

			return binNumber;

		}

		/////////////////////////////////////////////////////////////////////////
		char Change(char poss, String^ key)
		{
			textBox1->Text = poss.ToString();
			int kek = (int)poss;
			textBox1->Text = kek.ToString();
			for (int i = 0; i < key->Length; i++)
			{
				if (i % 2 == 0) 
				{
					kek -= Convert::ToInt16(key[i]);
				}
				if (i % 2 != 0)
				{
					kek += Convert::ToInt16(key[i]);
				}
			}
			if (kek < 0) kek = kek + 255;
			if ((abs(kek) % 255) > 1) kek = abs(kek) % 255;
			//if (abs(pos) > 255) pos = abs(pos) - 255;
			textBox2->Text = ((char)kek).ToString();
			poss = (char)kek;
			return poss;
		}

		char ReChange(char poss, String^ key)
		{
			textBox1->Text = poss.ToString();
			int kek = (int)poss;
			textBox1->Text = kek.ToString();
			for (int i = 0; i < key->Length; i++)
			{
				if (i % 2 == 0)
				{
					kek += Convert::ToInt16(key[i]);
				}
				if (i % 2 != 0)
				{
					kek -= Convert::ToInt16(key[i]);
				}
			}
			//if (pos < 0) pos = pos + 255;
			//if (abs(pos) > 255) pos = abs(pos) - 255;
			textBox2->Text = ((char)kek).ToString();
			return poss;
		}








		/////////////////////////////////////////////////////////////////////////

		// Функция, шифрующая блок методом замены
		String^ Encrip_Change(String^ bites, String^ key) { // с char ломается, го ключ хранить в строке?
			String^ NewBites;
			for (int i = 0; i <= bites->Length;)
			{
				int XOR; // переменная
				XOR = (Convert::ToInt16(bites[i]) + Convert::ToInt16(key[i])) % 2;
				NewBites + Convert::ToString(XOR);
			}
			return NewBites;
		}


		void Transcripts_Change() {

		}

		// Функция, шифрующая блок методом перестановки
		System::String^ Encripts_transposition(System::String^ block, char key) {

			return L"df";
		}

		void Transcripts_transposition() {

		}


		// Фукнция чтения, записи файла
		void Input_output() {

		}



		// Главная функция, которая вызывается при начале шифрования. Все шифрование проходит в ней
		void EnCodingFistingIs300Codes() {

		}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Change('0', textBox3->Text);
	}
};
}
