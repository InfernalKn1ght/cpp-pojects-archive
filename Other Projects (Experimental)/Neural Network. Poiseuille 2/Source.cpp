#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;


double input_layer[4], hidden_layer[30], output_layer[1], weight0[784][784], weight1[784][784], bias0[30], bias1[1], ideal_mass[1], delta_o[784], mass_del_w0[784][784], mass_del_w1[784][784], mass_del_bw0[30], mass_del_bw1[1];
double v, sigma, c, cost_percentage, f_in, delta_h[784], sigma_delta, del_w, del_b_w;
const double e = 2.718;
const double E = 0.7;
const double alpha = 0.3;
int a, b, prediction, iteration, match;


const int MAXN = 6e4 + 7;
unsigned int image[MAXN][30][30];
unsigned int num, magic, rows, cols;
unsigned int label[MAXN];


unsigned int in(ifstream& icin, unsigned int size) {
	unsigned int ans = 0;
	for (int i = 0; i < size; i++) {
		unsigned char x;
		icin.read((char*)&x, 1);
		unsigned int temp = x;
		ans <<= 8;
		ans += temp;
	}
	return ans;
}
void input(string path_i, string path_l)
{
	ifstream icin;
	icin.open(path_i, ios::binary);
	if (icin.fail())
	{
		cout << "file-error!\n";

	}
	magic = in(icin, 4), num = in(icin, 4), rows = in(icin, 4), cols = in(icin, 4);

	cout << "num=" << num << "\n";
	cout << "rows=" << rows << "\n";
	cout << "cols=" << cols << "\n";

	for (int i = 0; i < num; i++) {
		for (int x = 0; x < rows; x++) {
			for (int y = 0; y < cols; y++) {
				image[i][x][y] = in(icin, 1);
			}
		}
	}
	icin.close();
	icin.open(path_l, ios::binary);
	magic = in(icin, 4), num = in(icin, 4);

	for (int i = 0; i < num; i++)
	{
		label[i] = in(icin, 1);
	}
}

double true_ans(double delta_p, double L, double R, double r)
{
	double nyu = 8 * 0.0001;
	return delta_p * (R * R - r * r) / 4 * L * nyu;
}

double fillrand()
{
	v = 0.0001 * (rand() % 20000 - 10000);
	return v;
}
double sigmoid(double x)
{
	return 1 / (1 + pow(e, -x));
}


void activation(double(&weight)[784][784], double layer[], double next_layer[], double bias[], int A, int B)
{
	sigma = 0;
	for (a = 0; a < A; a++)
	{
		sigma = 0;
		for (b = 0; b < B; b++)
		{
			sigma += weight[a][b] * layer[b];
		}
		sigma = sigma + bias[a];
		next_layer[a] = sigmoid(sigma);
	}
}


