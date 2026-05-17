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

//Fundal colorat cu text negru 
#define BG_ROZ       "\e[30;105m"  
#define BG_TURCOAZ   "\e[30;106m"  
#define BG_ALB       "\e[30;107m"

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

    int theme = 0;

    // 0. MENIUL DE SELECTIE CULOARE
    system("cls");
    printf("=========================================\n");
    printf("       CHOOSE GAME COLOR / ALEGE CULOARE \n");
    printf("=========================================\n");
    printf("  0. Default Terminal (Negru)\n");
    printf("  1. Pink Mode (Fundal Roz)\n");
    printf("  2. Cyan Mode (Fundal Turcoaz)\n");
    printf("  3. Light Mode (Fundal Alb)\n\n");
    printf("Alegere: ");
    scanf("%d", &theme);

    system("cls");

    // Fundalul ales
    if (theme == 1)       printf(BG_ROZ);
    else if (theme == 2)  printf(BG_TURCOAZ);
    else if (theme == 3)  printf(BG_ALB);
    else                  printf(RESET);

    system("cls"); 

    // 1. INTRO 
    printf(RED);
    printf(" _    _                    _                                \n");
    printf("| |  | |                  | |                               \n");
    printf("| |__| | __ _ _ __   __ _ | |__ ___   __ _ _ __             \n");
    printf("|  __  |/ _` | '_ \\ / _` || '_ ` _ \\ / _` | '_ \\            \n");
    printf("| |  | | (_| | | | | (_| || | | | | | (_| | | | |           \n");
    printf("|_|  |_|\\__,_|_| |_|\\__, ||_| |_| |_|\\__,_|_| |_|           \n");
    printf("                     __/ |                                  \n");
    printf("                    |___/                                   \n");
    
    // Revenim la textul temei (daca e fundal deschis, textul ramane negru)
    if (theme == 1)      printf(BG_ROZ);
    else if (theme == 2) printf(BG_TURCOAZ);
    else if (theme == 3) printf(BG_ALB);
    else                 printf(RESET);

    printf(GOLD "\n=========================================================\n");
    printf("          Welcome to the ultimate challenge...           \n");
    printf("=========================================================\n");
    
    if (theme == 0) printf(BOLD_WHITE "\n   Ready to save your character?\n" RESET);
    else            printf("\n   Ready to save your character?\n");
    
    printf("\n   >>> Press [ENTER] to start...");
    
    while (getchar() != '\n'); 
    getchar(); 
    system("cls");

    // 2. SELECTARE LIMBA
    if (theme == 0) printf(PINK);
    printf("=========================================================\n");
    printf("              SELECT YOUR LANGUAGE / LIMBA               \n");
    printf("=========================================================\n");
    if (theme == 0) printf(RESET);

    printf("\n     1. ROMANA\n     2. ENGLISH\n\n");
    
    if (theme == 0) printf(BOLD_WHITE "Alegere: " RESET);
    else            printf("Alegere: ");
    
    scanf("%d", &limba);
    system("cls");

    // 3. SELECTIE MOD SI DIFICULTATE 
    if (limba == 1) { // ROMANA
        if (theme == 0) printf(MAGENTA "=== MOD DE JOC ===\n\n" RESET);
        else            printf("=== MOD DE JOC ===\n\n");
        
        printf("     1. SOLO MODE (Contra calculatorului)\n");
        printf("     2. MULTIPLAYER (Cu un prieten)\n");
        printf("\nAlege: ");
        scanf("%d", &optiune);
        system("cls");

        if (optiune == 1) {
            if (theme == 0) printf(LIME "=== DIFICULTATE ===\n\n" RESET);
            else            printf("=== DIFICULTATE ===\n\n");
            printf("     1. Usor\n     2. Mediu\n     3. Greu\n\nAlege: ");
            scanf("%d", &dificultate);
        } else {
            if (theme == 0) printf(BOLD_WHITE "Jucator 1, scrie cuvantul: " RESET);
            else            printf("Jucator 1, scrie cuvantul: ");
            while(getchar() != '\n');

            fgets(secret, sizeof(secret), stdin);
            secret[strcspn(secret, "\n")] = '\0';
        }
    } 
    else { // ENGLISH 
        if (theme == 0) printf(MAGENTA "=== GAME MODE ===\n" RESET);
        else            printf("=== GAME MODE ===\n");
        printf("\n     1. SOLO MODE (Vs Computer)\n");
        printf("     2. MULTIPLAYER (Vs Friend)\n");
        printf("\nChoice: ");
        scanf("%d", &optiune);
        system("cls");

        if (optiune == 1) {
            if (theme == 0) printf(LIME "=== DIFFICULTY ===\n" RESET);
            else            printf("=== DIFFICULTY ===\n");
            printf("\n     1. Easy\n     2. Medium\n     3. Hard\n\nChoice: ");
            scanf("%d", &dificultate);
        } else {
            if (theme == 0) printf(BOLD_WHITE "Player 1, type the secret word: " RESET);
            else            printf("Player 1, type the secret word: ");
            while(getchar() != '\n');

            fgets(secret, sizeof(secret), stdin);
            secret[strcspn(secret, "\n")] = '\0';
        }
    }

    // 4. SOLO MODE (Citire din fisier text)
    if (optiune == 1) {
        char cale_fisier[50];

        if (limba == 1) { // Romana
            if (dificultate == 1)      strcpy(cale_fisier, "words/ro_usor.txt");
            else if (dificultate == 2) strcpy(cale_fisier, "words/ro_mediu.txt");
            else                       strcpy(cale_fisier, "words/ro_greu.txt");
        } else { // Engleza
            if (dificultate == 1)      strcpy(cale_fisier, "words/eng_easy.txt");
            else if (dificultate == 2) strcpy(cale_fisier, "words/eng_medium.txt");
            else                       strcpy(cale_fisier, "words/eng_hard.txt");
        }

        FILE *f = fopen(cale_fisier, "r");
        if (f == NULL) {
            printf(RED "EROARE: Nu am putut deschide fisierul de cuvinte %s!\n" RESET, cale_fisier);
            return; 
        }

        int linie_aleasa = rand() % 20;
        
        for (int i = 0; i <= linie_aleasa; i++) {
            if(fgets(secret, sizeof(secret), f)==NULL){
                break;
            }
        }
                
        fclose(f); 

        for (int i = 0; secret[i] != '\0'; i++) {
            if (secret[i] == '\n' || secret[i] == '\r') {
                secret[i] = '\0';
                break; 
            }
        }
    }

    // 5. PREGATIRE PROGRES JOC
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

    // 6. JOC
    while(mistake < TRIES && strcmp(secret, progres) != 0){
        system("cls");

        // Reactivam fundalul curat o singura data
        if (theme == 1)       printf(BG_ROZ);
        else if (theme == 2)  printf(BG_TURCOAZ);
        else if (theme == 3)  printf(BG_ALB);
        else                  printf(RESET);

        
        printf(GOLD "=========================================================\n");
        if (limba == 1) printf("                  JOCUL SPANZURATOAREA                   \n");
        else            printf("                     HANGMAN GAME                        \n");
        printf("=========================================================\n");

        printf(RED);
        draw(TRIES - mistake);
        
        
        if (theme == 1)       printf(BG_ROZ);
        else if (theme == 2)  printf(BG_TURCOAZ);
        else if (theme == 3)  printf(BG_ALB);
        else                  printf(RESET);

        printf(GOLD "---------------------------------------------------------\n");
        
        // Afisam cuvantul cu spatii mari ca sa arate aerisit
        printf("  CUVANT:          " PURPLE);
        for(int i = 0; i < len; i++) {
            printf("%c ", progres[i]); 
        }
        
        if (theme == 1)       printf(BG_ROZ);
        else if (theme == 2)  printf(BG_TURCOAZ);
        else if (theme == 3)  printf(BG_ALB);
        else                  printf(RESET);
        printf("\n\n");

        printf("  VIETI RAMASE:    ");
        for(int i = 0; i < (TRIES - mistake); i++){
            printf(RED "<3 " RESET);
            if (theme == 1)       printf(BG_ROZ);
            else if (theme == 2)  printf(BG_TURCOAZ);
            else if (theme == 3)  printf(BG_ALB);
        }
        for(int i = 0; i < mistake; i++){
            printf("X  ");
        }
        printf("\n");

        printf("  LITERE INCERCATE: " YELLOW);
        for(int i = 0; i < strlen(rep); i++){
            printf("%c ", rep[i]);
        }
        
        if (theme == 1)       printf(BG_ROZ);
        else if (theme == 2)  printf(BG_TURCOAZ);
        else if (theme == 3)  printf(BG_ALB);
        else                  printf(RESET);
        printf("\n");
        printf(GOLD "---------------------------------------------------------\n\n");
        
        printf("  >> Introdu o litera: "); 
        scanf(" %c", &letter);
        letter=toupper(letter);
        
        if(!isalpha(letter)){
            printf(RED"\n  --- EROARE: '%c' nu este o litera! Incearca din nou. ---\n" RESET, letter);
            if (theme == 1)       printf(BG_ROZ);
            else if (theme == 2)  printf(BG_TURCOAZ);
            else if (theme == 3)  printf(BG_ALB);
            printf("  Apasa ENTER pentru a continua...");
            while(getchar() != '\n');
            getchar();
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
            printf(RED"\n  --- Ai mai incercat litera '%c'! Incearca alta. ---\n" RESET, letter);
            if (theme == 1)       printf(BG_ROZ);
            else if (theme == 2)  printf(BG_TURCOAZ);
            else if (theme == 3)  printf(BG_ALB);
            printf("  Apasa ENTER pentru a continua...");
            while(getchar() != '\n');
            getchar();
            continue;
        }

        int n=strlen(rep);
        rep[n]=letter;
        rep[n+1]='\0';

        if (check(letter, secret, progres) == 0) {
            mistake++;
        }
    }

    // 7. ECRAN FINAL 
    system("cls");
    if (theme == 1)       printf(BG_ROZ);
    else if (theme == 2)  printf(BG_TURCOAZ);
    else if (theme == 3)  printf(BG_ALB);
    else                  printf(RESET);
    system("cls");

    if (strcmp(secret, progres)==0) {
        printf(GREEN "=========================================================\n");
        printf("                FELICITARII! AI CASTIGAT!                \n");
        printf("=========================================================\n");

        printf(YELLOW); 
        draw(TRIES - mistake); 
        
        if (theme == 1)       printf(BG_ROZ);
        else if (theme == 2)  printf(BG_TURCOAZ);
        else if (theme == 3)  printf(BG_ALB);
        else                  printf(RESET);

        printf("\n  Ai ghicit: " PURPLE "%s" RESET "\n", secret);
    } else {
        printf(RED "=========================================================\n");
        printf("                 GAME OVER! TE-A PRINS!                  \n");
        printf("=========================================================\n");
        
        printf(RED);
        draw(0);

        if (theme == 1)       printf(BG_ROZ);
        else if (theme == 2)  printf(BG_TURCOAZ);
        else if (theme == 3)  printf(BG_ALB);
        else                  printf(RESET);

        printf("\n  Cuvantul era: " PURPLE "%s" RESET "\n", secret);
    }

    if (theme == 1)       printf(BG_ROZ);
    else if (theme == 2)  printf(BG_TURCOAZ);
    else if (theme == 3)  printf(BG_ALB);
    printf("\n  Apasa ENTER pentru a continua...");
    while (getchar() != '\n');
    getchar();
    
   
    printf(RESET);
    system("cls");
}