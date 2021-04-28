#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <String>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <time.h>

int simple[1000000] = {};
bool isSimple[1000000] = {};
char ext[6] = {};
int count;
unsigned char start[1000000] = {};
int lengthS = 0;
unsigned char finish[1000000] = {};
int lengthF = 0;

#pragma once

namespace Vigener {

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
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textP;
	private: System::Windows::Forms::TextBox^ textG;
	private: System::Windows::Forms::TextBox^ textX;
	private: System::Windows::Forms::TextBox^ textY;
	private: System::Windows::Forms::TextBox^ textK;
	private: System::Windows::Forms::TextBox^ possibleG;






	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::TextBox^ error;
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









	private: System::Windows::Forms::Button^ buttonCrypt;
	private: System::Windows::Forms::Button^ buttonDecrypt;







	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::Button^ buttonFile1;
	private: System::Windows::Forms::Button^ buttonFile2;










	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->buttonCrypt = (gcnew System::Windows::Forms::Button());
			this->buttonDecrypt = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->buttonFile1 = (gcnew System::Windows::Forms::Button());
			this->buttonFile2 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textP = (gcnew System::Windows::Forms::TextBox());
			this->textG = (gcnew System::Windows::Forms::TextBox());
			this->textX = (gcnew System::Windows::Forms::TextBox());
			this->textY = (gcnew System::Windows::Forms::TextBox());
			this->textK = (gcnew System::Windows::Forms::TextBox());
			this->possibleG = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->error = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(12, 69);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->MaxLength = 2147483647;
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(488, 278);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(592, 68);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->MaxLength = 2147483647;
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(481, 278);
			this->textBox2->TabIndex = 1;
			// 
			// buttonCrypt
			// 
			this->buttonCrypt->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonCrypt.BackgroundImage")));
			this->buttonCrypt->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->buttonCrypt->Location = System::Drawing::Point(507, 158);
			this->buttonCrypt->Margin = System::Windows::Forms::Padding(4);
			this->buttonCrypt->Name = L"buttonCrypt";
			this->buttonCrypt->Size = System::Drawing::Size(77, 53);
			this->buttonCrypt->TabIndex = 11;
			this->buttonCrypt->UseVisualStyleBackColor = true;
			this->buttonCrypt->Click += gcnew System::EventHandler(this, &MyForm::buttonCrypt_Click);
			// 
			// buttonDecrypt
			// 
			this->buttonDecrypt->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonDecrypt.BackgroundImage")));
			this->buttonDecrypt->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->buttonDecrypt->Location = System::Drawing::Point(507, 218);
			this->buttonDecrypt->Margin = System::Windows::Forms::Padding(4);
			this->buttonDecrypt->Name = L"buttonDecrypt";
			this->buttonDecrypt->Size = System::Drawing::Size(77, 53);
			this->buttonDecrypt->TabIndex = 12;
			this->buttonDecrypt->UseVisualStyleBackColor = true;
			this->buttonDecrypt->Click += gcnew System::EventHandler(this, &MyForm::buttonDecrypt_Click);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"C:\\";
			// 
			// buttonFile1
			// 
			this->buttonFile1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonFile1.BackgroundImage")));
			this->buttonFile1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->buttonFile1->Location = System::Drawing::Point(12, 15);
			this->buttonFile1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->buttonFile1->Name = L"buttonFile1";
			this->buttonFile1->Size = System::Drawing::Size(53, 49);
			this->buttonFile1->TabIndex = 18;
			this->buttonFile1->UseVisualStyleBackColor = true;
			this->buttonFile1->Click += gcnew System::EventHandler(this, &MyForm::buttonFile1_Click);
			// 
			// buttonFile2
			// 
			this->buttonFile2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonFile2.BackgroundImage")));
			this->buttonFile2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->buttonFile2->Location = System::Drawing::Point(592, 15);
			this->buttonFile2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->buttonFile2->Name = L"buttonFile2";
			this->buttonFile2->Size = System::Drawing::Size(53, 49);
			this->buttonFile2->TabIndex = 19;
			this->buttonFile2->UseVisualStyleBackColor = true;
			this->buttonFile2->Click += gcnew System::EventHandler(this, &MyForm::buttonFile2_Click);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(12, 354);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(52, 37);
			this->textBox3->TabIndex = 20;
			this->textBox3->Text = L"p = ";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(12, 400);
			this->textBox4->Margin = System::Windows::Forms::Padding(4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(52, 37);
			this->textBox4->TabIndex = 21;
			this->textBox4->Text = L"g = ";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(12, 446);
			this->textBox5->Margin = System::Windows::Forms::Padding(4);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(52, 37);
			this->textBox5->TabIndex = 22;
			this->textBox5->Text = L"x = ";
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox6->Location = System::Drawing::Point(12, 491);
			this->textBox6->Margin = System::Windows::Forms::Padding(4);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(52, 37);
			this->textBox6->TabIndex = 23;
			this->textBox6->Text = L"y = ";
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox7->Location = System::Drawing::Point(12, 537);
			this->textBox7->Margin = System::Windows::Forms::Padding(4);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(52, 37);
			this->textBox7->TabIndex = 24;
			this->textBox7->Text = L"k = ";
			// 
			// textP
			// 
			this->textP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textP->Location = System::Drawing::Point(73, 354);
			this->textP->Margin = System::Windows::Forms::Padding(4);
			this->textP->MaxLength = 7;
			this->textP->Name = L"textP";
			this->textP->Size = System::Drawing::Size(132, 37);
			this->textP->TabIndex = 25;
			this->textP->TextChanged += gcnew System::EventHandler(this, &MyForm::textP_TextChanged);
			// 
			// textG
			// 
			this->textG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textG->Location = System::Drawing::Point(73, 400);
			this->textG->Margin = System::Windows::Forms::Padding(4);
			this->textG->MaxLength = 7;
			this->textG->Name = L"textG";
			this->textG->Size = System::Drawing::Size(132, 37);
			this->textG->TabIndex = 26;
			// 
			// textX
			// 
			this->textX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textX->Location = System::Drawing::Point(73, 446);
			this->textX->Margin = System::Windows::Forms::Padding(4);
			this->textX->MaxLength = 7;
			this->textX->Name = L"textX";
			this->textX->Size = System::Drawing::Size(132, 37);
			this->textX->TabIndex = 27;
			// 
			// textY
			// 
			this->textY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textY->Location = System::Drawing::Point(73, 491);
			this->textY->Margin = System::Windows::Forms::Padding(4);
			this->textY->MaxLength = 7;
			this->textY->Name = L"textY";
			this->textY->ReadOnly = true;
			this->textY->Size = System::Drawing::Size(132, 37);
			this->textY->TabIndex = 28;
			// 
			// textK
			// 
			this->textK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textK->Location = System::Drawing::Point(73, 537);
			this->textK->Margin = System::Windows::Forms::Padding(4);
			this->textK->MaxLength = 7;
			this->textK->Name = L"textK";
			this->textK->Size = System::Drawing::Size(132, 37);
			this->textK->TabIndex = 29;
			// 
			// possibleG
			// 
			this->possibleG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->possibleG->Location = System::Drawing::Point(385, 400);
			this->possibleG->Margin = System::Windows::Forms::Padding(4);
			this->possibleG->Multiline = true;
			this->possibleG->Name = L"possibleG";
			this->possibleG->ReadOnly = true;
			this->possibleG->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->possibleG->Size = System::Drawing::Size(688, 174);
			this->possibleG->TabIndex = 30;
			// 
			// textBox14
			// 
			this->textBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox14->Location = System::Drawing::Point(565, 354);
			this->textBox14->Margin = System::Windows::Forms::Padding(4);
			this->textBox14->Name = L"textBox14";
			this->textBox14->ReadOnly = true;
			this->textBox14->Size = System::Drawing::Size(303, 37);
			this->textBox14->TabIndex = 31;
			this->textBox14->Text = L"Возможне значения g";
			// 
			// error
			// 
			this->error->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->error->Location = System::Drawing::Point(12, 584);
			this->error->Name = L"error";
			this->error->Size = System::Drawing::Size(529, 38);
			this->error->TabIndex = 32;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1085, 634);
			this->Controls->Add(this->error);
			this->Controls->Add(this->textBox14);
			this->Controls->Add(this->possibleG);
			this->Controls->Add(this->textK);
			this->Controls->Add(this->textY);
			this->Controls->Add(this->textX);
			this->Controls->Add(this->textG);
			this->Controls->Add(this->textP);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->buttonFile2);
			this->Controls->Add(this->buttonFile1);
			this->Controls->Add(this->buttonDecrypt);
			this->Controls->Add(this->buttonCrypt);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"Шифрование";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void getSimple()
		{
			simple[0] = 2;
			int k = 0;

			for (int i = 3; i < 65535; i++)
			{
				bool bad = false;
				for (int j = 0; j <= k; j++)
					if (i % simple[j] == 0)
						bad = true;
				if (!bad)
				{
					k++;
					simple[k] = i;
				}
			}

			for (int i = 0; i <= k; i++)
				isSimple[simple[i]] = true;
			count = k;
		}

		String^ getBinary(unsigned char ch)
		{
			String^ binary = "";
			while (ch != 0)
			{
				int o = ch % 2;
				wchar_t num = o + '0';
				binary = num + binary;
				ch /= 2;
			}
			int len = 8 - binary->Length;
			for (int i = 0; i < len; i++)
				binary = "0" + binary;

			return binary;
		}

		String^ getCrypt(String^ start, String^ key)
		{
			char* finish = (char*) malloc(start->Length + 1);
			for (int i = 0; i < start->Length; i++)
			{
				int n1 = start[i] - '0';
				int n2 = key[i] - '0';
				char ch = n1 ^ n2 + '0';
				finish[i] = ch;
			}
			finish[start->Length] = 0;

			String^ res = gcnew String(finish);
			return res;
		}

		int getInt(String^ s)
		{
			int sum;
			int step = 1;
			for (int i = s->Length - 1; i >= 0; i--)
			{
				if (s[i] == '1') sum += step;
				step *= 2;
			}
			return sum;
		}

		void getText(String^ finish, char text[1000000], int* bytes)
		{
			int k = 0;
			while (finish->Length >= 8)
			{
				String^ part = finish->Substring(0, 8);
				char ch = getInt(part);
				text[k] = ch;
				k++;
				finish = finish->Substring(8, finish->Length - 8);
			}
			*bytes = k;
		}

		String^ getPart(String^ text)
		{
			String^ part = "";
			for (int i = 0; i < 800; i++)
				part += text[i];
			for (int i = text->Length - 800; i < text->Length; i++)
				part += text[i];

			return part;
		}

		String^ getNumber(String^ n)
		{
			String^ k = "";
			for (int i = 0; i < n->Length; i++)
				if ((n[i] >= '0') && (n[i] <= '9'))
					k += n[i];
			return k;
		}

		int toNumber(String^ n)
		{
			char m[10] = {};
			for (int i = 0; i < n->Length; i++)
				m[i] = n[i];
			int k = atoi(m);
			return k;
		}

		void change(String^ tp, String^ tg, String^ tx, String^ ty, String^ tk, int* p, int* g, int* x, int* y, int* k)
		{
			String^ gp = getNumber(tp);
			String^ gg = getNumber(tg);
			String^ gx = getNumber(tx);
			String^ gy = getNumber(ty);
			String^ gk = getNumber(tk);
			if (gp != "") *p = toNumber(gp); else *p = -1;
			if (gg != "") *g = toNumber(gg); else *g = -1;
			if (gx != "") *x = toNumber(gx); else *x = -1;
			if (gy != "") *y = toNumber(gy); else *y = -1;
			if (gk != "") *k = toNumber(gk); else *k = -1;
		}

		long long fastExp(long long a, long long z, long long n)
		{
			long long a1 = a % n;
			long long z1 = z;
			long long x = 1;
			while (z1 != 0)
			{
				while ((z1 % 2) == 0)
				{
					z1 = z1 / 2;
					a1 = (a1 * a1) % n;
				}
				z1 -= 1;
				x = (x * a1) % n;
			}
			return x;
		}

		bool isPRoot(int p, int g)
		{
			int k = 0;
			while (simple[k] < p - 1)
			{
				if ((p - 1) % simple[k] == 0)
				{
					int step = (p - 1) / simple[k];
					int res = fastExp(g, step, p);
					if (res == 1) return false;
				}
				k++;
			}

			return true;
		}

		int NOD(int a, int b)
		{
			while (a > 0 && b > 0)
				if (a > b) a %= b;
				else b %= a;
			return a + b;
		}



	private: System::Void buttonCrypt_Click(System::Object^ sender, System::EventArgs^ e) {
		error->Text = "";
		error->BackColor = Color::Green;
		int p, g, x, y, k;
		change(textP->Text, textG->Text, textX->Text, textY->Text, textK->Text, &p, &g, &x, &y, &k);
		if (p == -1) { error->BackColor = Color::Red; error->Text = "Неверное значение p"; goto end; }
		if (g == -1) { error->BackColor = Color::Red; error->Text = "Неверное значение g"; goto end; }
		if (x == -1) { error->BackColor = Color::Red; error->Text = "Неверное значение x"; goto end; }
		if (k == -1) { error->BackColor = Color::Red; error->Text = "Неверное значение k"; goto end; }
			if (isSimple[p] == false)
			{
				error->BackColor = Color::Red;
				error->Text = "p должно быть простым!";
				goto end;
			}
			if (!isPRoot(p, g))
			{
				error->BackColor = Color::Red;
				error->Text = "Выберите g из списка!";
				goto end;
			}
			if ((x <= 1) || (x >= p - 1))
			{
				error->BackColor = Color::Red;
				error->Text = "Выберите 1 < x < p-1";
				goto end;
			}
			if (NOD(k, p - 1) != 1)
			{
				error->BackColor = Color::Red;
				error->Text = "Выберите k взаимнопростое с p-1";
				goto end;
			}

			y = fastExp(g, x, p);

			if ((k <= 1) || (k >= p - 1))
			{
				error->BackColor = Color::Red;
				error->Text = "Выберите 1 < k < p-1";
				goto end;
			}

			textP->Text = p.ToString();
			textG->Text = g.ToString();
			textX->Text = x.ToString();
			textY->Text = y.ToString();
			textK->Text = k.ToString();

			char path[128] = "C:\\Users\\Asus\\Desktop\\tests\\out.";
			strcat(path, ext);
			FILE* f = fopen(path, "wb");
			int a = fastExp(g, k, p);
			char p1 = a / 256;
			char p2 = a % 256;
			int h = fastExp(y, k, p);
			for (int i = 0; i < lengthS; i++)
			{
				int b = h * start[i] % p;
				char p3 = b / 256;
				char p4 = b % 256;
				fwrite(&p1, 1, 1, f);
				fwrite(&p2, 1, 1, f);
				fwrite(&p3, 1, 1, f);
				fwrite(&p4, 1, 1, f);
			}
			fclose(f);

			f = fopen(path, "rb");
			String^ text = gcnew String("");
			unsigned char ch;
			int s = 0;

			int n = 0;
			while (fread(&ch, 1, 1, f))
			{
				finish[s] = ch;
				if (s % 2 == 0) n = ch * 256;
				else
				{
					n += ch;
					text += n.ToString() + " ";
					if (s % 4 == 3) text += "\r\n";
				}
				s++;
			}
			finish[s] = 0;
			lengthF = s;
			if (text->Length <= 1600)
				textBox2->Text = text; else
				textBox2->Text = getPart(text);
			fclose(f);

	end:
		int t;
	}

	private: System::Void buttonDecrypt_Click(System::Object^ sender, System::EventArgs^ e) {
		error->Text = "";
		error->BackColor = Color::Green;
		int p, g, x, y, k;
		change(textP->Text, textG->Text, textX->Text, textY->Text, textK->Text, &p, &g, &x, &y, &k);
		if (p == -1) { error->BackColor = Color::Red; error->Text = "Неверное значение p"; goto end; }
		if (g == -1) { error->BackColor = Color::Red; error->Text = "Неверное значение g"; goto end; }
		if (x == -1) { error->BackColor = Color::Red; error->Text = "Неверное значение x"; goto end; }
		if (k == -1) { error->BackColor = Color::Red; error->Text = "Неверное значение k"; goto end; }
		if (isSimple[p] == false)
		{
			error->BackColor = Color::Red;
			error->Text = "p должно быть простым!";
			goto end;
		}
		if (!isPRoot(p, g))
		{
			error->BackColor = Color::Red;
			error->Text = "Выберите g из списка!";
			goto end;
		}
		if ((x <= 1) || (x >= p - 1))
		{
			error->BackColor = Color::Red;
			error->Text = "Выберите 1 < x < p-1";
			goto end;
		}
		if (NOD(k, p - 1) != 1)
		{
			error->BackColor = Color::Red;
			error->Text = "Выберите k взаимнопростое с p-1";
			goto end;
		}

		y = fastExp(g, x, p);

		if ((k <= 1) || (k >= p - 1))
		{
			error->BackColor = Color::Red;
			error->Text = "Выберите 1 < k < p-1";
			goto end;
		}

		textP->Text = p.ToString();
		textG->Text = g.ToString();
		textX->Text = x.ToString();
		textY->Text = y.ToString();
		textK->Text = k.ToString();

		char path[128] = "C:\\Users\\Asus\\Desktop\\tests\\in.";
		strcat(path, ext);
		FILE* f = fopen(path, "wb");

		for (int i = 0; i < lengthF; i += 4)
		{
			int a = finish[i] * 256 + finish[i + 1];
			int b = finish[i + 2] * 256 + finish[i + 3];
			unsigned char m = b * fastExp(fastExp(a, x, p), p - 2, p) % p;
			fwrite(&m, 1, 1, f);
		}

		fclose(f);

		f = fopen(path, "rb");
		String^ text = gcnew String("");
		unsigned char ch;
		int s = 0;
		int n = 0;
		while (fread(&ch, 1, 1, f))
		{
			start[s] = ch;
			text += ch.ToString() + " ";
			s++;
		}
		start[s] = 0;
		lengthS = s;
		if (text->Length <= 1600)
			textBox1->Text = text; else
			textBox1->Text = getPart(text);
		fclose(f);

	end:
		int t;
	}

	private: System::Void buttonFile1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			String^ filePath = openFileDialog->FileName;
			char p[256] = {};
			for (int i = 0; i < filePath->Length; i++)
				p[i] = filePath[i];

			int i = strlen(p) - 1;
			while (p[i] != '.')
				i--;
			int k = 0;
			for (int j = i + 1; j < strlen(p); j++)
			{
				ext[k] = p[j];
				k++;
			}
			ext[k] = 0;

			FILE* f = fopen(p, "rb");
			String^ text = gcnew String("");
			unsigned char ch;
			 
			int s = 0;
			while (fread(&ch, 1, 1, f))
			{
				start[s] = ch;
				text += ch.ToString() + " ";
				s++;
			}
			start[s] = 0;
			lengthS = s;

			if (text->Length <= 1600)
			textBox1->Text = text; else
				textBox1->Text = getPart(text);
			fclose(f);
		}
	}

	private: System::Void buttonFile2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			String^ filePath = openFileDialog->FileName;
			char p[256] = {};
			for (int i = 0; i < filePath->Length; i++)
				p[i] = filePath[i];

			int i = strlen(p) - 1;
			while (p[i] != '.')
				i--;
			int k = 0;
			for (int j = i + 1; j < strlen(p); j++)
			{
				ext[k] = p[j];
				k++;
			}
			ext[k] = 0;

			FILE* f = fopen(p, "rb");
			String^ text = gcnew String("");
			unsigned char ch;
			int s = 0;
			int n = 0;
			while (fread(&ch, 1, 1, f))
			{
				finish[s] = ch;
				if (s % 2 == 0) n = ch * 256;
				else
				{
					n += ch;
					text += n.ToString() + " ";
					if (s % 4 == 3) text += "\r\n";
				}
				s++;
			}
			finish[s] = 0;
			lengthF = s;
			if (text->Length <= 1600)
				textBox2->Text = text; else
				textBox2->Text = getPart(text);
			fclose(f);
		}
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		getSimple();
	}

	private: System::Void textP_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		error->Text = "";
		error->BackColor = Color::White;
		int p, g, x, y, k;
		change(textP->Text, textG->Text, textX->Text, textY->Text, textK->Text, &p, &g, &x, &y, &k);
		possibleG->Text = "";

		if (isSimple[p] == false)
		{
			error->BackColor = Color::Red;
			error->Text = "p должно быть простым!";
			goto end;
		}

		String^ text = "";
		if (p != -1)
		{
			for (int i = 2; i < p; i++)
				if (isPRoot(p, i))
				{
					text = text + i.ToString() + " ";
				}
			possibleG->Text = text;
		}

	end:
		int t;
	}
};
}
