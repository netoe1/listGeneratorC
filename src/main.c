#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct type
{
    char label[100];
    char type[100];
} Type;
const char *validTypes[] = {"char", "int", "float", "double"};

int verifyValidChar(const char *token, const char *validTypes[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (strcmp(token, validTypes[i]) == 0)
        {
            return 0;
        }
    }
    return -1;
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    Type type[100];
    int cont = -1;

    if (argc > 2)
    {
        if (strcmp(argv[1], "create") == 0)
        {
            for (int i = 2; i < argc; i++)
            {
                char *token = strtok(argv[i], ":");
                if (token != NULL && verifyValidChar(token, validTypes, argc - 2) == 0)
                {
                    strncpy(type[++cont].type, token, sizeof(type[0].type) - 1);
                    type[cont].type[sizeof(type[0].type) - 1] = '\0'; // Ensure null-terminated string
                    token = strtok(NULL, ":");
                    if (token != NULL)
                    {
                        strncpy(type[cont].label, token, sizeof(type[0].label) - 1);
                        type[cont].label[sizeof(type[0].label) - 1] = '\0'; // Ensure null-terminated string
                    }
                    else
                    {
                        printf("Error: Invalid input format for argument %s\n", argv[i]);
                        return 1;
                    }
                }
                else
                {
                    printf("Error: Invalid type format for argument %s\n", argv[i]);
                    return 1;
                }
            }
            for (int i = 0; i <= cont; i++)
            {
                printf("\nSec:%d:", i + 1);
                printf("\nType:%s\nLabel:%s", type[i].type, type[i].label);
            }
        }
        else
        {
            printf("Error: Invalid command. Usage: %s create <type:label>\n", argv[0]);
            return 1;
        }
    }
    else
    {
        printf("Usage: %s create <type:label>\n", argv[0]);
        return 1;
    }

    return 0;
}
