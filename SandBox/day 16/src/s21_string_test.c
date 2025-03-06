#include "s21_string.h"

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();
void s21_strtok_test();

int main() {
#ifdef STRLEN
    s21_strlen_test();
#endif
#ifdef STRCMP
    s21_strcmp_test();
#endif
#ifdef STRCPY
    s21_strcpy_test();
#endif
#ifdef STRCAT
    s21_strcat_test();
#endif
#ifdef STRCHR
    s21_strchr_test();
#endif
#ifdef STRSTR
    s21_strstr_test();
#endif
#ifdef STRTOK
    s21_strtok_test();
#endif
}

void s21_strlen_test() {
    char *str1 = "Source test string", *str2 = "", *str3 = " ";

    puts(str1);
    if (str1 != NULL) {
        printf("%lu\n", s21_strlen(str1));
        printf("SUCCESS\n");
    } else
        printf("\nFAIL\n");

    puts(str2);
    if (str2 != NULL) {
        printf("%lu\n", s21_strlen(str2));
        printf("SUCCESS\n");
    } else
        printf("\nFAIL\n");

    puts(str3);
    if (str3 != NULL) {
        printf("%lu\n", s21_strlen(str3));
        printf("SUCCESS\n");
    } else
        printf("\nFAIL\n");
}
void s21_strcmp_test() {
    char *str1 = "Source test string", *str2 = "Source test string";
    char *str3 = "", *str4 = "";
    char *str5 = "Some text", *str6 = " ";
    int cmp;

    for (int i = 0; i < 3; i++) {
        if (i == 0 && str1 != NULL && str2 != NULL) {
            printf("%s %s\n", str1, str2);
            cmp = s21_strcmp(str1, str2);
        }
        if (i == 1 && str1 != NULL && str2 != NULL) {
            printf("%s %s\n", str3, str4);
            cmp = s21_strcmp(str3, str4);
        }
        if (i == 2 && str1 != NULL && str2 != NULL) {
            printf("%s %s\n", str5, str6);
            cmp = s21_strcmp(str5, str6);
        }
        if (str1 != NULL && str2 != NULL) {
            printf("%d\n", cmp);
            printf("SUCCESS\n");
        } else
            printf("n/a\nFAIL\n");
    }
}

void s21_strcpy_test() {
    char str1[] = "String", str2[] = "Char", str3[] = "Str";
    char *str4 = "Char", *str5 = "String", *str6 = "Chring";

    printf("%s %s\n", str1, str2);
    if (str1 != NULL && str2 != NULL && (s21_strlen(str1) >= s21_strlen(str2))) {
        printf("%s\n", s21_strcpy(str1, str2));
        if (!s21_strcmp(str1, str2))
            printf("SUCCESS\n");
        else
            printf("FAIL\n");
    } else
        printf("\nFAIL\n");

    printf("%s %s\n", str3, str4);
    if (str3 != NULL && str4 != NULL && (s21_strlen(str3) >= s21_strlen(str4))) {
        printf("%s\n", s21_strcpy(str3, str4));
        if (!s21_strcmp(str3, str4))
            printf("SUCCESS\n");
        else
            printf("FAIL\n");
    } else
        printf("\nFAIL\n");

    printf("%s %s\n", str5, str6);
    if (str5 != NULL && str6 != NULL && (s21_strlen(str5) >= s21_strlen(str6))) {
        printf("%s\n", s21_strcpy(str5, str6));
        if (!s21_strcmp(str5, str6))
            printf("SUCCESS\n");
        else
            printf("FAIL\n");
    } else
        printf("\nFAIL\n");
}

void s21_strcat_test() {
    char str1[] = "String", str2[] = "Char", str3[] = "String";
    char *str4 = NULL, *str5 = "le", *str6 = "String";

    printf("%s %s\n", str1, str2);
    if (str1 != NULL && str2 != NULL) {
        printf("%s\n", s21_strcat(str1, str2));
        printf("SUCCESS\n");
    } else
        printf("\nFAIL\n");

    printf("%s %s\n", str3, str4);
    if (str3 != NULL && str4 != NULL) {
        printf("%s\n", s21_strcat(str3, str4));
        printf("SUCCESS\n");
    } else
        printf("\nFAIL\n");

    printf("%s %s\n", str5, str6);
    if (str5 != NULL && str6 != NULL) {
        printf("%s\n", s21_strcat(str5, str6));
        printf("SUCCESS\n");
    } else
        printf("\nFAIL\n");
}

void s21_strchr_test() {
    char *str1 = "String", *str2 = "String", *str3 = "String";
    int n1 = 'r', n2 = 'C', n3 = 'g';

    printf("%s %c\n", str1, n1);
    char *p1 = s21_strchr(str1, n1);
    if (str1 != NULL && p1 != NULL) {
        printf("%s\n", p1);
        printf("SUCCESS\n");
    } else
        printf("\nFAIL\n");

    printf("%s %c\n", str2, n2);
    char *p2 = s21_strchr(str2, n2);
    if (str2 != NULL && p2 != NULL) {
        printf("%s\n", p2);
        printf("SUCCESS\n");
    } else
        printf("\nFAIL\n");

    printf("%s %c\n", str3, n3);
    char *p3 = s21_strchr(str3, n3);
    if (str3 != NULL && p3 != NULL) {
        printf("%s\n", p3);
        printf("SUCCESS\n");
    } else
        printf("\nFAIL\n");
}

void s21_strstr_test() {
    char *str1 = "String", *str2 = "ri";
    char *str3 = "String", *str4 = "Char";
    char *str5 = "String", *str6 = "String";

    printf("%s %s\n", str1, str2);
    if (str1 != NULL && str2 != NULL) {
        const char *p = s21_strstr(str1, str2);
        printf("%s\n", p);
        if (p == NULL)
            printf("FAIL\n");
        else
            printf("SUCCESS\n");
    } else
        printf("\nFAIL\n");

    printf("%s %s\n", str3, str4);
    if (str3 != NULL && str4 != NULL) {
        const char *p = s21_strstr(str3, str4);
        printf("%s\n", p);
        if (p == NULL)
            printf("FAIL\n");
        else
            printf("SUCCESS\n");
    } else
        printf("\nFAIL\n");

    printf("%s %s\n", str5, str6);
    if (str5 != NULL && str6 != NULL) {
        const char *p = s21_strstr(str5, str6);
        printf("%s\n", p);
        if (p == NULL)
            printf("FAIL\n");
        else
            printf("SUCCESS\n");
    } else
        printf("\nFAIL\n");
}

void s21_strtok_test() {
    char str1[] = "String,Char", str2[] = "String", str3[] = ",String";
    char del[] = ",";

    printf("%s %s\n", str1, del);
    if (str1 != NULL && del != NULL) {
        char *p = s21_strtok(str1, del);
        printf("%s\n", p);
        if (p != NULL)
            printf("SUCCESS\n");
        else
            printf("FAIL\n");
    } else
        printf("\nFAIL\n");

    printf("%s %s\n", str2, del);
    if (str2 != NULL && del != NULL) {
        char *p = s21_strtok(str2, del);
        printf("%s\n", p);
        if (p != NULL)
            printf("SUCCESS\n");
        else
            printf("FAIL\n");
    } else
        printf("\nFAIL\n");

    printf("%s %s\n", str3, del);
    if (str3 != NULL && del != NULL) {
        char *p = s21_strtok(str3, del);
        printf("%s\n", p);
        if (p != NULL)
            printf("SUCCESS\n");
        else
            printf("FAIL\n");
    } else
        printf("\nFAIL\n");
}