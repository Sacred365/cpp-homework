#include <iomanip>
#include <iostream>

const int kHeight = 5;
const int kWidth = 10;


bool IsValidPosition(int x, int y);
bool IsEqual(const char* a, const char* b);
int StringLength(const char* word);

void Clear(char board[][kWidth]);
bool Put(char board[][kWidth], int x, int y, char c);
bool PutText(char board[][kWidth], int x, int y, const char* word);
void Print(const char board[][kWidth]);

int main() {
    char board[kHeight][kWidth];

    Clear(board);

    char command[32];

    while (true) {
        std::cin >> std::setw(32) >> command;

        if (!std::cin) {
            break;
        }

        if (IsEqual(command, "quit")) {
            break;
        }

        if (IsEqual(command, "clear")) {
            Clear(board);
        } else if (IsEqual(command, "put")) {
            int x;
            int y;
            char c;

            std::cin >> x >> y >> c;

            if (!Put(board, x, y, c)) {
                std::cout << "error\n";
            }
        } else if (IsEqual(command, "text")) {
            int x;
            int y;
            char word[11];

            std::cin >> x >> y >> std::setw(11) >> word;

            if (!PutText(board, x, y, word)) {
                std::cout << "error\n";
            }
        } else if (IsEqual(command, "print")) {
            Print(board);
        } else {
            std::cout << "error\n";
            std::cin.ignore(1000000, '\n');
        }
    }

    return 0;
}

bool IsValidPosition(int x, int y) {
    return x >= 0 && x < kWidth &&
           y >= 0 && y < kHeight;
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


int StringLength(const char* word) {
    int length = 0;

    while (word[length] != '\0') {
        ++length;
    }

    return length;
}


void Clear(char board[][kWidth]) {
    for (int y = 0; y < kHeight; ++y) {
        for (int x = 0; x < kWidth; ++x) {
            board[y][x] = ' ';
        }
    }
}


bool Put(char board[][kWidth], int x, int y, char c) {
    if (!IsValidPosition(x, y)) {
        return false;
    }

    board[y][x] = c;
    return true;
}


bool PutText(char board[][kWidth], int x, int y, const char* word) {
    int length = StringLength(word);


    if (!IsValidPosition(x, y) || length > kWidth - x) {
        return false;
    }

    for (int i = 0; i < length; ++i) {
        Put(board, x + i, y, word[i]);
    }

    return true;
}


void Print(const char board[][kWidth]) {
    for (int y = 0; y < kHeight; ++y) {
        for (int x = 0; x < kWidth; ++x) {
            std::cout << board[y][x];
        }

        std::cout << '\n';
    }
}