// August 2022

#include <header.h>

int main(void)
{

    display_title(false);
    display_hangman(6);

    // --- PLAYER 1 ---
    char *p1_input = inf_buffer("\nPLAYER 1, Enter name/phrase/word: ");

    // FIND PUNCTUATION
    int punc = 0;
    int len = strlen(p1_input);
    for (int i = 0; i < len; i++) {
        if (!isalpha(p1_input[i])) {
            punc++;
        }
    }

    // Initialize correct/wrong guesses arrays
    char correct_guesses[len+1];
    for (int i = 0; i < len+1; i++) {
        if (!isalpha(p1_input[i])) {
            correct_guesses[i] = p1_input[i];
        }
        else correct_guesses[i] = 0;
    }

    char wrong_guesses[7];
    for (int i = 0; i < 7; i++) {wrong_guesses[i] = 0;}

    //                          ------------- PLAYER 2 -------------
    int num_correct = 0, num_wrong = 0;
    char guess;

    do
    {
        // DISPLAY BOARD & HANGMAN
        display_title(true);
        display_hangman(num_wrong);
        print_board(p1_input, correct_guesses, wrong_guesses, num_wrong);

        // USER INPUT:
        bool guessed_correctly_already;
        do
        {
            guessed_correctly_already = false;
            printf("\n\nPlayer 2, Enter letter: ");
            scanf("%c", &guess);
            // for (int c = getchar(); c != '\n' && c != EOF; c = getchar());
            while (getchar() != '\n');

            // check if already guessed correctly
            for (int i = 0; i < len - punc + 1; i++) {
                if (tolower(guess) == tolower(correct_guesses[i])) {
                    guessed_correctly_already = true;
                    printf("You already correctly guessed: %c", correct_guesses[i]);
                }
            }
        }
        while (guessed_correctly_already == true);

        // CHECK IF GUESS IS CORRECT - UPDATE correct_guesses[] OR wrong_guesses[] accordingly
        bool guessed_correct = false;
        for (int i = 0; i < len; i++)
        {
            if (tolower(guess) == tolower(p1_input[i]))
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
    while (num_correct < len - punc && num_wrong < 6);



    // ----- END SCREEN -----
    print_board(p1_input, correct_guesses, wrong_guesses, num_wrong);
    display_hangman(num_wrong);

    if (num_wrong >= 6)
    {
        printf("\t\t\tYOU LOSE!!!!!\n");
        printf("\n\t\tThe word/phrase was: %s\n", p1_input);
    }
    else
    {
        printf("\n\t\t\t YOU WON!!!!!\n");
        printf("\n\t\t    \\( ﾟヮﾟ)/  \\( ﾟヮﾟ)/\n\n");
        printf("Congrats! You correctly guessed: '%s'\n\n", p1_input);
    }

    free(p1_input);
    p1_input = NULL;
    return 0;
}