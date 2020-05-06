//
// Created by Никита on 20.02.2020.
//

#ifndef FINAL_YELLOW_DATE_H
#define FINAL_YELLOW_DATE_H

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

class Date {
public:
    Date () {}
    Date(int year, int month, int day) : year(year), month(month), day(day) {}
    int GetYear() const {return year;};
    int GetMonth() const {return month;};
    int GetDay() const {return day;};
private:
    int year, month, day;
};

ostream& operator<<(ostream& os, const Date& date);
ostream& operator<<(ostream& os, const pair<Date, string>& date);
Date ParseDate(istream& is);
bool operator<(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);

#endif //FINAL_YELLOW_DATE_H
