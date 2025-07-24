#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include <ctype.h>

int convert(string player);
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    //轉換分數

    int score1 = convert(player1);
    int score2 = convert(player2);

    if(score1>score2)
    {
        printf("player1 win!\n");
    }
    else if(score1<score2)
    {
        printf("player2 win!\n");
    }
    else if(score1==score2)
    {
        printf("tie\n");
    }
}
int convert(string player)
{
    int score = 0;
    for(int i = 0, len = strlen(player); i < len; i++)
    {
        if (isupper(player[i]))
        {
            score += POINTS[player[i] - 'A'];
        }
        else if (islower(player[i]))
        {
            score += POINTS[player[i] - 'a'];
        }
    }
    return score;
}
