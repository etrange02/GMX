#ifndef ANALYSEPANEL_H
#define ANALYSEPANEL_H

//(*Headers(AnalysisPanel)
#include <wx/panel.h>
class wxBoxSizer;
class wxButton;
class wxComboBox;
class wxFlexGridSizer;
class wxListView;
class wxStaticBoxSizer;
class wxStaticText;
class wxTextCtrl;
//*)
#include "word/WordManager.h"

class AnalysisPanel: public wxPanel
{
	public:

		AnalysisPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size, long style, const wxString& name);
		virtual ~AnalysisPanel();

	private:

		//(*Declarations(AnalysisPanel)
		wxButton* m_addWord;
		wxComboBox* m_engines;
		wxFlexGridSizer* m_numberSizer;
		wxListView* m_similarWords;
		wxStaticText* StaticText1;
		wxStaticText* m_guematrixValueLabel;
		wxStaticText* m_recognizedWord;
		wxStaticText* m_reductionValueLabel;
		wxTextCtrl* m_wordToAnalyse;
		//*)

	public:

		//(*Identifiers(AnalysisPanel)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_LISTVIEW1;
		//*)

	private:

		//(*Handlers(AnalysisPanel)
		void OnWordToAnalyseText(wxCommandEvent& event);
		void OnAddWordClick(wxCommandEvent& event);
		void OnEnginesSelected(wxCommandEvent& event);
		//*)

		void addNumber(int value);

    private:
		word::WordManager m_wordManager;
		std::vector<wxStaticText*> m_displayedValues;

		DECLARE_EVENT_TABLE()
};

#endif
