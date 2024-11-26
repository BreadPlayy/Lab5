#include <iostream>
#include <fstream>
#include <cmath>
#include <Windows.h>
#include <stdexcept>

using namespace std;

double calculate_y(int n, double x) {
    if (n <= 0) throw invalid_argument("n ������� ���� ����� 0");
    if (x <= 0) {
        double product = 1.0;
        for (int i = 0; i < n; ++i) {
            product *= (i * i + i);
        }
        return product;
    }
    else {
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sum += x / (i + j);
            }
        }
        return sum;
    }
}

int main() {
    SetConsoleOutputCP(1251);

    double a, b, h, n;
    char saving;
    cout << "������ ��� ������� a = ";
    cin >> a;
    cout << "������ ����� ������� b = ";
    cin >> b;
    cout << "������ ���� h = ";
    cin >> h;
    cout << "������ n = ";
    cin >> n;
    cout << "�������� ���������� � ����? (y/n): ";
    cin >> saving;

    ofstream tofile;
    if (saving == 'y' || saving == 'Y') {
        tofile.open("results.txt");
        if (!tofile) {
            cerr << "������� �������� ����� ��� ������." << endl;
            return 1;
        }
    }

    double x = a;

    while (x <= b) {
        double y = 0;
        if (x <= 0) {
            for (int i = 0; i <= n - 1; i++) {
                y = y * (pow(i, 2) + i);
            }
        }
        else {
            for (int i = 0; i <= n - 1; i++) {
                double s = 0;
                for (int j = 0; j <= n - 1; j++) {
                    s = s + x / (i + j);
                }
                y = y + s;
            }
        }
        tofile << "x = " << x << ", y = " << y << endl;
        cout << "x = " << x << ", y = " << y << endl;

        x = x + h;
    }

    if (saving == 'y' || saving == 'Y') {
        tofile << "end" << endl;
        tofile.close();
        cout << "���������� ��������� � ���� results.txt" << endl;
    }
    else {
        cout << "end" << endl;
    }

    return 0;
}
