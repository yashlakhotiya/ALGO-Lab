#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int findMinimumVertix(int n, bool visited[], int distance[]){
	int min = -1;
	for(int i=0; i<n; i++){
		if(!visited[i] && (min == -1 || distance[i] < distance[min])){
			min = i;
		}
	}
	return min;
}

void printvector(int n, int vector[], bool visited[]){
	puts("");
	for(int i=0;i<n;i++) printf("%d\t",vector[i]);
	puts("");
	for(int i=0;i<n;i++) printf("%d\t",visited[i]);
	puts("");
}

void dijkstara(int n, int matrix[][n], int starting_vertix){
	bool visited[n];
	
	int distance[n];

	for(int i=0; i<n; i++){
		distance[i] = 9999;
		visited[i] = false;
	}
	
	distance[starting_vertix] = 0;


	for(int i=0; i<n; i++){
		//printvector(n,distance,visited);
		int min = findMinimumVertix(n,visited,distance);
		//printf("min %d\n",min);
		visited[min] = true;
		for(int j=0; j<n; j++){
			if(!visited[j] && matrix[min][j] != 0){
				int dist = distance[min] + matrix[min][j];
				if(dist < distance[j]){
					distance[j] = dist;
				}
			}
		}
	}

	for(int i=0; i<n; i++){
			printf("%d : %d\n",i,distance[i]);
	}
}

int main(){
	printf("enter number of vertices and edges\n");
	int n,e;
	
	
	scanf("%d%d",&n,&e);
	int matrix[n][n];

	for(int i=0;i<n;i++){
		for(int j=0; j<n; j++){
			matrix[i][j] = 0;
		}
 	}
	
	printf("enter u,v,w: ");
	int u,v,w;
	
	for(int i=0; i<e; i++){
 		scanf("%d%d%d",&u,&v,&w);
 		matrix[u][v] = matrix[v][u] = w;
 	}

 	printf("enter starting_vertix\n");
 	
 	int starting_vertix;
 	
 	scanf("%d",&starting_vertix);

 	dijkstara(n,matrix,starting_vertix);
}