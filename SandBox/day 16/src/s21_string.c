#include "s21_string.h"

size_t s21_strlen(const char *str) {
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int s21_strcmp(char *str1, char *str2) {
    for (; *str1 && *str1 == *str2; str1++, str2++)
        ;
    return *str1 - *str2;
}

char *s21_strcpy(char *destination, const char *source) {
    char *ptr = destination;

    if (destination != NULL) {
        while (*source != '\0') {
            *destination = *source;
            destination++;
            source++;
        }
        *destination = '\0';
    }

    return ptr;
}

char *s21_strcat(char *destination, const char *source) {
    // делаем так, чтобы `ptr` указывал на конец строки назначения
    char *ptr = destination + s21_strlen(destination);

    // добавляет символы источника к строке назначения
    while (*source != '\0') {
        *ptr++ = *source++;
    }

    // нулевая завершающая строка назначения
    *ptr = '\0';

    // пункт назначения возвращается стандартной функцией `strcat()`
    return destination;
}

char *s21_strchr(const char *str, int ch) {
    int i = 0;
    while (str[i] && str[i] != ch) ++i;
    return ch == str[i] ? (char *)str + i : NULL;
}

char *s21_strstr(char *str, char *needle) {
    char *needle_ptr = NULL, *str_ptr = NULL;

    if (str == NULL || needle == NULL) return NULL;
    while (*str) {
        if (*str == *needle) {
            int trigger_out = 1;
            needle_ptr = needle;
            str_ptr = str;
            while (*needle_ptr && *str_ptr) {
                trigger_out = trigger_out && (*needle_ptr == *str_ptr);
            }
            if (trigger_out) return str;
        }
        ++str;
    }
    return NULL;
}

char *s21_strtok(char *str, const char *delim) {
    static char *last = 0;
    if (str) last = str;
    if ((last == 0) || (*last == 0)) return 0;
    char *c = last;
    while (s21_strchr(delim, *c)) ++c;
    if (*c == 0) return 0;
    char *start = c;
    while (*c && (s21_strchr(delim, *c) == 0)) ++c;
    if (*c == 0) {
        last = c;
        return start;
    }
    *c = 0;
    last = c + 1;
    return start;
}
