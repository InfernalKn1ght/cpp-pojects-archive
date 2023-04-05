#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;


const double e = 2.718;
const double E = 0.7;
const double alpha = 0.3;


const int MAXN = 6e4 + 7;




double fillrand() {
	double num = 0.0001 * (rand() % 20000 - 10000);
	return num;
}
double sigmoid(double x) {
	double num = 1 / (1 + pow(e, -x));
	return num;
}
void activation(double**& weight, double layer[], double*& next_layer, double*& bias, int A, int B) {
	for (int i = 0; i < A; ++i) {
		double sigma = 0;
		for (int j = 0; j < B; ++j) {
			sigma += weight[i][j] * layer[j];
		}
		sigma = sigma + bias[i];
		next_layer[i] = sigmoid(sigma);
	}
}
void fill_matrix(double**& mass, int N, int M) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			mass[i][j] = fillrand();
		}
	}
}
void fill_bias(double*& mass, int N) {
	for (int i = 0; i < N; ++i) {
		mass[i] = fillrand();
	}
}
void print_matrix(double*& mass, string N, int I) {
	cout << N << ":  ";
	for (int i = 0; i < I; ++i) {
		cout << fixed;
		cout.precision(20);
		cout << mass[i] << " ";
	}
	cout << "\n" << "\n";
}
void print_matrix2(double**& mass, int A, int B) {
	for (int i = 0; i < A; ++i) {
		for (int j = 0; j < B; ++j) {
			cout << mass[i][j] << " ";
		}
	}
}
void cost_f(int N, double*& ideal_mass, double*& output_layer, double v) {
	double cost_percentage = 0;
	for (int i = 0; i < N; ++i) {
		ideal_mass[i] = v;
	}
	for (int i = 0; i < N; ++i) {
		cost_percentage += pow((ideal_mass[i] - output_layer[i]), 2);
	}
	cost_percentage = cost_percentage / N;
	cost_percentage = 0;
}
double sigmoid_deriv(double out) {
	double num = (1 - out) * out;
	return num;
}
void delta_out_l(double*& delta_o, int N, double*& ideal_mass, double*& output_layer) {
	for (int i = 0; i < N; ++i) {
		delta_o[i] = (ideal_mass[i] - output_layer[i]) * sigmoid_deriv(output_layer[i]);
	}
}
void delta_hid_l(double**& weights, double*& delta, double*& layer, int A, int B, double*& delta_h) {
	for (int i = 0; i < A; ++i) {
		double sigma_delta = 0;
		for (int j = 0; j < B; ++j) {
			sigma_delta += weights[j][i] * delta[j];
		}
		delta_h[i] = sigma_delta * sigmoid_deriv(layer[i]);
	}
}
void delta_weights(double*& delta, double**& weights, double*& layer, int A, int B, double**& mass_del_w) {
	for (int i = 0; i < A; ++i) {
		for (int j = 0; j < B; ++j) {
			double del_w = E * delta[j] * layer[i] + alpha * mass_del_w[j][i];
			mass_del_w[j][i] = del_w;
			weights[j][i] = weights[j][i] + del_w;
		}
	}
}
void delta_bias_w(double*& delta, double*& mass_del_bw, double*& bias, int A) {
	for (int i = 0; i < A; ++i) {
		double del_b_w = E * delta[i] + alpha * mass_del_bw[i];
		mass_del_bw[i] = del_b_w;
		bias[i] = bias[i] + del_b_w;
	}
}
void create_matrix(double**& matrix, int M, int N) {
	for (int i = 0; i < M; ++i) {
		matrix[i] = new double[N] {0};
	}
}
void delete_matrix(double**& matrix, int M) {
	for (int i = 0; i < M; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main()
{
	const int N1 = 5, N2 = 20, N3 = 1;

	double* ideal_mass = new double[N3];

	double* input_layer = new double[N1] {0};
	double* hidden_layer1 = new double[N2] {0};
	double* hidden_layer2 = new double[N2] {0};
	double* output_layer = new double[N3] {0};

	double** weight0 = new double* [N2];
	create_matrix(weight0, N2, N1);
	double** weight1 = new double* [N2];
	create_matrix(weight1, N2, N2);
	double** weight2 = new double* [N3];
	create_matrix(weight2, N3, N2);

	double* bias0 = new double[N2] {0};
	double* bias1 = new double[N2] {0};
	double* bias2 = new double[N3] {0};

	double* delta_o = new double[N3] {0};
	double* delta_h = new double[N2] {0};

	double** mass_del_w0 = new double* [N2];
	create_matrix(mass_del_w0, N2, N1);
	double** mass_del_w1 = new double* [N2];
	create_matrix(mass_del_w1, N2, N2);
	double** mass_del_w2 = new double* [N3];
	create_matrix(mass_del_w2, N3, N2);

	double* mass_del_bw0 = new double[N2] {0};
	double* mass_del_bw1 = new double[N2] {0};
	double* mass_del_bw2 = new double[N3] {0};

	srand(time(0));

	fill_bias(bias0, 50);
	fill_bias(bias1, 50);
	fill_bias(bias2, 10);

	fill_matrix(weight0, N2, N1);
	fill_matrix(weight1, N2, N2);
	fill_matrix(weight2, N3, N2);


	int match = 0;
	for (int i = 0; i < 10000; ++i) {
		double r = (rand() % 100 + 1) * 0.001;
		double R = (rand() % 100 + 1) * 0.1;
		double delta_p = rand() % 990 + 10;
		double nyu = (rand() % 1990 + 10) * 0.0001;
		double L = rand() % 50 + 1;

		input_layer[0] = r, input_layer[1] = R, input_layer[2] = delta_p, input_layer[3] = nyu, input_layer[4] = L;

		double v = (delta_p * R * R) / (4 * nyu * L);

		activation(weight0, input_layer, hidden_layer1, bias0, N2, N1);
		activation(weight1, hidden_layer1, hidden_layer2, bias1, N2, N2);
		activation(weight2, hidden_layer2, output_layer, bias2, N3, N2);

		delta_out_l(delta_o, N3, ideal_mass, output_layer);

		delta_bias_w(delta_o, mass_del_bw2, bias2, N3);
		delta_hid_l(weight2, delta_o, hidden_layer2, N2, N3, delta_h);
		delta_weights(delta_o, weight2, hidden_layer2, N2, N3, mass_del_w2);

		delta_hid_l(weight1, delta_h, hidden_layer1, N2, N2, delta_h);
		delta_bias_w(delta_h, mass_del_bw1, bias1, N2);
		delta_weights(delta_h, weight1, hidden_layer1, N2, N2, mass_del_w1);

		delta_weights(delta_h, weight0, input_layer, N1, N2, mass_del_w0);
		delta_bias_w(delta_h, mass_del_bw0, bias0, N2);



		double prediction = 0;

		if (abs(v - prediction) < 0.001) {
			match++;
		}
	}



	delete[] ideal_mass;

	delete[] input_layer;
	delete[] hidden_layer1;
	delete[] hidden_layer2;
	delete[] output_layer;

	delete_matrix(weight0, N2);
	delete_matrix(weight1, N2);
	delete_matrix(weight2, N3);

	delete[] bias0;
	delete[] bias1;
	delete[] bias2;

	delete[] delta_o;
	delete[] delta_h;

	delete_matrix(mass_del_w0, N2);
	delete_matrix(mass_del_w1, N2);
	delete_matrix(mass_del_w2, N3);

	delete[] mass_del_bw0;
	delete[] mass_del_bw1;
	delete[] mass_del_bw2;

	//while (iteration < 10000)
	//{
	//	for (a = 0; a < 784; a++)
	//	{
	//		c = image[iteration][a % 28][a / 28];
	//		c = c / 255;
	//		input_layer[a] = c;
	//	}
	//	activation(weight0, input_layer, hidden_layer1, bias0, 50, 784);
	//	activation(weight1, hidden_layer1, hidden_layer2, bias1, 50, 50);
	//	activation(weight2, hidden_layer2, output_layer, bias2, 10, 50);
	//	cost_f(iteration);
	//	/*delta_out_l();

	//	delta_hid_l(weight2, delta_o, hidden_layer2, 16, 10);
	//	delta_weights(delta_o, weight2, hidden_layer2, 16, 10, mass_del_w2);

	//	delta_hid_l(weight1, delta_h, hidden_layer1, 16, 16);
	//	delta_weights(delta_h, weight1, hidden_layer1, 16, 16, mass_del_w1);

	//	delta_weights(delta_h, weight0, input_layer, 784, 16, mass_del_w0);*/

	//	prediction = 0;
	//	c = output_layer[0];
	//	for (a = 0; a < 10; a++)
	//	{
	//		for (b = 0; b < 10; b++)
	//		{
	//			if (c < output_layer[b])
	//			{
	//				c = output_layer[b];
	//				prediction = b;
	//			}
	//		}
	//	}
	//	if (label[iteration] == prediction)
	//	{
	//		match++;
	//	}
	//	if ((label[iteration] != prediction) && (iteration > 9000))
	//	{
	//		//cout << "Number: " << label[iteration] << "\n" << "prediction: " << prediction << "\n" << "Output layer: ";
	//		for (a = 0; a < 10; a++)
	//		{
	//			//cout << output_layer[a] << " ";
	//		}
	//		//cout << "\n";
	//		//print_num(iteration);
	//	}
	//	one_k_count++;
	//	if (one_k_count >= 1000)
	//	{
	//		file();
	//		cout << "matches: " << match << "\n";
	//		one_k_count = 0;
	//		match = 0;
	//	}
	//	iteration++;
	//}
}