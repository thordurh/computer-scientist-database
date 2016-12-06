#include "models/scientist.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

using namespace std;

Scientist::Scientist(int id, string firstName, string secondName, string gender, int yearBorn)
{
    _id = id;
    _firstName = firstName;
    _secondName = secondName;
    _gender = gender;
    _yearBorn = yearBorn;
    _yearDied = constants::YEAR_DIED_DEFAULT_VALUE;
}

Scientist::Scientist(int id, string firstName, string secondName, string gender, int yearBorn, int yearDied)
{
    _id = id;
    _firstName = firstName;
    _secondName = secondName;
    _gender = gender;
    _yearBorn = yearBorn;
    _yearDied = yearDied;
}

std::string Scientist::getFirstName() const
{
    return _firstName;
}
std::string Scientist::getSecondName() const
{
    return _secondName;
}

string Scientist::getGender() const
{
    return _gender;
}

int Scientist::getYearBorn() const
{
    return _yearBorn;
}

int Scientist::getYearDied() const
{
    return _yearDied;
}

bool Scientist::contains(string searchTerm)
{
    string searchTermLower = utils::stringToLower(searchTerm);

    string firstNameLower = utils::stringToLower(_firstName);
    string secondNameLower = utils::stringToLower(_secondName);
    if (firstNameLower.find(searchTermLower) != string::npos)
    {
        return true;
    }
    if (secondNameLower.find(searchTermLower) != string::npos)
    {
        return true;
    }

    string genderString = utils::stringToLower(_gender);

    if (genderString.find(searchTermLower) != string::npos)
    {
        return true;
    }

    string yearBornString = utils::intToString(_yearBorn);

    if (yearBornString.find(searchTerm) != string::npos)
    {
        return true;
    }

    if (_yearDied != constants::YEAR_DIED_DEFAULT_VALUE)
    {
        string yearDiedString = utils::intToString(_yearDied);

        if (yearDiedString.find(searchTerm) != string::npos)
        {
            return true;
        }
    }
    else
    {
        if (searchTermLower == "alive")
        {
            return true;
        }
    }

    return false;
}
