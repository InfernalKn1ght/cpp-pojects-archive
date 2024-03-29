#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;


double input_layer[784], hidden_layer1[50], hidden_layer2[50], output_layer[10], weight0[784][784], weight1[784][784], weight2[784][784], bias0[50], bias1[50], bias2[10], ideal_mass[10], delta_o[784];
double mass_del_w0[784][784], mass_del_w1[784][784], mass_del_w2[784][784], mass_del_bw0[50], mass_del_bw1[50], mass_del_bw2[10];
double v, e1, sigma, c, cost_percentage, f_in, delta_h[784], sigma_delta, GRAD, del_w, image1[60000][28][28], del_b_w;
const double e = 2.718;
const double E = 0.7;
const double alpha = 0.3;
int a, b, c1, c2, x, prediction, iteration, a1, num1[60000], match;


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
	//num = 10000;
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
	//num = 10000;
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
void file()
{
	ofstream out("C:\\Users\\User\\Desktop\\����� �����\\file.txt", ios::app);
	if (out.is_open())
	{
		out << match << std::endl;
	}
	out.close();

}

int main()
{
	input("C:\\Users\\User\\Desktop\\images\\train\\60K\\train-images.idx3-ubyte", "C:\\Users\\User\\Desktop\\images\\train\\60K\\train-labels.idx1-ubyte");

	srand(time(0));

	fill_bias(bias0, 50);
	fill_bias(bias1, 50);
	fill_bias(bias2, 10);

	fill_matrix(weight0, 50, 784);
	fill_matrix(weight1, 50, 50);
	fill_matrix(weight2, 10, 50);

	zero_mass(mass_del_w0, 50, 784);
	zero_mass(mass_del_w1, 50, 50);
	zero_mass(mass_del_w2, 10, 50);

	zero_mass1(mass_del_bw0, 50);
	zero_mass1(mass_del_bw1, 50);
	zero_mass1(mass_del_bw2, 10);

	match = 0;
	int one_k_count = 0;
	iteration = 0;
	while (iteration < 60000)
	{
		for (a = 0; a < 784; a++)
		{
			c = image[iteration][a % 28][a / 28];
			c = c / 255;
			input_layer[a] = c;
		}
		activation(weight0, input_layer, hidden_layer1, bias0, 50, 784);
		activation(weight1, hidden_layer1, hidden_layer2, bias1, 50, 50);
		activation(weight2, hidden_layer2, output_layer, bias2, 10, 50);
		cost_f(iteration);

		delta_out_l();

		delta_bias_w(delta_o, mass_del_bw2, bias2, 10);
		delta_hid_l(weight2, delta_o, hidden_layer2, 50, 10);
		delta_weights(delta_o, weight2, hidden_layer2, 50, 10, mass_del_w2);

		delta_hid_l(weight1, delta_h, hidden_layer1, 50, 50);
		delta_bias_w(delta_h, mass_del_bw1, bias1, 50);
		delta_weights(delta_h, weight1, hidden_layer1, 50, 50, mass_del_w1);

		delta_weights(delta_h, weight0, input_layer, 784, 50, mass_del_w0);
		delta_bias_w(delta_h, mass_del_bw0, bias0, 50);



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
		if (label[iteration] == prediction)
		{
			match++;
		}
		if ((label[iteration] != prediction) && (iteration > 50000))
		{
			//cout << "Number: " << label[iteration] << "\n" << "prediction: " << prediction << "\n" << "Output layer: ";
			for (a = 0; a < 10; a++)
			{
				//cout << output_layer[a] << " ";
			}
			//cout << "\n";
			//print_num(iteration);
		}
		one_k_count++;
		if (one_k_count >= 1000)
		{
			file();
			cout << "matches: " << match << "\n";
			one_k_count = 0;
			match = 0;
		}
		iteration++;
	}
	iteration = 0;
	match = 0;
	one_k_count = 0;
	cout << "\n" << "\n";

	input("C:\\Users\\User\\Desktop\\images\\train\\10K\\t10k-images.idx3-ubyte", "C:\\Users\\User\\Desktop\\images\\train\\10K\\t10k-labels.idx1-ubyte");

	while (iteration < 10000)
	{
		for (a = 0; a < 784; a++)
		{
			c = image[iteration][a % 28][a / 28];
			c = c / 255;
			input_layer[a] = c;
		}
		activation(weight0, input_layer, hidden_layer1, bias0, 50, 784);
		activation(weight1, hidden_layer1, hidden_layer2, bias1, 50, 50);
		activation(weight2, hidden_layer2, output_layer, bias2, 10, 50);
		cost_f(iteration);
		/*delta_out_l();

		delta_hid_l(weight2, delta_o, hidden_layer2, 16, 10);
		delta_weights(delta_o, weight2, hidden_layer2, 16, 10, mass_del_w2);

		delta_hid_l(weight1, delta_h, hidden_layer1, 16, 16);
		delta_weights(delta_h, weight1, hidden_layer1, 16, 16, mass_del_w1);

		delta_weights(delta_h, weight0, input_layer, 784, 16, mass_del_w0);*/

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
		if (label[iteration] == prediction)
		{
			match++;
		}
		if ((label[iteration] != prediction) && (iteration > 9000))
		{
			//cout << "Number: " << label[iteration] << "\n" << "prediction: " << prediction << "\n" << "Output layer: ";
			for (a = 0; a < 10; a++)
			{
				//cout << output_layer[a] << " ";
			}
			//cout << "\n";
			//print_num(iteration);
		}
		one_k_count++;
		if (one_k_count >= 1000)
		{
			file();
			cout << "matches: " << match << "\n";
			one_k_count = 0;
			match = 0;
		}
		iteration++;
	}
}