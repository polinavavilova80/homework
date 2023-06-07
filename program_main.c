#include <stdio.h>
#include <math.h> //подключаем математические функции
#include <locale.h> //подключаем библиотеку для вывода русского языка в консоль 


#define ARR_SIZE 6000 //макроопределение константы 
//прототипы функций
double CalculateVa(double rA, double mu, double rP);//рассчет скорости va
double CalculateVw(double rA, double omegaE, double fi);//рассчет скорости vomega
double CalculateRp(double omegaE, double rA, double i, double mu);//рассчет радиуса перигея

int main() {
	setlocale(LC_ALL, "Russian");//установим локаль на русский язык 

	double mu = 398600;
	double omegaE = 7.2921159 * pow(10, -5);
	double i = 63.4;
	double rA = 45000;

	double rP = CalculateRp(omegaE, rA, i, mu);//высчитываем постоянную rP

	FILE *my_file = fopen("dannie.csv", "w"); //открываем файл для записи
    fprintf(my_file, "rA;Va;Vw\n");//записываем в файл строку заголовка

	for (int j = 1; j < ARR_SIZE; j++) { //пишем цикл for для рассчета разных значений ra
		int rA = j * 10; //рассчет нового значения для rA

		double cvw = CalculateVw(rA, omegaE, i);//рассчет скорости Vw
		double cva = CalculateVa(rA, mu, rP);//рассчет скорости va

		char str[100];

		if (cvw <= cva) {
            snprintf(str, 100, "%d;%.2f;%.2f\n", rA, cva, cvw); //записываем в файл три значения 
		} else {
            snprintf(str, 100, "%d;%.2f;\n", rA, cva);// записываем в файл только два значения 
		}
		fprintf(my_file, str);
	}

	fclose(my_file); 
	return 1;
}


double CalculateVa(double rA, double mu, double rP) {
	return sqrt(2 * mu * rP / (rA * (rA + rP)));
}

double CalculateVw(double rA, double omegaE, double i) {
	return omegaE * rA * cos(i);
}

double CalculateRp(double omegaE, double rA, double i, double mu) {
	return pow(omegaE, 2) * pow(rA, 4) * pow(cos(i), 2) / (2 * mu - pow(omegaE, 2) * pow(rA, 3) * pow(cos(i), 2));
}