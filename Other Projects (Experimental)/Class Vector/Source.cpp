#include <iostream>

class Vector {
private:
	int n;
	int* a;

public:
	Vector(int n = 0) : n(n) {}

	Vector(const Vector& v) {
		for (int i = 0; i < n; ++i) {

		}
	}

	int& operator[](const int index) {
		return a[index];
	}

	void push_back(int val) {
		int* b = new int[n + 1];
		for (int i = 0; i < n; ++i) {
			b[i] = a[i];
		}
		delete[] a;

		b[n] = val;
		a = b;
		delete b;
	}

	int size() {
		return n;
	}

	void clear() {
		delete[] a;
		n = 0;
	}

	~Vector() {
		delete[] a;
	}

};

int main(int argc, char argv[]) {
	Vector v()
		return EXIT_SUCCESS;
}