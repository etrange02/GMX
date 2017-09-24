/***************************************************************
 * Name:      AlphabeatReadingRequest.cpp
 * Purpose:   Code for GMX
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2017-07-23
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "AlphabeatReadingRequest.h"
#include <wx/wxsqlite3.h>
#include <tools/database/DataBaseManager.h>
#include "database/DataBase_MetaData.h"
#include "model/Alphabeat.h"
#include "database/alphabeat/AlphabeatReadingResponse.h"

using namespace database;

AlphabeatReadingRequest::AlphabeatReadingRequest() :
    tools::database::DataBaseRequest()
{
    //ctor
}

AlphabeatReadingRequest::~AlphabeatReadingRequest()
{
    //dtor
}

tools::database::DataBaseResponse* AlphabeatReadingRequest::execute(tools::database::DataBaseManager& dataBaseManager)
{
    wxSQLite3Database& db = dataBaseManager.getDatabase();

    wxSQLite3ResultSet result = db.ExecuteQuery(wxString("SELECT * FROM ") + TABLE_ALPHABEAT);

    std::vector<model::Alphabeat*>* alphabeats = new std::vector<model::Alphabeat*>();

    while (result.NextRow())
    {
        int rowId = result.GetInt(COLUMN_ALPHABEAT_ID);
        wxString letters = result.GetAsString(COLUMN_ALPHABEAT_LETTERS);
        model::Alphabeat* alphabeat = new model::Alphabeat(rowId, letters);
        alphabeats->push_back(alphabeat);
    }

    return new AlphabeatReadingResponse(true, alphabeats);
}

