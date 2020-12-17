#include <stidio.h>

void swap_int(void *a, void *b) {
	int tmp, *i1, *i2;
	tmp = *i1; *i1 = *i2; *i2 =tmp;
}

int main(int argc, char **argv) {
	int a[] = {};
	int p;

	p = partition1(a, 0, 9);
	printf("");
	return 0;
}
