#include <iostream>
#include <locale>
using namespace std;

double calculate(int x, int n)
{
    double y = 0;

    if (x > 0)
    {
        for (int i = 0; i < (n - 1); i++)
            for (int j = 0; j < i; j++)
                y += (i + 1) / (j + x);
    }
    else
        for (int i = 2; i <= (n - 1); i++)
            y += (x - 1) / i;

    return y;
}
int main()
{
    int x, n;
    cout << "Enter n (n >= 2): ";
    cin >> n;
    cout << "Enter x: ";
    cin >> x;

    double result = calculate(x, n);
    cout << "Result: " << result << endl;
    return 0;
}