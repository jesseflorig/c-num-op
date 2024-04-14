#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUMS 10

bool isNumber(const char *input){
    for (int i = 0; input[i] != '\0'; i++) { //Iterate through each character
      if (!(isdigit(input[i]) || (i == 0 && input[i] == '-'))) { //Check if digit or negative sign
        return false;
      }
    }
    return true;
}

bool isOperator(const char *input, const char value){
  if (input[0] == value) {
      return true;
  }
  return false;
}

int main() {
    char input[100];  //Store user input
    int numbers[100]; //Store numbers input
    int numSize = 0;
    bool done = false;

    while(!done){
      printf("Enter a number or an operator (+ or *): "); //Prompt user for input

      fgets(input, sizeof(input), stdin); //Read user input from standard input
      input[strcspn(input, "\n")] = '\0';

      if (isNumber(input)){
        int newNumber = atoi(input);
        numbers[numSize++] = newNumber;
        printf("You entered a number: %d\n", newNumber);
      }
      else if (isOperator(input, '+')) {
        int sum = 0;
        for (int i = 0; i < numSize; i++) {
          sum += numbers[i];
        }
        printf("The sum is: %d\n", sum);
        return 1;
      }
      else if (isOperator(input, '*')) {
        int product = 1;
        for (int i = 0; i < numSize; i++) {
          product *= numbers[i];
        }
        printf("The product is: %d\n", product);
        return 1;
      }
      else {
        printf("Invalid input...\n");
      }
    }

    return 0;
}
