#include <iostream>
#include <rational.h>

using namespace std;

int main()
{
    Rational r2(2, 11), r3(1, -3), r5(18, 6);
    Rational res1 = 3 + r2 * r3;
    Rational res2 = (3 + r2) * r3;
    Rational res3 = 3 + r3 * (r2 + 2) / (r5 - r3);

    cout << 3 << " + " << r2 << " * " <<  r3 << " = " << res1 << endl;
    cout << "(" << 3 << " + " << r2 << ")" << " * " <<  r3 << " = " << res2 << endl;
    cout << 3 << " + " << r3 << " * " << "(" << r2 << " + " << 2 << ")" << "/"
    << "(" << r5 << " - " << r3 << ")" << " = " << res3 << endl;

    return 0;
}
