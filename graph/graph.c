#include <stdio.h>
#include <stdlib.h>

typedef int edge[2];
void print_graph(int (*g)[4], int size);
char inGraph(int (*e)[2], int size, int e1, int e2);

int main(int argc, char **argv) {
	int v=4;
	int edges = 6;
	int E[edges][2];
	E[0][0]=0;
	E[0][1]=1;
	E[1][0]=0;
	E[1][1]=2;
	E[2][0]=0;
	E[2][1]=3;
	E[3][0]=1;
	E[3][1]=2;
	E[4][0]=1;
	E[4][1]=3;
	E[5][0]=2;
	E[5][1]=3;
	int (*G)[v] = (int(*)[v]) malloc(sizeof(int)*v*v);
	int ig=0;
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			if(inGraph(E, edges, i, j)){
				//printf("InGraph Count: %d\n", ig);
				ig+=2;
				G[i][j] = 1;
				G[j][i] = 1;
			}
		}
	}
	print_graph(G, v);
	free(G);
	return 0;
}

void print_graph(int (*g)[4], int size){
	for(int i = 0;i<size;i++) {
		for(int j=0; j<size;j++) {
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
}

char inGraph(int (*e)[2], int size, int e1, int e2){
	for(int i = 0;i<size;i++) {
		if((e[i][0]==e1&&e[i][1]==e2)||(e[i][0]==e2&&e[i][1]==e1)) return 1;
	}
	return 0;
	
}
