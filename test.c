#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define stacksize 10 // 100만개
#define MIN 1000
#define MAX 9999

void *stack[stacksize];
int top = -1;

int isEmpty() { return top == -1; }

void push(void *element) {
  if (top >= stacksize - 1) {
    return;
  }
  stack[++top] = element;
}

void *pop() {
  if (isEmpty()) {
    return NULL;
  }
  void *element = stack[top];
  top--;
  return element;
}

void *pushMillion() {
  srand(time(NULL));

  for (int i = 0; i < stacksize; i++) {
    int *element = (int *)malloc(sizeof(int));
    *element = rand() % (MAX - MIN + 1) + MIN;
    push(element);
  }
  return stack;
}

void popMillion() {
  while (!isEmpty()) {
    void *element = pop();
    free(element);
  }
  return;
}

void findMin() {
  if (isEmpty()) {
    return;
  }

  int *min = (int *)stack[0];
  for (int i = 0; i <= top; i++) {
    int *element = (int *)stack[i];
    if (*element < *min)
      min = element;
  }
  printf("%d", *min);
}

int main() {
  char function;
  clock_t start, end;

  while (1) {
    scanf("%c", &function);

    switch (function) {
    case 'p': {
      int element;
      scanf("%d", &element);

      void *element_ptr = malloc(sizeof(int));
      *(int *)element_ptr = element;

      start = clock();
      push(element_ptr);
      end = clock();
      printf("push ");
      findMin();
      printf(" CPU Time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);
      break;
    }
    case 'P': {
      start = clock();
      pushMillion();
      end = clock();
      printf("pushMillion");
      printf(" CPU Time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);
      break;
    }
    case 'o': {
      start = clock();
      void *pop_element = pop();
      free(pop_element); // 동적 할당 해제
      end = clock();
      printf("pop ");
      findMin();
      printf(" CPU Time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);
      break;
    }
    case 'O': {
      start = clock();
      popMillion();
      end = clock();
      printf("popMillion");
      printf(" CPU Time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);
      break;
    }
    case 'f': {
      start = clock();
      printf("min ");
      findMin();
      end = clock();
      printf(" CPU Time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);
      break;
    }
    case 'q': {
      while (!isEmpty()) {
        void *element = pop();
        free(element); // 동적 할당 해제
      }
      return 0;
    }
    default: {
      break;
    }
    }
  }

  return 0;
}