#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	char *str = "hello world world hello.";
	int n_char;
	char dest[101];
	while(sscanf(str, "%s%n", dest, &n_char)!=0 && str[n_char-1]!='\0'){
		printf("%s\n", dest);
		str += n_char;
	}
	return 0;
}
