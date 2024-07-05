#include<stdio.h>
#include "hel.h"


void printName (Emp *em) {
	printf("Emp name = %s\n",em->Name);
	printf("EmpNo = %d\n",em->empNo);
}

int doThings(Emp *sourav) {

	sourav->empNo = 5;
	sourav->Name = "Das";

	printName(sourav);

	return 0;
}
