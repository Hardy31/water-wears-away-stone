CC = GCC
CFLAGS = -std=c11 -Wall -Wextra -Werror

all: build

build: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests

strlen_tests: s21_string.o s21_string_test_len.o
	gcc s21_string.o s21_string_test.o -o ../build/Quest_1

strcmp_tests: s21_string.o s21_string_test_cmp.o
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_2

strcpy_tests: s21_string.o s21_string_test_cpy.o
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_3

strcat_tests: s21_string.o s21_string_test_cat.o
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_4

strchr_tests: s21_string.o s21_string_test_chr.o
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_5

strstr_tests: s21_string.o s21_string_test_str.o
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_6

strtok_tests: s21_string.o s21_string_test_tok.o
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_7

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) -c $<

s21_string_test_len.o: s21_string_test.c
	$(CC) -DSTRLEN $(CFLAGS) -c $<

s21_string_test_cmp.o: s21_string_test.c
	$(CC) -DSTRCMP $(CFLAGS) -c $<

s21_string_test_cpy.o: s21_string_test.c
	$(CC) -DSTRCPY $(CFLAGS) -c $<

s21_string_test_cat.o: s21_string_test.c
	$(CC) -DSTRCAT $(CFLAGS) -c $<

s21_string_test_chr.o: s21_string_test.c
	$(CC) -DSTRCHR $(CFLAGS) -c $<

s21_string_test_str.o: s21_string_test.c
	$(CC) -DSTRSTR $(CFLAGS) -c $<

s21_string_test_tok.o: s21_string_test.c
	$(CC) -DSTRTOK $(CFLAGS) -c $<

clean:
	rm -rf *.o *.a *.so ../build/Quest*

rebuild:
	clean build