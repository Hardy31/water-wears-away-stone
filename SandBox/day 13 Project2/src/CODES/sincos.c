#include <stdio.h>
#include <math.h>

int main() {
    int x,y;
    for (int phi = 0; phi < 360; phi += 45) {
        x = round(cos(phi * 3.14159265 / 180));
        y = round(sin(phi * 3.14159265 / 180));
        printf("X=%d Y=%d\n", x, y);
    }
    printf("-------------------\n");

    for (x=-1; x<=1; x++)
        for (y=-1; y<=+1; y++) 
            if (x != 0 || y != 0) //{} else
                printf("X=%d Y=%d\n", x, y);              
        
}