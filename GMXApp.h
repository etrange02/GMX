/***************************************************************
 * Name:      GMXApp.h
 * Purpose:   Defines Application Class
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2016-07-24
 * Copyright: David Lecoconnier (www.getfux.fr)
 * License:
 **************************************************************/

#ifndef GMXAPP_H
#define GMXAPP_H

#include <wx/app.h>
#include "application/Mediator.h"

class GMXApp : public wxApp
{
    public:
        virtual bool OnInit();

    private:
        Mediator m_mediator;
};

#endif // GMXAPP_H