void fill_matrix(double(&mass)[784][784], int N, int M)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			mass[i][j] = fillrand();
		}
	}
}
void fill_bias(double mass[], int N)
{
	for (int i = 0; i < N; i++)
	{
		mass[i] = fillrand();
	}
}
void print_matrix(double mass[], string N, int I)
{
	cout << N << ":  ";
	for (int p = 0; p < I; p++)
	{
		cout << fixed;
		cout.precision(20);
		cout << mass[p] << " ";
	}
	cout << "\n" << "\n";
}
void print_matrix2(double(&mass)[784][784], int A, int B)
{
	for (int i = 0; i < A; ++i)
	{
		for (int j = 0; j < B; ++j)
		{
			cout << mass[i][j] << " ";
		}
	}
}
void cost_f(int num)
{
	for (a = 0; a < 10; a++)
	{
		if (a == label[num])
		{
			ideal_mass[a] = 1;
		}
		else
		{
			ideal_mass[a] = 0;
		}
	}
	for (a = 0; a < 10; a++)
	{
		cost_percentage += pow((ideal_mass[a] - output_layer[a]), 2);
	}
	cost_percentage = cost_percentage / 10;
	cost_percentage = 0;
}
void print_num(int k)
{
	int i, j;
	for (j = 0; j < 28; j++)
	{

		for (i = 0; i < 28; i++)
		{

			cout << image[k][j][i] / 128;

		}
		cout << "\n";
	}
	cout << "\n" << "\n";
}
double sigmoid_deriv(double out)
{
	return f_in = (1 - out) * out;
}
void delta_out_l()
{

	delta_o[0] = (ideal_mass[0] - output_layer[0]) * sigmoid_deriv(output_layer[0]);
}
void delta_hid_l(double(&weights)[784][784], double delta[], double layer[], int A, int B)
{
	for (a = 0; a < A; a++)
	{
		sigma_delta = 0;
		for (b = 0; b < B; b++)
		{
			sigma_delta += weights[b][a] * delta[b];
		}
		delta_h[a] = sigma_delta * sigmoid_deriv(layer[a]);
	}
}
void delta_weights(double delta[], double(&weights)[784][784], double layer[], int A, int B, double(&mass_del_w)[784][784])
{
	for (a = 0; a < A; a++)
	{
		for (b = 0; b < B; b++)
		{
			del_w = E * delta[b] * layer[a] + alpha * mass_del_w[b][a];
			mass_del_w[b][a] = del_w;
			weights[b][a] = weights[b][a] + del_w;
		}
	}
}
void zero_mass(double(&mass)[784][784], int A, int B)
{
	for (a = 0; a < A; a++)
	{
		for (b = 0; b < B; b++)
		{
			mass[a][b] = 0;
		}
	}
}
void zero_mass1(double mass[], int A)
{
	for (a = 0; a < A; a++)
	{
		mass[a] = 0;
	}
}
void delta_bias_w(double delta[], double mass_del_bw[], double bias[], int A)
{
	for (a = 0; a < A; a++)
	{
		del_b_w = E * delta[a] + alpha * mass_del_bw[a];
		mass_del_bw[a] = del_b_w;
		bias[a] = bias[a] + del_b_w;
	}
}
//void file(string path)
//{
//	const int SIZE = 784;
//	double R[SIZE];
//	ifstream fr(path, ios::binary);
//	for (int i = 0; i < SIZE; i++) {
//		fr.read((char*)&R[i], sizeof(R[i]));
//		input_layer1[i] = R[i];
//	}
//	fr.close();
//}
/*void save(string path)
{
	const int SIZE = 784;
	ofstream fr(path, ofstream::binary | ios::out);
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 784; j++)
			fr.write((char*)&weight0[i][j], sizeof(double));
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 30; j++)
			fr.write((char*)&weight1[i][j], sizeof(double));
	}
	for (int i = 0; i < 30; i++)
	{
		fr.write((char*)&bias0[i], sizeof(double));
	}
	for (int i = 0; i < 10; i++)
	{
		fr.write((char*)&bias1[i], sizeof(double));
	}
	fr.close();
}*/

void load()
{
	ifstream fr;
	fr.open("C:\\Users\\User\\source\\repos\\Neural Network 2\\Neural Network 2\\weights.dat", ios::binary);
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 784; j++)
			fr.read((char*)&weight0[i][j], sizeof(double));
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 30; j++)
			fr.read((char*)&weight1[i][j], sizeof(double));
	}
	for (int i = 0; i < 30; i++)
	{
		fr.read((char*)&bias0[i], sizeof(double));
	}
	for (int i = 0; i < 10; i++)
	{
		fr.read((char*)&bias1[i], sizeof(double));
	}
	fr.close();
}
void file99(string path)
{
	ofstream out(path, ios::app);
	if (out.is_open())
	{
		out << match << std::endl;
	}
	out.close();

}


