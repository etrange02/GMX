/***************************************************************
 * Name:      Alphabeat.cpp
 * Purpose:   Code for GMX
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2017-05-02
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "Alphabeat.h"

using namespace model;

Alphabeat::Alphabeat() :
    m_id(-1)
{
    //ctor
}

Alphabeat::Alphabeat(int id, const wxString& letters) :
    m_id(id),
    m_letters(letters)
{
    //ctor
}

Alphabeat::~Alphabeat()
{
    //dtor
}

int Alphabeat::getId() const
{
    return m_id;
}


std::vector<Thesaurus>& Alphabeat::thesauruses()
{
    return m_thesauruses;
}

std::vector<ValuedSet>& Alphabeat::valuedSets()
{
    return m_valuedSets;
}

