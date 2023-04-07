#include <stdio.h> 
#include <math.h>

void main () {
    double for_test[10][2] = {{-6., 6.}, {-5., -5.}, {5.,-5.}, {5., 5.}, {1., 8.}, {1.,3.},
	{2., 0.}, {0.,2.}, {0.,0.}, {1.,1.}};

    double x,y;
    for (int i = 0; i < 10; i++) {
	    printf("Проверка %d: %d\n", i+1, (!(pow((for_test[i][0]- 5.),2.) + 
        pow((for_test[i][1]- 5.),2.) < pow(5.,2.))) && (for_test[i][0] <= 5.) && 
        (for_test[i][1] <= 5.) && (for_test[i][0]>=0) && (for_test[i][1] >= 0));    
		/*Обоснование выбора координат в строках 5-6
	 входит ли {-6., 6.} во 2-ую четверть (ожид.: 0)
	входит ли {-5., -5.} в 3-ю четверть (ожид.:  0)
	входит ли {5.,-5.}  в 4-ую четверть (ожид. 0)
	входит ли  {5., 5.}  в окружность (ожид.: 0)
	лежит ли {1., 8.}  на окружности (где нет границы с закрашенной обл.) (ожид.: 0)
	лежит ли {1.,3.}  на окружности (где есть граница с закрашенной обл) (ожид.: 1)
	лежит ли {2., 0.}  на оси х (где есть закрашенная обл.) (ожид.: 1)
	лежит ли {0.,2.}  на оси у ( где есть закрашенная обл.) (ожид.: 1)
	как {0.,0.} ведут себя в начале координат (ожид.: 1)
	как {1.,1.} ведут себя в закрашенной области (ожид.: 1) */
	}

	printf ("Ввод координаты х: ");
	scanf ("%lf", &x);
	printf ("Ввод координаты y: ");
	scanf ("%lf", &y);
    if ((!(pow((x - 5.),2.) + pow((y - 5.),2.) < pow(5.,2.))) && (x <= 5.) && (y <= 5.) && (x >= 0) && (y >= 0))
	    printf("Результат проверки: 1\n");
    else
        printf("Результат проверки: 0\n");
}
	