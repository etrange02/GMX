#ifndef ALPHABEAT_H
#define ALPHABEAT_H

#include <wx/wx.h>
#include <vector>
#include "model/Thesaurus.h"
#include "model/ValuedSet.h"

namespace model
{
    class Alphabeat
    {
        public:
            /** Default constructor */
            Alphabeat();
            Alphabeat(int id, const wxString& letters);
            /** Default destructor */
            virtual ~Alphabeat();

            int getId() const;
            std::vector<Thesaurus>& thesauruses();
            std::vector<ValuedSet>& valuedSets();

        protected:

        private:
            int m_id;
            wxString m_letters;
            std::vector<Thesaurus> m_thesauruses;
            std::vector<ValuedSet> m_valuedSets;
    };
}

#endif // ALPHABEAT_H
