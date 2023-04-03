#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* getinput() {
    char* value = malloc(sizeof(char) * 256);
    printf("Введите значение: ");
    scanf("%s", value);
    return value;
}

bool testinput(char* value) {
    char* endptr;
    strtol(value, &endptr, 10);
    if (*endptr == '\0') {
        return true;
    }
    else {
        return false;
    }
}

int strToint(char* value) {
    return atoi(value);
}

void printint(int value) {
    printf("%d\n", value);
}

int main() {
    char* input_value = getinput();
    if (testinput(input_value)) {
        int int_value = strToint(input_value);
        printint(int_value);
    }
    else {
        printf("Введенное значение не является целым числом.\n");
    }
    free(input_value);
    return 0;
}