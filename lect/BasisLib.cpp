#include "BasisLib.h"
#include <fstream>
#include <iostream>
#include <sstream>



//TODO better to put this func in new Class 
int BasisLib::loadContent(char* filename, vector<string>& cont){
	ifstream inp(filename);
	string tmpStr;
	cont.clear();
	while (getline(inp, tmpStr)){
		cont.push_back(tmpStr);
	}
	inp.close();
}

// TODO same as prev comment

int BasisLib::parseString(const string& inputStr, vector<string>& result){
	result.clear();
	stringstream ss;
	ss<<inputStr;
	string tStr;
	while(ss>>tStr) result.push_back(tStr);
}

int BasisLib::findDATA(){
	vector<string> tmpCont;
	for ( int i=0; i< (int) content.size();i++){
		parseString(content[i],tmpCont);
		if(tmpCont.size()==1)
			if(tmpCont[0]=="$DATA")
				return i;
	}
	return -1;
}


int BasisLib::load(char* filename){
	loadContent(filename, content);
	for (int i=0; i< (int) content.size(); i++){
		cout << content[i] << endl;
	}
	int nPos = findDATA();
	nPos++;
	cout << nPos <<endl;
	while(getNewElement()){
		
	}
}
