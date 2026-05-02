#include<stdio.h>
#include "game.h"

void draw(int tries);

int main() {
    for (int i = 6; i >= 0; i--) {
        printf("\n--- tries = %d ---\n", i);
        draw(i);
    }
}