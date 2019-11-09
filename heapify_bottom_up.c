#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void min_heapify(int h[],int n){
	int k,v,i,heapify,j;
	for(i=n/2; i>=1; i++){
		k = i;
		v = h[k];
		heap = 0;
		while(heap == 0 && 2*i <= n){
			j = 2*i;
			if(j < n){
				if(h[j] > h[j+1]){
					j = j+1;
				}
			}
			if(v <= h[j]){
				heapify  = 1;
			}
			else{
				h[k] = h[j];
				k = j;
			}
		}
		h[k] = v;
	}
}
void max_heapify(int h[],int n){
	int k,v,i,heapify,j;
	for(i=n/2; i>=1; i++){
		k = i;
		v = h[k];
		heap = 0;
		while(heap == 0 && 2*i <= n){
			j = 2*i;
			if(j < n){
				if(h[j] < h[j+1]){
					j = j+1;
				}
			}
			if(v >= h[j]){
				heap = 1;
			}
			else{
				h[k] = h[j];
				k = j;
			}
		}
		h[k] = v;
	}
}
void heap_sort_ascending(int h[],int n){
	min_heapify(h,n);
	int i = n;
	while(i > 0){
		printf("%d\t",h[0]);
		swap(&h[1],&h[i]);
		i--;
	}
	puts("");
}

void heap_sort_descending(int h[],int n){
	int i = n;
	while(i > 0){
		min_heapify(h,i);
		printf("%d\t",h[0]);
		swap(&h[1],&h[i]);
		i--;
	}
	puts("");
}

int main(){
	int n = 10;
	int arr[n+1] = {0,5,2,4,7,6,8,1,10,9,3};
	heap_sort_descending(arr,n);
	heap_sort_ascending(arr,n);
}