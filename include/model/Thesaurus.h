#ifndef THESAURUS_H
#define THESAURUS_H

#include <wx/wx.h>
#include <vector>

namespace model
{
    class Thesaurus
    {
        public:
            /** Default constructor */
            Thesaurus(int id);
            /** Default destructor */
            virtual ~Thesaurus();

            std::vector<wxString>& getWords();

        protected:

        private:
            int m_id;
            std::vector<wxString> m_words;
    };
}

#endif // THESAURUS_H