int main()
{
	srand(time(0));

	fill_bias(bias0, 30);
	fill_bias(bias1, 1);

	fill_matrix(weight0, 30, 4);
	fill_matrix(weight1, 1, 30);

	zero_mass(mass_del_w0, 30, 4);
	zero_mass(mass_del_w1, 1, 30);

	zero_mass1(mass_del_bw0, 30);
	zero_mass1(mass_del_bw1, 1);

	ofstream file("C:\\Users\\arzha\\Desktop\\123321.txt");

	match = 0;
	int one_k_count = 0;
	iteration = 0;
	double error = 0;
	int ep;
	cin >> ep;
	for (int i = 0; i < 20; ++i) {
		while (iteration < ep)
		{
			double r = (rand() % 100 + 1) * 0.01;
			double R = (rand() % 50 + 1) * 0.1;
			double delta_p = (rand() % 100) * 0.000001;
			double nyu = 8.9 * 0.0001;
			double L = (rand() % 100) + 1;

			input_layer[0] = r, input_layer[1] = R, input_layer[2] = delta_p, input_layer[3] = L;

			double v = (delta_p * (R * R - r * r)) / (4 * nyu * L);
			ideal_mass[0] = v;
			//cout << v << endl;

			activation(weight0, input_layer, hidden_layer, bias0, 30, 4);
			activation(weight1, hidden_layer, output_layer, bias1, 1, 30);

			error += abs(output_layer[0] - v);
			iteration++;

		}
		cout << error / ep << endl;
		iteration = 0;
		error = 0;
	}
	cin >> ep;
	iteration = 0;
	double error2 = 0;
	while (iteration < ep)
	{
		double r = (rand() % 100 + 1) * 0.01;
		double R = (rand() % 50 + 1) * 0.1;
		double delta_p = (rand() % 100) * 0.000001;
		double nyu = 8.9 * 0.0001;
		double L = (rand() % 100) + 1;

		input_layer[0] = r, input_layer[1] = R, input_layer[2] = delta_p, input_layer[3] = L;

		double v = (delta_p * (R * R - r * r)) / (4 * nyu * L);
		ideal_mass[0] = v;

		activation(weight0, input_layer, hidden_layer, bias0, 30, 4);
		activation(weight1, hidden_layer, output_layer, bias1, 1, 30);

		//cost_f(iteration);

		delta_out_l();

		delta_hid_l(weight1, delta_o, hidden_layer, 30, 1);
		delta_bias_w(delta_o, mass_del_bw1, bias1, 1); //bias1 update
		delta_weights(delta_o, weight1, hidden_layer, 30, 1, mass_del_w1); //weight1 update

		delta_bias_w(delta_h, mass_del_bw0, bias0, 30); //bias0 update
		delta_weights(delta_h, weight0, input_layer, 4, 30, mass_del_w0); //weight0 update

		error += abs(output_layer[0] - v);
		error2 += abs(output_layer[0] - v);

		if (iteration % 1000 == 0) {
			error2 /= 1000;
			file << error2 << "\n";
			error2 = 0;
		}

		iteration++;
	}
	cout << error / ep << endl;
	error = 0;
	cin >> ep;
	iteration = 0;
	for (int i = 0; i < 20; ++i) {
		while (iteration < ep)
		{
			double r = (rand() % 100 + 1) * 0.01;
			double R = (rand() % 50 + 1) * 0.1;
			double delta_p = (rand() % 100) * 0.000001;
			double nyu = 8.9 * 0.0001;
			double L = (rand() % 100) + 1;

			input_layer[0] = r, input_layer[1] = R, input_layer[2] = delta_p, input_layer[3] = L;

			double v = (delta_p * (R * R - r * r)) / (4 * nyu * L);
			ideal_mass[0] = v;

			activation(weight0, input_layer, hidden_layer, bias0, 30, 4);
			activation(weight1, hidden_layer, output_layer, bias1, 1, 30);

			error += abs(output_layer[0] - v);
			iteration++;
		}
		iteration = 0;
		cout << error / ep << endl;
		error = 0;
	}
}

