/***************************************************************
 * Name:      GuematricNumber.cpp
 * Purpose:   Code for GMX
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2017-09-19
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "GuematricNumber.h"

using namespace word;

GuematricNumber::GuematricNumber(int guematric) :
    m_guematric(guematric)
{
    m_transreal = m_guematric * (m_guematric+1) / 2;
}

GuematricNumber::~GuematricNumber()
{
    //dtor
}

int GuematricNumber::getGuematric() const
{
    return m_guematric;
}

int GuematricNumber::getTransreal() const
{
    return m_transreal;
}

