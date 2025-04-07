#include <vector>

using namespace std;

class Command {
public:
	int type;
	int o1;
	int o2;
	int calc;
	int size;
	vector<int> code;

	Command();
	Command generate(float P1_1, float P1_2, float P2, int N, int M);
	void set_code(int N);
	int get_time();
	void add_shift(int n);
	void expend(int n);
	void print();
};