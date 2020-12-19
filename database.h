//
// Created by denis on 13.08.2020.
//

#ifndef FINAL_DATABASE_H
#define FINAL_DATABASE_H

#include "date.h"
#include <string>
#include <set>
#include <map>
#include <functional>

class Database {
public:
    Database();
    void Add(Date date, const string& event);
    void Print(ostream& os) const;
    template <typename T>
    int RemoveIf(T Func) {
        int count = 0;
        auto it = order_db.begin();
        while (it != order_db.end()) {
            const auto& date = it->first;
            auto border = stable_partition(it->second.begin(), it->second.end(),
                                           [date, Func](const string& event) {
                    return Func(date, event);
            });
            for (auto i = it->second.begin(); i != border; ++i) {
                db[date].erase(*i);
                ++count;
            }
            order_db[date].erase(it->second.begin(), border);
            ++it;
        }
        vector<Date> dates;
        for (auto it = db.begin(); it != db.end(); ++it) {
            if (it->second.empty()) {
                order_db.erase(it->first);
                dates.push_back(it->first);
            }
        }
        for (auto it = dates.begin(); it != dates.end(); ++it) {
            db.erase(*it);
        }
        dates.clear();
        return count;
    }
    template<typename T>
    vector<pair<Date, string>> FindIf(T Func) const {
        vector<pair<Date, string>> result;
        for (auto it = order_db.begin(); it != order_db.end(); ++it) {
            const Date date = it->first;
            auto beginIt = it->second.begin();
            auto endIt = it->second.end();
            while (beginIt != endIt) {
                auto temp = find_if(beginIt, endIt, [date, Func](const string& event) {
                    return Func(date, event);
                });
                if (temp != endIt) {
                    result.push_back({date, *temp});
                    temp++;
                }
                beginIt = temp;
            }
        }
        return result;
    }
    pair<Date, string> Last(Date date) const;
private:
    map<Date, set<string>> db;
    map<Date, vector<string>> order_db;
};

ostream& operator<<(ostream& os, const pair<Date, string>& p);

#endif //FINAL_DATABASE_H
