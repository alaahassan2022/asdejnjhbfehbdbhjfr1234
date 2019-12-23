#include <iostream>
#include<string>
#include <fstream>
#include<vector>
#include "BigInteger.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
	ofstream outtest;
	ifstream intest;
	ifstream incompare;
	ofstream outcompare;

	incompare.open("SampleRSA.txt", ios::in);

	outcompare.open("SampleCompareOrig.txt", ios::app);
	vector<string> orig;
	string sorig;
	int count = 0;
	int iii = 0;
	while (getline(incompare, sorig)){
		count++;
		if (sorig != "" && count%4==0){
			orig.push_back(sorig);
		}
	}
	for (int i = 0; i < orig.size() ; i++)
	{
		if (i % 2 != 0){
			outcompare << orig[i - 1] << endl;
		}
		else{

			outcompare << orig[i + 1] << endl;
		}

	}
	incompare.close();
	outcompare.close();
	orig.clear();
	incompare.open("TestRSA.txt", ios::in);

	outcompare.open("CompleteCompareOrig.txt", ios::app);
	count = 0;
	 iii = 0;
	while (getline(incompare, sorig)){
		count++;
		if (sorig != "" && count % 4 == 0){
			orig.push_back(sorig);
		}
	}
	for (int i = 0; i < orig.size(); i++)
	{
		if (i % 2 != 0){
			outcompare << orig[i-1] << endl;
		}
		else{

			outcompare << orig[i + 1] << endl;
		}
		
	}
	incompare.close();
	outcompare.close();
	orig.clear();
	BigInteger s;

	outtest.open("SampleMytest.txt",ios::app);
	intest.open("SampleRSA.txt", ios::in);

	vector<string> file;
	string temp;
	while (getline(intest, temp)){
		if (temp != ""){
			file.push_back(temp);
		}
	}
	temp.clear();
	intest.close();

	int index = 1;
	for (int i = 0; i < stoi(file[0]); i++)
	{
		if (stoi(file[index + 3]) == 0){
			outtest << s.Encrypt(file[index], file[index + 1], file[index + 2]) << endl;
			index += 4;
		}
		else if (stoi(file[index + 3]) == 1){
			outtest << s.Decrypt(file[index], file[index + 1], file[index + 2]) << endl;
			index += 4;
		}
	}

	outtest.close();
	file.clear();

	outtest.open("CompleteMytest.txt", ios::app);
	intest.open("TestRSA.txt", ios::in);

	while (getline(intest, temp)){
		if (temp != ""){
			file.push_back(temp);
		}
	}

	intest.close();

	index = 1;
	

	for (int i = 0; i < stoi(file[0]); i++)
	{
		if (stoi(file[index + 3]) == 0){
			auto start = high_resolution_clock::now();

			outtest << s.Encrypt(file[index], file[index + 1], file[index + 2]) << endl;

			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<seconds>(stop - start);
			cout << "Complete Test Case " << i + 1  << " takes :"<<endl;
			cout << duration.count() << " Seconds" << endl <<endl;
			index += 4;
		}
		else if (stoi(file[index + 3]) == 1){
			auto start = high_resolution_clock::now();

			outtest << s.Decrypt(file[index], file[index + 1], file[index + 2]) << endl;

			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<seconds>(stop - start);
			cout << "Complete Test Case " << i + 1 << " takes :" << endl;
			cout << duration.count() << " Seconds" << endl <<endl;
			index += 4;
		}
	}
	outtest.close();
	file.clear();
	return 0;
}