#ifndef ALPHABEATCREATINGRESPONSE_H
#define ALPHABEATCREATINGRESPONSE_H

#include "tools/database/DataBaseResponse.h"
#include "model/Alphabeat.h"

namespace database
{
    class AlphabeatCreatingResponse : public tools::database::DataBaseResponse
    {
        public:
            /** Default constructor */
            AlphabeatCreatingResponse(bool isOk, model::Alphabeat* alphabeat);
            /** Default destructor */
            virtual ~AlphabeatCreatingResponse();

            model::Alphabeat* getAlphabeat();

        protected:

        private:
            model::Alphabeat* m_alphabeat;
    };
}

#endif // ALPHABEATCREATINGRESPONSE_H
