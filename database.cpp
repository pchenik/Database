

#include "date.h"
#include "database.h"

using  namespace std;

void Database::Add(const Date& date, const string& event) {
    if (events_set[date].find(event) == events_set[date].end()) {
        events_vector[date].push_back(event);
        events_set[date].insert(event);
    }
};

string Database::Last(const Date& date) const {
    stringstream ss;
    if (events_vector.empty())
        throw invalid_argument("");
    auto it = events_vector.lower_bound(date);
    if (it == events_vector.begin() && !(it->first == date))
        throw invalid_argument("");
    else if (it->first == date)
        ss << (it)->first << " " << (it)->second.back();
    else
        ss << (--it)->first << " " << it->second.back();
    return ss.str();
};

void Database::Print(ostream& os) const {
    for (const auto& [key, value]: events_vector) {
        for (const auto& event: value)
            os << key << " " << event << endl;
    }
};
