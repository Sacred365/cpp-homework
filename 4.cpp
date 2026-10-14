#include <iostream>

int main() {
    /*
    Проверка лампочек в доме. Программа счиатет сколько лампочек нужно заменить и каков процент работающих

    int*** используется для хранения состояний лампочек в трехмерном массиве lamps[подезд][этаж][сост лампочки(0 либо 1)]

    void* используется для хранения результатов разных типов в едином отчёте: int (количество замен) и 
    double (процент работающих лампочек).
    */

    int n, m, k;
    std::cin >> n >> m >> k;

    if (n <= 0 || m <= 0 || k <= 0) {
        return 0;
    }

    int*** lamps = new int**[n];

    for (int i = 0; i < n; ++i) {
        lamps[i] = new int*[m];

        for (int j = 0; j < m; ++j) {
            lamps[i][j] = new int[k];
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int z = 0; z < k; ++z) {
                std::cin >> lamps[i][j][z];
            }
        }
    }

    void* report[2];

    int replacements = 0;
    double percentage = 0;

    report[0] = &replacements;
    report[1] = &percentage;

    int total = m * k;
    int required = (total + 1) / 2;


    for (int i = 0; i < n; ++i) {
        int working = 0;

        for (int j = 0; j < m; ++j) {
            for (int z = 0; z < k; ++z) {
                working += lamps[i][j][z];
            }
        }

        replacements = 0;

        if (working < required) {
            replacements = required - working;
        }

        percentage = 100.0 * working / total;

        int* missing = static_cast<int*>(report[0]);
        double* percent = static_cast<double*>(report[1]);

        std::cout << "Entrance " << i + 1 << ": "
                  << *missing << " replacements, "
                  << *percent << "% working\n";
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            delete[] lamps[i][j];
        }

        delete[] lamps[i];
    }

    delete[] lamps;

    return 0;
}