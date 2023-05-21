#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct info {
	string lname;
	string fname;
	string mname;
	int age;
	string gender;
};
													//table of contents
void start();										//line 36
void home();										//line 63
void add();											//line 96
void savedata(list <info>);							//line 121
void view();										//line 151
void search();										//line 205
void stringsearch(int, string);						//line 262
void edit(int, string, string);						//line 327
void deleto(int, string, string);					//line 382
void savedatav2(list <info>);						//line 417
void sort();										//line 447
void stringsort(int, string);						//line 504
bool comparelname(const info&, const info&);		//line 545
bool comparefname(const info&, const info&);		//line 548
bool comparemname(const info&, const info&);		//line 551
bool compareage(const info&, const info&);			//line 554
bool comparegender(const info&, const info&);		//line 557

int main() {
	start();

	return 0;
}

void start() {
	char choice;

	cout << "\n-------------------------------------------------------------------------"
		 << "\nSTUDENT PROFILE INFORMATION SYSTEM"
		 << "\n[a] Start"
		 << "\n[b] End"
		 << "\nEnter your Choice: ";
	cin >> choice;
	system("cls");

	switch (choice) {
	case 'a': {
		cout << "\nLoad is Success, Match";
		home();
		break;
	}
	case 'b': {
		break;
	}
	default: {
		cout << "\nChoice is None, Mismatch";
		start();
	}
	}
}

void home() {
	char choice;

	cout << "\n-------------------------------------------------------------------------"
		 << "\nSTUDENT PROFILE INFORMATION SYSTEM -> Home"
		 << "\n[a] Add"
		 << "\n[b] View"
		 << "\n[c] End"
		 << "\nEnter your Choice: ";
	cin >> choice;
	system("cls");

	switch (choice) {
	case 'a': {
		cout << "\nLoad is Success, Match";
		add();
		break;
	}
	case 'b': {
		cout << "\nLoad is Success, Match";
		view();
		break;
	}
	case 'c': {
		break;
	}
	default: {
		cout << "\nChoice is None, Mismatch";
		home();
	}
	}
}

void add() {
	list <info> adding;
	string name[4];
	int age;

	cout << "\n-------------------------------------------------------------------------"
		<< "\nSTUDENT PROFILE INFORMATION SYSTEM -> Add"
		<< "\nLast Name: ";
	cin >> name[0];
	cout << "\nFirst Name: ";
	cin >> name[1];
	cout << "\nMiddle Initial: ";
	cin >> name[2];
	cout << "\nAge: ";
	cin >> age;
	cout << "\nGender: ";
	cin >> name[3];

	adding.push_back({ name[0], name[1], name[2], age, name[3]});
	savedata(adding);

	system("cls");
	cout << "\nAdd is Success, Match";
	home();
}
void savedata(list <info> adding) {
	fstream file;

	file.open("lname.txt", ios::app);
	for (auto word : adding) {
		file << "\n" << word.lname;
	}
	file.close();
	file.open("fname.txt", ios::app);
	for (auto word : adding) {
		file << "\n" << word.fname;
	}
	file.close();
	file.open("mname.txt", ios::app);
	for (auto word : adding) {
		file << "\n" << word.mname;
	}
	file.close();
	file.open("age.txt", ios::app);
	for (auto word : adding) {
		file << "\n" << word.age;
	}
	file.close();
	file.open("gender.txt", ios::app);
	for (auto word : adding) {
		file << "\n" << word.gender;
	}
	file.close();
}

void view() {
	string line[5];
	fstream file[5];
	char choice;

	cout << "\nLast Name" << setw(13) << "First Name" << setw(9) << "M.I." << setw(7) << "Age" << setw(11) << "Gender\n";

	file[0].open("lname.txt");
	file[1].open("fname.txt");
	file[2].open("mname.txt");
	file[3].open("age.txt");
	file[4].open("gender.txt");
	while (getline(file[0], line[0]) && getline(file[1], line[1]) && getline(file[2], line[2]) && getline(file[3], line[3]) && getline(file[4], line[4])) {
		cout << setw(9) << line[0] << setw(13) << line[1] << setw(9) << line[2] << setw(7) << line[3] << setw(10) << line[4] << "\n";
	}
	for (int h = 0; h < 5; h++) {
		file[h].close();
	}

	cout << "\n-------------------------------------------------------------------------"
		 << "\nSTUDENT PROFILE INFORMATION SYSTEM -> View"
		 << "\n[a] Search"
		 << "\n[b] Sort"
		 << "\n[c] Home"
		 << "\n[d] End"
		 << "\nEnter your Choice: ";
	cin >> choice;
	system("cls");

	switch (choice) {
	case 'a': {
		cout << "\nLoad is Success, Match";
		search();
		break;
	}
	case 'b': {
		cout << "\nLoad is Success, Match";
		break;
	}
	case 'c': {
		cout << "\nLoad is Success, Match";
		home();
		break;
	}
	case 'd': {
		break;
	}
	default: {
		cout << "\nChoice is None, Mismatch";
		view();
	}
	}
}

