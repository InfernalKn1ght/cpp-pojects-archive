#include <iostream>
using namespace std;
double combin(double  N, double  K) {
	if (K == 0) K = N;
	if (N == 0) return 1;
	else return (N / K) * combin(N - 1, K - 1);
}
int main() {
	double  N, K;
	cin >> N >> K;
	cout << combin(N, K);
}
