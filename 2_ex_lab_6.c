#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void search_element(int arr[][4], int rows, int cols, int x) { // функция для поиска элемента
    int row = -1; // индекс строки с элементом, по умолчанию -1 (элемент не найден)
    int col = -1; // индекс столбца с элементом, по умолчанию -1 (элемент не найден)
    
    for(int i = 0; i < rows; i++) { // перебираем строки
        for(int j = 0; j < cols; j++) { // перебираем столбцы
            if(arr[i][j] == x) { // если текущий элемент равен заданному искомому числу
                row = i; // запоминаем индекс строки
                col = j; // запоминаем индекс столбца
                break; // выходим из цикла, так как нашли элемент
            }
        }
        if(row != -1) { // если элемент найден
            break; // выходим из внешнего цикла
        }
    }
    
    if(row != -1) { // если элемент найден
        printf("Элемент %d находится в строке %d и столбце %d", x, row+1, col+1); // выводим сообщение
    }else{ // если элемент не найден
        printf("Элемент %d не найден", x); // выводим сообщение
    }
}

int main() {
    const int rows = 3; // задаем количество строк
    const int cols = 4; // задаем количество столбцов
    int arr[rows][cols]; // создаем двумерный массив
    
    srand(time(NULL)); // инициализируем генератор случайных чисел
    for(int i = 0; i < rows; i++) { // заполняем массив случайными числами
        for(int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 10; // случайные числа от 0 до 9
        }
    }
    
    printf("Исходный массив:\n"); // выводим исходный массив
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    int x;
    printf("Введите искомый элемент: ");
    scanf("%d", &x); // вводим искомый элемент
    
    search_element(arr, rows, cols, x); // вызываем функцию для поиска элемента
    
    return 0;
}