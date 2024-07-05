
typedef struct emp {
	int empNo;
	char *Name;
} Emp;

void printName (Emp *emp_);
int doThings(Emp *emp_);

/*
 
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

*/
