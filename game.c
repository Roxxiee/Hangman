#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include "game.h"

#define TRIES 6
#define WORD 50

void draw(int left){
    printf("--- HANGMAN ---\n\n");
    switch(left){
        case 5: printf(" O \n"); break;
        case 4: printf(" O \n | \n"); break;
        case 3: printf("   O \n / | \n"); break;
        case 2: printf("    O \n  / | \\\n"); break;
        case 1: printf("    O \n  / | \\\n   / \n"); break;
        case 0: printf("   O \n / | \\\n  / \\\n"); break;
    } printf("\n");
}

int check(char letter, char secret[], char progres[]){
        int find=0;
        for(int i=0; i<strlen(secret); i++){
            if(secret[i]==letter){
                progres[i]=letter;
                find=1;
            }
        } return find;
} 

void start(){
    char secret[50];
    char progres[50];
    int mistake=0;
    char letter;

    int optiune;
    printf("1. Joci cu un prieten\n2. Joci cu calculatorul\nAlege: ");
    scanf("%d", &optiune);

    if (optiune == 1) {
        printf("Jucator 1, scrie cuvantul: ");
        scanf("%s", secret);
    } else {
        char lista[][10] = {"MERE", "SCOALA", "MASINA"};
        strcpy(secret, lista[0]); 
    }

    int len=strlen(secret);
    for(int i=0; i<len; i++){
        progres[i]='_';
    } progres[len]='\0';

    while(mistake < 6 && strcmp(secret, progres) != 0){
        draw(mistake);
        printf("Cuvant: %s\n" , progres);
        printf("Greseli: %d /6 \n", mistake);

        printf("Introdu o litera: "); 
        scanf(" %c", &letter);
        letter=toupper(letter); 

        if (check(letter, secret, progres) == 0) {
            mistake++;
            printf("Gresit!\n");
        } else {
            printf("Corect!\n");
        }
    }

    if (mistake < 6) {
        printf("BRAVO! Ai castigat!\n");
    } else {
        printf("GAME OVER! Te-a prins!\n");
}

}

