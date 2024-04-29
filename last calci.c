#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define note "Please enter a valid operation"
#define STACK_SIZE 100

// Stack structure
typedef struct {
    float items[STACK_SIZE];
    int top;
} Stack;

// Function prototypes for stack operations
void initializeStack(Stack *s);
bool isFull(const Stack *s);
bool isEmpty(const Stack *s);
void push(Stack *s, float value);
float pop(Stack *s);

// Function prototypes for mathematical operations
void addition(Stack *s);
void subtraction(Stack *s);
void multiplication(Stack *s);
void division(Stack *s);
void modulus(Stack *s);
void power(Stack *s);
void square(Stack *s);
void cube(Stack *s);
void squareroot(Stack *s);
void sine(Stack *s);
void cosine(Stack *s);
void tangent(Stack *s);
void naturalLogarithm(Stack *s);
void base10Logarithm(Stack *s);
void quadraticRoots(Stack *s);
void mean(Stack *s);
void median(Stack *s);
void standardDeviation(Stack *s);

int main() {
    printf("\t\tWelcome to the scientific calculator!!\n\n");

    Stack operandStack;
    initializeStack(&operandStack);

    while (1) {
        printf("\n******* Press 0 to quit the program ********\n");
        printf("Enter 1 for Addition \n");
        printf("Enter 2 for Subtraction \n");
        printf("Enter 3 for Multiplication \n");
        printf("Enter 4 for Division \n");
        printf("Enter 5 for Modulus\n");
        printf("Enter 6 for Power \n");
        printf("Enter 7 for Square \n");
        printf("Enter 8 for Cube \n");
        printf("Enter 9 for Square Root\n");
        printf("Enter 10 for Sine \n");
        printf("Enter 11 for Cosine \n");
        printf("Enter 12 for Tangent \n");
        printf("Enter 13 for Natural Logarithm \n");
        printf("Enter 14 for Base-10 Logarithm \n");
        printf("Enter 15 for Quadratic Roots \n");
        printf("Enter 16 for Mean \n");
        printf("Enter 17 for Median \n");
        printf("Enter 18 for Standard Deviation \n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the program.\n");
            break;
        }

        // Evaluate expression using postfix notation
        switch (choice) {
            case 1:
                addition(&operandStack);
                break;
            case 2:
                subtraction(&operandStack);
                break;
            case 3:
                multiplication(&operandStack);
                break;
            case 4:
                division(&operandStack);
                break;
            case 5:
                modulus(&operandStack);
                break;
            case 6:
                power(&operandStack);
                break;
            case 7:
                square(&operandStack);
                break;
            case 8:
                cube(&operandStack);
                break;
            case 9:
                squareroot(&operandStack);
                break;
            case 10:
                sine(&operandStack);
                break;
            case 11:
                cosine(&operandStack);
                break;
            case 12:
                tangent(&operandStack);
                break;
            case 13:
                naturalLogarithm(&operandStack);
                break;
            case 14:
                base10Logarithm(&operandStack);
                break;
            case 15:
                quadraticRoots(&operandStack);
                break;
            case 16:
                mean(&operandStack);
                break;
            case 17:
                median(&operandStack);
                break;
            case 18:
                standardDeviation(&operandStack);
                break;
            default:
                printf("\n********** %s ***********\n", note);
        }
    }

    return 0;
}

// Function implementations for stack operations
void initializeStack(Stack *s) {
    s->top = -1;
}

bool isFull(const Stack *s) {
    return s->top == STACK_SIZE - 1;
}

bool isEmpty(const Stack *s) {
    return s->top == -1;
}

void push(Stack *s, float value) {
    if (!isFull(s)) {
        s->items[++s->top] = value;
    } else {
        printf("Stack Overflow!\n");
    }
}

float pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    } else {
        printf("Stack Underflow!\n");
        return NAN; // Not-a-Number to indicate error
    }
}

// Function implementations for mathematical operations
void addition(Stack *s) {
    float a, b;
    printf("Enter operand a: ");
    scanf("%f", &a);
    printf("Enter operand b: ");
    scanf("%f", &b);
    push(s, a + b);
    printf("Result: %.2f\n", a + b);
}

void subtraction(Stack *s) {
    float a, b;
    printf("Enter operand a: ");
    scanf("%f", &a);
    printf("Enter operand b: ");
    scanf("%f", &b);
    push(s, a - b);
    printf("Result: %.2f\n", a - b);
}

void multiplication(Stack *s) {
    float a, b;
    printf("Enter operand a: ");
    scanf("%f", &a);
    printf("Enter operand b: ");
    scanf("%f", &b);
    push(s, a * b);
    printf("Result: %.2f\n", a * b);
}

void division(Stack *s) {
    float a, b;
    printf("Enter numerator: ");
    scanf("%f", &a);
    printf("Enter denominator: ");
    scanf("%f", &b);
    if (b == 0) {
        printf("Error: Division by zero\n");
    } else {
        push(s, a / b);
        printf("Result: %.2f\n", a / b);
    }
}

