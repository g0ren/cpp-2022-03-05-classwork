#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "children.hpp"

using namespace std;

subject* appendToArray(subject *ar, int size, subject *add) {
	subject *r = new subject[size + 1];
	for (int i = 0; i < size; i++)
		r[i] = ar[i];
	r[size] = *add;
	return r;
}

template<typename T>
T* removeLastFromArray(T *ar, int size) {
	T *r = new T[size - 1];
	for (int i = 0; i < size - 1; i++)
		r[i] = ar[i];
	return r;
}

children* initData() {
	int *e = new int[10] { 12, 12, 12, 12, 12, 12, 12, 12, 12, 10 };
	int *e1 = new int[10] { 11, 11, 5, 1, 1, 8, 8, 9, 4, 10 };
	int *e2 = new int[10] { 10, 10, 10, 12, 12, 12, 9, 9, 9, 10 };
	subject *s = new subject[3] { { "Language", e, 10 },
			{ "Mathematics", e1, 10 }, { "Job", e2, 10 } };

	children *n_c = new children[6] { { "Elena", "female", 140, 14, s, 3 }, {
			"Anton", "male", 150, 12, nullptr, 0 }, { "Anna", "female", 160, 16,
			nullptr, 0 }, { "Marina", "female", 120, 11, nullptr, 0 }, { "Dima",
			"male", 130, 10, nullptr, 0 }, { "Janna", "female", 150, 17,
			nullptr, 0 } };
	return n_c;
}

void printMenu() {
	cout << "|---------------------------------------|\n";
	cout << "|1. Enter new data for children.        |\n";
	cout << "|---------------------------------------|\n";
	cout << "|2. Delete children of number.          |\n";
	cout << "|---------------------------------------|\n";
	cout << "|3. Edit data for children.             |\n";
	cout << "|---------------------------------------|\n";
	cout << "|4. Print average height.               |\n";
	cout << "|---------------------------------------|\n";
	cout << "|5. Print average age.                  |\n";
	cout << "|---------------------------------------|\n";
	cout << "|6. Print all childrens.                |\n";
	cout << "|---------------------------------------|\n";
	cout << "|7. Print children of number.           |\n";
	cout << "|---------------------------------------|\n";
	cout << "|8. Print male only.                    |\n";
	cout << "|---------------------------------------|\n";
	cout << "|9. Print female only.                  |\n";
	cout << "|---------------------------------------|\n";
	cout << "|0. Exit.                               |\n";
	cout << "|---------------------------------------|\n";
}

double getAverageHeight(children *c, int s) {
	double res = 0;
	for (int i = 0; i < s; i++)
		res += c[i].height;
	return res / s;
}

double getAverageAge(children *c, int s) {
	double res = 0;
	for (int i = 0; i < s; i++)
		res += c[i].age;
	return res / s;
}

void printEditMenu() {
	cout << "|--------------------|\n";
	cout << "|1. Edit name.       |\n";
	cout << "|--------------------|\n";
	cout << "|2. Edit age.        |\n";
	cout << "|--------------------|\n";
	cout << "|3. Edit height.     |\n";
	cout << "|--------------------|\n";
	cout << "|4. Edit subject.    |\n";
	cout << "|--------------------|\n";
	cout << "|0. Exit.            |\n";
	cout << "|--------------------|\n";
}
void printSubjects(subject *s, int size) {
	for (int i = 0; i < size; i++) {
		cout << "\t\t " << s[i].name << "  :";
		for (int j = 0; j < s[i].es_size; j++) {
			cout << s[i].estims[j] << " ";
		}
		cout << endl;
	}

}
void printChildren(children c) {
	cout << "Name: " << c.name << ".\t Gen is " << c.gen << ".\t Height is "
			<< c.height << ".\t Age is " << c.age;
	cout << endl;
	printSubjects(c.subjs, c.subj_size);
}

