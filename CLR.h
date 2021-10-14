#ifndef __CLR_H_
#define __CLR_H_

#include "Person.h"
#include "Session.h"

#include <string>
class CLR
{
    private:
    Person user;
    Session currentSession;
    std::string command;

    public:
    void read();
    void logging();
    void profile();
    void friendRequest();
    void accept();
    void decline();
    void review();
    void view();
    void help();


};
#endif