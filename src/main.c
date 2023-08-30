#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "../module/itrargs/itrargs.h"

typedef struct data
{
    char name[100];
    char content[100];
} Data;
int main(int argc, char **argv)
{
    ITRARGS_Line line;
    ITRARGS_init(&line);
    Data data[100];
    if (argc >= 2)
    {
        if (strcmp("--help", argv[1]) == 0 && strcmp("-h", argv[1]) == 0)
        {
            puts("Correct Usage: <program> <function> <name of atributtes1:type> ... <name of atributtes2:type>");
            puts("Valid function: <create>");
        }
        else if (strcmp("create", argv[1]) == 0)
        {
            static short int i, j;
            printf("Tamanho do argc:%d", argc);
            for (i = 2; i < argc; i++)
            {
                printf("Arg %d:%s\n", i, argv[i]);
                ITRARGS_tokens_w_pivot(&line, argv[i], ":");
            }

            // printf("%d", (int)sizeof(line.string) / sizeof(line.string[0]));
            ITRARGS_show(&line);

            ITRARGS_free(&line);

            return 0;
        }
    }
    else
    {
        puts("Usage: <program> <function> <name:type>");
    }
}