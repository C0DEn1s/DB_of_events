//
// Created by denis on 13.08.2020.
//

#ifndef FINAL_DATE_H
#define FINAL_DATE_H

#include <iostream>
#include <iomanip>
#include <tuple>
using namespace std;

class Date {
public:
    Date(int year_, int month_, int day_);
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
private:
    int year;
    int month;
    int day;
};

Date ParseDate(istream& is);

ostream& operator<<(ostream& os, const Date& d);

bool operator<(const Date& lhs, const Date& rhs);

bool operator>(const Date& lhs, const Date& rhs);

#endif //FINAL_DATE_H
