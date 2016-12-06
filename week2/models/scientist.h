#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

/**
 * @brief The data model for scientists
 */
class Scientist
{
public:
    Scientist(int id, std::string firstName, std::string secondName, std::string genderType, int yearBorn);
    Scientist(int id, std::string firstName, std::string secondName, std::string genderType, int yearBorn, int yearDied);

    std::string getFirstName() const;
    std::string getSecondName() const;
    std::string getGender() const;
    int getYearBorn() const;
    int getYearDied() const;

    bool contains(std::string searchTerm);

private:
    int _id;
    std::string _firstName;
    std::string _secondName;
    std::string _gender;
    int _yearBorn;
    int _yearDied;
};

#endif // SCIENTIST_H
