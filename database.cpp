//
// Created by denis on 13.08.2020.
//

#include "database.h"

Database::Database() = default;

void Database::Add(Date date, const string &event) {
    if (db[date].insert(event).second) {
        order_db[date].push_back(event);
    }
    else {
        if (db.find(date) == db.end()) {
            db[date].insert(event);
        }
        if (order_db.find(date) == order_db.end()) {
            order_db[date].push_back(event);
        }
    }
}

void Database::Print(ostream &os) const {
    if (order_db.empty()) {
        return;
    }
    for (const auto& [date, events] : order_db) {
        for (const auto& event : events) {
            os << date << ' ' << event << endl;
        }
    }
}

pair<Date, string> Database::Last(Date date) const {
    if (order_db.empty()) {
        throw invalid_argument("");
    }
    try {
        if (order_db.at(date).empty()) {
            throw invalid_argument("");
        }
        return make_pair(date, *order_db.at(date).rbegin());
    } catch (out_of_range&) {}

    auto it = order_db.upper_bound(date);
    if (it == order_db.begin()) {
        throw invalid_argument("");
    } else {
        it--;
        if (!it->second.empty()) {
            return make_pair(it->first, *it->second.rbegin());
        }
        else {
            throw invalid_argument("");
        }
    }
}

ostream& operator<<(ostream& os, const pair<Date,string>& p) {
    os << p.first << ' ' << p.second;
    return os;
}