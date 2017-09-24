#ifndef ALPHABEATCREATINGREQUEST_H
#define ALPHABEATCREATINGREQUEST_H

#include "tools/database/DataBaseRequest.h"

/**
 * Namespace of database tools
 */
namespace database
{
    class AlphabeatCreatingRequest : public tools::database::DataBaseRequest
    {
        public:
            /** Default constructor */
            AlphabeatCreatingRequest(const wxString& alphabeat);
            /** Default destructor */
            virtual ~AlphabeatCreatingRequest();

            protected:
                virtual tools::database::DataBaseResponse* execute(tools::database::DataBaseManager& dataBaseManager);

        private:
            wxString m_alphabeat;
    };
}

#endif // ALPHABEATCREATINGREQUEST_H
