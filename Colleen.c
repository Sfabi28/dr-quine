#include <stdio.h>

void timeToPrint(void)
{
	char *str = "#include <stdio.h>%c%cvoid timeToPrint(void)%c{%c	char *str = %c%s%c;%c	printf(str, 10, 10, 10, 10, 34, str, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);%c}%c%cint main(void)%c{%c	/*%c		comment inside the main%c	*/%c	timeToPrint();%c	return (0);%c}%c%c/*%c	comment outside the main%c*/%c";
	printf(str, 10, 10, 10, 10, 34, str, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);
}

int main(void)
{
	/*
		comment inside the main
	*/
	timeToPrint();
	return (0);
}

/*
	comment outside the main
*/
