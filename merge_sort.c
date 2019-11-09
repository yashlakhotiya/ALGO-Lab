#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void merge(int arr[],int l,int m,int r){
	int i = l,j = m+1,int k;
	int temp[r-l+1];
	while(i <= m && j <= r){
		if(arr[i] < arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
		}
		if(i>m){
			temp[k++] = arr[j++];
		}
		if(j > r){
			temp[k++] = arr[j++];
		}
	}
	for(int i = l;i <= r; i++){
		arr[i] = temp[i];
	}
}

void mergesort(int arr[],int l,int r){
	if(l<r){
		int m = l+(r-l)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

int main(){
	int n = 5;
	int arr[n] = {5,3,2,4,1};
	mergesort(arr,0,n-1);
	for(int i = 0;i < 5;i++){
		cout<<arr[i];
	}
}