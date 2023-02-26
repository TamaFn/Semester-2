#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* newNode(int data){
	Node* new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void push(Node** head_ref, int new_data){
	Node* new_node = newNode(new_data);
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

Node* addthem(Node* X, Node* Y){
	Node* addition = NULL;
	Node *temp, *prev = NULL;
	int carry = 0, sum;

	while (X != NULL || Y != NULL) {
		sum = carry + (X ? X->data : 0) + (Y ? Y->data : 0);
		carry = (sum >= 10) ? 1 : 0;
		sum = sum % 10;
		temp = newNode(sum);
		if (addition == NULL)
			addition = temp;
		else
			prev->next = temp;
			prev = temp;
		if (X)
			X = X->next;
		if (Y)
			Y = Y->next;
	}
	if (carry > 0)
		temp->next = newNode(carry);
	return addition;
}

Node* reverse(Node* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	Node* rest = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return rest;
}

void printList(Node* node)
{
    printf("[");
	while (node != NULL) {
		printf("%d",node->data);
		node = node->next;
	}
	printf("]");
    printf("\n");
}


int main(){
    int M, N, X, Y, Z;

    Node* MyList1 = NULL;
    Node* MyList2 = NULL;
    Node* ListAddition = NULL;

    scanf("%d %d", &M, &N);

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &X);
        push(&MyList1, X);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &Y);
        push(&MyList2, Y);
    }
    ListAddition = addthem (MyList1, MyList2);
    ListAddition = reverse(ListAddition);
    printList (ListAddition);
	return 0;
}