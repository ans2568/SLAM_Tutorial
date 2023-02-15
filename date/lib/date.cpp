#include "date.hpp"

void Date::SetDate(int year, int month, int date)
{
    year_ = year;
    if (month > 12)
    {
        cout << "월은 12월을 넘길 수 없습니다." << endl;
        return;
    }
    else
        month_ = month;
    if (lastday_[month - 1] < date)
    {
        cout << to_string(month) + "월에는 " + to_string(date) + "일이 없습니다." << endl;
        return;
    }
    else
        day_ = date;
}

void Date::AddDay(int inc)
{
    if (month_ != NULL && lastday_[month_ - 1] < inc)
    {
        cout << to_string(month_) + "월에는 " + to_string(inc) + "일이 없습니다." << endl;
        return;
    }
    else
        day_ = inc;
}

void Date::AddMonth(int inc)
{
    if (inc > 12)
    {
        cout << "월은 12월을 넘길 수 없습니다." << endl;
        return;
    }
    else
        month_ = inc;
}

void Date::AddYear(int inc)
{
    year_ = inc;
}

void Date::ShowDate()
{
    if (year_ != NULL || month_ != NULL || day_ != NULL)
    {
        cout << to_string(year_) + "년" << endl;
        cout << to_string(month_) + "월" << endl;
        cout << to_string(day_) + "일" << endl;
    }
}