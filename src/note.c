#include "../include/note.h"#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define VERSION "v0.3"
#define INVALID_INPUT "invalid input"

FILE *note; //сам файл с заметками
char choose[10]; //теперь это choise т.к. atoi
char text[100][256]; //позже переделать в malloc & free
int count = 0;  //счетчик заметок

int menu(){
    fputs("note-CLI. "VERSION"\n", stdout);
    fputs("1. add note\n", stdout);
    fputs("2. show notes\n", stdout);
    fputs("3. delete note\n", stdout);
    fputs("4. status\n", stdout);
    fputs("5. quit\n", stdout);
    fputs("choose action: ", stdout);
    fgets(choose, 5, stdin);

    int choise = atoi(choose);

    return choise;
}


void add_note(){
    note = fopen("note.txt", "a");
    fputs("enter note: ", stdout);
    fgets(text[count], 100, stdin);
    fprintf(note, "%s", text[count]);
        count++;

    fclose(note);
}

void show_notes(){
    int count_notes = 0;
    printf("\n");
    fputs("your notes: \n", stdout);

    note = fopen("note.txt", "r");


    if (note == NULL) {
        fputs("no notes found.\n", stdout);
            return;
}

        while (fgets(text[count], 100, note) != NULL) {
            printf("%d. %s", count_notes + 1, text[count]);
            printf("\n");
                count_notes++;
        }   

    fclose(note);
}

void delete_note(){
    int count_notes = 0;
    char delete_choise[10];
    int atoi_delete;

    printf("\n");
    note = fopen("note.txt", "r");
        while (fgets(text[count], 100, note) != NULL) {
            printf("%d. %s", count_notes + 1, text[count]);
            printf("\n");
                count_notes++;
        }
    printf("\n");

    fclose(note);

    fputs("select the number of the note you want to delete: ", stdout);
    fgets(delete_choise, 100, stdin);

    while (1) {

    fputs("select note. try again: ", stdout);
    fgets(delete_choise, sizeof(delete_choise), stdin);

    atoi_delete = atoi(delete_choise) - 1;

    if (atoi_delete >= 0 && atoi_delete < count_notes) {
        break;
    }

    fputs(INVALID_INPUT"\n", stderr);
}
    atoi_delete = atoi(delete_choise) - 1;

    for(int i = atoi_delete; i < count_notes; i++){
        strcpy(text[i], text[i + 1]);
    }
    count--;

    note = fopen("note.txt", "w");
        for(int i = 0; i < count; i++){
            fprintf(note, "%s", text[i]);
        }
    printf("note deleted...\n");

    fclose(note);
}

void status_note(){     //v0.1
    int count_spaces = 0;
    int count_symbols = 0;

    fputs("status of notes:\n", stdout);
    for(int i = 0; i < count; i++){
        count_symbols += strlen(text[i]);
        for(size_t c = 0; c < strlen(text[i]); c++){

            if (text[i][c] == ' ') {
                count_spaces++;
            }
        }
    }
    printf("notes: %d\n", count);
    printf("words: %d\n", count_spaces + 1);    //or spaces
    printf("symbols: %d\n", count_symbols);
}

void quit(){
    fputs("quit...\n", stdout);
        exit(0);
}