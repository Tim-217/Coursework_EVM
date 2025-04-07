#include "command.h"
#include <iostream>
using namespace std;

Command::Command() {
	this->type = 0;
	this->o1 = 0;
	this->o2 = 0;
	this->calc = 0;
}

void Command::print() {
	for (int i = 0; i < this->size; i++) {
		if (code[i] == 0)
			cout << "D" << "  ";			
		else if (code[i] == 1)
			cout << "R1" << " ";
		else if (code[i] == 2)
			cout << "M1" << " ";
		else if (code[i] == 3)
			cout << "C" << "  ";
		else if (code[i] == 4)
			cout << " " << " ";
		else if (code[i] == 5)
			cout << "_" << "  ";
		else if (code[i] == 6)
			cout << "K" << "  ";
		else if (code[i] == 7)
			cout << "R2" << " ";
		else if (code[i] == 8)
			cout << "M2" << " ";
	}
	cout << endl;
}

Command Command::generate(float P1_1, float P1_2, float P2, int N, int M) {
	Command com;
	if ((rand() % 100) < (P1_1 * 100)) com.o1 = 1;
	else com.o1 = N;
	if ((rand() % 100) < (P1_2 * 100)) com.o2 = 1;
	else com.o2 = N;
	if ((rand() % 100) < (P2 * 100)) {
		com.type = 1;
		com.calc = 1;
	}
	else {
		com.type = 2;
		com.calc = M;
	}
	return com;
}

int Command::get_time() {
	int time = 0;
	for (int i = 0; i < this->size; i++) {
		if (this->code[i] != 4)
			time++;
	}
	return time;
}

void Command::set_code(int N) {
	this->size = N + 1 + this->o1 + this->o2 + this->calc + this->o2;
	vector <int>::iterator it;
	it = this->code.begin();
	int i = 0;
	while (i < N) {
		this->code.insert(it, 6);
		i++;
		it = this->code.begin() + i;
	}

	this->code.insert(it, 0);
	i++;
	it = this->code.begin() + i;

	if (this->o1 == 1) {
		this->code.insert(it, 1);
		i++;
		it = this->code.begin() + i;
	}
	else {
		int i1 = i;
		while (i < this->o1 + i1) {
			this->code.insert(it, 2);
			i++;
			it = this->code.begin() + i;
		}
	}

	if (this->o2 == 1) {
		this->code.insert(it, 7);
		i++;
		it = this->code.begin() + i;
	}
	else {
		int i2 = i;
		while (i < this->o2 + i2) {
			this->code.insert(it, 8);
			i++;
			it = this->code.begin() + i;
		}
	}

	int ic = 0;
	while (ic < this->calc) {
		this->code.insert(it, 3);
		i++;
		it = this->code.begin() + i;
		ic++;
	}

	if (this->o2 == 1)
		this->code.push_back(7);
	else {
		int i3 = i;
		while (i < this->o2 + i3) {
			this->code.push_back(8);
			i++;
		}
	}
}

void Command::add_shift(int n) {
	for (int i = 0; i < n; i++) {
		vector <int>::iterator it;
		it = this->code.begin();
		this->size++;
		this->code.insert(it, 5);
	}
}

void Command::expend(int n) {
	for (int i = 0; i < n; i++) {
		this->size++;
		this->code.push_back(4);
	}
}