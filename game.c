#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include "game.h"

#define TRIES 6
#define WORD 50

void draw(int left){
    printf("\n--- HANGMAN ---\n\n");
    switch(left){
        case 6: printf("\n"); break;
        case 5: printf("   O \n"); break;
        case 4: printf("   O \n   | \n"); break;
        case 3: printf("   O \n / | \n"); break;
        case 2: printf("   O \n / | \\\n"); break;
        case 1: printf("   O \n / | \\\n  /\n"); break;
        case 0: printf("   O \n / | \\\n  / \\\n"); break;
    } printf("\n");
}

int check(char letter, char secret[], char progres[]){
        int find=0;
        int len=strlen(secret);
        for(int i=0; i<len; i++){
            if(secret[i]==letter && progres[i]=='_'){
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
    char rep[50]="";

    printf("1. Joci cu un prieten\n2. Joci cu calculatorul\nAlege: ");
    scanf("%d", &optiune);

    if (optiune == 1) {
        printf("Jucator 1, scrie cuvantul: ");
        scanf("%s", secret);
    } else {
        char lista[][10] = {"MERE", "SCOALA", "MASINA", "PROGRAMARE"};
        strcpy(secret, lista[2]); 
    }

    int len=strlen(secret);
    for(int i=0; i<len; i++){
        progres[i]='_';
    } progres[len]='\0';

    while(mistake < TRIES && strcmp(secret, progres) != 0){
        
        printf("Cuvant: %s\n" , progres);
        printf("Greseli: %d /6 \n", mistake);
        printf("Litere incercate: ");
        for(int i=0; i<strlen(rep); i++){
            printf("%c ", rep[i]);
        }printf("\n");
        

        printf("Introdu o litera: "); 
        scanf(" %c", &letter);
        letter=toupper(letter);
        
        if(!isalpha(letter)){
            printf("\n---EROARE: '%c' nu este o litera! Incearca din nou.---\n", letter);
            continue;
        }

        int used=0;
        for(int i=0; i<strlen(rep); i++){
            if(rep[i]==letter){
                used=1;
                break;
            }
        }

        if(used){
            printf("\n---Ai mai incercat litera '%c'! Incearca alta. ---\n", letter);
            continue;
        }

        int n=strlen(rep);
        rep[n]=letter;
        rep[n+1]='\0';


        if (check(letter, secret, progres) == 0) {
            mistake++;
            draw(TRIES-mistake);
            printf("Gresit!\n");
        } else {
            printf("Corect!\n");
        }
    }

    if (strcmp(secret, progres)==0) {
        printf("BRAVO! Ai castigat!\n");
    } else {
        printf("GAME OVER! Te-a prins!\n");
}

}

