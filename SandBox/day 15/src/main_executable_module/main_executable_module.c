#include <stdio.h>
#include <stdlib.h>

#ifdef MACROS
#include "../data_libs/data_io_macros.h"
#else
#include "../data_libs/data_io.h"
#endif

#include "../data_libs/data_stat.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

int main() {
    double *data;
    int n;
    if (scanf("%d", &n)) {
        data = (double *)calloc(n, sizeof(double));
        printf("LOAD DATA...\n");
        input(data, n);

        printf("RAW DATA:\n\t");
        output(data, n);

        printf("\nNORMALIZED DATA:\n\t");
        normalization(data, n);
        output(data, n);

        printf("\nSORTED NORMALIZED DATA:\n\t");
        sort(data, n);
        output(data, n);

        printf("\nFINAL DECISION:\n\t");
        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");

        free(data);
    } else
        printf("n/a");
    return 0;
}
