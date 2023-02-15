#include "date.hpp"

int main()
{
    int year, month, day, type;
    Date* date = new Date;
    while(1)
    {
        cout << "선택지를 고르시오(1~6)[1: 날짜 입력, 2: 년 추가, 3: 월 추가, 4: 일 추가, 5: 날짜 확인, 6: 종료]"<<endl;
        cout << "입력 : ";
        cin >> type;
        switch (type)
        {
        case 1:
            cout << "날짜를 입력하시오(년 월 일 순으로 입력하세요)";
            cout << "입력(공백으로 구분) : ";
            cin >> year >> month >> day;
            date->SetDate(year, month, day);
            break;
        case 2:
            cout << "날짜에 추가할 년을 입력하시오";
            cout << "입력 : ";
            cin >> year;
            date->AddYear(year);
            break;
        case 3:
            cout << "날짜에 추가할 월을 입력하시오";
            cout << "입력 : ";
            cin >> month;
            date->AddMonth(month);
            break;
        case 4:
            cout << "날짜에 추가할 일을 입력하시오";
            cout << "입력 : ";
            cin >> day;
            date->AddDay(day);
            break;
        case 5:
            date->ShowDate();
            break;
        case 6:
            cout << "종료합니다."<< endl;
            delete date;
            return 0;
        default:
            break;
        }
    }
}