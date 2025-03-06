#include <math.h>
#include <stdio.h>

double verz_anez(double x);   // Верзьера Аньези с единичным диаметром
double lemni_bern(double x);  // Лемниската Бернулли с единичным интервалом в положительной полуплоскости
double sqr_hiper(double x);   // Квадратичная гипербола

int main() {
    // Вывод значений первой функции
    double pi = 3.1415926;
    double minus_pi = pi * (-1);
    double step = 2 * pi / 41;
    // printf ("%.7l | %.7lf | ", minus_pi);
    for (double i = minus_pi; i <= pi; i = i + step)
        if ((i < 0) && ((i + step) > 0)) {  // проверка на наличие в выводе значения 0
            printf("%.7lf | %.7lf | %.7lf | -\n", 0.0, verz_anez(0.0), lemni_bern(0));
        } else {
            if (lemni_bern(i) >= 0)
                printf("%.7lf | %.7lf | %.7lf | %.7lf\n", i, verz_anez(i), lemni_bern(i), sqr_hiper(i));
            else
                printf("%.7lf | %.7lf | -         | %.7lf\n", i, verz_anez(i), sqr_hiper(i));
        }

    if (lemni_bern(pi) >= 0)  // вывод крайнего значения
        printf("%.7lf | %.7lf | %.7lf | %.7lf\n", pi, verz_anez(pi), lemni_bern(pi), sqr_hiper(pi));
    else
        printf("%.7lf | %.7lf | -         | %.7lf\n", pi, verz_anez(pi), sqr_hiper(pi));

    return 0;
}

/* Функции */
double verz_anez(double x) {
    double y = pow(1, 3) / (pow(1, 2) + pow(x, 2));
    return y;
}

double lemni_bern(double x) {
    double y = sqrt(sqrt(pow(1, 4) + 4 * pow(x, 2) * pow(1, 2)) - pow(x, 2) - pow(1, 2));
    return y;
}

double sqr_hiper(double x) {
    double y = 1 / pow(x, 2);
    return y;
}