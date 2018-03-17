#include<iostream>
#include "BasisLib.h"

using namespace std;

int main(int argc, char* argv[]) {
	BasisLib basisLib;
	basisLib.load((char*)"newbasis");
	basisLib.print();
	return 0;
}
