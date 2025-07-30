#pragma once
#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
private:
    int days;
    int hours;
    int minutes;
    int seconds;

    void normalize();  // Helper to ensure values are within bounds

public:
    // Constructors
    Time();
    Time(int d, int h, int m, int s);
    Time(int h, int m, int s);
    Time(int h, int m);
    Time(const Time& time);  // Copy constructor

    // Getters
    int getDays() const;
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    // Setters
    void setDays(int d);
    void setHours(int h);
    void setMinutes(int m);
    void setSeconds(int s);

    // Assignment
    Time& operator=(const Time& right);

    // Arithmetic
    Time operator+(const Time& right) const;
    Time operator-(const Time& right) const;

    // Relational Operators
    bool operator>(const Time& right) const;
    bool operator<(const Time& right) const;
    bool operator>=(const Time& right) const;
    bool operator<=(const Time& right) const;
    bool operator==(const Time& right) const;
    bool operator!=(const Time& right) const;

    // Output Stream
    friend std::ostream& operator<<(std::ostream& stream, const Time& right);

    // Conversion to int (seconds)
    operator int() const;
};

#endif
