#include <iomanip>
#include <iostream>

struct TemperatureMinMax {
    int min;
    int max;
};

double FindAvgTemp(const int* a, int n);

TemperatureMinMax FindMinMax(const int* a, int n);

int CountNegative(const int* a, int n);


int main() {
    int n;
    std::cin >> n;

    if (n <= 0) {
        return 0;
    }
    int* a = new int[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    double average = FindAvgTemp(a, n);
    TemperatureMinMax min_max = FindMinMax(a, n);
    int negative_count = CountNegative(a, n);

    std::cout << std::fixed << std::setprecision(1);
    std::cout << average << '\n';

    std::cout << min_max.min << ' ' << min_max.max << '\n';
    std::cout << negative_count << '\n';

    delete[] a;

    return 0;
}

double FindAvgTemp(const int* a, int n) {
    double sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }

    return sum / n;
}


TemperatureMinMax FindMinMax(const int* a, int n) {
    TemperatureMinMax result = {a[0], a[0]};

    for (int i = 1; i < n; ++i) {
        if (a[i] < result.min) {
            result.min = a[i];
        }

        if (a[i] > result.max) {
            result.max = a[i];
        }
    }

    return result;
}


int CountNegative(const int* a, int n) {
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            ++count;
        }
    }

    return count;
}