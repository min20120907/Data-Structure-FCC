#include<stdio.h>

int main(int argc, char **argv){
	unsigned char buffer[110];
	FILE *ptr;

	ptr = fopen("fraction_binary.bin","rb");  // r for read, b for binary

	fread(buffer,sizeof(buffer),1,ptr); // read 10 bytes to our buffer

	printf("%s", buffer);
	return 0;
}
