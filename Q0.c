/*********************************************************************
** Program name:	CS261- Assignment 1 - Q0
** Author:			Tim Johnston
** Date:			9/25/2017
** Solution Description:
**   Passing variable address, printing addresses and values.
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr) {
	/*Print the value pointed to by iptr*/
	printf("Value pointed to: %d\n", *iptr);

	/*Print the address pointed to by iptr*/
	printf("Address pointed to: %p\n", iptr);

	/*Print the address of iptr itself*/
	printf("Address of pointer: %p\n\n", &iptr);
}

int main() {

	/*declare an integer x*/
	int x = 0;

	/*print the address of x*/
	printf("\nAddress of integer variable: %p\n\n", &x);

	/*Call fooA() with the address of x*/
	fooA(&x);

	/*print the value of x*/
	printf("Value of variable (after function): %d\n\n", x);

	return 0;
}