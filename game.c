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
#define CYAN    "\e[0;106m"  //High Intensity backgrounds
#define WHITE   "\e[0;37m"
#define PURPLE  "\e[1;35m"

#define MAGENTA "\e[1;35m"
#define LIME    "\e[1;32m"
#define GOLD    "\e[1;33m"
#define PINK    "\e[1;95m"
#define ORANGE  "\e[38;5;208m"
#define BOLD_WHITE "\e[1;37m"

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
    int limba, dificultate;

    srand(time(NULL));

    // 1. INTRO
    system("cls");
    printf(GOLD "=============================================\n");
    printf("     Welcome to the ultimate challenge...    \n");
    printf("                                             \n");
    printf(RED  "           H A N G M A N    G A M E          \n");
    printf(GOLD "                                             \n");
    printf("=============================================\n" RESET);
    
    printf(BOLD_WHITE "\n   Ready to save your character?\n" RESET);
    printf("\n   >>>Press [ENTER] to start...");
    
    while (getchar() != '\n'); 
    getchar(); 
    system("cls");

    // 2. SELECTARE LIMBA
    printf(PINK "=================================\n");
    printf("   SELECT YOUR LANGUAGE / LIMBA  \n");
    printf("=================================\n" RESET);
    printf("\n     1. ROMANA\n     2. ENGLISH\n\n");
    printf(BOLD_WHITE "Alegere: " RESET);
    scanf("%d", &limba);
    system("cls");

    // 3. SELECTIE MOD SI DIFICULTATE 
    if (limba == 1) { // ROMANA
        printf(MAGENTA "=== MOD DE JOC ===\n\n" RESET);
        printf("     1. SOLO MODE (Contra calculatorului)\n");
        printf("     2. MULTIPLAYER (Cu un prieten)\n");
        printf("\nAlege: ");
        scanf("%d", &optiune);
        system("cls");

        if (optiune == 1) {
            printf(LIME "=== DIFICULTATE ===\n\n" RESET);
            printf("     1. Usor\n     2. Mediu\n     3. Greu\n\nAlege: ");
            scanf("%d", &dificultate);
        } else {
            printf(BOLD_WHITE "Jucator 1, scrie cuvantul: " RESET);
            scanf("%s", secret); 
        }
    } 
    else { // ENGLISH 
        printf(MAGENTA "=== GAME MODE ===\n" RESET);
        printf("\n     1. SOLO MODE (Vs Computer)\n");
        printf("     2. MULTIPLAYER (Vs Friend)\n");
        printf("\nChoice: ");
        scanf("%d", &optiune);
        system("cls");

        if (optiune == 1) {
            printf(LIME "=== DIFFICULTY ===\n" RESET);
            printf("\n     1. Easy\n     2. Medium\n     3. Hard\n\nChoice: ");
            scanf("%d", &dificultate);
        } else {
            printf(BOLD_WHITE "Player 1, type the secret word: " RESET);
            scanf("%s", secret);
        }
    }

    // 4. SOLO MODE
    if (optiune == 1) {
        if (limba == 1) { // Romana
            if (dificultate == 1) { 
                char cuvinte[][WORD] = {"MAMA", "TATA", "CASA", "MASA", "SCOALA", "VACANTA", "BANANA", "ALBINA", "LALEA", "SOARE", "IARNA", "VARA", "MERE", "CARTE", "TELEFON", "GRADINA", "POVESTE", "LAPTE", "PAINE", "CAFEA"};
                strcpy(secret, cuvinte[rand() % 20]);
            } else if (dificultate == 2) { 
                char cuvinte[][WORD] = {"ORIZONT", "BIROU", "AVION", "MUNTE", "FLOARE", "PADURE", "STELA", "VANT", "NORI", "CULOARE", "UNIVERS", "ZAPADA", "FRIGIDER", "OCHELARI", "TASTATURA", "CANTAR", "FERESTRA", "DICTIONAR", "PLANETA", "RUCHET"};
                strcpy(secret, cuvinte[rand() % 20]);
            } else { 
                char cuvinte[][WORD] = {"XILOFON", "FOCUL", "AXA", "VREJ", "STERNOCLEIDOMASTOIDIAN", "INCONSTITUTIONAL", "PARALELIPIPED", "METAMORFOZA", "HIPOPOTAM", "VULNERABILITATE", "INFRASTRUCTURA", "ENCICLOPEDIE", "SNC", "DEZMEMBRAMANT", "JAZZ", "FALX", "BOX", "OXID", "CHIRURG", "SFINX"};
                strcpy(secret, cuvinte[rand() % 20]);
            }
        } else { // Engleza
            if (dificultate == 1) {
                char cuvinte[][WORD] = {"APPLE", "BANANA", "SCHOOL", "HOME", "SMILE", "PIZZA", "COFFEE", "YELLOW", "SUMMER", "WINTER", "FLOWER", "GARDEN", "WINDOW", "BOTTLE", "ORANGE", "KITTEN", "PLAYER", "STREET", "HAMMER", "SPOON"};
                strcpy(secret, cuvinte[rand() % 20]);
            } else if (dificultate == 2) {
                char cuvinte[][WORD] = {"MOUNTAIN", "JOURNEY", "UNIVERSE", "EXPLORE", "HISTORY", "GALAXY", "WEATHER", "KITCHEN", "SILENCE", "BRAVERY", "BICYCLE", "KEYBOARD", "MORNING", "PICTURE", "BOTTLE", "YELLOW", "COMPUTER", "ASTRONOMY", "RESTAURANT", "DANGEROUS"};
                strcpy(secret, cuvinte[rand() % 20]);
            } else {
                char cuvinte[][WORD] = {"QUEUE", "PNEUMONIA", "THOROUGHLY", "PSYCHOLOGY", "AMBIGUOUS", "SOPHISTICATED", "MYSTERIOUS", "CHALLENGE", "PHILOSOPHY", "CHAMPAGNE", "LYNX", "RHYTHM", "VORTEX", "UNKNOWN", "WRIGHT", "GNOME", "PHARAOH", "SUBTLE", "SYNDROME", "BUREAU"};
                strcpy(secret, cuvinte[rand() % 20]);
            }
        }
    }


for(int i=0; secret[i]!='\0'; i++){
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

    //7. Jocul
    while(mistake < TRIES && strcmp(secret, progres) != 0){
        system("cls");

        printf(RED);
        draw(TRIES - mistake);
        printf(RESET);

        printf("Cuvant: " PURPLE  "%s" RESET "\n", progres);

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

        printf("\nAi ghicit: " PURPLE "%s" RESET "\n", secret);
    } else {
        printf(RED "===============================\n");
        printf("    GAME OVER! Te-a prins!\n");
        printf(RED "===============================\n" RESET);
        printf("\nCuvantul era: " PURPLE "%s" RESET "\n", secret);
}

printf("\nApasa ENTER pentru a continua...");
while (getchar() != '\n');
getchar();

}

