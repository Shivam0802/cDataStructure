#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define max 100
int top = -1, a[max];

void push(char x){
    a[++top] = x;
}

char pop(){
    if (top == -1)
        return -1;
    else
        return a[top--];
}

int precedence(char c){
    if (c == '(')
        return 0;
    else if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
}

int infixtopostfix(char infix[max], char postfix[max]){
    char temp, x;
    int i = 0, j = 0;
    while (infix[i] != '\0'){
        temp = infix[i];

        if (isalnum(temp)){
            postfix[j++] = temp;
        }

        else if (temp == '(')
            push(temp);
        else if (temp == ')'){
            while ((x = pop()) != '('){
                postfix[j++] = x;
            }
        }

        else{
            while (precedence(a[top]) >= precedence(temp)){
                postfix[j++] = pop();
            }
            push(temp);
        }
        i++;
    }

    while (top != -1)
        postfix[j++] = pop();
        
    postfix[j] = '\0';
}

void main(){
    char infix[max], postfix[max];
    printf("\nEnter the infix expression : ");
    gets(infix);
    printf("\nThe infix expression is : %s", infix);
    infixtopostfix(infix, postfix);
    printf("\nThe postfix expression is : %s", postfix);
}