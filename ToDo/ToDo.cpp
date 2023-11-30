// (c) Jackson Majewski, 2023
#include "ToDo.h"
#include "MainWindow.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(ToDo);

bool ToDo::OnInit() 
{
	MainWindow* window = new MainWindow("Simple Ordered To-Do List", wxDefaultPosition, 400, 600);

	window->Show();
	return true;
}