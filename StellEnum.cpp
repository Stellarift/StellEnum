#include <iostream>
#include <string>
using namespace std;
// Задача 1
void task1() {
    enum Day { MON, TUE, WED, THU, FRI, SAT, SUN };

    int userChoice;
    cout << "Выберите день недели (1-Пн, 2-Вт, 3-Ср, 4-Чт, 5-Пт, 6-Сб, 7-Вс): ";
    cin >> userChoice;

    if (userChoice < 1 || userChoice > 7) {
        cout << "Ошибка! Введите число от 1 до 7.\n";
        return;
    }

    Day d = static_cast<Day>(userChoice - 1);
    string name;

    if (d == MON) name = "Понедельник";
    else if (d == TUE) name = "Вторник";
    else if (d == WED) name = "Среда";
    else if (d == THU) name = "Четверг";
    else if (d == FRI) name = "Пятница";
    else if (d == SAT) name = "Суббота";
    else name = "Воскресенье";

    cout << "\nДень: " << name << endl;
    cout << "Выходной: " << ((d == SAT || d == SUN) ? "Да" : "Нет") << endl;
}

// Задача 2
void task2() {
    enum Light { RED, GREEN, YELLOW };

    int start;
    cout << "С какого цвета начать?\n";
    cout << "1. Красный\n2. Зеленый\n3. Желтый\nВаш выбор: ";
    cin >> start;

    if (start < 1 || start > 3) {
        cout << "Ошибка! Введите 1, 2 или 3.\n";
        return;
    }

    Light light;
    if (start == 1) light = RED;
    else if (start == 2) light = GREEN;
    else light = YELLOW;

    int steps;
    cout << "Сколько шагов показать? ";
    cin >> steps;

    if (steps <= 0) {
        cout << "Ошибка! Введите положительное число.\n";
        return;
    }

    cout << "\nСветофор:\n";
    for (int i = 0; i < steps; i++) {
        if (light == RED) {
            cout << i + 1 << ". Красный\n";
            light = GREEN;
        }
        else if (light == GREEN) {
            cout << i + 1 << ". Зеленый\n";
            light = YELLOW;
        }
        else {
            cout << i + 1 << ". Желтый\n";
            light = RED;
        }
    }
}

// Задача 3
void task3() {
    enum Error { OK, NO_FILE, NO_ACCESS, NO_MEM };

    int errorNum;
    cout << "Выберите код ошибки:\n";
    cout << "0. Успех\n1. Нет файла\n2. Нет доступа\n3. Нет памяти\n";
    cout << "Ваш выбор: ";
    cin >> errorNum;

    if (errorNum < 0 || errorNum > 3) {
        cout << "Ошибка! Введите число от 0 до 3.\n";
        return;
    }

    Error e = static_cast<Error>(errorNum);

    cout << "\nКод ошибки: ";
    if (e == OK) cout << "Успех\n";
    else if (e == NO_FILE) cout << "Файл не найден\n";
    else if (e == NO_ACCESS) cout << "Доступ запрещен\n";
    else cout << "Недостаточно памяти\n";
}

// Задача 4
void task4() {
    enum Level { INFO, WARN, ERR };

    int levelChoice;
    cout << "Выберите уровень логирования:\n";
    cout << "1. INFO\n2. WARNING\n3. ERROR\n";
    cout << "Ваш выбор: ";
    cin >> levelChoice;

    if (levelChoice < 1 || levelChoice > 3) {
        cout << "Ошибка! Введите 1, 2 или 3.\n";
        return;
    }

    Level l;
    if (levelChoice == 1) l = INFO;
    else if (levelChoice == 2) l = WARN;
    else l = ERR;

    cout << "Введите сообщение (одно слово): ";
    string msg;
    cin >> msg;

    cout << "\nРезультат:\n";
    cout << "[";
    if (l == INFO) cout << "INFO";
    else if (l == WARN) cout << "WARNING";
    else cout << "ERROR";
    cout << "] " << msg << endl;
}

// Задача 5
void task5() {
    enum Color { RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN };

    int colorChoice;
    cout << "Выберите цвет текста:\n";
    cout << "1. Красный\n2. Зеленый\n3. Желтый\n";
    cout << "4. Синий\n5. Пурпурный\n6. Голубой\n";
    cout << "Ваш выбор: ";
    cin >> colorChoice;

    if (colorChoice < 1 || colorChoice > 6) {
        cout << "Ошибка! Введите число от 1 до 6.\n";
        return;
    }

    Color c;
    if (colorChoice == 1) c = RED;
    else if (colorChoice == 2) c = GREEN;
    else if (colorChoice == 3) c = YELLOW;
    else if (colorChoice == 4) c = BLUE;
    else if (colorChoice == 5) c = MAGENTA;
    else c = CYAN;

    cout << "Введите текст (одно слово): ";
    string text;
    cin >> text;

    cout << "\nЦветной текст:\n";

    if (c == RED) cout << "\033[31m";
    else if (c == GREEN) cout << "\033[32m";
    else if (c == YELLOW) cout << "\033[33m";
    else if (c == BLUE) cout << "\033[34m";
    else if (c == MAGENTA) cout << "\033[35m";
    else cout << "\033[36m";

    cout << text << "\033[0m" << endl;
}

// Главная программа
int main() {
    setlocale(LC_ALL, "ru");
    int choice;

    while (true) {
        cout << "\n=====================================\n";
        cout << "1. Дни недели (выходной или нет)\n";
        cout << "2. Светофор (последовательность)\n";
        cout << "3. Коды ошибок\n";
        cout << "4. Логирование (уровни сообщений)\n";
        cout << "5. Цветной текст в консоли\n";
        cout << "0. Выход\n";
        cout << "=====================================\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 0) {
            cout << "\nДо свидания!\n";
            break;
        }

        if (choice < 1 || choice > 5) {
            cout << "Ошибка! Выберите число от 0 до 5.\n";
            continue;
        }

        cout << "\n=== Задача " << choice << " ===\n";

        if (choice == 1) task1();
        else if (choice == 2) task2();
        else if (choice == 3) task3();
        else if (choice == 4) task4();
        else if (choice == 5) task5();
    }

    return 0;
}
