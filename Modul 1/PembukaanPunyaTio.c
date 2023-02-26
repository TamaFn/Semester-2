#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0; 
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

void print_stack(Stack *stack)
{
    int i = 0;
    StackNode *temp = stack->_top;

    while(temp)
    {
        printf("%d", temp->data);

        if (i < stack->_size - 1)
        {
            printf(" ");
        }else{
            printf("\n");
        }

        temp = temp->next;
        i++;
        
    }
}

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack stack1;
    Stack stack2;
    Stack stack3;
    Stack stackTampil;

    // PENTING! Jangan lupa diinisialisasi
    stack_init(&stack1);
    stack_init(&stack2);
    stack_init(&stack3);
    stack_init(&stackTampil);

    int perintah, nBuku, urutan = 1;
    char str[16];

    //scan query

    scanf("%d", &perintah);

    //for sebanyak perintah
    for (int i = 0; i < perintah; i++)
    {
        //scan perintah
        scanf("%s", str);

        //if perintah
        if (strcmp(str, "CETAK") == 0)
        {
            //scan brp buku
            scanf("%d", &nBuku);

            //for sebanyak buku
            for (int i = 0; i < nBuku; i++)
            {
                //stack push
                stack_push(&stack1, urutan);

                //urutan++
                urutan++;
            }
        }
        else if (strcmp(str, "TTD") == 0)
        {
            scanf("%d", &nBuku);

            if (stack_size(&stack1) > 0)
            {
                //for sebanyak buku
                for (int i = 0; i < nBuku; i++)
                {
                    int temp = 0;
                    temp = stack_top(&stack1);

                    //stack push
                    
                    stack_push(&stack2, temp);
                    stack_pop(&stack1);
                }
            }
 
        }
        else if (strcmp(str, "SAMPUL") == 0)
        {
            scanf("%d", &nBuku);

            if (stack_size(&stack2) > 0)
            {
                //for sebanyak buku
                for (int i = 0; i < nBuku; i++)
                {
                    int temp = 0;
                    temp = stack_top(&stack2);

                    //stack push
                    
                    stack_push(&stack3, temp);
                    stack_pop(&stack2);
                }
            }  
        }
        
    }
    int size1, size2, size3;
    size1 = stack_size(&stack1);
    size2 = stack_size(&stack2);
    size3 = stack_size(&stack3);

    if (size1 == 0)
    {
        printf("tumpukan 1:\n");
    }else{
        for (int i = 0; i < size1; i++)
        {
            int temp = 0;
            temp = stack_top(&stack1);

            stack_push(&stackTampil, temp);
            stack_pop(&stack1);
        }

        printf("tumpukan 1: ");
        print_stack(&stackTampil);
        stack_init(&stackTampil);
    }
    

    if (size2 == 0)
    {
        printf("tumpukan 2:\n");
    }else{
        for (int i = 0; i < size2; i++)
        {
            int temp = 0;
            temp = stack_top(&stack2);

            stack_push(&stackTampil, temp);
            stack_pop(&stack2);
        }

        printf("tumpukan 2: ");
        print_stack(&stackTampil);
        stack_init(&stackTampil);
    }
    
    if (size3 == 0)
    {
        printf("tumpukan 3:\n");
    }else{
        for (int i = 0; i < size3; i++)
        {
            int temp = 0;
            temp = stack_top(&stack3);

            stack_push(&stackTampil, temp);
            stack_pop(&stack3);
        }

        printf("tumpukan 3: ");
        print_stack(&stackTampil);
    }
    
    return 0;
}