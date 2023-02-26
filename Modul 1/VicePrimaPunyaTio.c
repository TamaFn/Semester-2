#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

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

void init(Stack *stack){
    stack->_size = 0;
    stack->_top = NULL;
}

void print_stack(Stack *stack)
{
    StackNode *temp = stack->_top;
    while(temp)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}


int main() {

  Stack stackA;
  Stack stackB;
  init(&stackA);
  init(&stackB);

  int n, value;

  scanf("%d",&n);

  for (int i = 0; i < n; i++)
  {
      bool prima = true;

      scanf("%d", &value);
      for (int i = 2; i < value-1; i++)
      {
          if (value % i == 0)
          {
              prima = false;
              break;
          }
      }
      if (prima)
      {
          //printf("prima\n");
          stack_push(&stackA, value);
      }else{
          //printf("tidak prima\n");
          stack_push(&stackB, value);
      }
  }
  print_stack(&stackA);
  print_stack(&stackB);
  
  return 0;
}
