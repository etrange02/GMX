/***************************************************************
 * Name:      GMXApp.cpp
 * Purpose:   Code for Application Class
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2016-07-24
 * Copyright: David Lecoconnier (www.getfux.fr)
 * License:
 **************************************************************/

#include "GMXApp.h"

//(*AppHeaders
#include "include/GUI/GMXMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(GMXApp);

bool GMXApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	GMXFrame* Frame = new GMXFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
