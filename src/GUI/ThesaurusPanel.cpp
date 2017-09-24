#include "../../include/GUI/ThesaurusPanel.h"

//(*InternalHeaders(ThesaurusPanel)
#include <wx/button.h>
#include <wx/intl.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/string.h>
#include <wx/textctrl.h>
//*)

//(*IdInit(ThesaurusPanel)
const long ThesaurusPanel::ID_ENGINE_NAME_TEXTCTRL = wxNewId();
const long ThesaurusPanel::ID_CREATE_ENGINE_BUTTON = wxNewId();
const long ThesaurusPanel::ID_ENGINES_LISTCTRL = wxNewId();
//*)

BEGIN_EVENT_TABLE(ThesaurusPanel,wxPanel)
	//(*EventTable(ThesaurusPanel)
	//*)
END_EVENT_TABLE()

ThesaurusPanel::ThesaurusPanel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name)
{
	//(*Initialize(ThesaurusPanel)
	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	m_boxSizer1 = new wxBoxSizer(wxVERTICAL);
	m_staticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Nouveau moteur"));
	m_thesaurusName = new wxTextCtrl(this, ID_ENGINE_NAME_TEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_ENGINE_NAME_TEXTCTRL"));
	m_staticBoxSizer4->Add(m_thesaurusName, 1, wxTOP|wxBOTTOM|wxLEFT|wxEXPAND, 5);
	m_createButton = new wxButton(this, ID_CREATE_ENGINE_BUTTON, _("Créer"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CREATE_ENGINE_BUTTON"));
	m_staticBoxSizer4->Add(m_createButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_boxSizer1->Add(m_staticBoxSizer4, 0, wxALL|wxEXPAND, 5);
	m_boxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	m_engines = new wxListCtrl(this, ID_ENGINES_LISTCTRL, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_ENGINES_LISTCTRL"));
	m_boxSizer4->Add(m_engines, 1, wxALL|wxEXPAND, 5);
	m_boxSizer1->Add(m_boxSizer4, 1, wxEXPAND, 5);
	SetSizer(m_boxSizer1);
	m_boxSizer1->Fit(this);
	m_boxSizer1->SetSizeHints(this);
	//*)
}

ThesaurusPanel::~ThesaurusPanel()
{
	//(*Destroy(ThesaurusPanel)
	//*)
}


