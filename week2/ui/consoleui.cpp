#include "ui/consoleui.h"
#include "utilities/constants.h"
#include "utilities/utils.h"

#include <iostream>
#include <iomanip>

using namespace std;

ConsoleUI::ConsoleUI()
{
    lastCommand = command::menu;
    sortBy = "name";
    sortAscending = true;
}

int ConsoleUI::start()
{
    while(lastCommand != command::quit)
    {
        display();
        readInput();
    }

    return 0;
}

void ConsoleUI::display()
{
    switch (lastCommand)
    {
        case command::menu:
            displayMenu();
            break;
        case command::add:
            displayAddScientistMenu();
            break;
        case command::display:
            displayAllScientists();
            break;
        case command::search:
            displayScientistSearchMenu();
            break;
        case command::sort:
            displayScientistSortMenu();
            break;
        default:
            displayUnknownCommandMenu();
            break;
    }
}

void ConsoleUI::readInput()
{
    if (lastCommand == command::display)
    {
        lastCommand = command::sort;
        return;
    }

    string userInput;
    getline(cin, userInput);

    cout << "\n\n";

    bool shouldTreatInputAsCommand = (lastCommand != command::search);

    if (userInput == "2" && shouldTreatInputAsCommand)
    {
        lastCommand = command::sort;
    }
    else if (userInput == "1" && shouldTreatInputAsCommand)
    {
        lastCommand = command::add;
    }
    else if (userInput == "3" && shouldTreatInputAsCommand)
    {
        lastCommand = command::search;
    }
    else if (userInput == "back")
    {
        lastCommand = command::menu;
    }
    else if (userInput == "4")
    {
        lastCommand = command::quit;
    }
    else
    {
        if (lastCommand == command::add)
        {
            addCommandHandler(userInput);
        }
        else if (lastCommand == command::sort)
        {
            sortCommandHandler(userInput);
        }
        else if (lastCommand == command::search)
        {
            searchCommandHandler(userInput);
        }
        else
        {
            lastCommand = command::unknown;
        }
    }
}

void ConsoleUI::addCommandHandler(string userInput)
{
    enum addStatus status = addScientist(userInput);
    if ( status == addStatus::success) {
        cout << "Successfully added a scientist\n\n";
        lastCommand = command::menu;
    }
    else
    {
        switch(status)
        {
        case addStatus::nameMissing:
            cout << "The name is required" << endl;
            break;
        case addStatus::yearBornMissing:
            cout << "You must specify when the scientist was born" << endl;
            break;
        case addStatus::yearDiedBeforeYearBorn:
            cout << "The scientist cannot be born after (s)he died!" << endl;
            break;
        case addStatus::invalidInput:
            cout << "Check your input - type in 3 or 4 values, separated by commas" << endl;
            break;
        default:
            cout << "There was an error adding the scientist. Sorry for that :/" << endl;
            break;
        }
    }
}

void ConsoleUI::sortCommandHandler(string userInput)
{
    if (setSort(userInput))
    {
        lastCommand = command::display;
    }
    else
    {
        displayError("Your input did not match any of the sort commands");
    }
}

void ConsoleUI::searchCommandHandler(string userInput)
{
    displayScientists(scientistService.searchForScientists(userInput));
}

void ConsoleUI::displayMenu()
{
    system("CLS");
    cout << " ------------------------------------------------------" << endl;
    cout << "|            Computer Scientist Database               |" << endl;
    cout << " ------------------------------------------------------\n" << endl;
    cout << "Please choose a number from 1-4:\n" << endl;

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "1." << "Adds a scientist\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "2." << "Displays scientists\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "3." << "Search for a scientist\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "4." << "Quits the program\n\n";

    cout << "Command: ";
}

void ConsoleUI::displayAddScientistMenu()
{
    cout << "To add a scientist, type in:\n";
    cout << "Name,gender,yearBorn,yearDied (optional)\n";
    cout << "Comma separated like in the example above.\n\n";
    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}

