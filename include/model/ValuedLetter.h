#ifndef VALUEDLETTER_H
#define VALUEDLETTER_H

#include <wx/wx.h>

namespace model
{
    class ValuedLetter
    {
        public:
            /** Default constructor */
            ValuedLetter(int id, const wxString& letter, int value);
            /** Default destructor */
            virtual ~ValuedLetter();

            int getId() const;
            const wxString& getLetter() const;
            int getValue() const;

        protected:

        private:
            int m_id;
            wxString m_letter;
            int m_value;
    };
}

#endif // VALUEDLETTER_H
