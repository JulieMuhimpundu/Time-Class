#include "Time.h"

// Normalize function
void Time::normalize() {
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    if (hours >= 24) {
        days += hours / 24;
        hours %= 24;
    }

    // Handle underflow for subtraction
    while (seconds < 0) {
        seconds += 60;
        minutes--;
    }
    while (minutes < 0) {
        minutes += 60;
        hours--;
    }
    while (hours < 0) {
        hours += 24;
        days--;
    }
}

// Constructors
Time::Time() : days(0), hours(0), minutes(0), seconds(0) {}

Time::Time(int d, int h, int m, int s) : days(d), hours(h), minutes(m), seconds(s) {
    normalize();
}

Time::Time(int h, int m, int s) : days(0), hours(h), minutes(m), seconds(s) {
    normalize();
}

Time::Time(int h, int m) : days(0), hours(h), minutes(m), seconds(0) {
    normalize();
}

Time::Time(const Time& time) {
    days = time.days;
    hours = time.hours;
    minutes = time.minutes;
    seconds = time.seconds;
}

// Getters
int Time::getDays() const { return days; }
int Time::getHours() const { return hours; }
int Time::getMinutes() const { return minutes; }
int Time::getSeconds() const { return seconds; }

// Setters
void Time::setDays(int d) { days = d; }
void Time::setHours(int h) { hours = h; normalize(); }
void Time::setMinutes(int m) { minutes = m; normalize(); }
void Time::setSeconds(int s) { seconds = s; normalize(); }

// Assignment
Time& Time::operator=(const Time& right) {
    if (this != &right) {
        days = right.days;
        hours = right.hours;
        minutes = right.minutes;
        seconds = right.seconds;
    }
    return *this;
}

// Arithmetic
Time Time::operator+(const Time& right) const {
    Time result;
    result.seconds = seconds + right.seconds;
    result.minutes = minutes + right.minutes;
    result.hours = hours + right.hours;
    result.days = days + right.days;
    result.normalize();
    return result;
}

Time Time::operator-(const Time& right) const {
    Time result;
    result.seconds = seconds - right.seconds;
    result.minutes = minutes - right.minutes;
    result.hours = hours - right.hours;
    result.days = days - right.days;
    result.normalize();
    return result;
}

// Relational
bool Time::operator>(const Time& right) const {
    return static_cast<int>(*this) > static_cast<int>(right);
}
bool Time::operator<(const Time& right) const {
    return static_cast<int>(*this) < static_cast<int>(right);
}
bool Time::operator>=(const Time& right) const {
    return static_cast<int>(*this) >= static_cast<int>(right);
}
bool Time::operator<=(const Time& right) const {
    return static_cast<int>(*this) <= static_cast<int>(right);
}
bool Time::operator==(const Time& right) const {
    return days == right.days && hours == right.hours &&
        minutes == right.minutes && seconds == right.seconds;
}
bool Time::operator!=(const Time& right) const {
    return !(*this == right);
}

// Output
std::ostream& operator<<(std::ostream& stream, const Time& right) {
    stream << right.days << "d " << right.hours << "h " << right.minutes << "m " << right.seconds << "s";
    return stream;
}

// Conversion to int
Time::operator int() const {
    return days * 86400 + hours * 3600 + minutes * 60 + seconds;
}
