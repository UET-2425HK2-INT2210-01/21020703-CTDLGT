#include <iostream>
using namespace std;

double powerBitwise(int n) {
    if (n == 0) return 1;
    
    if (n > 0) {
        return 1 << n; 
    } else {
        return 1.0 / (1 << -n); 
    }
}

int main() {
    int n;
    cin >> n;
    cout << powerBitwise(n) << endl;
    return 0;
}


//FUNCTION powerBitwise(n):
//    IF n = 0 THEN
//        RETURN 1  
//
//    IF n > 0 THEN
//        RETURN (1 << n) 
//    
//    ELSE
//        RETURN 1.0 / (1 << (-n)) 
//    
//END FUNCTION
//// COMPLEXITY IS O(1).

