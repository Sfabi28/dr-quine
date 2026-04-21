#include <stdio.h>
#include <stdlib.h>
#define N 10
void create_file(char *source, int number) {
	if (number < 1)
		return ;
	number--;
	char buffer[50];
	char command[50];
	snprintf(buffer, 49, "Sully_%d.c", number);
	FILE *file = fopen(buffer, "w");
	fprintf(file, source, N, N, N, N, N, N, N, N, N, 34, 34, N, 34, 34, N, N, 34, 34, N, N, N, N, N, N, number, N, 34, source, 34, N, N);
	snprintf(command, 49, "cc -Wall -Wextra -Werror %s && ./a.out", buffer);
	fclose(file);
	system(command);
}

int main() {
	int number = 12;
	char *source = "#include <stdio.h>%c#include <stdlib.h>%c#define N 10%cvoid create_file(char *source, int number) {%c	if (number < 1)%c		return ;%c	number--;%c	char buffer[50];%c	char command[50];%c	snprintf(buffer, 49, %cSully_%%d.c%c, number);%c	FILE *file = fopen(buffer, %cw%c);%c	fprintf(file, source, N, N, N, N, N, N, N, N, N, 34, 34, N, 34, 34, N, N, 34, 34, N, N, N, N, N, N, number, N, 34, source, 34, N, N);%c	snprintf(command, 49, %ccc -Wall -Wextra -Werror %%s && ./a.out%c, buffer);%c	fclose(file);%c	system(command);%c}%c%cint main() {%c	int number = %d;%c	char *source = %c%s%c;%c	create_file(source, number);%c}";
	create_file(source, number);
}