#include <stdio.h>
//#include <stdlib.h>
#include <locale.h>

int Function_1(double , double );
int Function_2(double , double );
int Function_3(double , double );

int main(){
    double x , y;
    scanf("%lf%lf", &x, &y);
    printf("%lf %lf\n", x, y);
    // программа проверят принадлежность точки хотя бы одной из трех областей
    printf("%d",Function_1(x,y) || Function_2(x,y) || Function_3(x,y) );

    return 0;

}
int Function_1(double x, double y){
    return (y <= -x) || (x >= 4 && y >= 3);
}
 int Function_2(double x, double y){
    return (x*x + y*y > 9);
}   
int Function_3(double x, double y){
    return ((x*x-10*x+25)+(y*y-10*y+25) >= 25) && (x <=5) && (y<=5);
}   
