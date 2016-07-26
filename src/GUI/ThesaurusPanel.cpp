#include "../../include/GUI/ThesaurusPanel.h"

//(*InternalHeaders(ThesaurusPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ThesaurusPanel)
//*)

BEGIN_EVENT_TABLE(ThesaurusPanel,wxPanel)
	//(*EventTable(ThesaurusPanel)
	//*)
END_EVENT_TABLE()

ThesaurusPanel::ThesaurusPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ThesaurusPanel)
	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	//*)
}

ThesaurusPanel::~ThesaurusPanel()
{
	//(*Destroy(ThesaurusPanel)
	//*)
}