void search() {
	char choice;

	cout << "\n------------------------------------------------------------------------"
		 << "\nSTUDENT PROFILE INFORMATION SYSTEM -> Search"
		 << "\n[a] Last Name"
		 << "\n[b] First Name"
		 << "\n[c] Middle Initial"
		 << "\n[d] Age"
		 << "\n[e] Gender"
		 << "\n[f] Home"
	 	 << "\n[g] End"
		 << "\nEnter your Choice: ";
	cin >> choice;
	system("cls");

	switch (choice) {
	case 'a': {
		cout << "\nLoad is Success, Match";
		stringsearch(0, "Last Name");
		break;
	}
	case 'b': {
		cout << "\nLoad is Success, Match";
		stringsearch(1, "First Name");
		break;
	}
	case 'c': {
		cout << "\nLoad is Success, Match";
		stringsearch(2, "Middle Initial");
		break;
	}
	case 'd': {
		cout << "\nLoad is Success, Match";
		stringsearch(3, "Age");
		break;
	}
	case 'e': {
		cout << "\nLoad is Success, Match";
		stringsearch(4, "Gender");
		break;
	}
	case 'f': {
		cout << "\nLoad is Success, Match";
		home();
		break;
	}
	case 'g': {
		break;
	}
	default: {
		cout << "\nChoice is None, Mismatch";
		search();
	}
	}
}

void stringsearch(int h, string word) {
	string search;
	fstream file[5];
	string line[5];
	char choice;

	cout << "\n-------------------------------------------------------------------------"
		 << "\nSTUDENT PROFILE INFORMATION SYSTEM -> Search -> " << word
		 << "\nSearch: ";
	cin >> search;
	system("cls");

	cout << "\nSearch is Success, Match"
		 << "\nLast Name" << setw(13) << "First Name" << setw(9) << "M.I." << setw(7) << "Age" << setw(11) << "Gender\n";
	file[0].open("lname.txt");
	file[1].open("fname.txt");
	file[2].open("mname.txt");
	file[3].open("age.txt");
	file[4].open("gender.txt");
	while (getline(file[0], line[0]) && getline(file[1], line[1]) && getline(file[2], line[2]) && getline(file[3], line[3]) && getline(file[4], line[4])) {
		if (line[h] == search) {
			cout << setw(9) << line[0] << setw(13) << line[1] << setw(9) << line[2] << setw(7) << line[3] << setw(10) << line[4] << "\n";
		}
	}
	for (int i = 0; i < 5; i++) {
		file[i].close();
	}

	cout << "\n-------------------------------------------------------------------------"
		 << "\nSTUDENT PROFILE INFORMATION SYSTEM -> Search -> " << word
		 << "\nSearch: " << search
		 << "\n[a] Edit"
		 << "\n[b] Delete"
		 << "\n[c] Home"
		 << "\n[d] End"
		 << "\nEnter your Choice: ";
	cin >> choice;
	system("cls");

	switch (choice) {
	case 'a': {
		cout << "\nLoad is Success, Match";
		edit(h, word, search);
		break;
	}
	case 'b': {
		cout << "\nLoad is Success, Match";
		deleto(h, word, search);
		break;
	}
	case 'c': {
		cout << "\nLoad is Success, Match";
		home();
		break;
	}
	case 'd': {
		break;
	}
	default: {
		cout << "\nChoice is None, Mismatch";
		stringsearch(h, word);
	}
	}
}

void edit(int h, string word, string search) {
	fstream file[5];
	string line[5];
	string edit;
	list <info> editing;

	cout << "\n-------------------------------------------------------------------------"
		 << "\nSTUDENT PROFILE INFORMATION SYSTEM -> Search -> " << word << "-> Edit"
		 << "\nEdit: ";
	cin >> edit;
	system("cls");

	file[0].open("lname.txt");
	file[1].open("fname.txt");
	file[2].open("mname.txt");
	file[3].open("age.txt");
	file[4].open("gender.txt");
	while (getline(file[0], line[0]) && getline(file[1], line[1]) && getline(file[2], line[2]) && getline(file[3], line[3]) && getline(file[4], line[4])) {
		int age = stoi(line[3]);

		if (line[h] == search) {
			line[h] = edit;

			if (word == "Last Name") {
				editing.push_back({ line[h], line[1], line[2], age, line[4] });
			}
			else if (word == "First Name") {
				editing.push_back({ line[0], line[h], line[2], age, line[4] });
			}
			else if (word == "Middle Name") {
				editing.push_back({ line[0], line[1], line[h], age, line[4] });
			}
			else if (word == "Age") {
				int age = stoi(line[h]);
				editing.push_back({ line[0], line[1], line[2], age, line[4] });
			}
			else if (word == "Gender") {
				editing.push_back({ line[0], line[1], line[2], age, line[h] });
			}
		}
		else {
			editing.push_back({ line[0], line[1], line[2], age, line[4] });
		}
	}
	for (int i = 0; i < 5; i++) {
		file[i].close();
	}

	savedatav2(editing);

	system("cls");
	cout << "\nEdit is Success, Match";
	home();
}

