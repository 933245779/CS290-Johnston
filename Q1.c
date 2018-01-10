/*********************************************************************
** Program name:	CS261- Assignment 1 - Q1
** Author:			Tim Johnston
** Date:			9/25/2017
** Solution Description:
**  Dynamic memory allocated for struct student
**  Randomly generate random (and unique) IDs.
**  Randomly generate scores from 0 to 100 inclusive.
**  Calculate and print: min, max, and avg score.
**  Deallocate dynamic memory.
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>

struct student {
	int id;
	int score;
};

struct student* allocate() {
	/*Allocate memory for ten students*/
	int numStudents = 10;
	struct student* temp = malloc(numStudents * sizeof(struct student));
	assert(temp != NULL); //Check to make sure temp is not null

	/*return the pointer*/
	return temp;
}

void generate(struct student* students) {
	//Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100
	int maxID = 10;
	int maxScore = 100;
	srand((unsigned int)time(NULL));

	for (int i = 0; i < maxID; ++i) {
		int check = 0;

		while (!check) {
			//While loop continues until loop ends with a true check value
			students[i].id = rand() % maxID + 1;
			//Initialize check to true value to start the while loop
			check = 1;
			//Cycle through all student IDs (inner loop index) and compare them to student ID (outer loop index)
			for (int j = 0; j < i; ++j) {
				if (students[i].id == students[j].id)
					check = 0;	//If there is a match the check value is reassigned to false
			}
		}
	}

	for (int i = 0; i < 10; ++i) {
		students[i].score = rand() % (maxScore + 1);
	}
}

void output(struct student* students) {
	/*Output information about the ten students in the format:
	ID1 Score1
	*/

	for (int i = 0; i < 10; ++i) {
		printf("ID%d\t Score %d\n", students[i].id, students[i].score);
	}
}


void summary(struct student* students) {
	//Compute and print the minimum, maximum and average scores of the ten students
	int tempScore = -1;
	int tempID = -1;
	int end = 10;
	int length = 10;

	//Begin bubble sort by student score
	for (int i = length - 1; i > 0; i--) {
		for (int j = 0; j < end - 1; j++) {
			if (students[j].score > students[j + 1].score) {
				tempScore = students[j + 1].score;
				tempID = students[j + 1].id;
				students[j + 1].score = students[j].score;
				students[j + 1].id = students[j].id;
				students[j].score = tempScore;
				students[j].id = tempID;
			}
		}
		end--;
	}

	//Calculate min and max
	int min = students[0].score;
	int max = students[9].score;

	//Prepare to calculate avg
	double avg = 0;
	double num = 10;
	double sum = 0;

	//Sum all scores
	for (int k = 0; k < 10; k++) {
		sum += students[k].score;
	}

	//Calculate avg
	avg = sum / num;

	//Print min, max, and avg
	printf("\n Min: %d\n Max: %d\n Avg: %.1f\n", min, max, avg);
}

void deallocate(struct student* stud) {
	/*Deallocate memory from stud*/
	free(stud);
}

int main() {
	struct student* stud = NULL;

	/*call allocate*/
	stud = allocate();

	/*call generate*/
	generate(stud);

	/*call output*/
	output(stud);

	/*call summary*/
	summary(stud);

	/*call deallocate*/
	assert(stud != NULL); //Check to make sure that stud is not NULL.
	deallocate(stud);

	return 0;
}