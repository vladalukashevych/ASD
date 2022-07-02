#include <iostream>
#include <math.h>

int main()
{
    int stack[1000], index = 0;
    printf("Enter math expression: ");
    while (!feof(stdin))
    {
        int symbol = getchar();
        int number;
        switch (symbol)
        {
        case  ' ':
            break;
        case '\n':
            break;
        case '=': {
            printf("Result: %d\n", stack[index - 1]);  index--;
            return 0;
            break;
        }
        case '+': {
            stack[index - 2] = stack[index - 2] + stack[index - 1];
            index--;
            break;
        }
        case '-': {
            stack[index - 2] = stack[index - 2] - stack[index - 1];
            index--;
            break;
        }
        case '*': {
            stack[index - 2] = stack[index - 1] * stack[index - 2];
            index--;
            break;
        }
        case '/': {
            stack[index - 2] = stack[index - 2] / stack[index - 1];
            index--;
            break;
        }
        case '^': {
            stack[index - 2] = pow(stack[index - 2], stack[index - 1]);
            index--;
            break;
        }
        case 's': {
            if (getchar() == 'q') {
                if (getchar() == 'r') {
                    if (getchar() == 't') {
                        stack[index - 1] = sqrt(stack[index - 1]);
                        break;
                    }
                }
            }
        }
        default: {
            ungetc(symbol, stdin);
            if (scanf_s("%d", &number) != 1) {
                printf("Can't read integer\n");
                return 1;
            }
            else {
                stack[index] = number;
                index++;
            }
        }
        }
    }

    return 0;
}