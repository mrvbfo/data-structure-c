
#include <stdlib.h>
#include <stdio.h>

struct Node{
	int data;
	struct Node *next;
};

void push(struct Node** head_ref, int new_data){ //basa ekleme yapan fonksiyon
	struct Node* new_node=(struct Node*) malloc(sizeof(struct Node)); //yeni dugum icin bellek alani ayriliyor.
	
	new_node->data=new_data;
	new_node->next=(*head_ref);
	(*head_ref)=new_node;
	
}

void insertAfter(struct Node* prev_node, int new_data){ //verilen degerin yanina ekleme yapan fonksiyon
	if(prev_node==NULL){ 
		printf("the given previous node cannot be NULL");
		return;
	}
	
	struct Node* new_node=(struct Node*) malloc(sizeof(struct Node)); //yeni dugum icin bellek alani ayriliyor.
	
	new_node->data=new_data;
	new_node->next=prev_node->next; 
	prev_node->next = new_node; 
	
}

void append(struct Node** head_ref, int new_data){ //listenin sonuna ekleme yapan fonksiyon
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
	struct Node *last= *head_ref; 
	
	new_node->data=new_data;
	new_node->next=NULL; 
	
	if(*head_ref==NULL){ //ilk dugum bossa yeni dugum basa eklenir.
		*head_ref=new_node;
		return;
	} 
	
	while(last->next!=NULL){ //ilk dugum bos degilse son dugume sirali bir sekilde ulasilir. 
		last=last->next;
	}
	
	last->next=new_node; 
	return;
}

void printList(struct Node *node){ //sirali bir sekilde dugumleri ekrana yazdiran fonksiyon
	while(node!=NULL){ 
		printf(" %d ",node->data);
		node=node->next;
	}
}

void revPrintList(struct Node* head){ //listeyi sondan basa dogru yazdiran fonksiyon
	if (head == NULL) //dugum bossa fonksiyondan cikar
      return;
    
    revPrintList(head->next); 
    printf("%d  ", head->data);
	
}

int lengthList(struct Node* head){ //listenin eleman sayisini int turunden geri donduren fonksiyon
	int count=0;
	struct Node* current=head; 
	
	while(current!=NULL){ 
		count++;
		current=current->next; 
	}
	return count;
}

void swap(struct Node *head1, struct Node *head2) //dugumlerin yerini degistiren fonksiyon
{ 
    int temp = head1->data; 
    head1->data = head2->data; 
    head2->data = temp; 
} 

void bubbleSort(struct Node *head) //liste elemanlarini kucukten buyuge siralayan fonksiyon
{ 
    int swapped, i; 
    struct Node *head1; 
    struct Node *head2 = NULL; 
  
    if (head == NULL) 
        return; 
  
    do
    { 
        swapped = 0; //
        head1 = head; 
  
        while (head1->next != head2) 
        { 
            if (head1->data > head1->next->data) 
            { 
                swap(head1, head1->next); 
                swapped = 1; 
            } 
            head1 = head1->next; 
        } 
        head2 = head1; 
    } 
    while (swapped); 
} 
  
void deleteAllNodes(struct Node* head){ //ayni degerdeki tum elemanlari silen fonksiyon.
	bubbleSort(head); 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->next = head;
    struct Node* prev = temp;
    struct Node* current = head;
  
    while (current != NULL) { 
		if(current->next != NULL && current->data == current->next->data){
			while (current->next != NULL && current->data == current->next->data){
     	       current = current->next; 
			}
			prev->next = current->next;
		}
        
        else{
        	prev = prev->next; 
		}
            
        current = current->next; 
	}
}

int main(){
	int choice;
	int data;
	int cont;
	struct Node* head=NULL; 
	
	do{
		printf("Create a Linked List: \nAppend(1)-Push(2)-InsertAfter(3)\nType your choice: ");
		scanf("%d",&choice);
		if(choice==1){
			printf("\nType the data you want to add: ");
			scanf("%d",&choice);
			append(&head, choice);
		}
		else if(choice==2){
			printf("\nType the data you want to add: ");
			scanf("%d",&choice);
			push(&head, choice);
		}
		else if(choice==3){
			printf("\nType the data you want to add: ");
			scanf("%d",&choice);
			
			insertAfter(head->next, choice);
		}
		printf("If you want to add an element, enter 1\nIf you want to exit, enter 0: ");
		scanf("%d",&cont);
	}while(cont);
	
	
	printf("\n Created Linked list is: ");
	printList(head);
	printf("\n Reversed Linked List is: ");
	revPrintList(head);
	printf("\n Length of Linked List is: %d",lengthList(head));
	deleteAllNodes(head);
	printf("\n All elements with the same value in the Linked List are deleted: ");
	printList(head);

	return 0;
}


