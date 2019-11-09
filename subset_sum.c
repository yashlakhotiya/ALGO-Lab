#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void printArray(int n, int arr[n]){
	puts("");
	for(int i=0; i<n; i++) printf("%d\t",arr[i]);
	puts("");
}

int findTotal(int n, int arr[n]){
	int sum = 0;
	for(int i=0; i<n; i++){
		sum += arr[i];
	}
	return sum;
}

bool subset_sum(int n, int ite, int sum, int arr[n], int flag[n], int tot, int left){
	printArray(n,flag);
	if(tot == sum) return true;
	else if(tot > sum) return false;
	if(tot+left < sum) return false;
	if(ite == n) return false;
	flag[ite] = 1;
	if(subset_sum(n,ite+1,sum,arr,flag,tot+arr[ite],left-arr[ite])){
		return true;
	}
	else{
		flag[ite] = 0;
		subset_sum(n,ite+1,sum,arr,flag,tot,left-arr[ite]);
	}
}

int main(){
	int n;
	puts("Enter size of array");
	scanf("%d",&n);
	int arr[n];
	int flag[n];
	puts("Enter array");
	for(int i=0; i<n; i++){
		scanf("%d",&arr[i]);
		flag[i] = 0;
	}
	printf("Enter sum to find\n");
	int sum;
	scanf("%d",&sum);
	int left = findTotal(n,arr);
	int ite = 0;
	if(subset_sum(n,ite,sum,arr,flag,0,left)) printArray(n,flag);
	else puts("Not possible");
}