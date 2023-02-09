#include<stdio.h>

/*
Name: Kevin Feng
Purpose: The purpose of this program is to translate user inputted digits from 1-999 to their word representations
Author: kfeng58 (251231033)
*/

void main() {
    int number, counter, tempNum;
    int numDigits;

    //Using a do while statement to keep code running unless input equals 0
    beginning:
    do {
        printf("\nPlease enter a value (1-999, 0 to quit): ");
        scanf("%d", &number);

        //Determining the size of the integer (How many individual digits it has)
        if (number / 10 == 0) {
            numDigits = 1;
        }
        else if (number / 100 == 0) {
            numDigits = 2;
        }
        else {
            numDigits = 3;
        }

        if (numDigits == 3) {

            //Getting the hundreds integer
            tempNum = number / 100;
            if (tempNum == 1) printf("One Hundred and ");
            else if (tempNum == 2) printf("Two Hundred and ");
            else if (tempNum == 3) printf("Three Hundred and ");
            else if (tempNum == 4) printf("Four Hundred and ");
            else if (tempNum == 5) printf("Five Hundred and ");
            else if (tempNum == 6) printf("Six Hundred and ");
            else if (tempNum == 7) printf("Seven Hundred and ");
            else if (tempNum == 8) printf("Eight Hundred and ");
            else if (tempNum == 9) printf("Nine Hundred and ");

            //Getting the tens integer
            tempNum = number / 10 % 10;
                if (tempNum == 1) {
                    if (number % 10 == 0) {
                        printf("Ten");
                    }
                    else if (number % 10 == 1) {
                        printf("Eleven");
                    }
                    else if (number % 10 == 2) {
                        printf("Twelve");
                    }
                    else if (number % 10 == 3) {
                        printf("Thirteen");
                    }
                    else if (number % 10 == 4) {
                        printf("Fourteen");
                    }
                    else if (number % 10 == 5) {
                        printf("Fifteen");
                    }
                    else if (number % 10 == 6) {
                        printf("Sixteen");
                    }
                    else if (number % 10 == 7) {
                        printf("Seventeen");
                    }
                    else if (number % 10 == 8) {
                        printf("Eighteen");
                    }
                    else if (number % 10 == 9) {
                        printf("Nineteen");
                    }
                    goto beginning;
                }
                else if (tempNum == 2) printf("Twenty ");
                else if (tempNum == 3) printf("Thirty ");
                else if (tempNum == 4) printf("Forty ");
                else if (tempNum == 5) printf("Fifty ");
                else if (tempNum == 6) printf("Sixty ");
                else if (tempNum == 7) printf("Seventy ");
                else if (tempNum == 8) printf("Eighty ");
                else if (tempNum == 9) printf("Ninety ");

            //Getting the ones integer
            tempNum = number % 10;
            if (tempNum == 1) printf("One");
            else if (tempNum == 2) printf("Two");
            else if (tempNum == 3) printf("Three");
            else if (tempNum == 4) printf("Four");
            else if (tempNum == 5) printf("Five");
            else if (tempNum == 6) printf("Six");
            else if (tempNum == 7) printf("Seven");
            else if (tempNum == 8) printf("Eight");
            else if (tempNum == 9) printf("Nine");
        }
        else if (numDigits == 2) {
            
            //Getting the tens integer
            tempNum = number / 10;
            if (tempNum == 1) {
                    if (number % 10 == 0) {
                    printf("Ten");
                    }
                    else if (number % 10 == 1) {
                        printf("Eleven");
                    }
                    else if (number % 10 == 2) {
                        printf("Twelve");
                    }
                    else if (number % 10 == 3) {
                        printf("Thirteen");
                    }
                    else if (number % 10 == 4) {
                        printf("Fourteen");
                    }
                    else if (number % 10 == 5) {
                        printf("Fifteen");
                    }
                    else if (number % 10 == 6) {
                        printf("Sixteen");
                    }
                    else if (number % 10 == 7) {
                        printf("Seventeen");
                    }
                    else if (number % 10 == 8) {
                        printf("Eighteen");
                    }
                    else if (number % 10 == 9) {
                        printf("Nineteen");
                    }
                    goto beginning;
                }
            else if (tempNum == 2) printf("Twenty ");
            else if (tempNum == 3) printf("Thirty ");
            else if (tempNum == 4) printf("Forty ");
            else if (tempNum == 5) printf("Fifty ");
            else if (tempNum == 6) printf("Sixty ");
            else if (tempNum == 7) printf("Seventy ");
            else if (tempNum == 8) printf("Eighty ");
            else if (tempNum == 9) printf("Ninety ");

            //Getting the ones integer
            tempNum = number % 10;
            if (tempNum == 1) printf("One");
            else if (tempNum == 2) printf("Two");
            else if (tempNum == 3) printf("Three");
            else if (tempNum == 4) printf("Four");
            else if (tempNum == 5) printf("Five");
            else if (tempNum == 6) printf("Six");
            else if (tempNum == 7) printf("Seven");
            else if (tempNum == 8) printf("Eight");
            else if (tempNum == 9) printf("Nine");
        }
        else if (numDigits == 1) {

            //Getting the ones integer
            if (number == 1) printf("One");
            else if (number == 2) printf("Two");
            else if (number == 3) printf("Three");
            else if (number == 4) printf("Four");
            else if (number == 5) printf("Five");
            else if (number == 6) printf("Six");
            else if (number == 7) printf("Seven");
            else if (number == 8) printf("Eight");
            else if (number == 9) printf("Nine");
        }
    } while(number != 0);
}