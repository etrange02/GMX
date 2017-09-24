#ifndef ALPHABEATREADINGRESPONSE_H
#define ALPHABEATREADINGRESPONSE_H

#include <vector>
#include "tools/database/DataBaseResponse.h"
#include "model/Alphabeat.h"

namespace database
{
    class AlphabeatReadingResponse : public tools::database::DataBaseResponse
    {
        public:
            /** Default constructor */
            AlphabeatReadingResponse(bool isOk, std::vector<model::Alphabeat*>* alphabeats);
            /** Default destructor */
            virtual ~AlphabeatReadingResponse();

            std::vector<model::Alphabeat*>* getAlphabeats();

        protected:

        private:
            std::vector<model::Alphabeat*>* m_alphabeats;
    };
}

#endif // ALPHABEATREADINGRESPONSE_H
