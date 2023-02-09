#include<stdio.h>

/*
Name: Kevin Feng
Purpose: The purpose of this program is to make conversions from one metric to another
Author: kfeng58 (251231033)
*/

void main() {
    int input;
	char charMetric;
	float inputValue;

	//Label for going back to the menu
	menu:
	printf("What would you like to do? ");

	//Using an infinite loop to continue running until correct input is inputted
	while (1) {
		scanf(" %d", &input);

		if (input == 1) {
			printf("\nKilograms to pounds (K) or pounds to kilograms (P)? ");

			//Another infinite loop to get correct user input
			while (1) {

				//Using getchar() as a more efficient way to get user input for characters
				charMetric = getchar();
				if (charMetric == 'K') {
					printf("\nPlease enter a value: ");
					scanf("%f", &inputValue);
					printf("Your conversion from kilograms to pounds is: %f\n", inputValue * 2.20462);

					//Going back to the menu so that the code continues to run
					goto menu;
				}
				else if (charMetric == 'P') {
					printf("\nPlease enter a value: ");
					scanf("%f", &inputValue);
					printf("Your conversion from pounds to kilograms is: %f\n", inputValue / 2.20462);
					goto menu;
				}
				else {
					break;
				}
			}
		}
		else if (input == 2) {
			printf("\nHectares to acres (H) or acres to hectares (A)? ");
			while (1) {
				charMetric = getchar();
				if (charMetric == 'H') {
					printf("\nPlease enter a value: ");
					scanf("%f", &inputValue);
					printf("Your conversion from hectares to acres is: %f\n", inputValue * 2.47105);
					goto menu;
				}
				else if (charMetric == 'A') {
					printf("\nPlease enter a value: ");
					scanf("%f", &inputValue);
					printf("Your conversion from acres to hectares is: %f\n", inputValue / 2.47105);
					goto menu;
				}
				else {
					break;
				}
			}
		}
		else if (input == 3) {
			printf("\nLitres to gallons (L) or gallons to litres (G)? ");

			while (1) {
				charMetric = getchar();
				if (charMetric == 'L') {
					printf("\nPlease enter a value: ");
					scanf("%f", &inputValue);
					printf("Your conversion from litres to gallons is: %f\n", inputValue * 0.264172);
					goto menu;
				}
				else if (charMetric == 'G') {
					printf("\nPlease enter a value: ");
					scanf("%f", &inputValue);
					printf("Your conversion from gallons to litres is: %f\n", inputValue / 0.264172);
					goto menu;
				}
				else {
					break;
				}
			}
		}
		else if (input == 4) {
			printf("\nKilometres to miles (K) or miles to kilometres (M)? ");

			while (1) {
				charMetric = getchar();
				if (charMetric == 'K') {
					printf("\nPlease enter a value: ");
					scanf("%f", &inputValue);
					printf("Your conversion from kilometers to miles is %f\n", inputValue * 0.621371);
					goto menu;
				}
				else if (charMetric == 'M') {
					printf("\nPlease enter a value: ");
					scanf("%f", &inputValue);
					printf("Your conversion from miles to kilometers is %f\n", inputValue / 0.621371);
					goto menu;
				}
				else {
					break;
				}
			}
		}
		else if (input == 5) {
			printf("Program exited");
			return 0;
		}
		else {
			printf("Please enter an integer between 1-5 inclusive: ");
		}
	}
}