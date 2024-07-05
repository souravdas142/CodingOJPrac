#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>


int gflag = 1;

void parseCli (int argc,char *argv[],int *arr) {
	
	int opt;

	while((opt = getopt(argc,argv,":i:")) != -1) {

		switch(opt) {

			case 'i':
				gflag = atoi(optarg);
				printf("gflag  = %d \n",gflag);
				break;
			case '?':
				printf("usage()");
				break;
			case ':':
				printf("option needs a value: \n");
				printf("usage()");
				break;
		}
	}

	int i = 0;
	for(;optind<argc;optind++) {
		arr[i++] = atoi(argv[optind]);
	}

}


int main (int argc, char* argv[]) {

	int args[5];

	if(argc > 3) {
		parseCli(argc,argv,args);
	}

	printf("\n");
	for(int i = 0;i<5;i++) {
		printf("args[%d] = %d ",i,args[i]);
	}
	printf("\n");

	return 0;

}



