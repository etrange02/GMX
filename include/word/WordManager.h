#ifndef WORDMANAGER_H
#define WORDMANAGER_H

#include <wx/wx.h>
#include <vector>
#include "model/ValuedSet.h"
#include "word/GuematricNumber.h"

namespace word
{
    class WordManager
    {
        public:
            /** Default constructor */
            WordManager();
            /** Default destructor */
            virtual ~WordManager();

            void setWord(const wxString& word);
            const wxString& getAnalysedWord() const;
            int getValue() const;
            const std::vector<GuematricNumber*> getGuematricNumbers() const;

        protected:

        private:
            void analyse();
            void clearGuematricNumbers();
            void clearValuedSet();

        private:
            wxString m_word;
            wxString m_analysedWord;
            model::ValuedSet* m_selectedValuedSet;
            std::vector<model::ValuedSet*> m_valuedSets;
            std::vector<GuematricNumber*> m_guematricNumbers;
            int m_value;
    };
}

template<typename T>
bool deleteAll(T& item) { delete item; return true; }

template<typename T>
void clearContainer(std::vector<T>& vect)
{
    if (std::is_pointer<T>::value)
        std::remove_if(vect.begin(), vect.end(), deleteAll<T>);
    //else
        vect.clear();
}

#endif // WORDMANAGER_H
