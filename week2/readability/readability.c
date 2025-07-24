#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int count_letter(string usersentence);
int count_word(string usersentence);
int count_sentence(string usersentence);

int main(void)
{
    string usersentence = get_string("Text: ");
    int letters = count_letter(usersentence);
    int words = count_word(usersentence);
    int sentences = count_sentence(usersentence);

    int score = 0.0588 * letters/words *100 - 0.296 * sentences/words *100- 15.8;
    printf("total score: %i\n",score);
}

int count_letter(string usersentence)
{
    int count = 0;
    for(int i = 0, length = strlen(usersentence);i<length;i++)
    {
        if(isalpha(usersentence[i]))
        {
            count+=1;
        }
    }
    printf("letter count: %i\n",count);
    return count;
}
int count_word(string usersentence)
{
    int count = 0;
    for(int i = 0, length = strlen(usersentence);i<length;i++)
    {
        if(isspace(usersentence[i]))
        {
            count+=1;
        }
    }
    printf("word count: %i\n",count+1);
    return count+1;
}
int count_sentence(string usersentence)
{
    int count = 0;
    for(int i = 0, length = strlen(usersentence);i<length;i++)
    {
        if(usersentence[i] == '.'||usersentence[i] == '?'||usersentence[i] == '!')
        {
            count+=1;
        }
    }
    printf("sentence count: %i\n",count);
    return count;
}
