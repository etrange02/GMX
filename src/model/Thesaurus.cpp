/***************************************************************
 * Name:      Thesaurus.cpp
 * Purpose:   Code for GMX
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2017-05-02
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "Thesaurus.h"

using namespace model;

Thesaurus::Thesaurus(int id) :
    m_id(id)
{
    //ctor
}

Thesaurus::~Thesaurus()
{
    //dtor
}

std::vector<wxString>& Thesaurus::getWords()
{
    return m_words;
}

