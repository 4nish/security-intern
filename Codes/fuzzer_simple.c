// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <string.h>
// #include <regex.h>

// // Define the maximum length of the input string
// #define MAX_INPUT_LENGTH 100

// // Define the number of initial seed inputs
// #define NUM_SEED_INPUTS 10

// // Define the maximum number of fuzzing iterations
// #define MAX_FUZZ_ITERATIONS 1000

// // Define the maximum fuzzing time in milliseconds
// #define MAX_FUZZ_TIME 10000

// // Define the target problem function
// void target_problem(char *input, char bugs[][MAX_INPUT_LENGTH], int *num_bugs)
// {
//   // Define a regular expression pattern for a simple email address
//   const char *pattern = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";

//   // Compile the regular expression pattern
//   regex_t regex;
//   int reti = regcomp(&regex, pattern, REG_EXTENDED);
//   if (reti)
//   {
//     fprintf(stderr, "Could not compile regex\n");
//     return;
//   }

//   // Execute the regular expression pattern on the input string
//   reti = regexec(&regex, input, 0, NULL, 0);
//   if (!reti)
//   {
//     printf("Valid email address: %s\n", input);
//   }
//   else if (reti == REG_NOMATCH)
//   {
//     printf("Invalid email address: %s\n", input);
//     // Add the input to the set of bugs
//     if (*num_bugs < MAX_INPUT_LENGTH) {
//       strncpy(bugs[*num_bugs], input, MAX_INPUT_LENGTH - 1);
//       bugs[*num_bugs][MAX_INPUT_LENGTH - 1] = '\0'; // Add null terminator
//       (*num_bugs)++;
//     } else {
//       fprintf(stderr, "Maximum number of bugs reached\n");
//     }
//   }
//   else
//   {
//     fprintf(stderr, "Error executing regex\n");
//   }

//   // Free the compiled regular expression
//   regfree(&regex);
// }

// int main()
// {
//   // Seed the random number generator
//   srand(time(NULL));

//   // Initialize the set of bugs
//   char bugs[MAX_INPUT_LENGTH][MAX_INPUT_LENGTH];
//   int num_bugs = 0;

//   // Initialize the initial seed inputs
//   char seed_inputs[NUM_SEED_INPUTS][MAX_INPUT_LENGTH] = {
//       "hello",
//       "world",
//       "test",
//       "input",
//       "password",
//       "password1",
//       "password1234",
//       "1234",
//       "5678",
//       "0000"};

//   // Initialize the number of fuzzing iterations
//   int fuzz_iterations = 0;

//   // Fuzz for a fixed amount of time
//   clock_t start_time = clock();
//   while ((clock() - start_time) * 1000 / CLOCKS_PER_SEC < MAX_FUZZ_TIME)
//   {
//     // Select a random seed input
//     int input_index = rand() % NUM_SEED_INPUTS;
//     char *input = seed_inputs[input_index];
//     // Call the target problem function with the input
//     target_problem(input, bugs, &num_bugs);

//     // Increment the number of fuzzing iterations
//     fuzz_iterations++;

//     // Check if the maximum number of fuzzing iterations has been reached
//     if (fuzz_iterations >= MAX_FUZZ_ITERATIONS)
//     {
//       break;
//     }
//   }

//   // Print the set of bugs
//   printf("Bugs:\n");
//   for (int i = 0; i < num_bugs; i++)
//   {
//     printf("%s\n", bugs[i]);
//   }

//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <regex.h>

// Define the maximum length of the input string
#define MAX_INPUT_LENGTH 100

// Define the number of initial seed inputs
#define NUM_SEED_INPUTS 10

// Define the maximum number of fuzzing iterations
#define MAX_FUZZ_ITERATIONS 1000

// Define the maximum fuzzing time in milliseconds
#define MAX_FUZZ_TIME 10000

// Define the target problem function
void target_problem(char *input, char bugs[][MAX_INPUT_LENGTH], int *num_bugs)
{
    // Define a regular expression pattern for a simple email address
    const char *pattern = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";

    // Compile the regular expression pattern
    regex_t regex;
    int reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti)
    {
        fprintf(stderr, "Could not compile regex\n");
        return;
    }

    // Execute the regular expression pattern on the input string
    reti = regexec(&regex, input, 0, NULL, 0);
    if (!reti)
    {
        printf("Valid email address: %s\n", input);
    }
    else if (reti == REG_NOMATCH)
    {
        printf("Invalid email address: %s\n", input);
        // Add the input to the set of bugs
        strncpy(bugs[*num_bugs], input, MAX_INPUT_LENGTH - 1);
        bugs[*num_bugs][MAX_INPUT_LENGTH - 1] = '\0'; // make sure string is null-terminated
        (*num_bugs)++;
    }
    else
    {
        fprintf(stderr, "Error executing regex\n");
    }

    // Free the compiled regular expression
    regfree(&regex);
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the set of bugs
    char bugs[MAX_FUZZ_ITERATIONS][MAX_INPUT_LENGTH] = {0}; // initialize all elements to zero
    int num_bugs = 0;

    // Initialize the initial seed inputs
    char seed_inputs[NUM_SEED_INPUTS][MAX_INPUT_LENGTH] = {
        "hello",
        "world",
        "test",
        "input",
        "password",
        "password1",
        "password1234",
        "1234",
        "5678",
        "0000"};

    // Initialize the number of fuzzing iterations
    int fuzz_iterations = 0;

    // Fuzz for a fixed amount of time
    clock_t start_time = clock();
    while ((clock() - start_time) * 1000 / CLOCKS_PER_SEC < MAX_FUZZ_TIME)
    {
        // Select a random seed input
        int input_index = rand() % NUM_SEED_INPUTS;
        char *input = seed_inputs[input_index];

        // Call the target problem function with the input
        target_problem(input, bugs, &num_bugs);

        // Increment the number of fuzzing iterations
        fuzz_iterations++;

        if (fuzz_iterations >= MAX_FUZZ_ITERATIONS)
        {
            break;
        }
    }

    // Print the set of bugs
    printf("Bugs:\n");
    for (int i = 0; i < num_bugs; i++)
    {
        printf("%s\n", bugs[i]);
    }

    return 0;
}