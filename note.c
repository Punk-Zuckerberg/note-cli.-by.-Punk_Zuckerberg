#include "note.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE *note;
char choose[10]; //теперь это choise т.к. atoi
char text[10][100];
int count = 0;

int menu(){
    fputs("note-CLI. v0.1\n", stdout);
    fputs("1. add note\n", stdout);
    fputs("2. show notes\n", stdout);
    fputs("3. delete note\n", stdout);
    fputs("4. quit\n", stdout);
    fputs("choose action: ", stdout);
    fgets(choose, 5, stdin);

    int choise = atoi(choose);

    return choise;
}


void add_note(){
    note = fopen("note.txt", "a");
    fputs("Enter note: ", stdout);
    fgets(text[count], 100, stdin);
    fprintf(note, "%s", text[count]);
        count++;

    fclose(note);
}

void show_notes(){
    int count_notes = 0;
    printf("\n");
    fputs("Your notes: \n", stdout);

    note = fopen("note.txt", "r");

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

    printf("\n");
    note = fopen("note.txt", "r");
        while (fgets(text[count], 100, note) != NULL) {
            printf("%d. %s", count_notes + 1, text[count]);
            printf("\n");
                count_notes++;
        }
    printf("\n");

    fclose(note);

    fputs("Select the number of the note you want to delete: ", stdout);
    fgets(delete_choise, 100, stdin);
    int atoi_delete = atoi(delete_choise) - 1;

    for(int i = atoi_delete; i < count_notes; i++){
        strcpy(text[i], text[i + 1]);
    }
    count--;

    note = fopen("note.txt", "w");
        for(int i = 0; i < count; i++){
            fprintf(note, "%s", text[i]);
        }

    fclose(note);
}

void quit(){
    fputs("quit...\n", stdout);
        exit(0);
}