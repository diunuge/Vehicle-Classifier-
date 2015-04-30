#pragma once

#include "CVTest.h"

namespace FormApplicationTest {

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
			cvtest = new CVTest();
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
	private: System::Windows::Forms::Button^  buttonVidStart;
	private: System::Windows::Forms::Button^  buttonStart;
	protected: 


	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  buttonVidStop;
	private: System::Windows::Forms::Button^  buttonManualUp;
	private: System::Windows::Forms::Button^  buttonManualDown;


	private: System::Windows::Forms::Button^  buttonManualLeft;
	private: System::Windows::Forms::Button^  buttonManualRight;
	private: System::Windows::Forms::Button^  buttonStop;
	private: System::Windows::Forms::Button^  buttonAuto;
	private: System::Windows::Forms::Button^  buttonManual;
	private: System::Windows::Forms::Label^  label1;


	protected: 

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
		void InitializeComponent()
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->buttonVidStart = (gcnew System::Windows::Forms::Button());
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonVidStop = (gcnew System::Windows::Forms::Button());
			this->buttonManualUp = (gcnew System::Windows::Forms::Button());
			this->buttonManualDown = (gcnew System::Windows::Forms::Button());
			this->buttonManualLeft = (gcnew System::Windows::Forms::Button());
			this->buttonManualRight = (gcnew System::Windows::Forms::Button());
			this->buttonStop = (gcnew System::Windows::Forms::Button());
			this->buttonAuto = (gcnew System::Windows::Forms::Button());
			this->buttonManual = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// buttonVidStart
			// 
			this->buttonVidStart->Location = System::Drawing::Point(524, 23);
			this->buttonVidStart->Name = L"buttonVidStart";
			this->buttonVidStart->Size = System::Drawing::Size(75, 78);
			this->buttonVidStart->TabIndex = 0;
			this->buttonVidStart->Text = L"Start \r\nVideo\r\nMonitor";
			this->buttonVidStart->UseVisualStyleBackColor = true;
			this->buttonVidStart->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// buttonStart
			// 
			this->buttonStart->Location = System::Drawing::Point(39, 26);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(76, 75);
			this->buttonStart->TabIndex = 1;
			this->buttonStart->Text = L"Start";
			this->buttonStart->UseVisualStyleBackColor = true;
			this->buttonStart->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(257, 26);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(229, 164);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// buttonVidStop
			// 
			this->buttonVidStop->Location = System::Drawing::Point(524, 115);
			this->buttonVidStop->Name = L"buttonVidStop";
			this->buttonVidStop->Size = System::Drawing::Size(75, 75);
			this->buttonVidStop->TabIndex = 3;
			this->buttonVidStop->Text = L"Stop\r\nVideo\r\nMonitor";
			this->buttonVidStop->UseVisualStyleBackColor = true;
			this->buttonVidStop->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// buttonManualUp
			// 
			this->buttonManualUp->Location = System::Drawing::Point(142, 233);
			this->buttonManualUp->Name = L"buttonManualUp";
			this->buttonManualUp->Size = System::Drawing::Size(75, 52);
			this->buttonManualUp->TabIndex = 4;
			this->buttonManualUp->Text = L"Up";
			this->buttonManualUp->UseVisualStyleBackColor = true;
			this->buttonManualUp->Click += gcnew System::EventHandler(this, &MyForm::buttonManualUp_Click);
			// 
			// buttonManualDown
			// 
			this->buttonManualDown->Location = System::Drawing::Point(142, 307);
			this->buttonManualDown->Name = L"buttonManualDown";
			this->buttonManualDown->Size = System::Drawing::Size(75, 48);
			this->buttonManualDown->TabIndex = 5;
			this->buttonManualDown->Text = L"Down";
			this->buttonManualDown->UseVisualStyleBackColor = true;
			this->buttonManualDown->Click += gcnew System::EventHandler(this, &MyForm::Down_Click);
			// 
			// buttonManualLeft
			// 
			this->buttonManualLeft->Location = System::Drawing::Point(245, 233);
			this->buttonManualLeft->Name = L"buttonManualLeft";
			this->buttonManualLeft->Size = System::Drawing::Size(75, 52);
			this->buttonManualLeft->TabIndex = 6;
			this->buttonManualLeft->Text = L"Left";
			this->buttonManualLeft->UseVisualStyleBackColor = true;
			this->buttonManualLeft->Click += gcnew System::EventHandler(this, &MyForm::buttonManualLeft_Click);
			// 
			// buttonManualRight
			// 
			this->buttonManualRight->Location = System::Drawing::Point(39, 233);
			this->buttonManualRight->Name = L"buttonManualRight";
			this->buttonManualRight->Size = System::Drawing::Size(75, 52);
			this->buttonManualRight->TabIndex = 7;
			this->buttonManualRight->Text = L"Right";
			this->buttonManualRight->UseVisualStyleBackColor = true;
			this->buttonManualRight->Click += gcnew System::EventHandler(this, &MyForm::buttonManualRight_Click);
			// 
			// buttonStop
			// 
			this->buttonStop->Location = System::Drawing::Point(142, 26);
			this->buttonStop->Name = L"buttonStop";
			this->buttonStop->Size = System::Drawing::Size(75, 75);
			this->buttonStop->TabIndex = 8;
			this->buttonStop->Text = L"Stop";
			this->buttonStop->UseVisualStyleBackColor = true;
			this->buttonStop->Click += gcnew System::EventHandler(this, &MyForm::buttonStop_Click);
			// 
			// buttonAuto
			// 
			this->buttonAuto->Location = System::Drawing::Point(39, 115);
			this->buttonAuto->Name = L"buttonAuto";
			this->buttonAuto->Size = System::Drawing::Size(76, 75);
			this->buttonAuto->TabIndex = 9;
			this->buttonAuto->Text = L"Auto";
			this->buttonAuto->UseVisualStyleBackColor = true;
			this->buttonAuto->Click += gcnew System::EventHandler(this, &MyForm::buttonAuto_Click);
			// 
			// buttonManual
			// 
			this->buttonManual->Location = System::Drawing::Point(142, 115);
			this->buttonManual->Name = L"buttonManual";
			this->buttonManual->Size = System::Drawing::Size(75, 75);
			this->buttonManual->TabIndex = 10;
			this->buttonManual->Text = L"Manual";
			this->buttonManual->UseVisualStyleBackColor = true;
			this->buttonManual->Click += gcnew System::EventHandler(this, &MyForm::buttonManual_Click);
			// 
			// label1
			// 
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(338, 225);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(250, 130);
			this->label1->TabIndex = 11;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 367);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonManual);
			this->Controls->Add(this->buttonAuto);
			this->Controls->Add(this->buttonStop);
			this->Controls->Add(this->buttonManualRight);
			this->Controls->Add(this->buttonManualLeft);
			this->Controls->Add(this->buttonManualDown);
			this->Controls->Add(this->buttonManualUp);
			this->Controls->Add(this->buttonVidStop);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->buttonStart);
			this->Controls->Add(this->buttonVidStart);
			this->Name = L"MyForm";
			this->Text = L"Observer Control Station 1.0v";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		CVTest* cvtest;

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 cvtest->captureStream();
			 }

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 cvtest->setCommand("avoid_obs");
				 cvtest->updateInfo();
				 this->textBox1->Text = gcnew String(cvtest->getInterfaceText().c_str());
			 }

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 cvtest->setCommand("stop");
				 cvtest->close();
			 }

	private: System::Void buttonStop_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 cvtest->setCommand("stop");
			 }

	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {

			 }

	private: System::Void buttonAuto_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 cvtest->setControl("auto");
			 }

	private: System::Void buttonManual_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 cvtest->setControl("manual");
			 }

	private: System::Void buttonManualRight_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 cvtest->setCommand("right");
			 }

	private: System::Void buttonManualLeft_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 cvtest->setCommand("left");
			 }

	private: System::Void buttonManualUp_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 cvtest->setCommand("forward");
			 }

	private: System::Void Down_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 cvtest->setCommand("backward");
			 }

	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) 
			 {

			 }
	};
}
