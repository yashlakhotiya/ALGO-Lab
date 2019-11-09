#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int findMinVertix(int weight[], bool visited[], int n){
	int minVertix = -1;
	for(int i=0; i<n; i++){
		if(!visited[i] && (minVertix == -1 || weight[i] < weight[minVertix])){
			minVertix = i;
		}
	}
	return minVertix;
}

void prims(int n, int matrix[][n]){
	int parent[n];
	bool visited[n];
	int weight[n];

	for(int i=0; i<n; i++){
		weight[i] = 9999;
		visited[i] = false;
	}
	parent[0] = -1;
	weight[0] = 0;

	for(int i=0; i<n; i++){
		int minVertix = findMinVertix(weight,visited,n);
		visited[minVertix] = true;
		for(int j=0; j<n; j++){
			if(matrix[minVertix][j] != 0 && !visited[j]){
				if(matrix[minVertix][j] < weight[j]){
					weight[j] = matrix[minVertix][j];
					parent[j] = minVertix;
				}
			}
		}
	}

	for(int i=1; i<n; i++){
		if(parent[i] < i){
			printf("%d %d %d\n",parent[i],i,weight[i]);
		}
		else{
			printf("%d %d %d\n",i,parent[i],weight[i]);
		}
	}
}

int main(){
	printf("enter no of vertices and edges\n");
	int n,e;
	scanf("%d%d",&n,&e);;

	int matrix[n][n];
	printf("enter verticx1 vertix2 weight\n");
	for(int i=0; i<e; i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		matrix[u][v] = matrix[v][u] = w;
	}

	prims(n,matrix);
}