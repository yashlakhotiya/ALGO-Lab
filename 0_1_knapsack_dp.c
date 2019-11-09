#include<stdio.h>
#include<stdlib.h>

int max(int a, int b){
	return a>b?a:b;
}

int findInRow(int ele, int row[], int capacity){
	for(int i=0; i<=capacity; i++){
		if(row[i] == ele){
			return 1;
		}
	}
	return 0;
}

int backtrack(int n, int capacity, int matrix[][capacity+1],int values[]){
	int flag[n];
	int lval = matrix[n][capacity];
	for(int i=n; i>0;i--){
		if(findInRow(lval,matrix[i-1],capacity)){
			flag[i] = 0;
		}
		else{
			flag[i] = 1;
			lval -= values[i];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d\t",flag[i]);
	}
}

int knapsack(int n, int weight[], int values[],int capacity){
	int matrix[n+1][capacity+1];
	for(int i=0; i<=n; i++){
		matrix[0][i] = matrix[i][0] = 0;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=capacity; j++){
			if(j<weight[i]){
				matrix[i][j] = matrix[i-1][j];
			}
			else{
				matrix[i][j] = max(matrix[i-1][j], matrix[i-1][j-weight[i]]+values[i]);
			}
		}
	}
	backtrack(n,capacity,matrix,values);
	return matrix[n][capacity];
}

int main(){
	int n;
	printf("enter number of items\n");
	scanf("%d",&n);
	printf("enter weight and value of each item\n");
	int weight[n], values[n];
	for(int i=0; i<n; i++){
		scanf("%d%d",&weight[i],&values[i]);
	}
	printf("enter capacity of knapsack\n");
	int capacity;
	scanf("%d",&capacity);
	int maxval = knapsack(n,weight,values,capacity);
	printf("max val is %d\n",maxval);
}