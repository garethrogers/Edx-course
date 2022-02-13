#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
//printf("%i\n", word1[0]);
    // TODO: Print the winner
    if(score1 > score2)
    {
        printf("Player 1 wins!");
    }
    if(score1 == score2)
    {
        printf("Tie!");
    }
    if(score1< score2)
    {
        printf("Player 2 wins!");
    }
}
int compute_score(string word)
{
    int sum = 0;
    int i = 0;
    int length = strlen(word);
    while(i < length)
    {
        char letter = word[i];
        // if uppercase, convert to lowercase
        if(((int) word[i] >= 65) && ((int) word[i] <= 90))
        {
            letter = tolower(word[i]);
            sum = sum + POINTS[(int) letter - 97];
        }
        //lowercase
        if(((int) word[i] >= 97) && ((int) word[i] <= 122))
        {
            sum = sum + POINTS[(int) letter - 97];
        }
    }
    return sum;
}