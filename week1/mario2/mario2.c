#include<stdio.h>
#include<cs50.h>

void print_row(int row, int height);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height? ");
    }
    while(height < 1 || height > 8);

    for(int i = 0; i < height; i++)
    {
        print_row(i + 1, height);
    }
}
void print_row(int row, int height)
{
    for(int n = 0; n < height-row; n++)
    {
        printf(" ");
    }

    for(int i = 0; i < row; i++)
    {
        printf("#");
    }
    printf("  ");

    for(int i = 0; i < row; i++)
    {
        printf("#");
    }
    printf("\n");
}

