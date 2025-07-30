
/*Assignment Test:
t1: 1d 2h 30m 45s
t2: 1d 2h 30m 45s

Addition Test:
0d 23h 59m 50s + 0d 0h 0m 15s = 1d 0h 0m 5s

Subtraction Test:
1d 0h 0m 30s - 0d 1h 0m 45s = 0d 22h 59m 45s

Relational Operators Test:
0d 5h 10m 10s > 0d 4h 59m 59s = 1
0d 5h 10m 10s < 0d 4h 59m 59s = 0
0d 5h 10m 10s >= 0d 4h 59m 59s = 1
0d 5h 10m 10s <= 0d 4h 59m 59s = 0
0d 5h 10m 10s == 0d 4h 59m 59s = 0

Ostream Operator Test:
Time: 2d 12h 5m 30s

Integer Conversion Test:
1d 1h 1m 1s = 90061 seconds
*/


#include "Time.h"
#include <iostream>

void assignmentTest() {
    Time t1(1, 2, 30, 45);
    Time t2;
    t2 = t1;

    std::cout << "Assignment Test:\n";
    std::cout << "t1: " << t1 << "\nt2: " << t2 << "\n\n";
}

void testTimeAddition() {
    Time t1(0, 23, 59, 50);
    Time t2(0, 0, 0, 15);

    Time sum = t1 + t2;

    std::cout << "Addition Test:\n";
    std::cout << t1 << " + " << t2 << " = " << sum << "\n\n";
}

void testTimeSubtraction() {
    Time t1(1, 0, 0, 30);
    Time t2(0, 1, 0, 45);

    Time diff = t1 - t2;

    std::cout << "Subtraction Test:\n";
    std::cout << t1 << " - " << t2 << " = " << diff << "\n\n";
}

void testTimeRelationalOperators() {
    Time t1(0, 5, 10, 10);
    Time t2(0, 4, 59, 59);

    std::cout << "Relational Operators Test:\n";
    std::cout << t1 << " > " << t2 << " = " << (t1 > t2) << "\n";
    std::cout << t1 << " < " << t2 << " = " << (t1 < t2) << "\n";
    std::cout << t1 << " >= " << t2 << " = " << (t1 >= t2) << "\n";
    std::cout << t1 << " <= " << t2 << " = " << (t1 <= t2) << "\n";
    std::cout << t1 << " == " << t2 << " = " << (t1 == t2) << "\n\n";
}

void testTimeOutStreamOperator() {
    Time t(2, 12, 5, 30);
    std::cout << "Ostream Operator Test:\n";
    std::cout << "Time: " << t << "\n\n";
}

void testTimeIntegerConversion() {
    Time t(1, 1, 1, 1);  // 1 day, 1 hour, 1 minute, 1 second
    int totalSeconds = t;

    std::cout << "Integer Conversion Test:\n";
    std::cout << t << " = " << totalSeconds << " seconds\n\n";
}

int main() {
    assignmentTest();
    testTimeAddition();
    testTimeSubtraction();
    testTimeRelationalOperators();
    testTimeOutStreamOperator();
    testTimeIntegerConversion();
    return 0;
}

