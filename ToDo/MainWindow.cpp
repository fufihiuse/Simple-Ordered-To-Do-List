#include "MainWindow.h"

MainWindow::MainWindow(const wxString& title, wxPoint point, int sizeX, int sizeY) 
	: wxFrame(nullptr, wxID_ANY, title, point, wxSize{ sizeX, sizeY })
{
	tasks = std::queue<wxString>();

	// Set font
	font = this->GetFont();
	font.SetPointSize(12);
	this->SetFont(font);

	//Setup windows	
	wxPanel* panel = new wxPanel(this); // Fixes auto-sizing

	taskList = new wxListBox(panel, wxID_ANY, wxPoint(sizeX/2 - 185, sizeY/3 - 175), wxSize(350, 450), NULL, wxLB_NEEDED_SB);

	button = new wxButton(panel, wxID_ANY, "Complete Task", wxPoint(sizeX / 2.0f - 60, sizeY - 75), wxSize(120, 25));

	textInput = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(sizeX / 2 - 185, sizeY - 115), wxSize(350, 25), wxTE_PROCESS_ENTER);

	textInput->Bind(wxEVT_TEXT_ENTER, &MainWindow::addTask, this);
	button->Bind(wxEVT_BUTTON, &MainWindow::completeTopTask, this);
}

void MainWindow::addTask(wxCommandEvent& event)
{
	if (textInput->IsModified())
	{
		taskList->Insert(textInput->GetValue(), taskList->GetCount());
		taskList->SetSelection(0);
		textInput->SetValue("");
		textInput->DiscardEdits();
	}
}

void MainWindow::completeTopTask(wxCommandEvent& event)
{
	taskList->Delete(0);
	taskList->SetSelection(0);
	return;
}
