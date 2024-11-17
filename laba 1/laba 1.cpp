#include <iostream>
#include <fstream> //для робоити з фаілами 
#include <locale>

using namespace std;

int main()
{
    double a, b, h, n, y, s;
    char save;

    cout << "Enter n (n >= 2): ";
    cin >> n;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter h: ";
    cin >> h;

    cout << "Do you want save results? (y - yes; n - no): ";
    cin >> save;

    ofstream fout;  // Оголошуємо змінну для файлу
    if (save == 'y') {
        fout.open("test.txt");  // Відкриваємо файл
        if (!fout) {
            cout << "Error opening file!" << endl;
            return 1;
        }
    }
    

    for (double x = a; x <= b; x += h) {
        if (x > 0) {
            y = 1;
            for (int i = 0; i < (n - 1); i++) {
                s = 0;
                for (int j = 0; j <= i; j++) {
                    s += (i + 1) / static_cast<double>(j + x);
                }
            }
            y *= s;
        }
        else {
            y = 0.0;
            for (int i = 2; i <= (n - 1); i++) {
                y += (x - 1) / static_cast<double>(i);
            }
        }
        cout << "x= " << x << "     y = " << y;

    if (save == 'y') {
        fout << "x = " << x << "   y = " << y;
        }
    
    }

    if (save == 'y')  // закриваємл фаіл
    {
        fout.close();
        cout << "Results saved to test.txt" << endl;
    }
    return 0;
}