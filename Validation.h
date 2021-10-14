#ifndef __VALIDATION_H_
#define __VALIDATION_H_

#include <string>
#include <vector>

class Validation
{
    private:
    static std::vector<int> convertDates(std::string);

    public:
    static bool validateRequest(std::string, std::string);
    static bool existingUser (std::string);
    static bool newDestination(std::string);
    static bool uniqueUser(std::string);
    static bool validTimePeriod(std::string);
    static bool validGrade(int);
    static bool validImages(std::string);

    

};

#endif