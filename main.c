#include <stdio.h>
#include <stdlib.h>
#include "note_st.h"
#include "utils/note_io.h"

int main()
{
  
  char operation;
  printf("\n");
  printf("Welcome to the Note manager\n");
  while(1)
  {
    int numofline = get_numoflines();
    struct Notes user_notes[numofline];
    
    printf("+---------------------------------------------+\n");
    printf("|                                             |\n");
    printf("|   1 <-- to the add note                     |\n");
    printf("|                                             |\n");
    printf("|   2 <-- to show the notes                   |\n");
    printf("|                                             |\n");
    printf("|   3 <-- to deleto note                      |\n");
    printf("|                                             |\n");
    printf("|   4 <-- to search the note by key word      |\n");
    printf("|                                             |\n");
    printf("|   q <-- to the quit from Note manage        |\n");
    printf("|                                             |\n");
    printf("+---------------------------------------------+\n");

    scanf(" %c", &operation);

    switch (operation) {
      case '1':
        add_note();
        break;
      case '2':
        get_notes(user_notes, numofline);
        show_note(user_notes, numofline);
        break;
      case '3':
        get_notes(user_notes, numofline);
        delete_note(user_notes, numofline);
        break;
      case '4':
        search_note();
        break;
      case 'q':
        printf("Exit...\n");
        return 0;
      default:
        printf("Unknown option.Try again\n");
      
    }

  }
  return 0;
}
