#ifndef ALPHABEATREADINGREQUEST_H
#define ALPHABEATREADINGREQUEST_H

#include "tools/database/DataBaseRequest.h"

namespace database
{
    class AlphabeatReadingRequest : public tools::database::DataBaseRequest
    {
        public:
            /** Default constructor */
            AlphabeatReadingRequest();
            /** Default destructor */
            virtual ~AlphabeatReadingRequest();

        protected:
            virtual tools::database::DataBaseResponse* execute(tools::database::DataBaseManager& dataBaseManager);

        private:
    };
}

#endif // ALPHABEATREADINGREQUEST_H
