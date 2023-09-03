#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct validArgs
{
    char type[100];
    char label[100];
} ValidArgs;

ValidArgs args[100];
int positionArgs = 0;

const char *valid[] = {"int", "char", "float", "double"};

char *
findArg(int argc, char **argv, char *argToFind);
char *verifingValid(int argc, char **argv, char *arg);
int addingAndTokenizeArgs(int argc, char **argv);
void seeAll();
int countStr(const char *ptr[]);
int indexOf(const char *haystack, const char *needle);
int main(int argc, char **argv)
{
    positionArgs = 0;
    addingAndTokenizeArgs(argc, argv);
    seeAll();

    return 0;
}

char *findArg(int argc, char **argv, char *argToFind)
{
    if (&argc != NULL && argv != NULL && argToFind != NULL)
    {
        for (int i = 0; i < argc; i++)
        {
            if (strcmp(argv[i], argToFind) == 0)
                return argv[i];
        }
    }

    return NULL;
}

char *verifingValid(int argc, char **argv, char *arg)
{
    if (&argc != NULL && argv != NULL && arg != NULL)
    {
        if (strstr(arg, ":") != NULL || strchr(arg, ':') != NULL)
        {
            for (int i = 0; i < countStr(valid); i++)
            {
                if (strstr(arg, valid[i]) != NULL)
                {
                    return arg;
                }
            }
        }
    }
    return NULL;
}

int addingAndTokenizeArgs(int argc, char **argv)
{
    if (&argc != NULL && argv != NULL)
    {
        for (int i = 0; i < argc; i++)
        {
            if (verifingValid(argc, argv, argv[i]) != NULL)
            {
                char *buf = strtok(argv[i], ":");

                if (buf != NULL)
                {
                    strcpy(args[positionArgs].type, buf);
                    buf = strtok(NULL, ":");
                    if (buf != NULL)
                    {
                        strcpy(args[positionArgs].label, buf);
                        positionArgs++;
                    }
                }
            }
        }
    }
}

void seeAll()
{
    for (int i = 0; i < positionArgs; i++)
    {
        printf("\nARG:%d", i + 1);
        printf("\nTYPE:%s", args[i].type);
        printf("\nLABEL:%s\n", args[i].label);
    }
}

int countStr(const char **ptr)
{
    int count = 0;
    if (ptr != NULL)
    {
        while (ptr[count] != NULL)
        {
            count++;
        }
        }
    return count;
}

int indexOf(const char *haystack, const char *needle)
{
    const char *found = strstr(haystack, needle);

    if (found != NULL)
    {
        return found - haystack; // Calcula a posição subtraindo os ponteiros
    }
    else
    {
        return -1; // Retorna -1 se a substring não for encontrada
    }
}
