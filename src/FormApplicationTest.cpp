// FormApplicationTest.cpp : main project file.

#include "stdafx.h"
#include "MyForm.h"

namespace FormApplicationTest {    // Change this!!
    using namespace System;
    using namespace System::Windows::Forms;

	void foo(){


	};

    [STAThread]
    int main(array<System::String ^> ^args)
    {
		//CVTest cvtest;
		//cvtest.captureStream();
		
        Application::EnableVisualStyles();
        Application::SetCompatibleTextRenderingDefault(false); 
        Application::Run(gcnew MyForm());

        return 0;
    }
}



/*
#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Hello World");
    return 0;
}
*/