void ConsoleUI::displayAllScientists()
{
    vector<Scientist> scientists = scientistService.getAllScientists(sortBy, sortAscending);

    displayScientists(scientists);

    cout << '\n';

    lastCommand = command::display;
}

void ConsoleUI::displayScientistSearchMenu()
{
    cout << "Search for a scientist.\n\n";

    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}

void ConsoleUI::displayScientistSortMenu()
{
    cout << "How should the list be sorted:\n\n";
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_NAME_ASCENDING << "Sorts by name, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_NAME_DESCENDING << "Sorts by name, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_BORN_ASCENDING << "Sorts by year born, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_BORN_DESCENDING << "Sorts by year born, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_DIED_ASCENDING << "Sorts by year died, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_DIED_DESCENDING << "Sorts by year died, descending.\n\n";

    cout << "If you would like to go back to the main menu, please type: back\n";

    cout << "Command: ";
}

void ConsoleUI::displayUnknownCommandMenu()
{
    displayError("Unknown command");
    cout << "Command: ";
}

void ConsoleUI::displayScientists(std::vector<Scientist> scientists)
{
    if (scientists.size() == 0)
    {
        cout << "No scientist found.\n";
        return;
    }

    system("CLS");
    cout << "------------------------------------------------------" << endl;
    cout << "             Computer Scientist Database                " << endl;
    cout << "======================================================" << endl;
    cout << setw(20) << std::left << "Name"
         << setw(8) << std::left << "Gender"
         << setw(12) << std::left << "Year born"
         << setw(12) << std::left << "Year died" << endl;
    cout << "------------------------------------------------------" << endl;

    for (unsigned int i = 0; i < scientists.size(); i++)
    {

        int yearDied = scientists.at(i).getYearDied();
        string died = (yearDied == constants::YEAR_DIED_DEFAULT_VALUE) ? "Alive" : utils::intToString(yearDied);

        cout << setw(20) << std::left << scientists.at(i).getFirstName()
             << setw(8) << std::left << scientists.at(i).getGender()
             << setw(12) << std::left << scientists.at(i).getYearBorn()
             << setw(12) << std::left << died << endl;
    }
    cout << "------------------------------------------------------" << endl;
}

enum addStatus ConsoleUI::addScientist(string data)
{
    vector<string> fields = utils::splitString(data, ',');

    // General validation of input, i.e. check if the number of parameters
    // entered by the user is within the expected range:
    if (fields.size() > 2 && fields.size() < 7)
    {
        int id = stoi(fields.at(0));
        string firstName = fields.at(1);
        string secondName = fields.at(2);

        // A very simplistic implementation of gender selection.
        // We could of course offer more options, but to keep this
        // simple, we won't.
        string gender = fields.at(2);
        int yearBorn = utils::stringToInt(fields.at(4));

        if (fields.size() == 5)
        {
            return scientistService.addScientist(Scientist(id, firstName, secondName, gender, yearBorn));
        }
        else
        {
            int yearDied = utils::stringToInt(fields.at(5));

            return scientistService.addScientist(Scientist(id, firstName, secondName, gender, yearBorn, yearDied));
        }
    }

    return addStatus::invalidInput;
}

bool ConsoleUI::setSort(string sortCommand)
{
    if (sortCommand == constants::SORT_SCIENTIST_NAME_ASCENDING)
    {
        sortBy = "name";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_NAME_DESCENDING)
    {
        sortBy = "name";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_BORN_ASCENDING)
    {
        sortBy = "yearBorn";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_BORN_DESCENDING)
    {
        sortBy = "yearBorn";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_DIED_ASCENDING)
    {
        sortBy = "yearDied";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_DIED_DESCENDING)
    {
        sortBy = "yearDied";
        sortAscending = false;
    }
    else
    {
        return false;
    }

    return true;
}

void ConsoleUI::displayError(string error)
{
    cout << "There was an error: " << error << "\n";
    cout << "Please try again or type 'back' to go back.\n\n";
}
