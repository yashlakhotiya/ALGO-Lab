#include<stdio.h>

struct pair{
	int key;
	int value;
};

void display(struct pair hash_table[], int n){
	printf("VALUE\tKEY\n");
	for(int i=0; i<n; i++){
		printf("%d\t%d\n",hash_table[i].value,hash_table[i].key);
	}
}

void search(struct pair hash_table[], int size){
	int se;
	printf("enter element to search\n");
	scanf("%d",&se);
	if(hash_table[se%size].value == se){
		printf("element present\n");
	}
	else{
		printf("element does not exist\n");
	}
}

void main(){
	int size, i;
	printf("enter size of table\n");
	scanf("%d",&size);
	struct pair hash_table[size];
	printf("enter the elements\n");
	for(int i=0; i<size; i++){
		int temp;
		scanf("%d",&temp);
		hash_table[temp % size].value = temp;
		hash_table[temp % size].key = temp%size;
	}

	printf("\n");
	display(hash_table,size);
	search(hash_table,size);
}