#ifndef directed_graph_h
#define directed_graph_h
typedef struct _Vinfo{
	char color[100]="white";
	double discover;
	char name[100];
	struct _Ainfo *adj;
}ver, *ver_p;

typedef struct _AInfo{
	int V_idx;
	double weight;
	struct _AInfo *next;
}adj, adj_p;
#endif
