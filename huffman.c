#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	char title;
	int frequency;
	struct node *left,*right;
}*NODE;

int flag = 0;

void sort(int n, NODE node[]){
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i-1; j++){
			if(node[j]->frequency < node[j+1]->frequency){
				NODE temp = node[j];
				node[j] = node[j+1];
				node[j+1] = temp;
			}
		}
	}
}

NODE huffman(int n, NODE node[]){
	int j=n;
	int i=n-1;
	while(i > 0){
		sort(j,node);
		NODE first = node[i];
		NODE second = node[i-1];
		NODE third = (NODE)malloc(sizeof(NODE));
		third->frequency = first->frequency+second->frequency;
		third->title = '*';
		third->left = first;
		third->right = second;
		node[i-1] = third;
		i -= 1;
		j -= 1;
	}
	return node[i];
}

void printCode(NODE head, char c, int step){
	if(head == NULL) return;
	if(flag == 1){
		if(step == 2){
			printf("0 step %d\n",step);
		}
		else if(step == 3){
			printf("1 step %d\n",step);
		}
		return;
	}
	printCode(head->left,c,2);
	if(head->title == c){
		flag = 1;
		printCode(head,c,step);
		return;
	}
	printCode(head->right,c,3);
	if(head->title == c){
		flag = 1;
		printCode(head,c,step);
		return;
	}
}

void preorder(NODE head){
	if(head==NULL) return;
	preorder(head->left);
	printf("%c %d\t",head->title,head->frequency);
	preorder(head->right);
}

int main(){
	printf("enter number of characters\n");
	int n;
	scanf("%d",&n);
	NODE node[n];
	printf("enter character and frequency\n");
	char c;
	int f;
	for(int i=0; i<n; i++){
		scanf(" %c%d",&c,&f);
		NODE temp = (NODE)malloc(sizeof(struct node));
		temp->title = c;
		temp->frequency = f;
		temp->left = temp->right = NULL;
		node[i] = temp;
	}

	NODE head = huffman(n,node);

	preorder(head);
	printCode(head,'f',0);

}