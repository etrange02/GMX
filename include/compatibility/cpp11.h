#ifndef CPP11_H_INCLUDED
#define CPP11_H_INCLUDED

namespace std
{
    template <>
    inline void iter_swap<wxString::iterator>(wxString::iterator i1, wxString::iterator i2)
    {
        wxUniCharRef r1 = *i1;
        wxUniCharRef r2 = *i2;
        std::swap(r1, r2);
    }
}

#endif // CPP11_H_INCLUDED
