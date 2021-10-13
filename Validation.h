#ifndef __VALIDATION_H_
#define __VALIDATION_H_

#include <string>

class Validation
{
    private:

    public:
    static bool validateRequest(std::string, std::string);
    static bool existingUser (std::string);
    static bool newDestination(std::string);

};

#endif