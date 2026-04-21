#include <stdio.h>
#define RETURN return (0);
#define N 10
#define FT()int main() {FILE *f = fopen("Grace_kid.c","w");char *str = "#include <stdio.h>%c#define RETURN return (0);%c#define N 10%c#define FT()int main() {FILE *f = fopen(%cGrace_kid.c%c,%cw%c);char *str = %c%s%c;fprintf(f,str,N,N,N,34,34,34,34,34,str,34,N,N,N);/*ok*/fclose(f);RETURN}%c%cFT()%c";fprintf(f,str,N,N,N,34,34,34,34,34,str,34,N,N,N);/*ok*/fclose(f);RETURN}

FT()
