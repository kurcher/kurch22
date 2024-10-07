#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#ifdef _WIN32
#include <windows.h> // Для функції Sleep() на Windows
#define usleep(x) Sleep(x / 1000) // Конвертація мікросекунд в мілісекунди для Sleep()
#else
#include <unistd.h> // Для UNIX-систем
#endif
using namespace std;

// Функція для кольорового виведення
void printColored(char symbol, int colorCode) {
    cout << "\033[" << colorCode << "m" << symbol << "\033[0m";
}


// Функція для запису ялинки в файл
void saveTreeToFile(const vector<vector<char>>& tree, const string& filename) {
    ofstream file(filename);
    for (const auto& row : tree) {
        for (char c : row) {
            file << c;
        }
        file << endl;
    }
    file.close();
}

// Функція для створення рівнів ялинки
void generateTree(vector<vector<char>>& tree, vector<pair<int, int>>& toysPositions, int n) {
    int width = 2 * n + 1;  // Ширина найширшого рівня
    int center = width / 2;

    srand(time(0)); // Ініціалізація для випадкових іграшок

    for (int level = 1; level <= n; ++level) {
        for (int row = 0; row < level + 1; ++row) {
            vector<char> line(width, ' ');
            int numStars = 2 * row + 1;
            for (int col = 0; col < numStars; ++col) {
                int pos = center - row + col;
                // Випадкове розміщення іграшок
                if (rand() % 10 < 2) {
                    char toys[] = { '@', '$', '%', '#' };
                    char toy = toys[rand() % 4];
                    line[pos] = toy;
                    toysPositions.push_back({ tree.size(), pos });  // Запам'ятовуємо позицію іграшок
                }
                else {
                    line[pos] = '*';
                }
            }
            tree.push_back(line);
        }
    }

    // Додаємо стовбур
    for (int i = 0; i < 2; ++i) {
        vector<char> trunk(width, ' ');
        trunk[center] = '|';
        tree.push_back(trunk);
    }
}

// Функція для виведення ялинки з кольорами (лише іграшки змінюють колір)
void printTreeWithToys(const vector<vector<char>>& tree, const vector<pair<int, int>>& toysPositions, bool toggleColors) {
    // Виведення всієї ялинки
    for (size_t i = 0; i < tree.size(); ++i) {
        for (size_t j = 0; j < tree[i].size(); ++j) {
            char symbol = tree[i][j];
            if (symbol == '*') {
                printColored(symbol, 32);  // Зелений для зірочок
            }
            else if (symbol == '|') {
                printColored(symbol, 33);  // Жовтий для стовбура
            }
            else if (symbol == '@' || symbol == '$' || symbol == '%' || symbol == '#') {
                // Перемикаємо кольори для іграшок
                int toyColor = toggleColors ? 31 : 36;  // Червоний або Синій
                printColored(symbol, toyColor);
            }
            else {
                cout << symbol;  // Виводимо інші символи (пробіли)
            }
        }
        cout << endl;
    }
}

void updateToysColors(const vector<pair<int, int>>& toysPositions, bool toggleColors) {
    for (const auto& pos : toysPositions) {
        // Переміщуємо курсор в консоль на потрібну позицію і змінюємо колір іграшки
        cout << "\033[" << pos.first + 1 << ";" << pos.second + 1 << "H";
        char toy = '@';  // Іграшки позначаються '@', '$', '%', '#', але їхній символ не змінюємо
        int toyColor = toggleColors ? 31 : 36;  // Червоний або Синій
        printColored(toy, toyColor);
    }
    // Повертаємо курсор в кінець, щоб уникнути непотрібного мерехтіння
    cout << "\033[" << toysPositions.size() + 1 << ";1H";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RU");


    int n;
    cout << "Введіть кількість рівнів ялинки: ";
    cin >> n;

    vector<vector<char>> tree;
    vector<pair<int, int>> toysPositions; // Зберігаємо позиції іграшок
    generateTree(tree, toysPositions, n);

    // Збереження ялинки в файл
    saveTreeToFile(tree, "christmas_tree.txt");

    // Виводимо ялинку один раз
    printTreeWithToys(tree, toysPositions, false);

    // Анімація гірлянди
    bool toggle = false; // Початковий стан кольорів
    while (true) {
        updateToysColors(toysPositions, toggle); // Оновлюємо лише кольори іграшок
        toggle = !toggle; // Зміна стану кольорів
        usleep(500000);  // Пауза 0.5 секунд
    }

    return 0;
}

