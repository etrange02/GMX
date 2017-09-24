#ifndef GUEMATRICNUMBER_H
#define GUEMATRICNUMBER_H

namespace word
{
    class GuematricNumber
    {
        public:
            /** Default constructor */
            GuematricNumber(int guematric);
            /** Default destructor */
            virtual ~GuematricNumber();

            int getGuematric() const;
            int getTransreal() const;

        protected:

        private:
            int m_guematric;
            int m_transreal;
    };
}

#endif // GUEMATRICNUMBER_H
