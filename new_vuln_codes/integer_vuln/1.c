#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t a = UINT32_MAX; // Maximum value for a 32-bit unsigned integer
    int32_t b = INT32_MAX;   // Maximum value for a 32-bit signed integer
    int32_t c = INT32_MIN;   // Minimum value for a 32-bit signed integer

    // Perform arithmetic operations on the integers
    a = a + 1;
    b = b + 1;
    c = c - 1;

    // Print the results
    printf("a = %u\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    return 0;
}