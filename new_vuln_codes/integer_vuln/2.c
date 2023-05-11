#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_items = 100000;
    int item_price = 50000;
    int total_sales = num_items * item_price;
    int cogs = 700000;
    int profit = total_sales - cogs;
    printf("Profit: $%d\n", profit);
    return 0;
}