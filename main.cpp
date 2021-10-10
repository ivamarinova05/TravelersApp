#include "Trip.h"
#include "Person.h"
#include "CommandLineReader.h"
int main()
{
    /*Trip t;
    t.addTrip();
    t.printTrip();
    Person p;
    p.createPerson();
    p.addTrip();
    p.addTrip();
    p.addTrip();
    //p.printPerson();*/
    Person p;
    CLR c;
    //c.signup();
    p = c.signin();
    p.printPerson();


    return 0;
}