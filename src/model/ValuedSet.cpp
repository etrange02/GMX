/***************************************************************
 * Name:      ValuedSet.cpp
 * Purpose:   Code for GMX
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2017-05-02
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "ValuedSet.h"

using namespace model;

ValuedSet::ValuedSet(int id, const wxString& name) :
    m_id(id),
    m_name(name)
{
    //ctor
}

ValuedSet::~ValuedSet()
{
    //dtor
}

const wxString& ValuedSet::getName() const
{
    return m_name;
}

int ValuedSet::getId() const
{
    return m_id;
}

std::vector<ValuedLetter*>& ValuedSet::getValuedLetters()
{
    return m_valuedLetters;
}

const std::vector<ValuedLetter*>& ValuedSet::getValuedLetters() const
{
    return m_valuedLetters;
}

