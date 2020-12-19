//
// Created by denis on 13.08.2020.
//

#include "date.h"


Date::Date(int new_year, int new_month, int new_day) {
    year = new_year;
    if (new_month > 12 || new_month < 1) {
        throw logic_error("Month value is invalid: " + to_string(new_month));
    }
    month = new_month;
    if (new_day > 31 || new_day < 1) {
        throw logic_error("Day value is invalid: " + to_string(new_day));
    }
    day = new_day;
}

int Date::GetYear() const {
    return year;
}
int Date::GetMonth() const {
    return month;
}
int Date::GetDay() const {
    return day;
}

Date ParseDate(istream& is) {
    bool ok = true;

    int year_;
    ok = ok && (is >> year_);
    ok = ok && (is.peek() == '-');
    is.ignore(1);

    int month_;
    ok = ok && (is >> month_);
    ok = ok && (is.peek() == '-');
    is.ignore(1);

    int day_;
    ok = ok && (is >> day_);
    //ok = ok && is.eof();

    if (!ok) {
        throw logic_error("...");
    } else {
        return Date(year_, month_, day_);
    }
}

ostream& operator<<(ostream& os, const Date& date) {
    os << setw(4) << setfill('0') << date.GetYear() <<
       "-" << setw(2) << setfill('0') << date.GetMonth() <<
       "-" << setw(2) << setfill('0') << date.GetDay();
    return os;
}

bool operator<(const Date& lhs, const Date& rhs) {
    tuple<int, int, int> left = make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay());
    tuple<int, int, int> right = make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
    return left < right;
}

bool operator>(const Date& lhs, const Date& rhs) {
    tuple<int, int, int> left = make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay());
    tuple<int, int, int> right = make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
    return left > right;
}