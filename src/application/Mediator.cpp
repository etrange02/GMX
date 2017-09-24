/***************************************************************
 * Name:      Mediator.cpp
 * Purpose:   Code for GMX
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2017-05-01
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "Mediator.h"
#include "tools/database/DataBaseManager.h"

Mediator::Mediator()
{
    //ctor
}

Mediator::~Mediator()
{
    //dtor
}

tools::database::DataBaseManager& Mediator::getDatabase()
{
    return m_database;
}
