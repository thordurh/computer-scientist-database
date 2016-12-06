#include "repositories/scientistrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"


#include <fstream>
#include <cstdlib>
#include <QtSql>
using namespace std;

vector<Scientist> ScientistRepository::getAllScientists()
{
    vector <Scientist> scientists;
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "computer_science.sqlite";
    db.setDatabaseName(dbName);

    db.open();
    QSqlQuery query(db);
    query.exec("SELECT * FROM computer_scientist");

    while(query.next()){
    int id = query.value("id").toUInt();
    string first_name = query.value("first_name").toString().toStdString();
    string second_name = query.value("second_name").toString().toStdString();
    string gender = query.value("gender").toString().toStdString();
    int birth_year = query.value("birth_year").toUInt();
    int death_year = query.value("death_year").toUInt();


    scientists.push_back(Scientist(id, first_name, second_name, gender, birth_year, death_year));
    return scientists;
    }

}
