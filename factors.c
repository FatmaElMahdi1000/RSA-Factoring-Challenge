#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 10000

void factorize(const char *numberStr) 
{
    long long number = atoll(numberStr); 
    long long p = 0, q = 0;

    for (long long i = 2; i * i <= number; i++) 
    {
        if (number % i == 0) {
            p = i;
            q = number / i;
            break;
        }
    }

    if (p != 0 && q != 0) 
    {
        printf("%lld = %lld * %lld\n", number, p, q);
    }
}

void openFile(const char *filename) 
{
    char *buffer;

    buffer = (char *)malloc(LIMIT * sizeof(char));
    if (buffer == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        fprintf(stderr, "ERROR OPENING FILE\n");
        free(buffer);
        return;
    }

    while (fgets(buffer, LIMIT, fp) != NULL) 
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        factorize(buffer);
    }
    free(buffer);
    fclose(fp); 
}

int main(int argc, char *argv[]) {
    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    openFile(argv[1]);
    return 0;
}