//тактика №1
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, elements_count;
    int *arr;

    printf("Введите максимальный размер массива: ");
    scanf("%d", &size); // вводим максимальный размер массива

    printf("Введите количество элементов, которое нужно заполнить: ");
    scanf("%d", &elements_count); // вводим количество элементов, которые нужно заполнить

    if (elements_count > size) { // проверяем, что количество элементов не больше максимального размера
        printf("Ошибка! Количество элементов не должно превышать максимальный размер массива.");
        return 0;
    }

    arr = malloc(size * sizeof(int)); // выделяем память под массив

    printf("Введите %d элементов массива:\n", elements_count);
    for (int i = 0; i < elements_count; i++) { // заполняем массив элементами
        scanf("%d", &arr[i]);
    }

    printf("Массив:\n");
    for (int i = 0; i < elements_count; i++) { // выводим массив на экран
        printf("%d ", arr[i]);
    }

    // добавление в конец массива (append)
    int value;
    printf("\nВведите элемент, который нужно добавить в конец массива: ");
    scanf("%d", &value);
    if (elements_count < size) { // проверяем, что есть место в массиве
        arr[elements_count] = value; // добавляем элемент
        elements_count++; // увеличиваем количество элементов в массиве
        printf("Массив после добавления элемента в конец:\n");
        for (int i = 0; i < elements_count; i++) { // выводим массив на экран
            printf("%d ", arr[i]);
        }
    } else {
        printf("Ошибка! Массив уже заполнен, добавление элемента невозможно.");
    }

    // добавление в середину массива (insert)
    int index;
    printf("\nВведите индекс, на который нужно вставить элемент в массив (от 0 до %d): ", elements_count-1);
    scanf("%d", &index);
    if (index < 0 || index > elements_count-1) { // проверяем, что индекс в допустимых границах
        printf("Ошибка! Некорректный индекс.");
        return 0;
    }
    printf("Введите элемент, который нужно вставить в массив: ");
    scanf("%d", &value);
    if (elements_count < size) { // проверяем, что есть место в массиве
        for (int i = elements_count-1; i >= index; i--) { // сдвигаем элементы вправо
            arr[i+1] = arr[i];
        }
        arr[index] = value; // вставляем новый элемент
        elements_count++; // увеличиваем количество элементов в массиве
        printf("Массив после вставки элемента в середину:\n");
        for (int i = 0; i < elements_count; i++) { // выводим массив на экран
            printf("%d ", arr[i]);
        }
    } else {
        printf("Ошибка! Массив уже заполнен, вставка элемента невозможна.");
    }

    free(arr); // освобождаем выделенную память
    return 0;
}
 //Тесты:  (проверка append)elements_count = 5;size = 10;arr = {1, 2, 3, 4, 5};value = 6;append(arr, &elements_count, size, value;
// вывод: arr = {1, 2, 3, 4, 5, 6}; elements_count = 6; (проверка в заполненном массиве append)elements_count = 10;size = 10;arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};value = 11;append(arr, &elements_count, size, value);
//  вывод: выводится сообщение об ошибке, массив не изменяется (проверка insert)elements_count = 5;size = 10;arr = {1, 2, 3, 4, 5};index = 2;value = 6;insert(arr, &elements_count, size, index, value);
// вывод: arr = {1, 2, 6, 3, 4, 5}; elements_count = 6;(проверка insert в заполненном массиве)elements_count = 10;size = 10;arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};index = 2;value = 11;insert(arr, &elements_count, size, index, value);
// вывод: выводится сообщение об ошибке, массив не изменяется (проверка insert в неправильном диапазоне индексов)elements_count = 5;size = 10;arr = {1, 2, 3, 4, 5};index = 10;value = 6;insert(arr, &elements_count, size, index, value);
// вывод: выводится сообщение об ошибке, массив не изменяется