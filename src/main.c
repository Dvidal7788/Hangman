#include "../include/header.h"

int main(void)
{

    printf("\t\t\t~~~ HANGMAN ~~~\n");
    display_hangman(6);

    // --- PLAYER 1 ---
    char s[200];

    char *p1_input = inf_buffer("\nPLAYER 1, Enter name/phrase/word: ");

    printf("%s\n", p1_input);

    strcpy(s, p1_input);
    int l = strlen(p1_input);
    int punc = 0;

    // FIND PUNCTUATION
    for (int i = 0; i < l; i++)
    {
        if (!isalpha(p1_input[i]))
        {
            punc++;
        }
    }

    // Initialize correct/wrong guesses arrays
    char correct_guesses[l - punc + 1];
    for (int i = 0; i < l - punc + 1; i++)
    {
        correct_guesses[i] = 0;
    }

    char wrong_guesses[7];
    for (int i = 0; i < 7; i++)
    {
        wrong_guesses[i] = 0;
    }

    //                          ------------- PLAYER 2 -------------
    int num_correct = 0;
    int num_wrong = 0;
    char guess;

    do
    {
        dont_scroll_up();
        printf("\t\t\t~~~ HANGMAN ~~~\n\n");

        // DISPLAY BOARD & HANGMAN
        display_hangman(num_wrong);
        print_board(correct_guesses, p1_input, s, l, wrong_guesses, num_wrong);

        // USER INPUT:
        bool guessed_correctly_already;
        do
        {
            guessed_correctly_already = false;
            printf("\n\nPlayer 2, Enter letter: ");
            scanf("%c", &guess);
            // for (int c = getchar(); c != '\n' || c != EOF; c = getchar()){}
            while (getchar() != '\n');

            // check if already guessed correctly
            for (int i = 0; i < l - punc + 1; i++)
            {
                if (tolower(guess) == tolower(correct_guesses[i]))
                {
                    guessed_correctly_already = true;
                    printf("You already correctly guessed: %c", correct_guesses[i]);
                }
            }
        }
        while (guessed_correctly_already == true);

        // CHECK IF GUESS IS CORRECT - UPDATE correct_guesses[] OR wrong_guesses[] accordingly
        bool guessed_correct = false;
        for (int i = 0; i < l; i++)
        {
            if (tolower(guess) == tolower(s[i]))
            {
                num_correct++;
                correct_guesses[i] = p1_input[i];
                guessed_correct = true;
            }
        }
        if (guessed_correct == false)
        {
            wrong_guesses[num_wrong] = guess;
            num_wrong++;
        }


    }
    while (num_correct < l - punc && num_wrong < 6);



    // ----- END SCREEN -----
    print_board(correct_guesses, p1_input, s, l, wrong_guesses, num_wrong);
    display_hangman(num_wrong);

    if (num_wrong >= 6)
    {
        printf("\t\t\tYOU LOSE!!!!!\n");
        printf("\t\t\tThe word/phrase was: %s", p1_input);
    }
    else
    {
        printf("\n\t\t\t YOU WON!!!!!\n");
        printf("\n\t\t\t \\( ﾟヮﾟ)/\n\n");
        printf("Congrats! You correctly guessed: '%s'\n\n", p1_input);
    }

    free(p1_input);
    p1_input = NULL;
    return 0;
}