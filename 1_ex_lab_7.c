//Алгоритм Bubble Sort отсортировал один и тот же словарь за наименьшее количество итераций.
// Но это не будет работать для любого словаря,поскольку зависит от порядка ввода слов,если слова уже отсортированы или ввод отсортирован по алфавиту,
 // то во всех алгоритмах сортировки будет одинаковое кол-во итераций. Использование функций из библиотеки <time.h> может показать разное время выполнения для каждого из алгоритмов
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void selection_sort(char arr[][50], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (strcmp(arr[j], arr[min_idx]) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            char temp[50];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[min_idx]);
            strcpy(arr[min_idx], temp);
        }
        printf("Selection sort iteration %d: ", i+1);
        for (int k = 0; k < n; k++) {
            printf("%s ", arr[k]);
        }
        printf("\n");
    }
    printf("Total iterations: %d\n", n*(n-1)/2); // формула для нахождения общего кол-ва итераций
}

void bubble_sort(char arr[][50], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                char temp[50];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
        printf("Bubble sort iteration %d: ", i+1);
        for (int k = 0; k < n; k++) {
            printf("%s ", arr[k]);
        }
        printf("\n");
    }
    printf("Total iterations: %d\n", n*(n-1)/2);
}

void comb_sort(char arr[][50], int n) {
    int gap = n;
    float shrink = 1.3;
    int sorted = 0;
    int i, j;
    while (!sorted) {
        gap = (int)(gap/shrink);
        if (gap > 1) {
            sorted = 0;
        } else {
            gap = 1;
            sorted = 1;
        }
        i = 0;
        while (i+gap < n) {
            if (strcmp(arr[i], arr[i+gap]) > 0) {
                char temp[50];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[i+gap]);
                strcpy(arr[i+gap], temp);
                sorted = 0;
            }
            i++;
        }
        printf("Comb sort iteration: ");
        for (int k = 0; k < n; k++) {
            printf("%s ", arr[k]);
        }
        printf("\n");
    }
    printf("Total iterations: %d\n", n*(n-1)/2);
}

int main() {
    char words[10][50];

    // читаем слова в массив
    printf("Enter 10 words in lowercase: ");
    for (int i = 0; i < 10; i++) {
        scanf("%s", words[i]);
    }

    // выбор типа сортировки
    int choice;
    printf("\nChoose a sorting algorithm:\n");
    printf("1. Selection sort\n");
    printf("2. Bubble sort\n");
    printf("3. Comb sort\n");
    printf("4. All of them\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nSorting with Selection Sort:\n");
        selection_sort(words, 10);
    }
    else if (choice == 2) {
        printf("\nSorting with Bubble Sort:\n");
        bubble_sort(words, 10);
    }
    else if (choice == 3) {
        printf("\nSorting with Comb Sort:\n");
        comb_sort(words, 10);
    }
    else if (choice == 4) {
        printf("\nSorting with all 3 algorithms:\n");
        printf("\nSelection Sort:\n");
        selection_sort(words, 10);
        printf("\n\nBubble Sort:\n");
        bubble_sort(words, 10);
        printf("\n\nComb Sort:\n");
        comb_sort(words, 10);
    }
    else {
        printf("\nInvalid choice!\n");
        return 0;
    }

    return 0;
}