void modulus(Stack *s) {
    float a, b;
    printf("Enter operand a: ");
    scanf("%f", &a);
    printf("Enter operand b: ");
    scanf("%f", &b);
    if (b == 0) {
        printf("Error: Modulus by zero\n");
    } else {
        push(s, fmod(a, b));
        printf("Result: %.2f\n", fmod(a, b));
    }
}

void power(Stack *s) {
    float base, exponent;
    printf("Enter base: ");
    scanf("%f", &base);
    printf("Enter exponent: ");
    scanf("%f", &exponent);
    push(s, pow(base, exponent));
    printf("Result: %.2f\n", pow(base, exponent));
}

void square(Stack *s) {
    float num;
    printf("Enter number: ");
    scanf("%f", &num);
    push(s, num * num);
    printf("Result: %.2f\n", num * num);
}

void cube(Stack *s) {
    float num;
    printf("Enter number: ");
    scanf("%f", &num);
    push(s, num * num * num);
    printf("Result: %.2f\n", num * num * num);
}

void squareroot(Stack *s) {
    float num;
    printf("Enter number: ");
    scanf("%f", &num);
    if (num < 0) {
        printf("Error: Cannot compute square root of a negative number\n");
    } else {
        push(s, sqrt(num));
        printf("Result: %.2f\n", sqrt(num));
    }
}

void sine(Stack *s) {
    float angle;
    printf("Enter the angle in degrees: ");
    scanf("%f", &angle);
    push(s, sin(angle * M_PI / 180));
    printf("Result: %.2f\n", sin(angle * M_PI / 180));
}

void cosine(Stack *s) {
    float angle;
    printf("Enter the angle in degrees: ");
    scanf("%f", &angle);
    push(s, cos(angle * M_PI / 180));
    printf("Result: %.2f\n", cos(angle * M_PI / 180));
}

void tangent(Stack *s) {
    float angle;
    printf("Enter the angle in degrees: ");
    scanf("%f", &angle);
    push(s, tan(angle * M_PI / 180));
    printf("Result: %.2f\n", tan(angle * M_PI / 180));
}

void naturalLogarithm(Stack *s) {
    float num;
    printf("Enter the number: ");
    scanf("%f", &num);
    if (num <= 0) {
        printf("Error: Cannot compute natural logarithm of a non-positive number\n");
    } else {
        push(s, log(num));
        printf("Result: %.2f\n", log(num));
    }
}

void base10Logarithm(Stack *s) {
    float num;
    printf("Enter the number: ");
    scanf("%f", &num);
    if (num <= 0) {
        printf("Error: Cannot compute base-10 logarithm of a non-positive number\n");
    } else {
        push(s, log10(num));
        printf("Result: %.2f\n", log10(num));
    }
}

void quadraticRoots(Stack *s) {
    float a, b, c;
    printf("Enter the coefficients a, b, and c of the quadratic equation (ax^2 + bx + c): ");
    scanf("%f %f %f", &a, &b, &c);
    float discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        // Real roots
        float root1 = (-b + sqrt(discriminant)) / (2 * a);
        float root2 = (-b - sqrt(discriminant)) / (2 * a);
        push(s, root1);
        push(s, root2);
        printf("Real Roots: %.2f, %.2f\n", root1, root2);
    } else if (discriminant == 0) {
        // Equal real roots
        float root = -b / (2 * a);
        push(s, root);
        push(s, root);
        printf("Equal Real Roots: %.2f, %.2f\n", root, root);
    } else {
        // Complex roots
        float realPart = -b / (2 * a);
        float imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Complex Roots: %.2f + %.2fi, %.2f - %.2fi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }
}

void mean(Stack *s) {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    float sum = 0;
    for (int i = 0; i < n; ++i) {
        float num;
        printf("Enter number %d: ", i + 1);
        scanf("%f", &num);
        sum += num;
    }
    float mean = sum / n;
    push(s, mean);
    printf("Mean: %.2f\n", mean);
}

void median(Stack *s) {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    float *arr = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; ++i) {
        printf("Enter number %d: ", i + 1);
        scanf("%f", &arr[i]);
    }
    // Sort the array
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    float median;
    if (n % 2 == 0) {
        median = (arr[n / 2 - 1] + arr[n / 2]) / 2;
    } else {
        median = arr[n / 2];
    }
    free(arr);
    push(s, median);
    printf("Median: %.2f\n", median);
}

void standardDeviation(Stack *s) {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    float *arr = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; ++i) {
        printf("Enter number %d: ", i + 1);
        scanf("%f", &arr[i]);
    }
    // Calculate mean
    float sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    float mean = sum / n;
    // Calculate variance
    float variance = 0;
    for (int i = 0; i < n; ++i) {
        variance += (arr[i] - mean) * (arr[i] - mean);
    }
    variance /= n;
    // Calculate standard deviation
    float std_dev = sqrt(variance);
    free(arr);
    push(s, std_dev);
    printf("Standard Deviation: %.2f\n", std_dev);
}
