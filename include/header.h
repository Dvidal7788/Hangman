// HEADER FILE FOR HANGMAN
#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

void display_hangman(int);
void print_board(char correct_guesses[], char input[], char s[], int l, char wrong_guesses[], int num_wrong);
char *inf_buffer(char *prompt);
void display_wrong(char wrong_guesses[], int num_wrong);
void display_title(bool scroll);

#endif /* HEADER_H */