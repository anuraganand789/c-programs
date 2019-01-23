#include <stdio.h>
#include <limits.h>

#define MAX 100

//A simple stack implementation

//Storage
static int stack[MAX];

//Utility method to remove an element from the stack
static int pop();

//Utility method to push element in the stack
static void push(int);

//Utiltiy method to check, if the stack is empty
static int empty();

//Utility method to check, if stack is full
static int full();

//position of top element in stack
static int top = -1;

void main () {

  for(int i=0; i<MAX; ++i) {
    push(i);
  }

  //Push in a full stack
  push(100);

  for(int i=0; i<MAX; ++i) {
    pop();
  }

  //Pop from an empty stack
  pop();
  
}

static int full() {
  return (top + 1) == MAX ? 1 : 0;
}

static int empty() {
  return top == -1 ? 1 : 0;
}

static void push(int value) {
  if(full()) {
    printf("Stack is full \n");
    return;
  }
  stack[++top] = value;
}

static int pop(){
  if(empty()) {
    printf("Stack is Empty. \n");
    return INT_MIN;
  }
  return stack[top--];
}
