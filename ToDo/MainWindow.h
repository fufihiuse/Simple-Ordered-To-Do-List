#pragma once
#include <wx/wx.h>
#include <queue>

class MainWindow : public wxFrame
{
public:
	std::queue<wxString> tasks;

	MainWindow(const wxString& title, wxPoint point, int sizeX, int sizeY);

	void addTask(wxCommandEvent& event);
	void completeTopTask(wxCommandEvent& event);

private:
	wxFont font;
	wxTextCtrl* textInput;
	wxButton* button;
	wxListBox* taskList;
};

