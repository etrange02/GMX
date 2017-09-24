/***************************************************************
 * Name:      AlphabeatReadingResponse.cpp
 * Purpose:   Code for GMX
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2017-07-23
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "AlphabeatReadingResponse.h"

using namespace database;

AlphabeatReadingResponse::AlphabeatReadingResponse(bool isOk, std::vector<model::Alphabeat*>* alphabeats) :
    tools::database::DataBaseResponse(isOk),
    m_alphabeats(alphabeats)
{
    //ctor
}

AlphabeatReadingResponse::~AlphabeatReadingResponse()
{
    //dtor
}

std::vector<model::Alphabeat*>* AlphabeatReadingResponse::getAlphabeats()
{
    return m_alphabeats;
}

