#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getInput() {    // функция для получения от пользователя целого числа
    int input;
    printf("Введите целое число: ");
    scanf("%d", &input);
    return input;
}

bool testInput(int input) {
    return (input >= 0 && input <= 100); // функция для проверки входных данных
}

int strToInt(int input) {   // функция для преобразующая строку в целое число
    return input;
}

void printInt(int n) {        // функция для вывода целого числа
    printf("Целое число: %d\n", n);
}

             // основная функция программы
int main() {
    int input = getInput(); // вызывается функция для получения целого числа 
    if (testInput(input)) { // проверка входных данных
        int intInput = strToInt(input); // передаем значение
        printInt(intInput); // передаем результат
    } else {
        printf("!Внимание, ввденное число не соответствует условию!\n"); // выводим ошибку,если число не соответствует
    }
    return 0;
}