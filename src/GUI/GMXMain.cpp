/***************************************************************
 * Name:      GMXMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2016-07-24
 * Copyright: David Lecoconnier (www.getfux.fr)
 * License:
 **************************************************************/

#include "GMXMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(GMXFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(GMXFrame)
const long GMXFrame::ID_PANEL_ANALYSE = wxNewId();
const long GMXFrame::ID_PANEL2 = wxNewId();
const long GMXFrame::ID_NOTEBOOK1 = wxNewId();
const long GMXFrame::idMenuQuit = wxNewId();
const long GMXFrame::idMenuAbout = wxNewId();
const long GMXFrame::ID_TOOLBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(GMXFrame,wxFrame)
    //(*EventTable(GMXFrame)
    //*)
END_EVENT_TABLE()

GMXFrame::GMXFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(GMXFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* m_menuBar;
    wxBoxSizer* BoxSizer1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("GMX++"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxDEFAULT_FRAME_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX, _T("wxID_ANY"));
    SetClientSize(wxSize(398,274));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    m_notebook = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(398,282), 0, _T("ID_NOTEBOOK1"));
    m_analysePanel = new AnalysePanel(m_notebook, ID_PANEL_ANALYSE, wxPoint(123,75), wxSize(-1,-1));
    m_thesaurusPanel = new wxPanel(m_notebook, ID_PANEL2, wxPoint(192,10), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    m_notebook->AddPage(m_analysePanel, _("Analyse"), false);
    m_notebook->AddPage(m_thesaurusPanel, _("Gestion des thésaurus"), false);
    BoxSizer1->Add(m_notebook, 1, wxALL|wxEXPAND, 0);
    SetSizer(BoxSizer1);
    m_menuBar = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    m_menuBar->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    m_menuBar->Append(Menu2, _("Help"));
    SetMenuBar(m_menuBar);
    SingleInstanceChecker1.Create(wxTheApp->GetAppName() + _T("_") + wxGetUserId() + _T("_Guard"));
    SetSizer(BoxSizer1);
    Layout();
    Center();

    //Connect(ID_NOTEBOOK1,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&GMXFrame::OnNotebook1PageChanged);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GMXFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GMXFrame::OnAbout);
    //*)
}

GMXFrame::~GMXFrame()
{
    //(*Destroy(GMXFrame)
    //*)
}

void GMXFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void GMXFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
