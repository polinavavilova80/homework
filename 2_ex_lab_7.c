// код функции до рефакторинга
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
// код после рефакторинга функции
void comb_sort(char (*arr)[50], int n) {
    int gap = n;
    float shrink = 1.3;
    int sorted = 0;
    char temp[50];
    while (!sorted) {
        gap = (int)(gap/shrink);
        if (gap > 1) {
            sorted = 0;
        } else {
            gap = 1;
            sorted = 1;
        }
        for (char (*p)[50] = arr; p < arr+(n-gap); ++p) {  
            char (*q)[50] = p + gap;  
            if (strcmp(*p, *q) > 0) {
                strcpy(temp, *p);
                strcpy(*p, *q);
                strcpy(*q, temp); 
                sorted = 0;
            }
        }
        printf("Comb sort iteration: ");
        for (int k = 0; k < n; k++) {
            printf("%s ", arr[k]);
        }
        printf("\n");
    }
    printf("Total iterations: %d\n", n*(n-1)/2);
}