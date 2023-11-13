/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Global declarations:
int top;
int size;
char operator[20];
char postfix[20];
char infix[20];
char item;

int prec(char c){
	if(c == '^'){
		return 3;
	}
	else if(c == '*'||c == '/'){
		return 2;
	}
	else if(c == '+'||c == '-'){
		return 1;
	}
	else{
		return -1;
	}

}


void main(){
	
	//Taking input for the infix array:
	int n;
	printf("Enter length of expression: \n");
	scanf("%d",&n);
	printf("Enter elements: \n");
	for(int i=0; i < n;i++){
		scanf("%c",&infix[i]);	
	}
	
	//Linear Search:
	for(int j=0;j<n;j++){
		if(infix[j] == '^'||infix[j] == '*'||infix == '/'||infix[j] == '+'||infix[j] == '-'){
			push(operator[j]);
			if(operator[j] <= operator[top]){
				pop(operator[top]);
				for(int k=0;k<n;k++){
					postfix[k]=operator[top];
				}
			}		
		}
		else{
			postfix[j] = infix[j];
		}
	}	
}

void push(char item){
	if(top > (size-1)){
		printf("Stack Overflow!!");	
	}
	else{
		top = top + 1;
		operator[top] = item;
	}
}

void pop(char item){
	if(top = -1){
		printf("Stack Underflow!!");
	}
	else{
		char var = item;
		top = top - 1;
		return var;
	}
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int getPrecedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1;
}

void infixToPostfix(char* infix, char* postfix) {
    struct Stack* stack = createStack(strlen(infix));
    int i, j;
    char ch;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(stack, ch);
        } else if (ch == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(') {
                printf("Invalid infix expression\n");
                return;
            } else {
                pop(stack);
            }
        } else {
            while (!isEmpty(stack) && getPrecedence(ch) <= getPrecedence(peek(stack))) {
                postfix[j++] = pop(stack);
            }
            push(stack, ch);
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
}

void infixToPrefix(char* infix, char* prefix) {
    int i, j;
    char temp;
    char reverse_infix[MAX_SIZE];

    for (i = strlen(infix) - 1, j = 0; i >= 0; i--, j++) {
        if (infix[i] == '(')
            reverse_infix[j] = ')';
        else if (infix[i] == ')')
            reverse_infix[j] = '(';
        else
            reverse_infix[j] = infix[i];
    }
    reverse_infix[j] = '\0';

    infixToPostfix(reverse_infix, prefix);

    for (i = 0, j = strlen(prefix) - 1; i < j; i++, j--) {
        temp = prefix[i];
        prefix[i] = prefix[j];
        prefix[j] = temp;
    }
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}




