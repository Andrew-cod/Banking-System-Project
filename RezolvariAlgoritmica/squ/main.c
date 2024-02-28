#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

//verificam daca elementul e operator
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

//returneaza prioritatea operandului
int getPrecedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

//implimentam o stiva cu ajuturol tabelului
struct Stack
        {
    char items[MAX];
    int top;
};

//adaugam in stiva
void push(struct Stack* stack, char item)
        {
    stack->items[++stack->top] = item;
}

//scoatem din stiva
char pop(struct Stack* stack)
        {
    if (stack->top == -1)
        return '\0';
    return stack->items[stack->top--];
}

//verificam daca stiva este goala
int isStackEmpty(struct Stack* stack)
        {
    return (stack->top == -1);
}

//returnam ultimul elementdin stiva
char peek(struct Stack* stack)
        {
    if (stack->top == -1)
        return '\0';
    return stack->items[stack->top];
}

//facem forma poloneza postfixata pentru a evalua expresia
void infixToRPN(const char* expression, char* rpn)
{
    struct Stack operatorStack;
    operatorStack.top = -1;

    int i = 0;
    int j = 0;

    while (expression[i] != '\0')
    {
        if (isdigit(expression[i]))
        {
            rpn[j++] = expression[i];
        }
        else if (isOperator(expression[i]))
        {
            while (!isStackEmpty(&operatorStack) && getPrecedence(expression[i]) <= getPrecedence(peek(&operatorStack)))
            {
                rpn[j++] = pop(&operatorStack);
            }
            push(&operatorStack, expression[i]);
        }
        else if (expression[i] == '(')
        {
            push(&operatorStack, expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (!isStackEmpty(&operatorStack) && peek(&operatorStack) != '(')
            {
                rpn[j++] = pop(&operatorStack);
            }
            if (!isStackEmpty(&operatorStack) && peek(&operatorStack) == '(')
            {
                pop(&operatorStack);
            }
        }
        i++;
    }

    while (!isStackEmpty(&operatorStack))
    {
        rpn[j++] = pop(&operatorStack);
    }

    rpn[j] = '\0';
}


int evaluateRPN(const char* rpn)
{
    struct Stack operandStack;
    operandStack.top = -1;

    int i = 0;

    while (rpn[i] != '\0')
    {
        if (isdigit(rpn[i]))
        {
            push(&operandStack, rpn[i] - '0');
        }
        else if (isOperator(rpn[i]))
        {
            int operand2 = pop(&operandStack);
            int operand1 = pop(&operandStack);
            int result;

            switch (rpn[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator\n");
                    return 0;
            }

            push(&operandStack, result);
        }
        i++;
    }

    return pop(&operandStack);
}

int evaluateExpression(const char* expression)
{
    char rpn[MAX];
    infixToRPN(expression, rpn);
    return evaluateRPN(rpn);
}

//extragem rezultatul ce trebuie obtinut
int rezultat(char *s)
{
    //mergem pana la egal
    char *p=s;
    while(*p!='=')p++;

    //schimbam '=' cu '\0' pentru e delimita ecuatia rezultatul operatiei
    *p='\0';
    p++;
    //transformam rezultatul din string in int si returnam rezultatul
    int n=0;
    while(*p!='\0'){
        n=n*10+( (*p)-48);
        p++;
    }
    return n;
}

//adaugam un caracter pe o pozitie specificata
void add_ch(char* array, char character, int position)
{
    size_t length = strlen(array);

    if (length < MAX - 1 && position >= 0 && position <= length)
    {
        memmove(&array[position + 1], &array[position], length - position + 1);
        array[position] = character;
    }
}

//sterge un caracter de pe o pozitie specificata
void rm_ch(char* array, int position)
{
    size_t length = strlen(array);

    if (position >= 0 && position < length)
    {
        memmove(&array[position], &array[position + 1], length - position);
    }
}

int main() {
    char expression[300];
    int result = 0;
FILE *f, *p;
f=fopen("in.txt", "rt");


    fscanf(f,"%s", expression);  // Citește expresia de intrare

    fclose(f);
    int n = rezultat(expression);  // Obține rezultatul dorit din ecuație
p=fopen("out.txt", "wt");
    int i = 0, j;
    add_ch(expression, '(', 0);  // Adaugă o paranteză deschisă la începutul expresiei

    while (i < strlen(expression) - 1) {
        if (i != 0) {
            while (isOperator(expression[i + 1]) == 0) {
                i++;  // Găsește poziția următorului operator
            }
            add_ch(expression, '(', i);  // Adaugă o paranteză deschisă înaintea operatorului
        }

        j = strlen(expression) - 1;
        while (j > i) {
            if (j != strlen(expression) - 1) {
                while (isOperator(expression[j]) == 0)
                    j--;  // Găsește poziția operatorului anterior
                add_ch(expression, ')', j);  // Adaugă o paranteză închisă după operator

                result = evaluateExpression(expression);  // Evaluează expresia modificată
                if (n == result) {
                    fprintf(p,"%s=%d\n", expression, n);  // Afișează soluția dacă rezultatul se potrivește cu valoarea dorită
                    fclose(p);
                    return 0;
                }
                rm_ch(expression, j);  // Elimină paranteza închisă pentru modificări ulterioare

            } else {
                result = evaluateExpression(expression);  // Evaluează expresia originală fără modificări
                if (n == result) {
                    if (j + 1 == strlen(expression))
                        add_ch(expression, ')', strlen(expression));  // Adaugă o paranteză închisă la sfârșitul expresiei
                    fprintf(p,"%s=%d\n", expression, n);  // Afișează soluția
                    fclose(p);
                    return 0;
                }
            }
            j--;
        }

        rm_ch(expression, i);  // Elimină paranteza deschisă pentru modificări ulterioare
        i++;
    }

    return 0;
}
