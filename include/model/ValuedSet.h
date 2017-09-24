#ifndef VALUEDSET_H
#define VALUEDSET_H

#include <wx/wx.h>
#include <vector>
#include "model/ValuedLetter.h"

namespace model
{
    class ValuedSet
    {
        public:
            /** Constructor */
            ValuedSet(int id, const wxString& name);
            /** Default destructor */
            virtual ~ValuedSet();

            const wxString& getName() const;
            int getId() const;
            std::vector<ValuedLetter*>& getValuedLetters();
            const std::vector<ValuedLetter*>& getValuedLetters() const;

        protected:

        private:
            int m_id;
            wxString m_name;
            std::vector<ValuedLetter*> m_valuedLetters;
    };
}

#endif // VALUEDSET_H
