#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x);
double f(double x)
{
    double a = log(cos(2 * x - 0.2) + 1.1);

    return a;
}

double fprime(double x);
double fprime(double x)
{
    double b = -20 * sin(2 * x - (1 / 5)) / 10 * cos(2 * x - (1 / 5) + 11);

    return b;
}
int main()
{
    double x, x1, e, fx, fx1;
    cout.precision(5);
    cout.setf(ios::fixed);

    cout << "Insira o valor desejado:\n";
    cin >> x1;
    cout << "Insira a precisao desejada:\n";
    cin >> e;
    cout << "x{i}"
        << "    "
        << "x{i+1}"
        << "        "
        << "|x{i+1}-x{i}|" << endl;

    do
    {
        x = x1;
        fx = f(x);
        fx1 = fprime(x);
        x1 = x - (fx / fx1);

        cout << x << "    " << x1 << "        " << abs(x1 - x) << endl;

    } while (fabs(x1 - x) >= e);

    cout << "A raiz da equacao eh " << x1 << endl;

    return 0;
}
