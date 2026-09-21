#include <iostream>

int main() {
	const char* file = R"(


#comment

int /address/ name << 6;
int /address/ name[size] << 8;

for (8) {

}

for (int i :: 8) {

}
for (int i << 6 : 8 : ++)

int foo(int x, int y) {}

int x << 4;
int y << 9;

int l << foo << x, y;

int> r << .l;

int k << *r;









)";
	std::cout << file;
	return 0;
}