#include "data_stat.h"

#include <math.h>

double max(double *data, int n) {
    double max = data[0];
    for (int i = 1; i < n; i++)
        if (data[i] > max) max = data[i];
    return max;
}
double min(double *data, int n) {
    double min = data[0];
    for (int i = 1; i < n; i++)
        if (data[i] < min) min = data[i];
    return min;
}
double mean(double *data, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += *data;
        data++;
    }
    return sum / n;
}

double variance(double *data, int n) {
    double sum = 0.0;
    double average = mean(data, n);
    for (int i = 0; i < n; i++) {
        sum += pow((*data - average), 2);
        data++;
    }
    return sum / n;
}

void sort(double *a, int n) {
    double temp;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}