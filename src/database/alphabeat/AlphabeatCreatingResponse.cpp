/***************************************************************
 * Name:      AlphabeatCreatingResponse.cpp
 * Purpose:   Code for GMX
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2017-07-22
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "AlphabeatCreatingResponse.h"

using namespace database;

AlphabeatCreatingResponse::AlphabeatCreatingResponse(bool isOk, model::Alphabeat* alphabeat) :
    tools::database::DataBaseResponse(isOk),
    m_alphabeat(alphabeat)
{
    //ctor
}

AlphabeatCreatingResponse::~AlphabeatCreatingResponse()
{
    //dtor
}

model::Alphabeat* AlphabeatCreatingResponse::getAlphabeat()
{
    return m_alphabeat;
}


