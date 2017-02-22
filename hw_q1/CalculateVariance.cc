#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void parseState(string line, vector<int> &v1, 
	vector<int> &v2, vector<int> &v3);

double computeVar(vector<int> v, double mean);

int main(int argc, char const *argv[])
{
	if (argc != 2) {
		cerr << "usage: ./CalculateVariance yourOutputFile.";
		return 1;
	}
	ifstream in(argv[1]);
	string fileString, line, avgLine;
	vector<int> v1, v2, v3;
	while (getline(in, line)) {
		// find each state line and prepare to parse them
		if (line.find("S [") != -1) {
			parseState(line, v1, v2, v3);
		}
		// find mean value line and prepare to parse
		else if (line.find("avg [") != -1) {
			avgLine = line;
		}
	}
	in.close();

	string avg = avgLine.substr(5, line.length() - 1 - 5);
	vector<double> avgVec;
	double d;
	stringstream ss(avg);
	while (ss >> d) {
		avgVec.push_back(d);
		if (ss.peek() == ',')
			ss.ignore(); // skip commas
	}

	// prepare to print the result to a file
	ofstream out;
	out.open("question_b.out");
	if (!out) {
		cerr << "could not open file: " << "question_b.out" << endl;
		exit(1);
	}
	out << "Mean: [" << avgVec[0] << ", " << avgVec[1] << ", " << avgVec[2] << "]" << endl;
	double Var1 = computeVar(v1, avgVec[0]);
	double Var2 = computeVar(v2, avgVec[1]);
	double Var3 = computeVar(v3, avgVec[2]);
	out << "Variance: [" << Var1 << ", " << Var2 << ", " << Var3 << "]" << endl;
	out.close();
	return 0;
}

// parse state line and put each kind of molecules into respective vectors 
void parseState(string line, vector<int> &v1, 
	vector<int> &v2, vector<int> &v3) {
	string stateLine = line.substr(5, line.length() - 1 - 5);
	int i, ct = 0;
	stringstream ss(stateLine);
	while (ss >> i) {
		ct++;
		switch (ct) {
			case 1:
				v1.push_back(i);
				break;
			case 2:
				v2.push_back(i);
				break;
			case 3:
				v3.push_back(i);
				break;
		}
		if (ss.peek() == ',')
			ss.ignore(); // skip commas
	}
}

double computeVar(vector<int> v, double mean) {
	double sqSum = 0;
	for (int i = 0; i < v.size(); i++) {
		sqSum += (v[i] - mean) * (v[i] - mean);
	}
	double var = sqSum / v.size();
	return var;
}