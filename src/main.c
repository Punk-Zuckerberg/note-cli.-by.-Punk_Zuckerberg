#include "../include/note.h"
#include <string.h>
#include <stdlib.h>

enum Commands{
    ADD_NOTE = 1,
    SHOW_NOTES = 2,
    DELETE_NOTE = 3,
    STATUS_NOTE = 4,
    QUIT = 5,
};

int main(int argc, char *argv[]){

    if(argc > 1){
        if (strcmp(argv[1], "add") == 0) {
            add_note();
                exit(0);
        }
        if (strcmp(argv[1], "show") == 0) {
            show_notes();
                exit(0);
        }
        if (strcmp(argv[1], "delete") == 0) {
            delete_note();
                exit(0);
        }        
        if (strcmp(argv[1], "quit") == 0) {
            quit();
        }
        if (strcmp(argv[1], "status") == 0) {
            status_note();
        }
}
    else {

    while (1) {
        int choise = menu();
        switch (choise) {
            case ADD_NOTE:
                add_note();
                    break;
            case SHOW_NOTES:
                show_notes();
                    break;
            case DELETE_NOTE:
                delete_note();
                    break;
            case STATUS_NOTE:
                status_note();
                    break;
            case QUIT:
                quit();
                    break;
        }   
    }
}
    return 0;
}