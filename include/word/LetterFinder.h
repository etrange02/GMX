#ifndef LETTERFINDER_H
#define LETTERFINDER_H

#include <wx/wx.h>
#include <vector>
#include "model/ValuedLetter.h"

namespace word
{
    class LetterFinder
    {
        public:
            /** Default constructor */
            LetterFinder(const wxUniChar& letter);
            /** Default destructor */
            virtual ~LetterFinder();

            bool operator()(const model::ValuedLetter* element);

        protected:

        private:
            wxString m_letter;
    };
}

#endif // LETTERFINDER_H
