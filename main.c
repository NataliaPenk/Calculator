#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int ReadingCorrectNumbers(char number_str[]) {
    int number = 0;
    printf("%s\n", number_str);
    int scanf_result = scanf("%d", &number);
    if (!scanf_result) {
        printf("ERROR:Invalid data\n");
        _Exit (EXIT_SUCCESS);

    }
    return number;
}

char ReadingCorrectOperation() {
    char tmp_operation;
    printf("Operation\n");
    scanf("\n%c", &tmp_operation);
    if (strchr("+-*/", tmp_operation) == NULL) {
        printf("ERROR:Invalid data\n");
        _Exit (EXIT_SUCCESS);
    }
    return tmp_operation;
}

int main() {
    char first_number_str[13] = "First number";
    char second_number_str[14] = "Second number";
    int first_number = ReadingCorrectNumbers(first_number_str);
    int second_number = ReadingCorrectNumbers(second_number_str);
    char operation = ReadingCorrectOperation();
    int result = 0;
    switch (operation) {
        case '+':
            result = first_number + second_number;
            break;
        case '-':
            result = first_number - second_number;
            break;
        case '*':
            result = first_number * second_number;
            break;
        case '/':
            if (second_number == 0) {
                printf("Second number can't be equal 0\n");
                return 1;
            }
            result = first_number / second_number;
            break;
    }

    printf("result is: %d\n", result);
    return 0;
}