void deleto(int h, string word, string search) {
	fstream file[5];
	string line[5];
	string edit;
	list <info> editing;

	cout << "\n-------------------------------------------------------------------------"
		<< "\nSTUDENT PROFILE INFORMATION SYSTEM -> Search -> " << word << "-> Delete"
		<< "\nDelete: ";
	cin >> edit;
	system("cls");

	file[0].open("lname.txt");
	file[1].open("fname.txt");
	file[2].open("mname.txt");
	file[3].open("age.txt");
	file[4].open("gender.txt");
	while (getline(file[0], line[0]) && getline(file[1], line[1]) && getline(file[2], line[2]) && getline(file[3], line[3]) && getline(file[4], line[4])) {
		int age = stoi(line[3]);

		if (line[h] != search) {
			editing.push_back({ line[0], line[1], line[2], age, line[4] });
		}
	}
	for (int i = 0; i < 5; i++) {
		file[i].close();
	}

	savedatav2(editing);

	system("cls");
	cout << "\nDelete is Success, Match";
	home();
}

void savedatav2(list <info> adding) {
	fstream file;

	file.open("lname.txt");
	for (auto word : adding) {
		file << "\n" << word.lname;
	}
	file.close();
	file.open("fname.txt");
	for (auto word : adding) {
		file << "\n" << word.fname;
	}
	file.close();
	file.open("mname.txt");
	for (auto word : adding) {
		file << "\n" << word.mname;
	}
	file.close();
	file.open("age.txt");
	for (auto word : adding) {
		file << "\n" << word.age;
	}
	file.close();
	file.open("gender.txt");
	for (auto word : adding) {
		file << "\n" << word.gender;
	}
	file.close();
}

void sort() {
	char choice;

	cout << "\n------------------------------------------------------------------------"
		<< "\nSTUDENT PROFILE INFORMATION SYSTEM -> Sort"
		<< "\n[a] Last Name"
		<< "\n[b] First Name"
		<< "\n[c] Middle Initial"
		<< "\n[d] Age"
		<< "\n[e] Gender"
		<< "\n[f] Home"
		<< "\n[g] End"
		<< "\nEnter your Choice: ";
	cin >> choice;
	system("cls");

	switch (choice) {
	case 'a': {
		cout << "\nLoad is Success, Match";
		stringsort(0, "Last Name");
		break;
	}
	case 'b': {
		cout << "\nLoad is Success, Match";
		stringsort(1, "First Name");
		break;
	}
	case 'c': {
		cout << "\nLoad is Success, Match";
		stringsort(2, "Middle Initial");
		break;
	}
	case 'd': {
		cout << "\nLoad is Success, Match";
		stringsort(3, "Age");
		break;
	}
	case 'e': {
		cout << "\nLoad is Success, Match";
		stringsort(4, "Gender");
		break;
	}
	case 'f': {
		cout << "\nLoad is Success, Match";
		home();
		break;
	}
	case 'g': {
		break;
	}
	default: {
		cout << "\nChoice is None, Mismatch";
		sort();
	}
	}
}

void stringsort(int h, string word) {
	fstream file[5];
	string line[5];
	list <info> sorting;

	file[0].open("lname.txt");
	file[1].open("fname.txt");
	file[2].open("mname.txt");
	file[3].open("age.txt");
	file[4].open("gender.txt");
	while (getline(file[0], line[0]) && getline(file[1], line[1]) && getline(file[2], line[2]) && getline(file[3], line[3]) && getline(file[4], line[4])) {
		int age = stoi(line[3]);
		sorting.push_back({ line[0], line[1], line[2], age, line[4] });
	}
	for (int i = 0; i < 5; i++) {
		file[i].close();
	}

	if (word == "Last Name") {
		sort(sorting.begin(), sorting.end(), comparelname);
	}
	else if (word == "First Name") {
		sort(sorting.begin(), sorting.end(), comparefname);
	}
	else if (word == "Middle Name") {
		sort(sorting.begin(), sorting.end(), comparemname);
	}
	else if (word == "Age") {
		sort(sorting.begin(), sorting.end(), compareage);
	}
	else if (word == "Gender") {
		sort(sorting.begin(), sorting.end(), comparegender);
	}

	system("cls");

	cout << "\nSort is Success, Match";
}

bool comparelname(const info& a, const info& b) {
	return a.lname < b.lname;
}
bool comparefname(const info& a, const info& b) {
	return a.fname < b.fname;
}
bool comparemname(const info& a, const info& b) {
	return a.mname < b.mname;
}
bool compareage(const info& a, const info& b) {
	return a.age < b.age;
}
bool comparegender(const info& a, const info& b) {
	return a.gender < b.gender;
}