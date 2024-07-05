#include<iostream>

extern "C" {
#include "hel.h"
}
using namespace std;



int main() {

	Emp Sourav;
	doThings(&Sourav);
	return 0;
}
