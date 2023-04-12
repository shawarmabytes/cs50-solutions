#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
//uppercase array
char ALPHA[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    printf("The score of Player 1 is: %i\n", score1);
    printf("The score of Player 2 is: %i\n", score2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (islower(word[i])) //converts lowercase to uppercase
        {
            word[i] = toupper(word[i]);
        }
        //printf("the word is: %s\n", word);

        for (int j = 0, v = strlen(ALPHA); j < v; j++) //iterates over the ALPHA array to check the index j
            //POINTS[j] to access the points of each letter
        {
            if (word[i] == ALPHA[j])
            {
                //printf("the letter is %c and the ALPHA letter is %c and the index is %i\n", word[i], ALPHA[j], j);
                score = score + POINTS[j];
            }
        }
    }
    return score;
}

