#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<string>
#include<fstream>
#include <sstream>
#include <ctype.h>
#include <string.h>
#include <algorithm>
using namespace std;


struct patient{

	string Name;
	string Age;
	string Gender;
	string Race;
	string IC;
	string Date;
	string Sickness;
	string Native;
	string Fees;
	string doctor;

}pat[50];

//patient pat[50];

int f_all = 30;


void List(){

	//cout << "Name	Age	   Gender		Race		IC/MYkid/Passport	Date		Sickness		Native			Fees(RM)	Doctor" << endl;
	for (int j = 0; j <= f_all; j++){
	cout << pat[j].Name << " " << pat[j].Age << " " << pat[j].Gender << " " << pat[j].Race << " " << pat[j].IC << " " << pat[j].Date << " " << pat[j].Sickness << " " << pat[j].Native << " " << pat[j].Fees << " " << pat[j].doctor << endl;
	}
}

string make_upper_case(string& s)
{
	string g = s;
	for (unsigned int i = 0; i<g.size(); i++)
	{
		if (g[i] >= 'a' && g[i] <= 'z')
			g[i] -= ('a' - 'A');
	}
	return g;
}

void Search_by_date(string date){
	int count = 0;
	int revenue = 0;
	for (int k = 0; k < f_all; k++){

		if (pat[k].Date == date){
			cout << pat[k].Name << " " << pat[k].Age << " " << pat[k].Gender << " " << pat[k].Race << " " << pat[k].IC << " " << pat[k].IC << " " << pat[k].Date << " " << pat[k].Sickness << " " << pat[k].Native << " " << pat[k].Fees << " " << pat[k].doctor << endl;
			
			int value = atoi(pat[k].Fees.c_str());
			revenue += value;
			

			count++;
		}

	}
	cout << "--------------------------------------------------------------" << endl;
	cout << "----------------Total-Revenue----------------" << endl;
	cout << "               " << revenue << endl;
	if (count == 0){

		cout << "\nNo such record found" << endl;
	}
}

void Search_by_keyword(string key){
	int count = 0;

	string keyword = make_upper_case(key);

	for (int k = 0; k < f_all; k++){

		string a = make_upper_case(pat[k].Name);
		string b = make_upper_case(pat[k].doctor);
		string c = make_upper_case(pat[k].Gender);
		string d = make_upper_case(pat[k].Native);
		string e = make_upper_case(pat[k].Race);
		string f = make_upper_case(pat[k].Sickness);
	
		

		if (a.find(keyword) != std::string::npos || b.find(keyword) != std::string::npos || c.find(keyword) != std::string::npos || d.find(keyword) != std::string::npos || e.find(keyword) != std::string::npos || f.find(keyword) != std::string::npos){
			cout << pat[k].Name << " " << pat[k].Age << " " << pat[k].Gender << " " << pat[k].Race << " " << pat[k].IC << " " << pat[k].IC << " " << pat[k].Date << " " << pat[k].Sickness << " " << pat[k].Native << " " << pat[k].Fees << " " << pat[k].doctor << endl;
			count++;
		}

	}

	if (count == 0){

		cout << "\nNo such record found" << endl;
	}

}

void Search_by__two_keyword(string ke,string kr){
	int count = 0;
	for (int k = 0; k < f_all; k++){

		string a = make_upper_case(pat[k].Name);
		string b = make_upper_case(pat[k].doctor);
		string c = make_upper_case(pat[k].Gender);
		string d = make_upper_case(pat[k].Native);
		string e = make_upper_case(pat[k].Race);
		string f = make_upper_case(pat[k].Sickness);
		string g = make_upper_case(pat[k].Age);
		string h = make_upper_case(pat[k].Fees);
		string i = make_upper_case(pat[k].IC);

		string keyword = make_upper_case(ke);
		string key = make_upper_case(kr);



		if ((a.find(keyword) != std::string::npos || b.find(keyword) != std::string::npos || c.find(keyword) != std::string::npos || d.find(keyword) != std::string::npos || e.find(keyword) != std::string::npos || f.find(keyword) != std::string::npos || g.find(keyword) != std::string::npos || h.find(keyword) != std::string::npos || i.find(keyword) != std::string::npos) && (a.find(key) != std::string::npos || b.find(key) != std::string::npos || c.find(key) != std::string::npos || d.find(key) != std::string::npos || e.find(key) != std::string::npos || f.find(key) != std::string::npos || g.find(key) != std::string::npos || h.find(key) != std::string::npos || i.find(key) != std::string::npos)){
			cout << pat[k].Name << " " << pat[k].Age << " " << pat[k].Gender << " " << pat[k].Race << " " << pat[k].IC << " " << pat[k].IC << " " << pat[k].Date << " " << pat[k].Sickness << " " << pat[k].Native << " " << pat[k].Fees << " " << pat[k].doctor << endl;
			count++;
		}

	}

	if (count == 0){

		cout << "\nNo such record found" << endl;
	}

}

