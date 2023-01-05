#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
int z = 0;
struct tree
{
	int field;
	struct tree* left;
	struct tree* right;
};
void fill_tree(tree* tree_n, int n, int* mass, int max)
{
	tree_n->field = mass[n];
	if (n == max) return;
	if (mass[n] <= mass[n + 1]) {
		tree_n->right = new tree;
		fill_tree(tree_n->right, n + 1, mass, max);
	}
	else {
		tree_n->left = new tree;
		fill_tree(tree_n->left, n + 1, mass, max);
	}
}
tree* fill_tree1(tree* tree_n, int n)
{
	if (tree_n == NULL) {
		tree_n = new tree;
		tree_n->field = n;
		tree_n->left = NULL;
		tree_n->right = NULL;
	}
	else {
		if (n < tree_n->field) {
			tree_n->left = fill_tree1(tree_n->left, n);
		}
		else {
			tree_n->right = fill_tree1(tree_n->right, n);
		}
	}
	return (tree_n);
}
bool exist(int tree_n)
{
	if (tree_n) return true;
	else return false;
}
void print_tree(tree* tree_n)
{
	if (tree_n != NULL) {
		print_tree(tree_n->left);
		cout << tree_n->field << " ";
		print_tree(tree_n->right);
	}
}
int main()
{
	srand(time(0));
	int n;
	n = rand() % 30 + 20;
	int* v = new int[n];
	tree* tree_n = NULL;

	cout << "Amount of elements: " << n << endl;
	for (int i = 0; i < n; i++) v[i] = rand() % 20;
	for (int i = 0; i < n; i++) cout << v[i] << " ";
	cout << endl;
	for (int i = 0; i < n; i++) {
		tree_n = fill_tree1(tree_n, v[i]);
	}
	print_tree(tree_n);
	delete tree_n;
}
