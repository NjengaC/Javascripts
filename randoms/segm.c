#include <stdio.h>
#include <stdlib.h>

ssize_t my_getline(char **lineptr) {
    if (lineptr == NULL) {
        return -1; // Invalid argument
    }

    char *buffer = NULL;
    size_t buffer_size = 0;
    ssize_t chars_read = 0;
    int c;

    while ((c = getchar()) != EOF && c != '\n') {
        if (chars_read >= buffer_size - 1) {
            // Resize the buffer when needed
            buffer_size += 64; // Increase buffer size (adjust as needed)
            char *temp = realloc(buffer, buffer_size);
            if (temp == NULL) {
                free(buffer);
                return -1; // Memory allocation error
            }
            buffer = temp;
        }
        buffer[chars_read++] = (char)c;
    }

    if (chars_read == 0 && c == EOF) {
        *lineptr = NULL; // No data read, set lineptr to NULL
        return -1;       // Reached end-of-file with no data read
    }

    buffer[chars_read] = '\0'; // Null-terminate the string

    *lineptr = buffer; // Assign the buffer to the caller's pointer

    return chars_read; // Return the number of characters read
}

int main() {
    char *line = NULL;
    ssize_t read;

    while (1) {
        printf("$ ");
        fflush(stdout); // Ensure the prompt is displayed

        read = my_getline(&line);

        if (read == -1) {
            // Check for EOF (Ctrl+D)
            if (feof(stdin)) {
                printf("\n"); // Print a newline and exit
                break;
            } else {
                perror("my_getline"); // Handle other errors
                break;
            }
        }

        // Print the entered command (line)
        printf("You entered: %s", line);

        // Free the dynamically allocated buffer
        free(line);
        line = NULL;
    }

    return 0;
}

