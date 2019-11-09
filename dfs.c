#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int count = 0;

void dfs(int n, int matrix[][n], int j, bool visited[]){
	if(count == n) return;
	visited[j] = true;
	printf("%d\t",j);
	count++;
	for(int i=0; i<n; i++){
		if(!visited[i] && matrix[j][i] != 0){
			dfs(n,matrix,i,visited);
		}
	}
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

	dfs(n,matrix,3,visited);
}