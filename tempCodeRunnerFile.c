#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPRESSION_LENGTH 100

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to determine the precedence of an operator
int getPrecedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(const char* infix, char* postfix) {
    int infix_len = strlen(infix);
    char stack[MAX_EXPRESSION_LENGTH];
    int top = -1;
    int postfix_index = 0;

    for (int i = 0; i < infix_len; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[postfix_index++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[postfix_index++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(')
                top--;
        } else {
            while (top >= 0 && getPrecedence(stack[top]) >= getPrecedence(ch)) {
                postfix[postfix_index++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while (top >= 0) {
        postfix[postfix_index++] = stack[top--];
    }
    postfix[postfix_index] = '\0';
}

int main() {
    char infix[MAX_EXPRESSION_LENGTH];
    char postfix[MAX_EXPRESSION_LENGTH];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}