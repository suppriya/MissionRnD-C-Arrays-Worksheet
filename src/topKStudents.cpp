/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:

*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};
int i, m;


struct student ** topKStudents(struct student *students, int len, int K) {
	if ((students != NULL) && (len > 0) && (K > 0))
	{
		struct student **ans = (struct student**)malloc(sizeof(struct student**)*K);
		struct student *temp = (struct student*)malloc(sizeof(struct student*)*len);
		
		for (int i = 0; i < len; i++)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (students[i].score > students[j].score)
				{
					temp[i] = students[i];
					students[i] = students[j];
					students[j] = temp[i];
				}
			}
		}
		if (K <= len) 
		{
			m = 1;
			int p = 0;
			for (int j = len ; j>= 1; j--)
			{
				if (m <= K)
				{
					ans[p++] = &students[j-1];
				}
				m++;
			}
		}
		else if (K > len)
		{
			for (int i = 0; i < len; i++)
			{
				ans[i] = &students[i];
			}
		}
		return ans;
	}
	return NULL;
}
