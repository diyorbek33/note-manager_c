#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "note_io.h"
#include "../note_st.h"

static void delete_newlines(char *str){
  size_t lenght = strlen(str);
  if(lenght > 0 && str[lenght-1] == '\n')
  {
    str[lenght-1] = '\0';
  }
}

int get_numoflines(){
  int amountofn = 0;
  FILE *note_file = fopen("notes/my_notes.txt","r");

  char ch;
  while((ch = fgetc(note_file)) != EOF){
    if(ch == '\n'){
      amountofn++;
    }
  }
  fclose(note_file);
  return amountofn;
}

void get_notes(struct Notes *user_notes, int size){
  FILE *note_file = fopen("notes/my_notes.txt","r");
  char endoflines = '\n';
  char lines[1000];
  int i = 0;

  while (fgets(lines, sizeof(lines), note_file) && i < size) {
    delete_newlines(lines);

    char *token = strtok(lines,"|");
    if(token) user_notes[i].id = atoi(token);
    
    token = strtok(NULL,"|");
    if(token) strcpy(user_notes[i].title , token);

    token = strtok(NULL,"|");
    if(token) strcpy(user_notes[i].content, token);

    token = strtok(NULL,"|");
    if(token) strcpy(user_notes[i].created_at, token);
    
    i++;
  }
  fclose(note_file);
}



void add_note(){
  //clear the terminal
  system("clear");
  FILE *notes_file = fopen("notes/my_notes.txt","a");

  int id;
  char title[50];
  char content[500];
  char created_at[30];

  //get current time
  time_t now = time(NULL);
  struct tm *t = localtime(&now);
  strftime(created_at, sizeof(created_at), "%Y-%m-%d %H:%M:%S", t);

  printf("+----------------------------+\n");
  printf("| Enter a number of the task |\n");
  printf("+----------------------------+\n");

  scanf("%d",&id);
  getchar();

  printf("+----------------------------+\n");
  printf("| Enter a title of  the task |\n");
  printf("+----------------------------+\n");

  fgets(title,sizeof(title),stdin);
  delete_newlines(title);

  printf("+-----------------------------+\n");
  printf("| Enter a content of the task |\n");
  printf("+-----------------------------+\n");

  
  fgets(content,sizeof(content),stdin);
  delete_newlines(content);
  
  fprintf(notes_file,"%d|%s|%s|%s\n", id, title, content, created_at);
  fclose(notes_file);
}
void show_note(struct Notes *user_notes, int size){
  //
  system("clear");
  for(int i=0;i<size;i++){
    printf("+---------------------------------------------+\n");
    printf("ID: %d\n", user_notes[i].id);
    printf("Title: %s\n", user_notes[i].title);
    printf("Content: %s\n", user_notes[i].content);
    printf("TIme: %s\n", user_notes[i].created_at);
    printf("+---------------------------------------------+\n");
  }
}
void delete_note(struct Notes *user_notes, int size){
  FILE *note_file = fopen("notes/my_notes.txt", "w");

  system("clear");
  int delete_id;
  
  printf("+--------------------------------------------------+\n");
  printf("| Enter the ID of the task that you want to delete |\n");
  printf("+--------------------------------------------------+\n");
  
  scanf("%d", &delete_id);
  getchar();
  for(int i=0;i<size;i++){
    if(user_notes[i].id == delete_id){
      continue;
    }
    fprintf(note_file,"%d|%s|%s|%s\n", user_notes[i].id, user_notes[i].title, user_notes[i].content, user_notes[i].created_at);
  }

  system("clear");
  printf("+---------------+\n");
  printf("| Note deleted  |\n");
  printf("+---------------+\n");
  
  fclose(note_file);
}
void search_note(){
  printf("search_note funciton called\n");
}
