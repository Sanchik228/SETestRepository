#include <iostream>
#include <locale>
#include <fstream>
#include <stdexcept>

using namespace std;

// Функція для обчислення значення y
double calculate(int x, int n) {
    double y = 0;
    if (n < 2) {
        throw invalid_argument("n має бути >= 2");
    }

    if (x > 0) {
        for (int i = 0; i < (n - 1); i++) {
            for (int j = 0; j < i; j++) {
                y += (i + 1) / (j + x);
            }
        }
    }
    else {
        for (int i = 2; i <= (n - 1); i++) {
            y += (x - 1) / i;
        }
    }

    return y;
}

// Функція для запису результату у файл
void saveToFile(double result, const string& filename = "result.txt") {
    ofstream outfile(filename);
    if (outfile.is_open()) {
        outfile << "Результат обчислення: " << result << endl;
        outfile.close();
        cout << "Результат успішно збережено у файл " << filename << endl;
    }
    else {
        cerr << "Не вдалося відкрити файл для запису." << endl;
    }
}

int main(int argc, char* argv[]) {
    system("chcp 65001");
    setlocale(LC_ALL, "ukrainian");

    try {
        int x, n;
        
            cout << "Введіть n (n >= 2): ";
            while (!(cin >> n) || n < 2) {
                cin.clear(); // Очищення помилкового стану
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Пропуск некоректного вводу
                cout << "Некоректне значення. Введіть n (n >= 2): ";
            }

            cout << "Введіть x: ";
            while (!(cin >> x)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Некоректне значення. Введіть x: ";
            }
      

        // Обчислення результату
        double result = calculate(x, n);
        cout << "Результат обчислення: " << result << endl;

        // Запис результату у файл
        saveToFile(result);

    }
    catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
        return 1;
    }

    return 0;
}