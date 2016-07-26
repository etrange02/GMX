#ifndef ANALYSEPANEL_H
#define ANALYSEPANEL_H

//(*Headers(AnalysePanel)
#include <wx/panel.h>
class wxTextCtrl;
class wxComboBox;
class wxStaticText;
class wxListView;
class wxBoxSizer;
class wxButton;
class wxStaticBoxSizer;
//*)

class AnalysePanel: public wxPanel
{
	public:

		AnalysePanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);
		virtual ~AnalysePanel();

	private:

		//(*Declarations(AnalysePanel)
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxBoxSizer* m_guematrixNumberSizer;
		wxBoxSizer* m_reductionNumberSizer;
		wxListView* ListView1;
		wxComboBox* ComboBox1;
		wxTextCtrl* m_wordToAnalyse;
		//*)

	public:

		//(*Identifiers(AnalysePanel)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_LISTVIEW1;
		//*)

	private:

		//(*Handlers(AnalysePanel)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
