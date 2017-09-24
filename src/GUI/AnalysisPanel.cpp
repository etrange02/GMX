#include "AnalysisPanel.h"
#include "word/GuematricNumber.h"

//(*InternalHeaders(AnalysisPanel)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/intl.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/string.h>
#include <wx/textctrl.h>
//*)

//(*IdInit(AnalysisPanel)
const long AnalysisPanel::ID_STATICTEXT1 = wxNewId();
const long AnalysisPanel::ID_COMBOBOX1 = wxNewId();
const long AnalysisPanel::ID_TEXTCTRL1 = wxNewId();
const long AnalysisPanel::ID_STATICTEXT2 = wxNewId();
const long AnalysisPanel::ID_BUTTON1 = wxNewId();
const long AnalysisPanel::ID_STATICTEXT3 = wxNewId();
const long AnalysisPanel::ID_STATICTEXT4 = wxNewId();
const long AnalysisPanel::ID_LISTVIEW1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(AnalysisPanel,wxPanel)
	//(*EventTable(AnalysisPanel)
	//*)
END_EVENT_TABLE()

AnalysisPanel::AnalysisPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size, long style, const wxString& name)
{
	//(*Initialize(AnalysisPanel)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;

	Create(parent, wxID_ANY, wxPoint(123,75), wxSize(390,243), wxTAB_TRAVERSAL, _T("wxID_ANY"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Moteur sélectionné"), wxDefaultPosition, wxSize(118,13), 0, _T("ID_STATICTEXT1"));
	BoxSizer3->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_engines = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY|wxCB_DROPDOWN, wxDefaultValidator, _T("ID_COMBOBOX1"));
	BoxSizer3->Add(m_engines, 1, wxALL, 5);
	BoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND, 0);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Analyser un mot"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	m_wordToAnalyse = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	m_wordToAnalyse->SetFocus();
	BoxSizer1->Add(m_wordToAnalyse, 1, wxALL|wxEXPAND, 5);
	m_recognizedWord = new wxStaticText(this, ID_STATICTEXT2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE|wxVSCROLL, _T("ID_STATICTEXT2"));
	BoxSizer1->Add(m_recognizedWord, 1, wxALL|wxEXPAND, 5);
	m_addWord = new wxButton(this, ID_BUTTON1, _("Ajouter au thésaurus"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer1->Add(m_addWord, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5);
	StaticBoxSizer1->Add(BoxSizer1, 1, wxALL|wxEXPAND, 0);
	StaticBoxSizer1->Add(2,150,0, wxALL|wxEXPAND, 0);
	m_numberSizer = new wxFlexGridSizer(0, 2, 5, 0);
	m_guematrixValueLabel = new wxStaticText(this, ID_STATICTEXT3, _("Guématrie"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	m_numberSizer->Add(m_guematrixValueLabel, 0, wxALL, 5);
	m_reductionValueLabel = new wxStaticText(this, ID_STATICTEXT4, _("Réduction"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	m_numberSizer->Add(m_reductionValueLabel, 0, wxALL, 5);
	StaticBoxSizer1->Add(m_numberSizer, 0, wxLEFT|wxEXPAND|wxFIXED_MINSIZE, 5);
	BoxSizer2->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Correspondances dans le thésaurus"));
	m_similarWords = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxSize(360,98), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTVIEW1"));
	StaticBoxSizer2->Add(m_similarWords, 1, wxALL|wxEXPAND, 5);
	BoxSizer2->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer2);
	SetSizer(BoxSizer2);
	Layout();

	Connect(ID_COMBOBOX1,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&AnalysisPanel::OnEnginesSelected);
	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&AnalysisPanel::OnWordToAnalyseText);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AnalysisPanel::OnAddWordClick);
	//*)
}

AnalysisPanel::~AnalysisPanel()
{
	//(*Destroy(AnalysisPanel)
	//*)
}


void AnalysisPanel::OnWordToAnalyseText(wxCommandEvent& event)
{
    for (wxStaticText* item : m_displayedValues)
    {
        m_numberSizer->Detach(item);
        delete item;
    }
    m_displayedValues.clear();

    m_wordManager.setWord(event.GetString());
    m_recognizedWord->SetLabel(m_wordManager.getAnalysedWord());

    m_wordManager.getGuematricNumbers();
    for (const word::GuematricNumber* item : m_wordManager.getGuematricNumbers())
    {
        addNumber(item->getGuematric());
        addNumber(item->getTransreal());
    }

    m_numberSizer->Layout();
}

void AnalysisPanel::OnAddWordClick(wxCommandEvent& event)
{
}

void AnalysisPanel::OnEnginesSelected(wxCommandEvent& event)
{
}

void AnalysisPanel::addNumber(int value)
{
    wxStaticText* element = new wxStaticText(this, wxID_ANY, wxString::Format("%i", value));
    m_displayedValues.push_back(element);
    m_numberSizer->Add(element, 0, wxLEFT|wxRIGHT, 5);
}

