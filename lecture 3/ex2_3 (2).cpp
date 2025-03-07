#include <iostream>
using namespace std;

double powerIterative(int n) {
    if (n == 0) {
        return 1; 
    }

    double result = 1;
    int abs_n;

    if (n < 0) {
        abs_n = -n;
    } else {
        abs_n = n;
    }

    for (int i = 0; i < abs_n; i++) {
        result *= 2;
    }

    if (n < 0) {
        return 1.0 / result;
    } else {
        return result;
    }
}

int main() {
    int n;
    cin >> n;
    double result = powerIterative(n);
    cout << result << endl;
    return 0;
}

//FUNCTION powerIterative(n):
//    IF n = 0:
//        RETURN 1
//
//    result ? 1
//    abs_n ? |n| 
//
//    FOR i FROM 0 TO abs_n - 1:
//        result ? result * 2
//
//    IF n < 0:
//        RETURN 1 / result
//    ELSE:
//        RETURN result
// COMPLEXITY IS O(n).
