/***************************************************************
 * Name:      ValuedLetter.cpp
 * Purpose:   Code for GMX
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2017-05-02
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "ValuedLetter.h"

using namespace model;

ValuedLetter::ValuedLetter(int id, const wxString& letter, int value) :
    m_id(id),
    m_letter(letter),
    m_value(value)
{
    //ctor
}

ValuedLetter::~ValuedLetter()
{
    //dtor
}

int ValuedLetter::getId() const
{
    return m_id;
}

const wxString& ValuedLetter::getLetter() const
{
    return m_letter;
}

int ValuedLetter::getValue() const
{
    return m_value;
}

