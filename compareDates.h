//
//  compareDates.h
//  Basic
//
//  Created by Eirik Hanasand on 03/10/2022.
//

#ifndef compareDates_h
#define compareDates_h

//Struct for storing time of day 1
struct time {
    int hour;
    int minute;
    int second;
};

//Struct for storing time of day 2
struct time2 {
    int hour;
    int minute;
    int second;
};

//Struct for storing date 1
struct date {
    int day;
    int month;
    int year;
    struct time t;
};

//Struct for storing date 2
struct date2 {
    int day;
    int month;
    int year;
    struct time2 t2;
};
#endif /* compareDates_h */
