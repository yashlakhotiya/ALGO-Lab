#include<stdio.h>
#include<stdlib.h>

#define INT_MAX 999999

int n=4;

int dist[4][4] = {
	{0,20,42,25},
	{20,0,30,34},
	{42,30,0,10},
	{25,34,10,0}
};

int min(int a, int b){
	(a<b)?a:b;
}

#define VISITED_ALL 1<<n - 1

int tsp(int mask, int pos){
	if(mask == VISITED_ALL){
		return dist[pos][0];
	}
	//try to go to an unvisited city
	int ans = INT_MAX;
	for(int city = 0; city < n; city++){
		if((mask & 1<<city)==0){
			int newans = dist[pos][city] + tsp(mask | (1<<city), city);
			ans = min(ans,newans);
		}
	}
	return ans;
}

int main(){
	printf("%d\n",tsp(1,0));
}