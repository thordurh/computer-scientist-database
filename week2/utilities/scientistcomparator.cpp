#include "utilities/scientistcomparator.h"

ScientistComparator::ScientistComparator(std::string column, bool sortInAscendingOrder)
{
    this->sortColumn = column;
    this->sortInAscendingOrder = sortInAscendingOrder;
}

bool ScientistComparator::operator() (const Scientist& first, const Scientist& second)
{
    if (sortColumn == "firstName")
    {
        if (sortInAscendingOrder)
        {
            return first.getFirstName() < second.getFirstName();
        }
        else
        {
            return second.getFirstName() < first.getFirstName();
        }
    }
    else if (sortColumn == "yearBorn")
    {
        if (sortInAscendingOrder)
        {
            return first.getYearBorn() < second.getYearBorn();
        }
        else
        {
            return second.getYearBorn() < first.getYearBorn();
        }
    }

    return false;
}



