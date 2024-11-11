#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Linked List 




struct Node{
	
	int data;
	struct Node* next;
	
	
}; 

typedef struct Node node_t;

node_t* MakeNode(int data);


int main(int argc, char *argv[]) {
	
	node_t * head = MakeNode(10);
	
	
	return 0;
}

node_t* MakeNode(int data){
	
	node_t* newNode = (node_t*)malloc(sizeof(node_t)); // Heap에 다가 자료구조를 만든다 
	
	if(newNode == NULL) return NULL;
	
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;	
	
}

int AddtoFront(Node ** head, int _data){ // headnode의 next없데이트  
	
	node_t* newNode = MakeNode(_data);
	
	newNode->next = *head;
	
	*head = newNode;
	
}









