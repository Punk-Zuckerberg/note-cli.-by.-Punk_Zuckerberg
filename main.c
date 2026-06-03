#include "note.h"
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    if(argc > 1){
        if (strcmp(argv[1], "add") == 0) {
            add_note();
        }
        if (strcmp(argv[1], "show") == 0) {
            show_notes();
        }
        if (strcmp(argv[1], "quit") == 0) {
            quit();
        }
}
    else {

    while (1) {
        int choise = menu();
        
        if (choise == 1) {
            add_note();
                exit(0);
        }
        if (choise == 2) {
            show_notes();
                exit(0);
        }
        if (choise == 3) {
            quit(); 
    }    

    }
}
    return 0;
}
