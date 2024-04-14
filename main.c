#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_LENGTH 100
#define MAX_NUM_COUNT 100

bool isNumber(const char *input){
    for (int i = 0; input[i] != '\0'; i++) { //Iterate through each character
      if (!(isdigit(input[i]) || (i == 0 && input[i] == '-'))) { //Check if digit or negative sign
        return false;
      }
    }
    return true;
}

bool isOperator(const char *input, const char value){
  if (input[0] == value) { //Check if first character is passed value
      return true;
  }
  return false;
}

int main() {
    char input[MAX_NUM_LENGTH];  //Store user input
    int numbers[MAX_NUM_COUNT]; //Store numbers input
    int numSize = 0;
    bool done = false;

    while(!done){
      printf("Enter a number or an operator (+ or *): "); //Prompt user for input

      fgets(input, sizeof(input), stdin); //Read user input from standard input
      input[strcspn(input, "\n")] = '\0';

      if (isNumber(input)){ //If input is a number
        int newNumber = atoi(input);
        numbers[numSize++] = newNumber; //Push the number to the array
        printf("You entered a number: %d\n", newNumber);
      }
      else if (isOperator(input, '+')) { //If plus sign is entered
        int sum = 0;
        for (int i = 0; i < numSize; i++) {
          sum += numbers[i]; //Sum the array
        }
        printf("The sum is: %d\n", sum);
        return 1;
      }
      else if (isOperator(input, '*')) { //If multiply is entered
        int product = 1;
        for (int i = 0; i < numSize; i++) {
          product *= numbers[i]; //Calculate product of the array
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
