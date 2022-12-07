#include "MyForm.h"

#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace System;
using namespace System::Windows::Forms;
using namespace std;





int main() {
    
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    
    GameFilter::MyForm form;
    Application::Run(% form);
    
    

    
    return 0;
}
