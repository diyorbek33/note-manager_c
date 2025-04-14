#ifndef NOTE_IO_H
#define NOTE_IO_H

#include "../note_st.h"


void get_notes(struct Notes *user_notes, int size);
int get_numoflines();
void add_note();
void show_note(struct Notes *user_notes, int size);
void delete_note(struct Notes *user_notes, int size);
void search_note();

#endif