void Search_by_Gender(string gender){
	int count = 0;
	for (int k = 0; k < f_all; k++){
	
		if (pat[k].Gender== gender){
			cout << pat[k].Name << " " << pat[k].Age << " " << pat[k].Gender << " " << pat[k].Race << " " << pat[k].IC << " " << pat[k].IC << " " << pat[k].Date << " " << pat[k].Sickness << " " << pat[k].Native << " " << pat[k].Fees << " " << pat[k].doctor << endl;
			count++;
		}

	}

	if (count == 0){

		cout << "\nNo such record found" << endl;
	}
}

void update(string date,string ic){

	int count = 0;
	string d, c;
	int r = -1;
	for (int k = 0; k < f_all; k++){

		if (pat[k].Date==date&&pat[k].IC==ic){
			
			r = k;
			count++;
			
		}
		

	}
	while (r != -1){
		cout << "\nEnter new Date : ";
		cin >> d;
		pat[r].Date = d;
		cout << "\nEnter new IC : ";
		cin >> c;
		pat[r].IC = c;
		r = -1;
	}

	if (count == 0){

		cout << "\nNo such record found" << endl;
	}

}

void add(){

	string N;
	string A;
	string G;
	string R;
	string I;
	string D;
	string S;
	string n;
	string F;
	string d;

	cout << "\nEnter Name : ";
	cin >> N;
	cout << "\nEnter Age: ";
	cin >> A;
	cout << "\nEnter Gender : ";
	cin >> G;
	cout << "\nEnter Race : ";
	cin >> R;
	cout << "\nEnter IC: ";
	cin >> I;
	cout << "\nEnter Date : ";
	cin >> D;

	cout << "\nEnter Sickness: ";
	cin >> S;
	cout << "\nEnter Native : ";
	cin >> n;
	cout << "\nEnter Fees : ";
	cin >> F;
	cout << "\nEnter Doctor : ";
	cin >> d;
	
	f_all = f_all + 1;

	pat[f_all].Name = N;
	pat[f_all].Age =A;
	pat[f_all].Gender = G;
	pat[f_all].Race = R;
	pat[f_all].IC = I;
	pat[f_all].Date = D;
	pat[f_all].Sickness = S;
	pat[f_all].Native = n;
	pat[f_all].Fees = F;
	pat[f_all].doctor = d;
}

void safe(){
	
	ofstream fout("Patient-List.txt", ios::binary);

	for (int j = 0; j < f_all; j++){

		fout << pat[j].Name << " " << pat[j].Age << " " << pat[j].Gender << " " << pat[j].Race << " " << pat[j].IC << " " << pat[j].Date << " " << pat[j].Sickness << " " << pat[j].Native << " " << pat[j].Fees << " " << pat[j].doctor<<" "<<endl;
		

	}
	
	fout.close();
	
}


int main(){

	ifstream inFile;
	ofstream outFile;

	ifstream fin;
	string p;
	fin.open("Patient-List.txt");
	int i = 0;
	while ( i < f_all) {
		getline(fin, p);
		if (p == "") {
			break;
		}
		istringstream iss(p);
		int co = 0;
		while (iss) {
			string word;
			iss >> word;
			if (co == 0){
				pat[i].Name = word;
							}
			if (co == 1){
				pat[i].Age = word;
			}
			if (co == 2){
				pat[i].Gender = word;
				
			}
			if (co == 3){
				pat[i].Race = word;
			}
			if (co == 4){
				pat[i].IC = word;
			}
			if (co == 5){
				pat[i].Date = word;
				
			}
			if (co == 6){
				pat[i].Sickness = word;
				
			}
			if (co == 7){
				pat[i].Native = word;
				
			}
			if (co == 8){
				pat[i].Fees = word;
				
			}
			if (co == 9){
				pat[i].doctor = word;
			}
			
			co++;
		}


		i++;
	}
	fin.close();
	
	int chk = 1;
	while (chk != -10){

		cout << "\n1: Display List\n2: Search By date\n3: Search By Keyword\n4: Search By 2-Keywords\n5: Search By Gender\n6: Update\n7: Add\n8: Exit \n";
		cin >> chk;
		string da;
		//string ke;
		string l,z,x;
		string r, s, ke;
		
		
		switch (chk)
		{
		case 1:
			List();
			break;
		case 2:
			
			cout << "enter date to be searched : ";
			cin >> da;
			Search_by_date(da);
			break;
		case 3:
			
			cout << "enter keyword to be searched : ";
			cin >> ke;
			Search_by_keyword(ke);
			break;
		case 4:
            cout << "enter ist keyword to be searched : ";
			cin >> r;
			cout << "enter 2nd keyword to be searched : ";
			cin >> s;
			Search_by__two_keyword(r, s);
			break;
		case 5:
			
			cout << "Enter Gender to be searced : ";
			cin >> l;
			Search_by_Gender(l);
			break;
		case 6:
			
			cout << "enter date to  update : ";
			cin >> z;

			cout << "enter IC to  update : ";
			cin >> x;
			update(z, x);
			break;
		case 7:
			add();
			break;
		case 8:

			safe();
			chk = -10;
			break;


		default:
			break;
		}
	}



}