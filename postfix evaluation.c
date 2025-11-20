#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char postfix[MAX];
    int i, a, b;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(ch - '0');   // convert char to int
        }
        else {
            b = pop();  // second operand
            a = pop();  // first operand

            switch (ch) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}
