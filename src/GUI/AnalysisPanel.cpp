#include "AnalysisPanel.h"

//(*InternalHeaders(AnalysePanel)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/intl.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/combobox.h>
//*)

//(*IdInit(AnalysePanel)
const long AnalysePanel::ID_STATICTEXT1 = wxNewId();
const long AnalysePanel::ID_COMBOBOX1 = wxNewId();
const long AnalysePanel::ID_TEXTCTRL1 = wxNewId();
const long AnalysePanel::ID_BUTTON1 = wxNewId();
const long AnalysePanel::ID_LISTVIEW1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(AnalysePanel,wxPanel)
	//(*EventTable(AnalysePanel)
	//*)
END_EVENT_TABLE()

AnalysePanel::AnalysePanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(AnalysePanel)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, wxID_ANY, wxPoint(123,75), wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Thésaurus sélectionné"), wxDefaultPosition, wxSize(118,13), 0, _T("ID_STATICTEXT1"));
	BoxSizer3->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY|wxCB_DROPDOWN, wxDefaultValidator, _T("ID_COMBOBOX1"));
	BoxSizer3->Add(ComboBox1, 1, wxALL, 5);
	BoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND, 0);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Analyser un mot"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	m_wordToAnalyse = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	m_wordToAnalyse->SetFocus();
	BoxSizer1->Add(m_wordToAnalyse, 1, wxALL|wxEXPAND, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("Ajouter au thésaurus"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer1->Add(Button1, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5);
	StaticBoxSizer1->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	m_guematrixNumberSizer = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1->Add(m_guematrixNumberSizer, 0, wxLEFT|wxRIGHT|wxALIGN_TOP, 5);
	m_reductionNumberSizer = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1->Add(m_reductionNumberSizer, 0, wxALL|wxALIGN_TOP, 0);
	BoxSizer2->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Correspondances dans le thésaurus"));
	ListView1 = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxSize(360,98));
	StaticBoxSizer2->Add(ListView1, 1, wxALL|wxEXPAND, 5);
	BoxSizer2->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer2);
	BoxSizer2->Fit(this);
	BoxSizer2->SetSizeHints(this);
	//*)
}

AnalysePanel::~AnalysePanel()
{
	//(*Destroy(AnalysePanel)
	//*)
}

