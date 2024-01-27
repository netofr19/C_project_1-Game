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
    Calculate calc;
    int difficulty;

    printf("Enter the desired difficulty level [1,2,3 or 4]: ");
    scanf("%d", &difficulty);

    calc.difficulty = difficulty;

    // Generates a random integer between 0 and 2
    // 0 -> sum, 1 -> subtraction, 2 -> Multiply
    calc.operation = rand() % 3;

    if (calc.difficulty == 1){ //easy
        calc.value1 = rand() % 11; // random integer between 0 and 10
        calc.value2 = rand() % 11;
    } else if (calc.difficulty == 2){//medium
        calc.value1 = rand() % 101; // random integer between 0 a 100
        calc.value2 = rand() % 101;
    } else if (calc.difficulty == 3){ //hard
        calc.value1 = rand() % 1001; // random integer between 0 a 1000
        calc.value2 = rand() % 1001;
    } else if (calc.difficulty == 4){ //very hard
        calc.value1 = rand() % 10001;// random integer between 0 a 10000
        calc.value2 = rand() % 10001;
    } else { // secret level
        calc.value1 = rand() % 100001;// random integer between 0 a 100000
        calc.value2 = rand() % 100001;
    }

    int answer;
    printf("Enter the result for the following operation: \n");

    //Sum
    if (calc.operation == 0){
        printf("%d + %d\n", calc.value1, calc.value2);
        scanf("%d", &answer);

        if(add(answer, calc)){
            points += 1;
            printf("You have %d points.\n", points);
        }
    } else if (calc.operation == 1){
        printf("%d - %d\n", calc.value1, calc.value2);
        scanf("%d", &answer);

        if (sub(answer, calc)){
            points += 1;
            printf("You have %d points.\n", points);
        }
    } else if (calc.operation == 2){
        printf("%d * %d\n", calc.value1, calc.value2);
        scanf("%d", &answer);

        if (multiply(answer, calc)){
            points += 1;
            printf("You have %d points.\n", points);
        }
    } else{
        printf("The operation %d is not recognized", calc.operation);
    }

    //Continue the game?
    printf("What do you want to do? [2 - Continue, 1 - Show Info, 0 - Exit]: ");
    int cont;
    scanf("%d", &cont);

    if (cont == 2){
        game();
    } else if (cont == 1){
        showInfo(calc);
        game();
    } else {
        printf("you finish the game with %d points\n", points);
        printf("See you next time!\n");
        exit(0);
    }
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
    printf("Value 01: %d \nValue 02: %d \nDifficulty: %d \nOperation: %s\n", calc.value1, calc.value2, calc.difficulty, op);
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
