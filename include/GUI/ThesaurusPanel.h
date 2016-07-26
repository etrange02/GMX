#ifndef THESAURUSPANEL_H
#define THESAURUSPANEL_H

//(*Headers(ThesaurusPanel)
#include <wx/panel.h>
//*)

class ThesaurusPanel: public wxPanel
{
	public:

		ThesaurusPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ThesaurusPanel();

	private:

		//(*Declarations(ThesaurusPanel)
		//*)

	public:

		//(*Identifiers(ThesaurusPanel)
		//*)

	private:

		//(*Handlers(ThesaurusPanel)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
