#include<stdio.h>
#include<stdlib.h>

struct edge{
	int source;
	int destination;
	int weight;
};

void sort(struct edge edges[], int e){
	for(int i=0; i<e; i++){
		for(int j=0; j<e-i-1; j++){
			if(edges[j].weight > edges[j+1].weight){
				struct edge temp = edges[j];
				edges[j] = edges[j+1];
				edges[j+1] = temp;
			}
		}
	}
}

int findParent(int i, int parent[]){
	if(i == parent[i]) return i;
	else return findParent(parent[i],parent);
}

int main(){
	printf("enter number of vertices and edges\n");
	int n,e;
	scanf("%d%d",&n,&e);
	struct edge edges[e];
	
	int parent[n];
	for(int i=0; i<n; i++){
		parent[i] = i;
	}
	printf("enter edges: source, destination and weight\n");
	for(int i=0; i<e; i++){
		scanf("%d%d%d",&edges[i].source,&edges[i].destination,&edges[i].weight);
	}

	struct edge output[n-1];

	sort(edges,e);
	

	int count = 0, i=0;
	while(count != n-1){
		struct edge currEdge = edges[i];

		int s_parent = findParent(currEdge.source,parent);
		int d_parent = findParent(currEdge.destination,parent);

		if(s_parent != d_parent){
			output[count++] = currEdge;
			parent[s_parent] = d_parent;
		}
		i++;
	}

	for(int i=0; i<n-1; i++){
		if(output[i].source < output[i].destination)
		printf("%d %d %d\n",output[i].source,output[i].destination,output[i].weight);
		else
		printf("%d %d %d\n",output[i].destination,output[i].source,output[i].weight);
	}
}