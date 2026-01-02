#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

/* push */
void push(char x) {
    top++;
    stack[top] = x;
}
/* pop */
char pop() {
    return stack[top--];
}

int main() {
    char exp[50];
    int i;

    printf("Enter expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++) {

        /* Opening brackets */
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }

        /* Closing brackets */
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {

           /*if (top == -1) {
                printf("Not Balanced");
                return 0;
            }*/

            char ch = pop();

            if ((ch == '(' && exp[i] != ')') ||
                (ch == '{' && exp[i] != '}') ||
                (ch == '[' && exp[i] != ']')) {
                printf("Not Balanced");
                return 0;
            }
        }
    }

     if (top == -1)
        printf("Balanced");
    else
        printf("Not Balanced");

    return 0;
}
