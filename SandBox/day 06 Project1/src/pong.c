// I WANT TO PLAY WITH YOU
//         YOUR FRIEND, AI

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#define shirina_polya 81  // ширина поля
#define visota_polya 25   // высота поля
#define rocket_height 3   //высота ракетки
#define angle_x 1.0       // коэффициент смещения по оси х
#define angle_y 1.0       // коэффициент смещения по оси у

void printField(int rocket1_y, int rocket2_y, float ball_x, float ball_y, int player1_score,
                int player2_score);

int main() {
    // Переменные стартовых позиций
    float reversey = angle_y;  // начальные реверсы
    float reversex = angle_x;
    int spos_r1 = 11;  // стартовая позиция рактки 1
    int spos_r2 = 11;  // стартовая позиция ракетки 2
    int point_1 = 0;   // стартовые очки игрок 1
    int point_2 = 0;   // стартовые очки игрок 2
    float movex = 4;   // стартовые позиции мяча
    float movey = spos_r1 + rocket_height / 2 + 1;
    int status;  // переменная для чтения нажатия клавиши

    printField(spos_r1, spos_r2, movex - 1, movey - 1, point_1,
               point_2);  // Первый вывод игрового поля со стартовыми значениями

    while (1) {
        //system("stty -icanon -echo");

        //status = getchar();
        initscr();
        nodelay(stdscr, TRUE);
        status = getch();
        sleep(1);
        if (status == 97 || status == 122 || status == 107 ||
            status == 109) {   // Если нажато управление ракетками
            if (status == 97)  // Код символа a=97
                if (spos_r1 >= 3) spos_r1 = spos_r1 - 1;
            if (status == 122)  // Код символа z=122
                if (spos_r1 <= visota_polya - 1 - rocket_height) spos_r1 = spos_r1 + 1;
            if (status == 107)  // Код символа k=107
                if (spos_r2 >= 3) spos_r2 = spos_r2 - 1;
            if (status == 109)  // Код символа m=109
                if (spos_r2 <= visota_polya - 1 - rocket_height) spos_r2 = spos_r2 + 1;

            if ((int)(movex + reversex) == shirina_polya) {  // добавление очков 1му игроку
                point_1++;
                movex = 3;
                movey = spos_r1 + rocket_height / 2;
            }
            if ((int)(movex + reversex) == 1) {  // добавление очков 2му игроку
                point_2++;
                movex = shirina_polya - 2;
                movey = spos_r2 + rocket_height / 2;
            }

            if (((int)(movey + reversey) == 1) || ((int)(movey + reversey) == visota_polya))
                reversey = reversey * (-1);  // Отражение от горизонтальных бортов
            for (int z = spos_r1; z <= spos_r1 + rocket_height; z++)  // Проверка отражения на высоту ракетки1
                if ((int)movex == 3 && ((int)movey == z))
                    reversex = reversex * (-1);  // Проверка отражения от ракетки1
            for (int z = spos_r2; z <= spos_r2 + rocket_height; z++)  // Проверка отражения на высоту ракетки2
                if ((int)movex == shirina_polya - 2 && ((int)movey == z))
                    reversex = reversex * (-1);  // Проверка отражения от ракетки2
            //printf("\033[0d\033[2J");            // Очистка экрана
            printField(spos_r1, spos_r2, movex, movey, point_1, point_2);
            movex = movex + reversex;
            movey = movey + reversey;

        } else if (status == 32) {  // Если нажат пробел
            if (((int)(movey + reversey) == 1) || ((int)(movey + reversey) == visota_polya))
                reversey = reversey * (-1);  // Отражение от горизонтальных бортов

            for (int z = spos_r1; z <= spos_r1 + rocket_height; z++)  // Проверка отражения на высоту ракетки1
                if ((int)movex == 3 && ((int)movey == z))
                    reversex = reversex * (-1);  // Проверка отражения от ракетки1
            for (int z = spos_r2; z <= spos_r2 + rocket_height; z++)  // Проверка отражения на высоту ракетки2
                if ((int)movex == shirina_polya - 2 && ((int)movey == z))  // Добавил: исправил "2" на "3"
                    reversex = reversex * (-1);  // Проверка отражения от ракетки2

            if ((int)(movex) == shirina_polya) {  // добавление очков 1 игроку
                point_1++;
                movex = 3;
                movey = spos_r1 + rocket_height / 2;
            }
            if ((int)(movex) == 1) {  // добавление очков 2 игроку
                point_2++;
                movex = shirina_polya - 2;
                movey = spos_r2 + rocket_height / 2;
            }

            //printf("\033[0d\033[2J");  // Очистка экрана
            printField(spos_r1, spos_r2, movex, movey, point_1, point_2);
            movex = movex + reversex;
            movey = movey + reversey;
        } else {  // Если нажаты другие клавиши, кроме пробела и управления ракетками

            //printf("\033[0d\033[2J");  // Очистка экрана
            printField(spos_r1, spos_r2, movex, movey, point_1, point_2);
        }
        if (point_1 == 21) {
            printw("Победил первый игрок!");
            break;
        }
        if (point_2 == 21) {
            printw("Победил второй игрок!");
            break;
        }
        //system("stty icanon echo");
    }
    // Конец программы
    endwin(); // завершение работы с ncurses
    return 0;
}

/* Функции */
void printField(int rocket1_y, int rocket2_y, float ball_x, float ball_y, int player1_score,
                int player2_score) {
    int rocket1 = rocket1_y;
    int rocket2 = rocket2_y;
    // Печать шапки
    printw("Для выхода нажмите CTRL+Z\n");
    for (int b = 1; b <= shirina_polya; b++) printw("-");
    printw("\n");
    // Вывод очков
    printw("Player 1: %d", player1_score);
    for (int z = 1; z < shirina_polya / 2 - 8; z++) printw(" ");  // вывод пробелов между Игрок 1 и Игрок 2
    printw("Player 2: %d", player2_score);  // Вывод очков
    printw("\n");
    // Печать первой строки
    for (int i = 1; i <= shirina_polya; i++) printw("-");
    printw("\n");
    // Заполнение строк от 2 до (высота поля-1)
    for (int i = 2; i <= visota_polya - 1; i++) {  // Основной рендеринг поля / i - переключение вывода строк
        printw(" ");
        for (int k = 2; k <= shirina_polya - 1; k++)  // Отрисовка строки посимвольно
            if (k == shirina_polya / 2)
                if (i == (int)ball_y && k == (int)ball_x)
                    printw("o");  // рисуем мяч
                else
                    printw("|");  // в противном случае сетка

            else {
                if (k == 2 && i == rocket1 && rocket1 < (rocket1_y + rocket_height)) {  // вывод ракетки 1
                    printw("@");
                    rocket1++;
                } else if (k == shirina_polya - 1 && i == rocket2 &&
                           rocket2 < (rocket2_y + rocket_height)) {  // вывод ракетки 2
                    printw("@");
                    rocket2++;
                } else {
                    if (i == (int)ball_y && k == (int)ball_x)
                        printw("o");  // рисуем мяч
                    else
                        printw(" ");  // в противном случае пробел
                }
            }

        printw("\n");
    }
    // Печать последней строки
    for (int i = 1; i <= shirina_polya; i++) printw("-");
    printw("\n");
}
