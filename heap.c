#include<stdio.h>
#include<stdlib.h>

void heapify_bottom_up(int n, int arr[]){
	for(int i=n/2; i>1; i--){
		int k=i;
		int v=h[k];
		int is_heap=0;

		while(!is_heap && 2*k <= n){
			 int j = 2*k;
			 if(j<n){
			 	if(arr[j] < arr[j+1]){
			 		j++;
			 	}
			 }
			 if(v >= arr[j]) heap=1
			 else{
			 	arr[k] = arr[j];
			 	k = j;
			 }
		}
		arr[k] = v;
	}
}

void heapify_top_down(int n, int arr[]){
	
}

int main(){
	printf("enter n\n");
	scanf("%d",&n);
	int arr[n];
	for(int i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	heapify(n,arr);
}