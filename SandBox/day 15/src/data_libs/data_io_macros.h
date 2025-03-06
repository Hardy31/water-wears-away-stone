#ifndef DATA_IO_MACROS_H_
#define DATA_IO_MACROS_H_

#define input(data, n)                                      \
    {                                                       \
        for (int i = 0; i < n; i++) scanf("%lf", &data[i]); \
    }

#define output(data, n)                 \
    {                                   \
        for (int i = 0; i < n; i++) {   \
            printf("%.2lf", data[i]);   \
            if (i < n - 1) printf(" "); \
        }                               \
    }

#endif //DATA_IO_MACROS_H_
