#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int cash;
    int quarters=0;
    int dimes =0;
    int nickels=0;
    int pennies=0;

    do
    {
        cash = get_int("Change owed: ");
    }
    while(cash < 0);

    for(int i = 0; i < cash/25; i++)
    {
        quarters+=1;
    }
    cash-= 25*quarters;
    for(int i = 0; i < cash/10; i++)
    {
        dimes+=1;
    }
    cash-= 10*dimes;
    for(int i = 0; i < cash/5; i++)
    {
        nickels+=1;
    }
    cash-= 5*nickels;
    for(int i = 0; i < cash/1; i++)
    {
        pennies+=1;
    }
    cash-= 1*pennies;
    printf("%i\n", pennies+nickels+dimes+quarters);
}
