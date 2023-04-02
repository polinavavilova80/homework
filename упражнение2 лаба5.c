#include <stdio.h>
//#include <stdlib.h>
#include <locale.h>

 char* getInput(){
    char* s;
    scanf("%s",&s);
    return s;
}
int main(void){
    char* s = getInput() ;
    printf("%s",s);
    return 0;
}