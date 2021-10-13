#ifndef __Session_H_
#define __Session_H_

#include "Person.h"

class Session
{
    private:

    public:
    Person signup();
    Person& signin(Person&);
    void addRequest(std::string, std::string);
    void addFriend(std::string, std::string);



};
#endif