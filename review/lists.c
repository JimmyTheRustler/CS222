#include <stdio.h>
#include <stdlib.h>

typedef struct _LinkNode{
	int data;
	struct _LinkNode* next;
}LinkNode;

LinkNode* add(LinkNode* head, int value);
LinkNode* delete(LinkNode* head, int value);
void print(LinkNode* head);
void empty(LinkNode* head);
void swap(LinkNode* a, LinkNode* b);

int main(){
	
	int usrInput;
	int usrVal;
	LinkNode* head = NULL;
	while(usrInput != 9){
		printf("1. Add new element\n");
		printf("2. Delete element\n");
		printf("3. Print list\n");
		printf("4. Swap\n");
		printf("9. Exit\n");
	
		scanf("%d", &usrInput);

		if(usrInput == 1){
			scanf("%d", &usrVal);
			head = add(head, usrVal);
		}
		else if(usrInput == 2){
			scanf("%d", &usrVal);
			head = delete(head, usrVal);
		}
		else if(usrInput == 3){
			print(head);
		}
		else if(usrInput == 9){
			empty(head);
			return 0;
		}
		
	}
	return 0;
}

void swap(LinkNode* a, LinkNode* b){
	LinkNode* temp = a;
	a = b;
	b = temp;
}

LinkNode* add(LinkNode* head, int value){
	LinkNode* temp = (LinkNode*)malloc(sizeof(LinkNode));
	temp->data = value;
	temp->next = head;
	head = temp;
	return head;
}

LinkNode* delete(LinkNode* head, int value){
	LinkNode* temp;
	LinkNode* tempy;
	if(head == NULL)
		return NULL;
	if(head->data == value){
		temp = head->next;
		free(head);
		return temp;
	}
	tempy = head;
	while(head->next != NULL){
		tempy = head;
		if(tempy->next->data == value){
			temp = tempy->next;
			tempy->next = tempy->next->next;
			free(temp);
			return 0;
		}
		tempy = tempy->next;
	}
}

void print(LinkNode* head){
	while(head != NULL){
		printf("Value: %d\n", head->data);
		head = head->next;
	}
}


void empty(LinkNode* head){
	LinkNode* temp = head;
	while(temp->next != NULL){
		temp = temp -> next;
		free(head);
		head = temp;
	}
}
