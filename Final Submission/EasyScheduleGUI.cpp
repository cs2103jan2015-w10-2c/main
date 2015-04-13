#include "EasyScheduleGUI.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(array<String^>^ argv) {
Application::EnableVisualStyles();
Application::SetCompatibleTextRenderingDefault(false);

UI::EasyScheduleGUI mainWindow;

Application::Run(%mainWindow);

return 0;
}
