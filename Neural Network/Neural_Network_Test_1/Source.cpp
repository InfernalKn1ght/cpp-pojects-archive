#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;


double input_layer[784], hidden_layer[30], output_layer[10], weight0[784][784], weight1[784][784], bias0[30], bias1[10], ideal_mass[10], delta_o[784], mass_del_w0[784][784], mass_del_w1[784][784], mass_del_bw0[30], mass_del_bw1[10], input_layer1[784];
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
	num = 10000;
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
	num = 10000;
	for (int i = 0; i < num; i++)
	{
		label[i] = in(icin, 1);
	}
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
	for (a = 0; a < 10; a++)
	{
		delta_o[a] = (ideal_mass[a] - output_layer[a]) * sigmoid_deriv(output_layer[a]);
	}
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
void file(string path)
{
	const int SIZE = 784;
	double R[SIZE];
	ifstream fr(path, ios::binary);
	for (int i = 0; i < SIZE; i++) {
		fr.read((char*)&R[i], sizeof(R[i]));
		input_layer1[i] = R[i];
	}
	fr.close();
}

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

void load2()
{
	ifstream fr;
	fr.open("letter.dat", ios::binary);
	for (int i = 0; i < 784; i++)
	{
		fr.read((char*)&input_layer[i], sizeof(double));
	}
	fr.close();
}


int prediction1()
{
	prediction = 0;
	c = output_layer[0];
	for (a = 0; a < 10; a++)
	{
		for (b = 0; b < 10; b++)
		{
			if (c < output_layer[b])
			{
				c = output_layer[b];
				prediction = b;
			}
		}
	}
	return prediction;
}


int main()
{
	iteration = 0;
	int m = 0;

	load();
	input("C:\\Users\\User\\Desktop\\images\\train\\60K\\train-images.idx3-ubyte", "C:\\Users\\User\\Desktop\\images\\train\\60K\\train-labels.idx1-ubyte");
	for (a = 0; a < 10; a++)
	{
		cout << weight0[0][a] << endl;
	}
	while (iteration < 1000)
	{
		for (a = 0; a < 784; a++)
		{
			c = image[iteration][a % 28][a / 28];
			c = c / 255;
			input_layer[a] = c;
			if (c == 1)
				cout << c << endl;
		}
		activation(weight0, input_layer, hidden_layer, bias0, 30, 784);
		activation(weight1, hidden_layer, output_layer, bias1, 10, 30);
		cost_f(iteration);
		if (label[iteration] != prediction1())
		{
			m++;
		}
		if (iteration == 9)
		{
			print_matrix(output_layer, "output_layer", 10);
		}
		cout << "iteration: " << label[iteration] << " " << "prediction: " << prediction1() << "\n";
		iteration++;
	}
	cout << "mistakes: " << m << endl;
	//print_matrix2(weight0, 30, 784);


	load2();
	activation(weight0, input_layer, hidden_layer, bias0, 30, 784);
	activation(weight1, hidden_layer, output_layer, bias1, 10, 30);
	cout << "prediction: " << prediction1() << "\n";
	//print_matrix(input_layer, "output_layer", 784);
}