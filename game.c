#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#include<time.h>
#include "game.h"

#define TRIES 6
#define WORD 50

#define RESET   "\e[0m"
#define RED     "\e[0;31m"
#define GREEN   "\e[0;32m"
#define YELLOW  "\e[0;33m"
#define CYAN    "\e[0;106m"
#define WHITE   "\e[0;37m"


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
    char secret[WORD];
    char progres[WORD];
    int mistake=0;
    char letter;
    int optiune;
    char rep[WORD]="";

    printf("1. Joci cu un prieten\n2. Joci cu calculatorul\nAlege: ");
    scanf("%d", &optiune);

    if (optiune == 1) {
        printf("Jucator 1, scrie cuvantul: ");
        while (getchar() != '\n');
        fgets(secret, sizeof(secret), stdin);
        secret[strcspn(secret,"\n")]=0;
        system("cls");
    } else {
        int limba, dificultate;
        printf("Alege limba\n   1. Romana\n   2. Engleza\n"); scanf("%d", &limba);
        printf("Alege dificultatea\n   1. Usor\n   2. Mediu\n   3. Greu\n" ); scanf("%d", &dificultate);
        
        srand(time(NULL));

        if (limba == 1) { // Romana
                if (dificultate == 1) {
                        char cuvinte[][WORD] = {"MERE", "CASA", "MAMA", "SCOALA", "CERUL", "LUNA", "PADURE", "FOCUL", "IARNA", "VARA", "SOARE", "CARTE", "LAPTE", "PAINE", "MASA", "BANAT", "IARBA", "MUNTE", "FLOARE", "PESTE", "CANAL", "VANT", "NORI", "STELE"};
                        strcpy(secret, cuvinte[rand() % 24]);
                } else if (dificultate == 2) {
                        char cuvinte[][WORD] = {"AUTOMOBIL", "TELEVIZOR", "DICTIONAR", "CANTAR", "TASTATURA", "TELEFON", "FERESTRA", "ALBASTRU", "GRADINA", "POVESTE", "ORIZONT", "SARBATOARE", "VACANTA", "BUCATARIE", "CALATORIE", "BIROU", "Ochelari", "BILETASE", "FRIGIDER", "ZAPADA", "CULOARE", "UNIVERS", "AVION"};
                        strcpy(secret, cuvinte[rand() % 23]);
                } else {
                        char cuvinte[][WORD] = {"INCONSTITUTIONAL", "XILOFON", "STERNOCLEIDOMASTOIDIAN","ELECTROCARDIOGRAMA", "PARALELIPIPED", "ARHITECTURA", "DEZMEMBRAMANT", "ENCICLOPEDIE", "METAMORFOZA", "HIPOPOTAM", "SINCRONIZARE", "VULNERABILITATE", "EXTRATERESTRU", "INFRASTRUCTURA", "CONSOLIDARE", "TRANSFORMARE", "DETERMINARE", "PROEMINENTA", "INDESCRIPTIBIL"};
                        strcpy(secret, cuvinte[rand() % 19]);
                }
        } else { // Engleza
                if (dificultate == 1) {
                        char cuvinte[][WORD] = {"APPLE", "HOME", "SCHOOL", "CAT", "BIRD", "FISH", "GREEN", "BREAD", "SMILE", "WATER", "NIGHT", "LIGHT", "STORM", "CLOUD", "PHONE", "CHAIR", "TABLE", "GRASS", "FRUIT", "SHIRT", "DREAM", "SPACE", "HEART", "PIZZA" };
                        strcpy(secret, cuvinte[rand() % 24]);
                } else if (dificultate == 2) {
                        char cuvinte[][WORD] = {"MOUNTAIN", "KEYBOARD", "COMPUTER", "JOURNEY", "UNIVERSE", "EXPLORE", "VAMPIRE", "PYRAMID", "WHISPER", "FREEDOM", "HISTORY", "GALAXY", "AIRPORT", "WEATHER", "KITCHEN", "MORNING", "SILENCE", "BRAVERY", "BOTTLE", "PICTURE", "WINDOW", "GARDEN", "YELLOW", "BICYCLE"};
                        strcpy(secret, cuvinte[rand() % 24]);
                } else {
                        char cuvinte[][WORD] = {"THOROUGHLY", "QUEUE", "PNEUMONIA", "PSYCHOLOGY", "REFRIGERATOR", "ASTRONOMY", "CHAMPAGNE", "KNOWLEDGE", "RESTAURANT", "PHILOSOPHY", "AMBIGUOUS", "CHALLENGE", "LITERATURE", "EXPERIMENT", "MYSTERIOUS", "SOPHISTICATED", "BEAUTIFUL", "DANGEROUS", "CELEBRATION", "IMPOSSIBLE"};
                        strcpy(secret, cuvinte[rand() % 20]);
                }
        } system("cls");
    }


    for(int i=0; secret[i]!='\0' ;i++){
        secret[i]=toupper(secret[i]);
    }    

int len = strlen(secret);
for (int i = 0; i < len; i++) {
    if (secret[i] == ' ') {
        progres[i] = ' '; 
    } else {
        progres[i] = '_'; 
    }
}
progres[len] = '\0';

    while(mistake < TRIES && strcmp(secret, progres) != 0){
        system("cls");
        printf(CYAN "=== HANGMAN ===\n" RESET);

        printf(RED);
        draw(TRIES - mistake);
        printf(RESET);

        printf("Cuvant: " CYAN "%s" RESET "\n", progres);

        printf("Vieti: ");
        for(int i = 0; i < (TRIES - mistake); i++){
            printf(RED " <3 " RESET);
        } printf("\n");

        printf("Litere incercate: " YELLOW);
        for(int i = 0; i < strlen(rep); i++){
            printf("%c ", rep[i]);
        } printf(RESET "\n\n");
        

        printf("Introdu o litera: "); 
        scanf(" %c", &letter);
        letter=toupper(letter);
        
        if(!isalpha(letter)){
            printf(RED"\n---EROARE: '%c' nu este o litera! Incearca din nou.---\n" RESET, letter);
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

    system("cls");

    if (strcmp(secret, progres)==0) {
        printf(GREEN "===============================\n");
        printf("    FELICITARII! AI CASTIGAT!\n");
        printf(GREEN"===============================\n" RESET);

        printf(YELLOW); 
        draw(TRIES - mistake); 
        printf(RESET);

        printf("\nAi ghicit: " CYAN "%s" RESET "\n", secret);
    } else {
        printf(RED "===============================\n");
        printf("    GAME OVER! Te-a prins!\n");
        printf(RED "===============================\n" RESET);
        printf("\nCuvantul era: " CYAN "%s" RESET "\n", secret);
}

printf("\nApasa ENTER pentru a continua...");
while (getchar() != '\n');
getchar();

}

