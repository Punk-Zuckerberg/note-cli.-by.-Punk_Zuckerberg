#include "note.h"

int main(){
while (1) {
    int choise = menu();    
    if (choise == 1) {
        add_note();
    }
    if (choise == 2) {
        show_notes();
    }
    if (choise == 3) {
        quit();
    }
}
    return 0;
}
