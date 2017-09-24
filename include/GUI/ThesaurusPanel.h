#ifndef THESAURUSPANEL_H
#define THESAURUSPANEL_H

//(*Headers(ThesaurusPanel)
#include <wx/panel.h>
class wxBoxSizer;
class wxButton;
class wxListCtrl;
class wxStaticBoxSizer;
class wxTextCtrl;
//*)

class ThesaurusPanel: public wxPanel
{
	public:

		ThesaurusPanel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name);
		virtual ~ThesaurusPanel();

	private:

		//(*Declarations(ThesaurusPanel)
		wxBoxSizer* m_boxSizer1;
		wxBoxSizer* m_boxSizer4;
		wxButton* m_createButton;
		wxListCtrl* m_engines;
		wxStaticBoxSizer* m_staticBoxSizer4;
		wxTextCtrl* m_thesaurusName;
		//*)

	public:

		//(*Identifiers(ThesaurusPanel)
		static const long ID_ENGINE_NAME_TEXTCTRL;
		static const long ID_CREATE_ENGINE_BUTTON;
		static const long ID_ENGINES_LISTCTRL;
		//*)

	private:

		DECLARE_EVENT_TABLE()
};

#endif
