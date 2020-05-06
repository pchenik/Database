

#ifndef FINAL_YELLOW_DATABASE_H
#define FINAL_YELLOW_DATABASE_H

#include "date.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using  namespace std;

struct MapComparator {
    // opt into being transparent comparator
    //using is_transparent = void;
    inline bool operator()(Date const& lhs, Date const& rhs) const {
        return lhs < rhs;
    }
    //inline bool operator()(const pair<Date, vector<string> >& lhs, const pair<Date, vector<string> >& rhs) const {
    //    return lhs.first < rhs.first || ;
    //}
};


class Database {
public:
    void Add(const Date& date, const string& event);

    template<typename Predicate>
    vector<pair<Date, string> > FindIf(Predicate func) const;

    template<typename Predicate>
    int RemoveIf(Predicate func);

    //pair<Date, string> Last(const Date& date) const;
    string Last(const Date& date) const;

    void Print(ostream& os) const;

private:
    map<Date, set<string>, MapComparator> events_set;
    map<Date, vector<string>, MapComparator> events_vector;
};

template<typename Predicate>
vector<pair<Date, string> > Database::FindIf(Predicate func) const {
    vector<pair<Date, string> > res_find_if;
    for (const auto& [key, value]: events_vector)
        for (const auto& event: value)
            if (func(key, event))
                res_find_if.emplace_back(key, event);

    return res_find_if;
};

template<typename Predicate>
int Database::RemoveIf(Predicate func) {
    //set's deleted part
    int del_cnt = 0;
    for (const auto& [key, value]: events_set) {
        for (const auto &event: value)
            if (func(key, event))
                del_cnt++;
        set<string> new_set;
        auto key_copy = key;
        auto predicate = [key_copy, func](const string& event) {
            return !func(key_copy, event);
        };
        copy_if(value.begin(), value.end(), inserter(new_set, new_set.begin()), predicate);
        events_set[key] = new_set;
    }

    //vector's deleted part
    for (auto& [key, value]: events_vector) {
        auto key_copy = key;
        auto predicate = [key_copy, func](const string& event) {
            return !func(key_copy, event);
        };
        auto it = stable_partition(value.begin(), value.end(), predicate);
        value.erase(it, value.end());
    }

    for(auto iter = events_set.begin(); iter != events_set.end(); ) {
        if (iter->second.empty()) {
            iter = events_set.erase(iter);
        } else {
            ++iter;
        }
    }

    for(auto iter = events_vector.begin(); iter != events_vector.end(); ) {
        if (iter->second.empty()) {
            iter = events_vector.erase(iter);
        } else {
            ++iter;
        }
    }

    return del_cnt;
};

#endif //FINAL_YELLOW_DATABASE_H
