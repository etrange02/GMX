/***************************************************************
 * Name:      WordAnalyzer.cpp
 * Purpose:   Code for GMX
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2017-09-16
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "WordAnalyzer.h"
#include <algorithm>
#include <vector>
#include "model/ValuedLetter.h"
#include "word/LetterFinder.h"

using namespace word;

WordAnalyzer::WordAnalyzer(const model::ValuedSet& valuedSet) :
    m_value(0),
    m_valuedSet(valuedSet)
{
    //ctor
}

WordAnalyzer::~WordAnalyzer()
{
    //dtor
}

void WordAnalyzer::operator()(wxString::iterator::reference letter)
{
    LetterFinder letterFinder(letter);
    std::vector<model::ValuedLetter*>::const_iterator a = std::find_if(m_valuedSet.getValuedLetters().begin(), m_valuedSet.getValuedLetters().end(), letterFinder);
    if (a == m_valuedSet.getValuedLetters().end())
        return;
    m_analyzedWord += letter;
    m_value += (*a)->getValue();
}

int WordAnalyzer::getValue()
{
    return m_value;
}

const wxString& WordAnalyzer::getAnalyzedWord()
{
    return m_analyzedWord;
}

