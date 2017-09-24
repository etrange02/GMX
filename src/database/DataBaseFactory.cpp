/***************************************************************
 * Name:      DataBaseFactory.cpp
 * Purpose:   Code for GMX
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2017-05-01
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "DataBaseFactory.h"
#include "database/DataBaseOpeningRequest_01.h"
#include "tools/database/requests/DataBaseClosingRequest.h"

DataBaseFactory::DataBaseFactory()
{
    //ctor
}

DataBaseFactory::~DataBaseFactory()
{
    //dtor
}

tools::database::DataBaseRequest* DataBaseFactory::createOpeningRequest(const wxString& filename)
{
    return new database::DataBaseOpeningRequest_01(filename);
}

tools::database::DataBaseRequest* DataBaseFactory::createClosingRequest()
{
    return new tools::database::DataBaseClosingRequest;
}
