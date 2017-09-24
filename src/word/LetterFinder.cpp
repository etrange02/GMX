/***************************************************************
 * Name:      LetterFinder.cpp
 * Purpose:   Code for GMX
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2017-09-17
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "LetterFinder.h"

using namespace word;

LetterFinder::LetterFinder(const wxUniChar& letter)
{
    m_letter = letter;
    m_letter.MakeLower();
}

LetterFinder::~LetterFinder()
{
    //dtor
}

bool LetterFinder::operator()(const model::ValuedLetter* element)
{
    return m_letter == element->getLetter();
}

