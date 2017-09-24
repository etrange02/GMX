/***************************************************************
 * Name:      GMXMain.h
 * Purpose:   Defines Application Frame
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2016-07-24
 * Copyright: David Lecoconnier (www.getfux.fr)
 * License:
 **************************************************************/

#ifndef GMXMAIN_H
#define GMXMAIN_H

//(*Headers(GMXFrame)
#include <wx/app.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/snglinst.h>
#include <wx/toolbar.h>
#include <wx/utils.h>
//*)
#include "AnalysisPanel.h"
#include "ThesaurusPanel.h"


class GMXFrame: public wxFrame
{
    public:

        GMXFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~GMXFrame();

    private:

        //(*Handlers(GMXFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnNotebook1PageChanged(wxNotebookEvent& event);
        void OnCustom1Paint(wxPaintEvent& event);
        void OnNotebookPageChanged(wxNotebookEvent& event);
        //*)

        //(*Identifiers(GMXFrame)
        static const long ID_PANEL_ANALYSE;
        static const long ID_ENGINE_PANEL;
        static const long ID_NOTEBOOK1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_TOOLBAR1;
        //*)

        //(*Declarations(GMXFrame)
        AnalysisPanel* m_analysisPanel;
        ThesaurusPanel* m_thesaurusPanel;
        wxNotebook* m_notebook;
        wxSingleInstanceChecker SingleInstanceChecker1;
        wxToolBar* m_toolBar;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GMXMAIN_H
