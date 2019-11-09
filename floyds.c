#include<stdio.h>
#include<stdlib.h>

int min(int a, int b){
	return a>b?b:a;
}

void floyds(int n, int matrix[][n]){
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for (int j = 0; j < n; j++){
				matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
			}
		}
	}
	for(int i=0; i<n; i++){
		for (int j = 0; j < n; j++)
		{
			printf("%d\t",matrix[i][j]);
		}
		puts("");
	}
}

int main(){
	printf("enter number of vertices\n");
	int n;
	scanf("%d",&n);

	printf("enter matrix\n");
	int matrix[n][n];

	for(int i=0; i<n; i++){
		for (int j = 0; j < n; j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}

	floyds(n,matrix);

}