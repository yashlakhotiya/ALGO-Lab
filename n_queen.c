#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void printBoard(int n, int board[n][n]){
	puts("-------------------------------------------");
	for(int i=0; i<n; i++){
		printf("|\t");
		for(int j=0; j<n; j++){
			printf("%d\t",board[i][j]);
		}
		printf("|");
		puts("\n|");
		for(int j=0; j<n+1; j++){
			printf("\t");
		}
		printf("|\n");
	}
	puts("-------------------------------------------");
}

bool isSafe(int N, int board[N][N], int row, int col){
	for(int i=0; i<N; i++){
		if(board[row][i]) return false;
	}
	for(int i=0; i<N; i++){
		if(board[i][col]) return false;
	}
	//top left diagonal
	for(int i=row,j=col; i>=0 && j>=0; i--,j--){
		if(board[i][j]) return false;
	}
	//bottom left diagonal
	for(int i=row,j=col; i<N && j>=0; i++,j--){
		if(board[i][j]) return false;
	}
	//top right diagonal
	for(int i=row,j=col; i>=0 && j<N; i--,j++){
		if(board[i][j]) return false;
	}
	return true;
}

bool n_queens(int N, int board[N][N], int row){
	printBoard(N,board);
	if(row >= N){
		return true;
	}
	for(int i=0; i<N; i++){
		if(isSafe(N,board,row,i)){
			board[row][i] = 1;
			if(n_queens(N,board,row+1)){
				return true;
			}
			else board[row][i] = 0;//backtrack
		}
	}
	return false;
}

int main(){
	int n;
	printf("Enter value of n\n");
	scanf("%d",&n);
	int board[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			board[i][j] = 0;
		}
	}
	int col = 0;
	if(n_queens(n,board,0)) printBoard(n,board);
	else puts("Not possible");

}