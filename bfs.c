#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int count = 0;
int front=0,rear=0;
int queue[10];

void bfs(int n,int matrix[][n],int j,bool visited[]){
	if(count == n) return;
	visited[j] = true;
	count++;
	printf("%d\n",j);
	for(int i=0; i<n; i++){
		if(!visited[i] && matrix[j][i]){
			queue[front++] = i;
		}
	}
	int p = queue[rear++];
	bfs(n,matrix,p,visited);
}

int main(){
	int n,e;
	printf("enter number of vertices and edges\n");
	scanf("%d%d",&n,&e);
	int matrix[n][n];
	bool visited[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
		for (int j = 0; j < n; ++j)
		{
			matrix[i][j] = 0;
		}
	}
	printf("enter vertice1 vertice2 weight\n");
	
	for(int i=0; i<e; i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		matrix[u][v] = matrix[v][u] = w;
	}

	bfs(n,matrix,3,visited);
}