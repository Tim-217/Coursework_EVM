#include "command.h"
#include "check.h"
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	float P1_1, P1_2, P2;
	int N, M, kol;
	cout << "Введите вроятность того, что для 1 операнда используется регистровая адресация (0.9 или 0.8 или 0.6): ";
	P1_1 = check_input_f();
	check_P1(P1_1);
	cout << "Введите вероятность того, что для 2 операнда используется регистровая адресация (0.9 или 0.8 или 0.6): ";
	P1_2 = check_input_f();
	check_P1(P1_2);
	cout << "Введите вероятность того, что команда имеет 1 тип (0.9 или 0.7 или 0.5): ";
	P2 = check_input_f();
	check_P2(P2);
	cout << "Введите количество такстов для обращения в память (2 или 5 или 10): ";
	N = check_input_i();
	check_N(N);
	cout << "Введите количество тактов для вычисления результатов команд 2 типа (4 или 8 или 16): ";
	M = check_input_i();
	check_M(M);
	cout << "Введите количество команд: ";
	kol = check_input_i();

	Command* list;
	list = new Command[kol];
	for (int i = 0; i < kol; i++) {
		Command element;
		element = element.generate(P1_1, P1_2, P2, N, M);
		element.set_code(N);
		element.add_shift(i);
		list[i] = element;
	}
	int maxsize = 0;
	for (int i = 0; i < kol; i++) {
		if (list[i].size > maxsize)
			maxsize = list[i].size;
	}
	for (int i = 0; i < kol; i++) {
		int n = maxsize - list[i].size;
		list[i].expend(n);
	}
	int flag_M, flag_R, flag_C, flag_K;
	for (int i = 0; i < maxsize; i++) {
		flag_M = 0;	flag_R = 0;	flag_C = 0; flag_K = 0;
		for (int j = 0; j < kol; j++) {
			if (list[j].code[i] == 1 || list[j].code[i] == 7) {
				if (flag_R == 0) {
					flag_R = 1;
					continue;
				}
				if (flag_R == 1) {
					vector <int>::iterator sR;
					sR = list[j].code.begin() + i;
					list[j].code.insert(sR, 5);
					list[j].size++;
					maxsize++;
					for (int r = 0; r < kol; r++) {
						if (r != j) {
							list[r].size++;
							list[r].code.push_back(4);
						}
					}

				}
			}
			if (list[j].code[i] == 2 || list[j].code[i] == 8) {
				if (flag_M == 0) {
					flag_M = 1;
					continue;
				}
				if (flag_M == 1) {
					if (list[j].code[i] == 2) {
						vector <int>::iterator sM;
						for (int k = 0; k < list[j].code.size(); k++) {
							if (list[j].code[k] == 2) {
								sM = list[j].code.begin() + k;
								break;
							}
						}
						list[j].size++;
						maxsize++;
						list[j].code.insert(sM, 5);
						for (int r = 0; r < kol; r++) {
							if (r != j)
								list[r].size++;
							list[r].code.push_back(4);
						}

						for (int k = 0; k < list[j].code.size(); k++) {
							if (list[j].code[k] == 2) {
								sM = list[j].code.begin() + k;
								break;
							}
						}
						int iM = i;
						while (list[j].code[iM] == 2) {
							list[j].size++;
							list[j].code.insert(sM, 5);
							for (int k = 0; k < list[j].code.size(); k++) {
								if (list[j].code[k] == 2) {
									sM = list[j].code.begin() + k;
									break;
								}
							}
						}
					}
					else {
						vector <int>::iterator sM;
						for (int k = 0; k < list[j].code.size(); k++) {
							if (list[j].code[k] == 8) {
								sM = list[j].code.begin() + k;
								break;
							}
						}
						list[j].size++;
						maxsize++;
						list[j].code.insert(sM, 5);
						for (int r = 0; r < kol; r++) {
							if (r != j)
								list[r].size++;
							list[r].code.push_back(4);
						}

						for (int k = 0; k < list[j].code.size(); k++) {
							if (list[j].code[k] == 8) {
								sM = list[j].code.begin() + k;
								break;
							}
						}
						int iM = i;
						while (list[j].code[iM] == 8) {
							list[j].size++;
							list[j].code.insert(sM, 5);
							for (int k = 0; k < list[j].code.size(); k++) {
								if (list[j].code[k] == 8) {
									sM = list[j].code.begin() + k;
									break;
								}
							}
						}
					}

				}
			}
			if (list[j].code[i] == 3) {
				if (flag_C == 0) {
					flag_C = 1;
					continue;
				}
				if (flag_C == 1) {
					vector <int>::iterator sC;
					for (int k = 0; k < list[j].code.size(); k++) {
						if (list[j].code[k] == 3) {
							sC = list[j].code.begin() + k;
							break;
						}
					}
					list[j].size++;
					maxsize++;
					list[j].code.insert(sC, 5);
					for (int r = 0; r < kol; r++) {
						if (r != j)
							list[r].size++;
						list[r].code.push_back(4);
					}
					for (int k = 0; k < list[j].code.size(); k++) {
						if (list[j].code[k] == 3) {
							sC = list[j].code.begin() + k;
							break;
						}
					}
					int iC = i;
					while (list[j].code[iC] == 3) {
						list[j].size++;
						list[j].code.insert(sC, 5);
						for (int k = 0; k < list[j].code.size(); k++) {
							if (list[j].code[k] == 3) {
								sC = list[j].code.begin() + k;
								break;
							}
						}
					}
				}
			}
			if (list[j].code[i] == 6) {
				if (flag_K == 0) {
					flag_K = 1;
					continue;
				}
				if (flag_K == 1) {
					vector <int>::iterator sK;
					for (int k = 0; k < list[j].code.size(); k++) {
						if (list[j].code[k] == 6) {
							sK = list[j].code.begin() + k;
							break;
						}
					}
					list[j].size++;
					maxsize++;
					list[j].code.insert(sK, 5);
					for (int r = 0; r < kol; r++) {
						if (r != j)
							list[r].size++;
						list[r].code.push_back(4);
					}
					for (int k = 0; k < list[j].code.size(); k++) {
						if (list[j].code[k] == 6) {
							sK = list[j].code.begin() + k;
							break;
						}
					}
					int iK = i;
					while (list[j].code[iK] == 6) {
						list[j].size++;
						list[j].code.insert(sK, 5);
						for (int k = 0; k < list[j].code.size(); k++) {
							if (list[j].code[k] == 6) {
								sK = list[j].code.begin() + k;
								break;
							}
						}
					}
				}
			}
		}
	}	
	int sum_time = 0, time_el;
	for (int i = 0; i < kol; i++) {
		time_el = list[i].get_time();
		sum_time += time_el;
	}
	for (int i = 0; i < kol; i++)
		list[i].print();
	cout << endl << "Среднее время выполнения команды: " << sum_time / kol << endl;
	return 0;
}