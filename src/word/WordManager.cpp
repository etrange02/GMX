/***************************************************************
 * Name:      WordManager.cpp
 * Purpose:   Code for GMX
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2017-09-10
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "WordManager.h"
#include <algorithm>
#include "word/WordAnalyzer.h"

using namespace word;

WordManager::WordManager() :
    m_selectedValuedSet(nullptr),
    m_value(0)
{
    m_selectedValuedSet = new model::ValuedSet(1, "default set");
    char letter[] = "a";
    for (int i = 0; i < 26; ++i)
    {
        m_selectedValuedSet->getValuedLetters().push_back(new model::ValuedLetter(i, wxString(letter), i+1));
        letter[0]++;
    }
    letter[0] = '0';
    for (int i = 0; i < 10; ++i)
    {
        m_selectedValuedSet->getValuedLetters().push_back(new model::ValuedLetter(i, wxString(letter), i));
        letter[0]++;
    }
    m_selectedValuedSet->getValuedLetters().push_back(new model::ValuedLetter(26, wxString(" "), 0));
    m_selectedValuedSet->getValuedLetters().push_back(new model::ValuedLetter(27, wxString("."), 0));
    m_selectedValuedSet->getValuedLetters().push_back(new model::ValuedLetter(28, wxString(","), 0));
    m_selectedValuedSet->getValuedLetters().push_back(new model::ValuedLetter(29, wxString(":"), 0));
    m_selectedValuedSet->getValuedLetters().push_back(new model::ValuedLetter(30, wxString(";"), 0));
    m_selectedValuedSet->getValuedLetters().push_back(new model::ValuedLetter(30, wxString("?"), 0));
    m_selectedValuedSet->getValuedLetters().push_back(new model::ValuedLetter(30, wxString("!"), 0));
    m_selectedValuedSet->getValuedLetters().push_back(new model::ValuedLetter(30, wxString("-"), 0));
    m_selectedValuedSet->getValuedLetters().push_back(new model::ValuedLetter(30, wxString("("), 0));
    m_selectedValuedSet->getValuedLetters().push_back(new model::ValuedLetter(30, wxString(")"), 0));
    m_selectedValuedSet->getValuedLetters().push_back(new model::ValuedLetter(30, wxString("'"), 0));
    m_selectedValuedSet->getValuedLetters().push_back(new model::ValuedLetter(30, wxString("\""), 0));
}

WordManager::~WordManager()
{
    //dtor
}

void WordManager::setWord(const wxString& word)
{
    m_word = word;
    analyse();
}

const wxString& WordManager::getAnalysedWord() const
{
    return m_analysedWord;
}

int WordManager::getValue() const
{
    return m_value;
}

void WordManager::analyse()
{
    WordAnalyzer analyzer(*m_selectedValuedSet);
    WordAnalyzer a = std::for_each(m_word.begin(), m_word.end(), analyzer);
    m_analysedWord = a.getAnalyzedWord();
    m_value = a.getValue();

    clearGuematricNumbers();
    int value = m_value;

    GuematricNumber* num = new GuematricNumber(value);
    m_guematricNumbers.push_back(num);
    while (value > 9)
    {
        int sum = 0;
        while (value > 9)
        {
            sum += value % 10;
            value /= 10;
        }
        sum += value;
        m_guematricNumbers.push_back(new GuematricNumber(sum));
        value = sum;
    }
}

const std::vector<GuematricNumber*> WordManager::getGuematricNumbers() const
{
    return m_guematricNumbers;
}

void WordManager::clearGuematricNumbers()
{
    clearContainer(m_guematricNumbers);
}

void WordManager::clearValuedSet()
{
    //clear(*m_selectedValuedSet);
}

