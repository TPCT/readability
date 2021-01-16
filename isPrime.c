/************************   CODE DESIGN   ************************
 * LOOP (infinite)
 *      read number from the user (msg: enter number to check if it's prime, number <= 0 terminates).
 *      if number <= 0 then
 *          program terminates (printing exit message then terminates).
 *      else if number == 1
 *          print it's not a prime number
 *      else
 *          get sqrt of input number
 *          loop from i = 2 to sqrt(input number)
 *              if (input number) % i == 0 then
 *                  print it's not prime number
 *                  continue
 *          print it's a prime number.
 * END LOOP
 */

#include <stdio.h>
#include <math.h>

char inputBuff[100];       /* buffer to read input from the user      */
unsigned long inputNumber; /*  the input number entered from the user */

int main(void){
    while (1){
        printf("Please enter number to check if it's prime (0 terminates): ");
        fgets(inputBuff, sizeof(inputBuff), stdin);
        sscanf(inputBuff, "%lu", &inputNumber);

        if (inputNumber == 0) {
            printf("You entered zero the program will terminate.\n");
            break;
        }
        else if (inputNumber == 1) {
            printf("Number 1 is not prime number.\n");
        }
        else {
            printf("Number %lu ", inputNumber);
            for (unsigned int i = 2; i <= (unsigned int)sqrt(inputNumber); i++){

                /*
                 * i is divisor that check if input number is prime or not
                 * if input_number % i == 0 then it's not divisible by i (it might be a prime number).
                 * if input_number % i != 0 then it's not a prime number.
                 */

                if (inputNumber % i == 0){
                    printf("is not a prime number.\n");

                    /*
                     * this jump statement.
                     * jump is made such that "is a prime number." statement is not printed after loop is broken
                     */

                    goto whileLoopContinue;
                }
            }
            printf("is a prime number.\n");
        }
        whileLoopContinue:
            /*
             * semi-colon is here because there's no empty label in c
             */
            ;
    }
    return 0;
}
