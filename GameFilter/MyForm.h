#pragma once
#include "NodeMaker.h"
#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <msclr\marshal_cppstd.h>


namespace GameFilter {
	using namespace std;
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button12;
	protected:

	private: System::Windows::Forms::ListBox^ displayPort;
	protected:

	private: System::Windows::Forms::Button^ Genre;




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ mergebutton;

	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox2;
	private: System::Windows::Forms::DomainUpDown^ TypeHere;

	private: System::Windows::Forms::Button^ eighties;
	private: System::Windows::Forms::Button^ thousands;
	private: System::Windows::Forms::Button^ twenties;
	private: System::Windows::Forms::Button^ TBA;
	private: System::Windows::Forms::Label^ label3;






	

	







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->displayPort = (gcnew System::Windows::Forms::ListBox());
			this->Genre = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->checkedListBox2 = (gcnew System::Windows::Forms::CheckedListBox());
			this->mergebutton = (gcnew System::Windows::Forms::Button());
			this->eighties = (gcnew System::Windows::Forms::Button());
			this->thousands = (gcnew System::Windows::Forms::Button());
			this->twenties = (gcnew System::Windows::Forms::Button());
			this->TBA = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(10, 47);
			this->button12->Margin = System::Windows::Forms::Padding(1);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(203, 52);
			this->button12->TabIndex = 0;
			this->button12->Text = L"Sort from Smallest using Quick Sort:";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// displayPort
			// 
			this->displayPort->BackColor = System::Drawing::SystemColors::Window;
			this->displayPort->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->displayPort->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->displayPort->FormattingEnabled = true;
			this->displayPort->ItemHeight = 12;
			this->displayPort->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Games will be Listed Here:" });
			this->displayPort->Location = System::Drawing::Point(215, 47);
			this->displayPort->Margin = System::Windows::Forms::Padding(1);
			this->displayPort->Name = L"displayPort";
			this->displayPort->Size = System::Drawing::Size(369, 364);
			this->displayPort->TabIndex = 1;
			// 
			// Genre
			// 
			this->Genre->Location = System::Drawing::Point(10, 359);
			this->Genre->Margin = System::Windows::Forms::Padding(1);
			this->Genre->Name = L"Genre";
			this->Genre->Size = System::Drawing::Size(203, 52);
			this->Genre->TabIndex = 2;
			this->Genre->Text = L"Filter by Blacklisted/Display Data";
			this->Genre->UseVisualStyleBackColor = true;
			this->Genre->Click += gcnew System::EventHandler(this, &MyForm::Genre_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Cursor = System::Windows::Forms::Cursors::Default;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(12, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(358, 21);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Welcome to Game Search Engine";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(19) {
				L"3D", L"Action", L"Adventure", L"Arcade",
					L"Board Games", L"Casual", L"Educational", L"Fighting", L"House", L"Indie", L"Massively Multiplayer", L"Platformer", L"Puzzle",
					L"Racing", L"RPG", L"Shooter", L"Simulation", L"Sports", L"Strategy"
			});
			this->checkedListBox1->Location = System::Drawing::Point(607, 47);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(119, 251);
			this->checkedListBox1->Sorted = true;
			this->checkedListBox1->TabIndex = 7;
			// 
			// checkedListBox2
			// 
			this->checkedListBox2->FormattingEnabled = true;
			this->checkedListBox2->Items->AddRange(gcnew cli::array< System::Object^  >(23) {
				L"Android", L"Game Boy", L"Game Boy Advance",
					L"iOS", L"Linux", L"macOS", L"Nintendo 3DS", L"Nintendo 64", L"Nintendo DS", L"Nintendo Switch", L"PC", L"Playstation 3", L"Playstation 4",
					L"Playstation 5", L"PS Vita", L"PSP", L"Snes", L"Web", L"Wii", L"Wii U", L"Xbox 360", L"Xbox One", L"Xbox Series S/X"
			});
			this->checkedListBox2->Location = System::Drawing::Point(732, 47);
			this->checkedListBox2->Name = L"checkedListBox2";
			this->checkedListBox2->Size = System::Drawing::Size(116, 303);
			this->checkedListBox2->TabIndex = 8;
			// 
			// mergebutton
			// 
			this->mergebutton->Location = System::Drawing::Point(10, 189);
			this->mergebutton->Margin = System::Windows::Forms::Padding(1);
			this->mergebutton->Name = L"mergebutton";
			this->mergebutton->Size = System::Drawing::Size(203, 52);
			this->mergebutton->TabIndex = 10;
			this->mergebutton->Text = L"Sort from Largest using Merge Sort:";
			this->mergebutton->UseVisualStyleBackColor = true;
			this->mergebutton->Click += gcnew System::EventHandler(this, &MyForm::mergebutton_Click);
			// 
			// eighties
			// 
			this->eighties->Location = System::Drawing::Point(607, 334);
			this->eighties->Name = L"eighties";
			this->eighties->Size = System::Drawing::Size(75, 23);
			this->eighties->TabIndex = 12;
			this->eighties->Text = L"1980-1999";
			this->eighties->UseVisualStyleBackColor = true;
			this->eighties->Click += gcnew System::EventHandler(this, &MyForm::eighties_Click);
			// 
			// thousands
			// 
			this->thousands->Location = System::Drawing::Point(607, 363);
			this->thousands->Name = L"thousands";
			this->thousands->Size = System::Drawing::Size(75, 23);
			this->thousands->TabIndex = 13;
			this->thousands->Text = L"2000-2019";
			this->thousands->UseVisualStyleBackColor = true;
			this->thousands->Click += gcnew System::EventHandler(this, &MyForm::thousands_Click);
			// 
			// twenties
			// 
			this->twenties->Location = System::Drawing::Point(607, 392);
			this->twenties->Name = L"twenties";
			this->twenties->Size = System::Drawing::Size(75, 23);
			this->twenties->TabIndex = 14;
			this->twenties->Text = L"2020--Now";
			this->twenties->UseVisualStyleBackColor = true;
			this->twenties->Click += gcnew System::EventHandler(this, &MyForm::twenties_Click);
			// 
			// TBA
			// 
			this->TBA->Location = System::Drawing::Point(688, 392);
			this->TBA->Name = L"TBA";
			this->TBA->Size = System::Drawing::Size(75, 23);
			this->TBA->TabIndex = 15;
			this->TBA->Text = L"TBA";
			this->TBA->UseVisualStyleBackColor = true;
			this->TBA->Click += gcnew System::EventHandler(this, &MyForm::TBA_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(597, 318);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 13);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Select Year Range";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 11);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(860, 420);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->TBA);
			this->Controls->Add(this->twenties);
			this->Controls->Add(this->thousands);
			this->Controls->Add(this->eighties);
			this->Controls->Add(this->mergebutton);
			this->Controls->Add(this->checkedListBox2);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Genre);
			this->Controls->Add(this->displayPort);
			this->Controls->Add(this->button12);
			this->Font = (gcnew System::Drawing::Font(L"MS PGothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(1);
			this->Name = L"MyForm";
			this->Text = L"Game Search Engine";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	
	private: System::Void eighties_Click(System::Object^ sender, System::EventArgs^ e) {
		idiot.cont = idiot.years80to99;

	}
	private: System::Void thousands_Click(System::Object^ sender, System::EventArgs^ e) {

		idiot.cont = idiot.years00to19;
	}
	private: System::Void twenties_Click(System::Object^ sender, System::EventArgs^ e) {

		idiot.cont = idiot.years20toNow;
	}
	private: System::Void TBA_Click(System::Object^ sender, System::EventArgs^ e) {
		idiot.cont = idiot.yearsNA;

	}
		  
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	
	
	idiot.QuickSort(idiot.cont, 0, idiot.cont.size() - 1);
	
}
private: System::Void mergebutton_Click(System::Object^ sender, System::EventArgs^ e) {


	idiot.mergeSort(idiot.cont, 0, idiot.cont.size() - 1);

}

private: System::Void Genre_Click(System::Object^ sender, System::EventArgs^ e) {
	this->displayPort->Items->Clear();
	int counter = 0;
	
	for (int i = 0; i < idiot.cont.size(); i++) {
		idiot.setter();
		//cout << idiot.cont.size() << endl;
		if (i >= idiot.cont.size()) {
			break;
		}
		
		std::string bob ="oop";
		//cout << "poop3" <<  endl;
		bool blacklist = false;
		
	
		IEnumerator^ myEnum1 = checkedListBox1->CheckedItems->GetEnumerator();
		while (myEnum1->MoveNext())
		{
			Object^ itemChecked = safe_cast<Object^>(myEnum1->Current);
			std::string str = msclr::interop::marshal_as<std::string>(String::Concat(itemChecked));
			//cout << str << endl;
			int genre = idiot.cont[i]->gennum();
			//cout << genre << endl;
			for (int j = 0; j < genre; j++) {
				//cout << idiot.cont[i]->genres[j] << "lookhere "+ idiot.cont[i]->title << endl;
				if (idiot.cont[i]->genres[j].find(str)!=string::npos) {
					blacklist = true;
				}
			}
			//cout << "poop4" << endl;
			
		}
		IEnumerator^ myEnum2 = checkedListBox2->CheckedItems->GetEnumerator();
		while (myEnum2->MoveNext())
		{
			Object^ itemChecked = safe_cast<Object^>(myEnum2->Current);
			std::string str = msclr::interop::marshal_as<std::string>(String::Concat(itemChecked));
			//cout << str << " 888 " << endl;
			int platform = idiot.cont[i]->platnum();
			//cout << platform << endl;
			for (int j = 0; j < platform; j++) {
				//cout << idiot.cont[i]->platforms[j] << "lookhere " + idiot.cont[i]->title << endl;
				if (idiot.cont[i]->platforms[j].find(str) != string::npos) {
					blacklist = true;
				}
			}
			//cout << "poop4" << endl;

		}
		System::String^ fool;
		if ((blacklist == false)&&(counter<30)) {
			fool = gcnew System::String(idiot.cont[i]->title.c_str());
			this->displayPort->Items->Add(fool);
			counter++;
		}
		
	}

}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}

};
}
