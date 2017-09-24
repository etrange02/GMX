#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "tools/database/DataBaseManager.h"

class Mediator
{
    public:
        /** Default constructor */
        Mediator();
        /** Default destructor */
        virtual ~Mediator();

        tools::database::DataBaseManager& getDatabase();

    protected:

    private:
        tools::database::DataBaseManager m_database;
};

#endif // MEDIATOR_H
