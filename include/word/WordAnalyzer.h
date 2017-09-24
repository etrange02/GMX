#ifndef WORDANALYZER_H
#define WORDANALYZER_H

#include <wx/wx.h>
#include "model/ValuedSet.h"

namespace word
{
    class WordAnalyzer
    {
        public:
            /** Default constructor */
            WordAnalyzer(const model::ValuedSet& valuedSet);
            /** Default destructor */
            virtual ~WordAnalyzer();

            void operator()(wxString::iterator::reference letter);
            int getValue();
            const wxString& getAnalyzedWord();

        protected:

        private:
            int m_value;
            wxString m_analyzedWord;
            const model::ValuedSet& m_valuedSet;
    };
}

#endif // WORDANALYZER_H
