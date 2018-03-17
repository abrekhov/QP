#ifndef BASIS_H
#define BASIS_H

#include<string>
#include<vector>
#include<iostream>


using namespace std;

class SingleBF{
public:
	int L;
	vector< pair<double,double> > c_Alpha;
};

class Element{
public:
	string nameElement;
	vector<SingleBF> bf;
};


class BasisLib{
public:
	BasisLib(){};
	~BasisLib(){};
	void print() const {};
	int load(char*);

private:
	vector<string> content;
	int loadContent(char *, vector<string>& );
	int parseString(const string&, vector<string>&);
	int findDATA();
	int getNewElement();
	
	vector< Element > superArray;

//	vector< pair<string, vector< pair<int, vector< pair<double,double> > > > > > superArray;
};
#endif



