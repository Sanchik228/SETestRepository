#include <iostream>
#include <fstream>
#include <locale>

using namespace std;

int main()
{
    int a, b, h, n;
    char save;

    // Введення даних від користувача
    cout << "Enter n (n >= 2): ";
    cin >> n;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter h: ";
    cin >> h;

    cout << "Do you want to save results? (y - yes; n - no): ";
    cin >> save;

    ofstream fout;  // Оголошуємо змінну для файлу
    if (save == 'y') {
        fout.open("test.txt");  // Відкриваємо файл
        if (!fout) {
            cout << "Error opening file!" << endl;
            return 1;
        }
    }

    // Цикл для обчислення значень y для кожного x з інтервалу [a, b]
    for (int x = a; x <= b; x += h)
    {
        double y = 0;   // Обнуляємо y для кожного нового значення x

        if (x > 0)  // Обчислення для x > 0
        {
            for (int i = 0; i < (n - 1); i++)  // Перша змінна
            {
                for (int j = 0; j < i; j++)   // Друга змінна
                {
                    y += (i + 1) / (j + x);
                }
            }
        }
        else  // Обчислення для x <= 0
        {
            for (int i = 2; i <= (n - 1); i++)
            {
                y += (x - 1) / i;
            }
        }

        // Виведення результатів на екран
        cout << "x = " << x << "    y = " << y << endl;

        // Запис результатів у файл, якщо користувач обрав збереження
        if (save == 'y') {
            fout << "x = " << x << "    y = " << y << endl;
        }
    }

    // Закриття файлу після завершення запису
    if (save == 'y')
    {
        fout.close();
        cout << "Results saved to test.txt" << endl;
    }

    return 0;
}