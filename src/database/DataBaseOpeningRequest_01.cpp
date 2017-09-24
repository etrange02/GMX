/***************************************************************
 * Name:      DataBaseOpeningRequest_01.cpp
 * Purpose:   Code for GMX
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2017-05-01
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "DataBaseOpeningRequest_01.h"
#include <wx/wxsqlite3.h>
#include "DataBase_MetaData.h"
#include "tools/database/DataBaseMetaData.h"

using namespace database;

/** @brief Constructor.
 *
 * @param filename const wxString&
 *
 */
DataBaseOpeningRequest_01::DataBaseOpeningRequest_01(const wxString& filename) :
    tools::database::DataBaseOpeningRequest(filename)
{
    //ctor
}

/** @brief Destructor.
 */
DataBaseOpeningRequest_01::~DataBaseOpeningRequest_01()
{
    //dtor
}

/** @brief Overload. Update the DB to version 1.
 *
 * @param database wxSQLite3Database&
 * @param currentVersion int
 * @return int
 *
 */
int DataBaseOpeningRequest_01::updateTables(wxSQLite3Database& database, int currentVersion)
{
    const int targetVersion = 1;
    if (currentVersion >= targetVersion)
        return targetVersion;

    tools::database::DataBaseOpeningRequest::updateTables(database, currentVersion);

    // Logical data
    if (!database.TableExists(TABLE_ALPHABEAT))
        database.ExecuteUpdate("CREATE TABLE " TABLE_ALPHABEAT "("
                                COLUMN_ALPHABEAT_ID " INTEGER PRIMARY KEY AUTOINCREMENT,"
                                COLUMN_ALPHABEAT_LETTERS " VARCHAR(512) NOT NULL);");

    if (!database.TableExists(TABLE_THESAURUS))
        database.ExecuteUpdate("CREATE TABLE " TABLE_THESAURUS "("
                                COLUMN_THESAURUS_ID " INTEGER PRIMARY KEY AUTOINCREMENT,"
                                COLUMN_THESAURUS_ALPHABEAT_ID " INTEGER REFERENCES " TABLE_ALPHABEAT "(" COLUMN_ALPHABEAT_ID "),"
                                COLUMN_THESAURUS_WORD " VARCHAR(254) NOT NULL);");

    if (!database.TableExists(TABLE_VALUEDSET))
        database.ExecuteUpdate("CREATE TABLE " TABLE_VALUEDSET "("
                                COLUMN_VALUEDSET_ID " INTEGER PRIMARY KEY AUTOINCREMENT,"
                                COLUMN_VALUEDSET_ALPHABEAT_ID " INTEGER REFERENCES " TABLE_ALPHABEAT "(" COLUMN_ALPHABEAT_ID "),"
                                COLUMN_VALUEDSET_NAME " VARCHAR(128) NOT NULL);");

    if (!database.TableExists(TABLE_GUEMATRIX))
        database.ExecuteUpdate("CREATE TABLE " TABLE_GUEMATRIX "("
                                COLUMN_GUEMATRIX_ID " INTEGER PRIMARY KEY AUTOINCREMENT,"
                                COLUMN_GUEMATRIX_VALUEDSET_ID " INTEGER REFERENCES " TABLE_VALUEDSET "(" COLUMN_VALUEDSET_ID "),"
                                COLUMN_GUEMATRIX_THESAURUS_ID " INTEGER REFERENCES " TABLE_THESAURUS "(" COLUMN_THESAURUS_ID "),"
                                COLUMN_GUEMATRIX_VALUE " INTEGER NOT NULL," // INTEGER
                                COLUMN_GUEMATRIX_OCCURENCE " INTEGER NOT NULL DEFAULT 1 CHECK (" COLUMN_GUEMATRIX_OCCURENCE " >=1);");

    if (!database.TableExists(TABLE_VALUEDLETTER))
        database.ExecuteUpdate("CREATE TABLE " TABLE_VALUEDLETTER "("
                                COLUMN_VALUEDLETTER_ID " INTEGER PRIMARY KEY AUTOINCREMENT,"
                                COLUMN_VALUEDLETTER_VALUEDSET_ID " INTEGER REFERENCES " TABLE_VALUEDSET "(" COLUMN_VALUEDSET_ID "),"
                                COLUMN_VALUEDLETTER_LETTER " CHAR NOT NULL,"
                                COLUMN_VALUEDLETTER_VALUE " INTEGER NOT NULL);");// INTEGER

    return targetVersion;
}

