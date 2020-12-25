#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// define the structure of LinkList
typedef struct _List {
    double v;
    struct _List *next;
}list, *list_p;

// double compare function
int compare (const void * a, const void * b)
{
  return ( *(double*)a - *(double*)b );
}

list_p find_tail(list_p l){
    list_p tmp = l;
    while(tmp->next!=NULL)
	    tmp=tmp->next;
    return tmp;
}

list_p delete_tail(list_p head)
{
  list_p temp =head;
  list_p t;
  if(head->next==NULL)
  {
    free(head);
    head=NULL;
  }
  else
  {
     while(temp->next != NULL)
     {
        t=temp;
        temp=temp->next;
     }
     free(t->next);
     t->next=NULL; 
  }    
  return head;
}

list_p remove_latest(list_p l, int num){
	list_p tmp = l;
	for(int i =0;i<num;i++){
		tmp = delete_tail(tmp);
	}
	return tmp;
}

// List counting function, return the sixe of the list
int count_list(list_p l){
    int len = 1;
    while(l->next!=NULL){
        l=l->next;
        len++;
    }
    return len;
}
// Array printing function
void print_array(double arr[], int size) {
    int i;
    for(i=0;i<size;i++)
        printf("%lf ", arr[i]);
}

int main(int argc, char **argv) {
    int i=0;
    double cur;
    list_p l = (list_p) malloc(sizeof(list));
    l->v = 0;
    l->next =NULL;
    while(scanf("%lf", &cur)==1){
        int j,k;
        list_p n_v = (list_p) malloc(sizeof(list));
        
        n_v->v=cur;
        n_v->next = l;
        l=n_v;
        
        double sum =0;
        double arr2[200]={0};
        
        j=0;
        list_p tmp = l;
        if(count_list(tmp)>200) tmp = remove_latest(tmp, count_list(tmp)-200);
        // Debug Section
	printf("The size is %d\n", count_list(tmp));
	printf("The first value is %lf\n", tmp->v);
	printf("The last value is %lf\n",find_tail(tmp)->v);
	// Fetch the latest j inputs
        while(tmp->next!=NULL){
            arr2[199-j] = tmp->v;
            tmp=tmp->next;
            j++;
        }
        qsort(arr2, 200,sizeof(double), compare);
        // remove top and bottom 25%
        for(k=0;k<50;k++){
            arr2[k]=0;
            arr2[199-k]=0;
        }
        // Summention
        for(k=0;k<200;k++){
            sum+=arr2[k];
        }
        // Print out
        printf("%lf ",sum/100);
        i++;
    }
    return 0;
}
