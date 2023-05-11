/*Double free*/
/*code 6*/
#include <stdlib.h>

int main()
{
    // Allocate memory for a buffer
    char *buffer = (char *)malloc(100);

    // Free the buffer
    free(buffer);

    // Attempt to free the buffer again
    free(buffer);

    return 0;
}