void editChildren(children *c) {
	int choice;
	while (true) {
		printChildren(*c);
		cout << endl;
		printEditMenu();
		cout << "Enter your choice:";
		cin >> choice;
		cin.clear();
		cin.ignore(32767, '\n');
		switch (choice) {
		case 1:
			cout << " Old name is " << c->name << ". Enter new name:";
			cin.getline(c->name, name_size);
			break;
		case 2:
			cout << " Old age is " << c->age << ". Enter new age:";
			cin >> c->age;
			break;
		case 3:
			cout << " Old height is " << c->height << ". Enter new height:";
			cin >> c->height;
			break;
		case 4:
			subject *s = new subject { };
			cout << "Enter new subject name: ";
			cin >> s->name;
			c->subjs = appendToArray(c->subjs, c->subj_size, s);
			c->subj_size++;
			break;
		}
		//system("cls");
		if (choice == 0)
			break;
	}
}

void printChildrens(children *c, int size) {
	for (int i = 0; i < size; i++) {
		cout << (i + 1) << ". ";
		printChildren(c[i]);
		cout << endl;
	}
}

void printChildrens(children *c, int size, char gen[]) {
	for (int i = 0, co = 0; i < size; i++) {
		if (strcmp(c[i].gen, gen) == 0) {
			cout << (co + 1) << ". ";
			printChildren(c[i]);
			cout << endl;
			co++;
		}
	}
}

children* deleteChildren(children *c, int size, int ind) {
	children *n_c = new children[size - 1];
	for (int i = 0, n = 0; i < size; i++) {
		if (i != ind) {
			n_c[n] = c[i];
			n++;
		}
	}
	delete[] c;
	return n_c;
}

children createChildren() {
	children c;
	cout << "Enter name:";
	cin.getline(c.name, name_size);
	cout << "Enter gender:";
	cin.getline(c.gen, gen_size);
	cout << "Enter height:";
	cin >> c.height;
	cout << "Enter age:";
	cin >> c.age;
	return c;
}

children* addChildren(children *c, int size) {
	children *n_c = new children[size + 1];
	for (int i = 0; i < size; i++)
		n_c[i] = c[i];
	n_c[size] = createChildren();
	delete[] c;
	return n_c;
}

int getIndex(int size) {
	cout << "Enter index: ";
	int ind;
	cin >> ind;
	cin.clear();
	cin.ignore(32767, '\n');
	if (ind > 0 && ind < size + 1)
		return ind - 1;
	else
		return -1;
}

int main() {
	int choice, ind;
	children *childrens = nullptr;
	int c_size = 0;

	childrens = initData();
	c_size = 6;

	while (true) {
		cout << "Current number of children is " << c_size << endl;
		printMenu();
		cout << "Enter your choice:";
		cin >> choice;
		cin.clear();
		cin.ignore(32767, '\n');
		switch (choice) {
		case 1:
			childrens = addChildren(childrens, c_size);
			c_size++;
			break;
		case 2:
			ind = getIndex(c_size);
			if (ind >= 0) {
				childrens = deleteChildren(childrens, c_size, ind);
				c_size--;
			} else
				cout << "Wrong number\n";
			break;
		case 3:
			ind = getIndex(c_size);
			if (ind >= 0)
				editChildren(childrens + ind);
			else
				cout << "Wrong number\n";
			break;
		case 4:
			cout << "Average height is " << getAverageHeight(childrens, c_size)
					<< endl;
			break;
		case 5:
			cout << "Average age is " << getAverageAge(childrens, c_size)
					<< endl;
			break;
		case 6:
			printChildrens(childrens, c_size);
			break;
		case 7:
			ind = getIndex(c_size);
			if (ind >= 0)
				printChildren(childrens[ind]);
			else
				cout << "Wrong number\n";
			break;
		case 8:
			printChildrens(childrens, c_size, (char*) "male");
			break;
		case 9:
			printChildrens(childrens, c_size, (char*) "female");
			break;

		}

		//system("pause");
		//system("cls");

		if (choice == 0)
			break;

	}
	return 0;
}
