#include <iostream>
using namespace std;

double f(double x, int n) {
    if (n == 1) return x;
    return (pow(-1, (n - 1)) * (pow(x, n) / n) + f(x, (n - 1)));
}

int main() {
    setlocale(LC_ALL, "Russian");
    double x;
    int n;
    cout << "Введите X: "; cin >> x;
    cout << "Введите N: "; cin >> n;
    while (n <= 0) {
        cout << "N должно быть больше 0.";
        cout << "\nВведите N: "; cin >> n;
    }

    cout << "Приближенный ряд ln(x+1) при x = " << x << " и n = " << n << ": ";
    double result = f(x, n);
    cout << result << endl << endl;
    
    system("pause");

    return 0;
}
