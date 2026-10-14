#include <iomanip>
#include <iostream>


bool IsEqual(const char* a, const char* b);
void Deposit(int& balance);
void Withdraw(int& balance);
void PrintBalance(int& balance);
void Reset(int& balance);
void DoubleBalance(int& balance);

int main() {

    int balance = 0;


    char commands[5][10] = {
        "deposit",
        "withdraw",
        "balance",
        "reset",
        "double"
    };

    void (*operations[5])(int&) = {
        Deposit,
        Withdraw,
        PrintBalance,
        Reset,
        DoubleBalance
    };

    const int kCommandCount = 5;

    char command[32];

    while (true) {

        std::cin >> std::setw(32) >> command;

        if (!std::cin) {
            break;
        }


        if (IsEqual(command, "stop")) {
            break;
        }

        bool found = false;


        for (int i = 0; i < kCommandCount; ++i) {
            if (IsEqual(command, commands[i])) {

                operations[i](balance);

                found = true;
                break;
            }
        }


        if (!found) {
            std::cout << "error\n";
            std::cin.ignore(1000000, '\n');
        }
    }

    return 0;
}


bool IsEqual(const char* a, const char* b) {
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return false;
        }

        ++i;
    }

    return a[i] == b[i];
}

void Deposit(int& balance) {
    int k;
    std::cin >> k;

    if (k <= 0) {
        std::cout << "error\n";
        return;
    }

    balance += k;
}


void Withdraw(int& balance) {
    int k;
    std::cin >> k;

    if (k <= 0 || k > balance) {
        std::cout << "error\n";
        return;
    }

    balance -= k;
}


void PrintBalance(int& balance) {
    std::cout << balance << '\n';
}

void Reset(int& balance) {
    balance = 0;
}


void DoubleBalance(int& balance) {
    balance *= 2;
}