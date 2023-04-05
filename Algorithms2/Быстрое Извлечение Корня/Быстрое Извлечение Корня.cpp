#include <iostream>
#define ld long double
using namespace std;
ld f(ld a, ld b) {
    return (a + b) / 2;
}
int main()
{
    ld a;
    cin >> a;
    ld  mid, low = 0, high = a;
    while (f(low, high) * f(low, high) != a) {
        mid = f(high, low);
        if (f(low, high) * f(low, high) > a) high = mid;
        else if (f(low, high) * f(low, high) < a) low = mid;
        cout << f(low, high) << "   ";
    }
    cout << f(low, high);
}