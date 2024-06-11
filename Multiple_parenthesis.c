#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

void Push(struct stack *s, char val)
{
    s->top++;
    s->arr[s->top] = val;
}

char Pop(struct stack *s)
{
    char val = s->arr[s->top];
    s->top--;
    return val;
}

char StackTop(struct stack *s)
{
    return s->arr[s->top];
}

int isMatch(char b, char a)
{
    if ((b == '(') && (a == ')'))
    {
        return 1;
    }
    if ((b == '{') && (a == '}'))
    {
        return 1;
    }
    if ((b == '[') && (a == ']'))
    {
        return 1;
    }
    return 0;
}

int parenthesisMatcher(char *exp)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char a;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            Push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }

            a = Pop(sp);

            if (!isMatch(a, exp[i]))
            {
                return 0;
            }
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{

    const char *exp = "{[()]}()[]";
    if (parenthesisMatcher(exp))
    {
        printf("Parenthesis are matching.\n");
    }
    else
    {
        printf("Parenthesis are not matching.\n");
    }
    return 0;
}
