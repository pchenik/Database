

#include <iostream>
#include <string>
#include <iomanip>
//#include <tuple>

#include "date.h"

using namespace std;

ostream& operator<<(ostream& os, const Date& date) {
    os << setfill('0');
    os << setw(4) << abs(date.GetYear()) <<  '-' << setw(2) << date.GetMonth() << "-" <<
       setw(2) << date.GetDay();
    return os;
};


ostream& operator<<(ostream& os, const pair<Date, string>& date) {
    os << date.first << " " << date.second;
    return os;
};

Date ParseDate(istream& is) {
    int year, month, day;
    is >> year;
    is.ignore(1);
    is >> month;
    is.ignore(1);
    is >> day;
    is.ignore(1);
    return Date(year, month, day);
}

bool operator<(const Date& lhs, const Date& rhs) {
    return lhs.GetYear() < rhs.GetYear() || (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() < rhs.GetMonth()) ||
           (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() < rhs.GetDay());
   // return std::tie(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) < std::tie(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator==(const Date& lhs, const Date& rhs) {
    return  lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay() ;
}

bool operator>(const Date& lhs, const Date& rhs) {
    return !(lhs < rhs || lhs == rhs);
};