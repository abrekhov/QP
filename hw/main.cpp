#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <regex>

#define BUFFER 2000

using namespace std;

class BFonEl{
	public:
		string tmp[BUFFER];
		double data1=0.0;
		double data2=0.0;
		void init(const char *filename);
		void printVec(void);
		void getVecSize(void);
		std::map<string, vector<vector<double>>> atom;
		int dataswitcher=0;
};

void BFonEl::init(const char *filename){
	ifstream infile;
	infile.open(filename, ios::in);
	
	string line;
	int i=0;
	while(getline(infile, line)){
		istringstream iss(line);
		while(iss.good()){
			iss >> tmp[i];
			if(tmp[i]=="!") break; //pass the comments
			if(tmp[i]==("$DATA")){
				dataswitcher=(dataswitcher)?0:1;
				cout << dataswitcher << endl;
				break;
			}
			regex rx("[A-Z]+", regex_constants::basic);
			
			if(dataswitcher&&regex_match(tmp[i], rx)){
				cout << tmp[i] << endl;
			}
			i++;
		}
		
	}
	
	
	infile.close();
}
/*
void BFonEl::printVec(void){
	for(int i=0; i< coef[0].size();i++){
		cout <<"Coef[0]["<<i<<"]" << coef[0][i];
		cout <<"Coef[1]["<<i<<"]" << coef[1][i] << endl;
	}
}

void BFonEl::getVecSize(void){
	cout << "Coef size:" << coef.size() << endl;
	cout << "Coef[0] size:" << coef[0].size() << endl;

}
*/
int main(){
	BFonEl BF1;
	BF1.init("basis");
	//BF1.getVecSize();
	//BF1.printVec();
	return 0;

}
