/* Practice 3: Strings
 * Variant 1
 * Printing characters from user input string if they have ASCII codes from 32 to 255
 *
 * Working with the first half of "extended" ASCII table (127 symbols), wihtout cyrillics
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
// #include <limits.h>

int main()
{
    // printf("\n");
    // printf("Limits.h: CHAR_MIN = %d, CHAR_MAX = %d\n", CHAR_MIN, CHAR_MAX); // -128, 127

    // for (int i = 32; i < 256; i++)
    // {
    //     printf("%d: ", i);
    //     putwchar(i); // 32-127 are printed, 128-255 are not printed
    //     printf("\t");
    // }
    // printf("\n");

    const int32_t max_str_len = 1024;
    char usr_string[max_str_len]; // char bounds to 127 - first half of ASCII table
    const int32_t min_code = 32;
    const int32_t max_code = 255;

    printf("\nEnter a string (without newlines; up to %d chars):\n", max_str_len - 1);
    if (!fgets(usr_string, max_str_len, stdin)) // ensuring null-termination with fgets
    {
        printf("Error reading input string.\n");
        return 1;
    }
    usr_string[strcspn(usr_string, "\n")] = 0; // deleting \n from the string to not count it in the length
    printf("\n");

    printf("len = %d\n", strlen(usr_string));
    printf("You entered: \"%s\"\n", usr_string);
    printf("\n");

    printf("Filtered string for symbols with ASCII codes from %d to %d:\n", min_code, max_code);
    printf("\"");
    size_t usr_str_len = strlen(usr_string);
    for (size_t i = 0; i < usr_str_len; i++)
    {
        if (usr_string[i] >= min_code && usr_string[i] <= max_code)
        {
            printf("%c", usr_string[i]);
        }
    }
    printf("\"\n");

    return 0;
}