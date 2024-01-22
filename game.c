#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int difficulty;
    int value1;
    int value2;
    int operation;
    int result_ope;
} Calculate;

void game();
void showInfo(Calculate calc);
int add(int answer, Calculate calc);
int sub(int answer, Calculate calc);
int multiply(int answer, Calculate calc);

int points = 0;


int main()
{
    // Must be called only one time.
    srand(time(NULL));

    game();
    
    return 0;
}

void game(){
    // In progress ...
}

void showInfo(Calculate calc){
    char op[25];

    if (calc.operation == 0){ //0 -> Add
        sprintf(op, "Add");
    } else if (calc.operation == 1){ //1 -> subtraction
        sprintf(op, "Subtraction");
    } else if (calc.operation == 2){//2 == Multiply
        sprintf(op, "Multiply");
    } else {
        sprintf (op, "Unknown Operation");
    }
    printf("Value 01: %d \nValue 02: %d \nDificuldade: %d \nOperation: %s", calc.value1, calc.value2, calc.difficulty, op);
}

int add(int answer, Calculate calc){
    int result_ope = calc.value1 + calc.value2;
    calc.result_ope = result_ope;
    int correct = 0; // 0 == wrong, 1 == right

    if(answer == calc.result_ope){
        printf("Correct Answer!\n");
        correct = 1;
    } else {
        printf("Wrong Answer!\n");
    }
    printf("%d + %d = %d\n", calc.value1, calc.value2, calc.result_ope);

    return correct;
}

int sub(int answer, Calculate calc){
    int result_ope = calc.value1 - calc.value2;
    calc.result_ope = result_ope;
    int correct = 0; // 0 == wrong, 1 == right

    if(answer == calc.result_ope){
        printf("Correct Answer!\n");
        correct = 1;
    } else {
        printf("Wrong Answer!\n");
    }
    printf("%d - %d = %d\n", calc.value1, calc.value2, calc.result_ope);

    return correct;
}

int multiply(int answer, Calculate calc){
    int result_ope = calc.value1 * calc.value2;
    calc.result_ope = result_ope;
    int correct = 0; // 0 == wrong, 1 == right

    if(answer == calc.result_ope){
        printf("Correct Answer!\n");
        correct = 1;
    } else {
        printf("Wrong Answer!\n");
    }
    printf("%d * %d = %d\n", calc.value1, calc.value2, calc.result_ope);

    return correct;
}