#include <iostream>
using namespace std;
// ham de quy tim ucln
int gcd(int x, int y) {
    if (y == 0)
        return x;			// neu y = 0 thi ucln la chinh no
    return gcd(y, x % y); // ucln cua mot so la y va phan du cua x/y
}

int main() {
    int x, y;			
    cout << "Nhap X va Y: ";		
    cin >> x >> y;			// nhap 2 so
    if (x < 0) x = -x;		// dao dau x va y neu bi am
    if (y < 0) y = -y;
    int result = gcd(x, y);
    cout << "GCD: " << result << endl;
    return 0;
}

