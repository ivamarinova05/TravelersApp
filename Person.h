#ifndef __PERSON_H_
#define __PERSON_H_

#include "Trip.h"

#include <vector>

class Person
{
    private:
    std::string username;
    std::string password;
    std::string email;
    std::vector<Trip> trips;

    public:
    void createPerson();
    void printPerson();
    void addTrip();
    void savePerson();

};

#endif