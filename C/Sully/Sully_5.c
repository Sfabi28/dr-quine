#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *read_source(void)
{
    FILE *file;
    char *buffer;
    long size;

    file = fopen(__FILE__, "r");
    if (!file)
        return (NULL);
    if (fseek(file, 0, SEEK_END) != 0)
    {
        fclose(file);
        return (NULL);
    }
    size = ftell(file);
    if (size < 0)
    {
        fclose(file);
        return (NULL);
    }
    rewind(file);
    buffer = malloc((size_t)size + 1);
    if (!buffer)
    {
        fclose(file);
        return (NULL);
    }
    if (fread(buffer, 1, (size_t)size, file) != (size_t)size)
    {
        free(buffer);
        fclose(file);
        return (NULL);
    }
    buffer[size] = '\0';
    fclose(file);
    return (buffer);
}

static void write_source(int i)
{
    char filename[32];
    char command[256];
    char *source;
    char *marker;
    char *end;
    FILE *file;

    if (i < 0)
        return;
    source = read_source();
    if (!source)
        return;
    marker = strstr(source, "int i = 4;
    end = marker ? strchr(marker, ';') : NULL;
    if (!marker || !end)
    {
        free(source);
        return;
    }
    snprintf(filename, sizeof(filename), "Sully_%d.c", i);
    file = fopen(filename, "w");
    if (!file)
    {
        free(source);
        return;
    }
    fwrite(source, 1, (size_t)(marker - source), file);
    fprintf(file, "int i = %d;", i - 1);
    fputs(end + 1, file);
    fclose(file);
    free(source);
    snprintf(command, sizeof(command), "cc -Wall -Wextra -Werror %s -o Sully_%d && ./Sully_%d", filename, i, i);
    system(command);
}

int main(void)
{
    int i = 5;

    write_source(i);
    return (0);
}