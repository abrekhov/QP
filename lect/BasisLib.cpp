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

int BasisLib::parseString(const string& inputStr, vector<string>& result){
	result.clear();
	stringstream ss;
	ss<<inputStr;
	string tStr;
	while(ss>>tStr) result.push_back(tStr);
}


int BasisLib::load(char* filename){
	loadContent(filename, content);
	for (int i=0; i< (int) content.size(); i++){
		cout << content[i] << endl;
	}
	int nPos = findDATA();
	nPos++;
	
	int bfnum = 0;
	vector<string> tmpCont;
	for (int i=nPos; i<(int) content.size(); i++){
		parseString(content[i], tmpCont);
		if(tmpCont.size()==1&&tmpCont[0]!="$END"){	
			Element element;
			element.nameElement = tmpCont[0];
			cout << tmpCont[0]<< endl;
			superArray.push_back(element);
		}
		if(tmpCont.size()==2){
			SingleBF singlebf;
			if(tmpCont[0]=="S") singlebf.L=0;
			else if(tmpCont[0]=="P") singlebf.L=1;
			else if(tmpCont[0]=="D") singlebf.L=2;
			
			superArray.back().bf.push_back(singlebf);
		}
		if(tmpCont.size()==3||tmpCont.size()==4){
			cout << tmpCont[1] << "  " << tmpCont[2] << endl;
			superArray.back().bf.back().c_Alpha.push_back(make_pair(stod(tmpCont[1]), stod(tmpCont[2])));	
		}
	}

	for( int i=0; i< (int) superArray.size(); i++){
		//cout<<superArray[i].nameElement<<endl;
	}
		
}

