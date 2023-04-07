#include <stdio.h> 
#include <stdbool.h>
bool Bissectrice(double, double);
bool Vertical(double);
bool Horizontal(double);

void main() {
	double for_test[10][2] = {{5., 4.}, {-4., -4.}, {-4.,3.}, {-10., 4.}, {1., 5.}, {5.,-7.},
	{3., -1.}, {1.,1.}, {0.,0.}, {4.,-4.}};
	double x;
	double y;
	for (int i = 0; i < 10; i++) {
		printf("Проверка %d: %d\n", i+1, (Bissectrice(for_test[i][0], for_test[i][1]) 
		&& (!Vertical(for_test[i][0])) && (!Horizontal(for_test[i][1]))) || 
		(Vertical(for_test[i][0]) && Horizontal(for_test[i][1])));
	}
	printf ("Ввод координаты х: ");
	scanf ("%lf", &x);
	printf ("Ввод координаты y: ");
	scanf ("%lf", &y);
	printf("Проверка от пользователя: %d\n", (Bissectrice(x, y) 
	&& (!Vertical(x)) && (!Horizontal(y))) || 
	(Vertical(x) && Horizontal(y)));      	/* Обоснование выбора координат для проверки:
	   входит ли {5., 4.} в закрашенную область 1-ой четверти (ожид.:1)
	   входят ли  {-4., -4.}  в 3-ю четверть (ожид.: 1 область 2-ой четверти (ожид.:1)
	   входит ли{-10., 4.}  в незакрашенную область 2-ой четверти под графиком (ожид.:0)
	   входит ли{1., 5.}  в незакрашенную область 2-ой четверти сверху графика (ожид.:0)
	   входит ли {5.,-7.}  в незакрашенную область 4-ой четверти под графиком (ожид.:0)
	   входит ли{3.,-1.}  в незакрашенную область 4-ой четверти сверху графика (ожид.:0)
	   входит ли{1.,1.}  в незакрашенную область 1-ой чертверти (ожид.:0)
	   как {0.,0.} ведут себя в начале координат (ожид.:1)
	   как {4.,-4.} ведут себя на границе графика (ожид.:1) */
}
bool Bissectrice(double x, double y) {
	bool resultat;
	resultat = (y <= -x);
	return resultat;
}
bool Vertical(double x) {
	bool resultat;
	resultat = (x > 4);
	return resultat;
}
bool Horizontal(double y) {
	bool resultat;
	resultat = (y > 3);
	return resultat;
}
	