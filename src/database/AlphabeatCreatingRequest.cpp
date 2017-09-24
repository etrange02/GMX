/***************************************************************
 * Name:      AlphabeatCreatingRequest.cpp
 * Purpose:   Code for GMX
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2017-05-04
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "AlphabeatCreatingRequest.h"
#include "tools/database/DataBaseManager.h"
#include "tools/database/DataBaseResponse.h"
#include <algorithm>
#include <wx/wxsqlite3.h>
#include "database/DataBase_MetaData.h"
#include "database/alphabeat/AlphabeatCreatingResponse.h"
#include "model/Alphabeat.h"
#include "compatibility/cpp11.h"


using namespace database;

AlphabeatCreatingRequest::AlphabeatCreatingRequest(const wxString& alphabeat) :
    tools::database::DataBaseRequest(),
    m_alphabeat(alphabeat)
{
    //ctor
}

AlphabeatCreatingRequest::~AlphabeatCreatingRequest()
{
    //dtor
}

tools::database::DataBaseResponse* AlphabeatCreatingRequest::execute(tools::database::DataBaseManager& dataBaseManager)
{
    wxSQLite3Database& db = dataBaseManager.getDatabase();

    m_alphabeat.LowerCase();
    std::sort(m_alphabeat.begin(), m_alphabeat.end());
    int id = db.ExecuteScalar(wxString("SELECT ") + COLUMN_ALPHABEAT_ID + " FROM " + TABLE_ALPHABEAT + " WHERE " + COLUMN_ALPHABEAT_LETTERS + "='" + m_alphabeat + wxString("'"));

    if (id == -1)
    {
        db.ExecuteUpdate(wxString("INSERT INTO " TABLE_ALPHABEAT " (" COLUMN_ALPHABEAT_LETTERS ") VALUES ('") + m_alphabeat + wxString("')"));
        id = db.GetLastRowId().ToLong();
    }

    model::Alphabeat* alphabeat = new model::Alphabeat(id, m_alphabeat);
    return new AlphabeatCreatingResponse(true, alphabeat);
}

