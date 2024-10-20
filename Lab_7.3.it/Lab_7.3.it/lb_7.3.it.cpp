#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int** a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int size) {
    cout << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int SumRowsWithoutNegatives(int** a, const int size) {
    int totalSum = 0;

    for (int i = 0; i < size; i++) {
        bool hasNegative = false;
        int rowSum = 0;

        for (int j = 0; j < size; j++) {
            if (a[i][j] < 0) {
                hasNegative = true;
                break;
            }
            rowSum += a[i][j];
        }

        if (!hasNegative) {
            totalSum += rowSum;
        }
    }

    return totalSum;
}

void MinDiagonalSum(int** a, const int size, int& minSum) {
    minSum = INT_MAX;

    for (int start = 0; start < size; start++) {
        int sum = 0;
        for (int i = 0, j = start; i < size && j < size; i++, j++) {
            sum += a[i][j];
        }
        if (sum < minSum) {
            minSum = sum;
        }
    }

    for (int start = 1; start < size; start++) {
        int sum = 0;
        for (int i = start, j = 0; i < size && j < size; i++, j++) {
            sum += a[i][j];
        }
        if (sum < minSum) {
            minSum = sum;
        }
    }
}

int main() {
    srand((unsigned)time(NULL));

    int Low = -10;
    int High = 10;
    int size;

    cout << "n = ";
    cin >> size;

    int** a = new int* [size];
    for (int i = 0; i < size; i++)
        a[i] = new int[size];

    Create(a, size, Low, High);
    Print(a, size);

    int rowSum = SumRowsWithoutNegatives(a, size);
    cout << "Сума елементів у рядках без від'ємних елементів: " << rowSum << endl;

    int minSum;
    MinDiagonalSum(a, size, minSum);
    cout << "Мінімум серед сум діагоналей, паралельних до головної діагоналі: " << minSum << endl;

    for (int i = 0; i < size; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
