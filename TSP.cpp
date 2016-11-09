#include <iostream>
#include <cmath>

enum set{Null,v2,v3,v4,v2v3,v2v4,v3v4,v2v3v4};
int subset(int, int);
int minus(int, int);
int min(int);
int min(int, int);
int min(int, int, int);
void print(int, int[][8]);
void travel(int, int[][4], int[][8], int&);

int main()
{
	int P[4][8] = {};
	int W1[4][4] = { {0,2,9,99},{1,0,6,4},{99,7,0,8},{6,3,99,0} };
	int W2[4][4] = { {0,3,9,10},{6,0,4,99},{10,2,0,8},{99,7,2,0} };
	int W3[4][4] = { {0,99,2,4},{99,0,1,5},{3,2,0,7},{99,99,4,0} };
	int minlength = 0;
	travel(4, W1, P, minlength);
	printf("Graph 1\n");
	print(4, P);
	travel(4, W2, P, minlength);
	printf("\nGraph 2\n");
	print(4, P);
	travel(4, W3, P, minlength);
	printf("\nGraph 3\n");
	print(4, P);
	system("pause");
	return 0;
}

void travel(int n, int W[][4], int P[][8], int& minlength) {
	int i, j, k, l;
	int A;
	int D[4][8] = {}; //D[n][2 ^(n-1)]
	int tmp[3];
	int index[3];
	for (i = 1; i < n; i++) {
		D[i][0] = W[i][0];
	}
for (k = 1; k <= n - 2; k++)
	if (k == 1) {
	for (A = v2; A < v2v3; A++)
			for (i = v2; i <= v4; i++) {
			if (subset(A, i) == 0)
					for (j = v2; j <= v4; j++) {
						if (subset(A, j) == 1) {
							D[i][A] = min(W[i][j] + D[j][minus(A, j)]);
							P[i][A] = j + 1;
						}
							
					}
			}

	}
	else
		for (A = v2v3; A < v2v3v4; A++)
			for (i = v2; i <= v4; i++) {
			if (subset(A, i) == 0) {
				for (j = v2, l = 0; j <= v4; j++)
					if (subset(A, j) == 1) {
						index[l] = j;
						tmp[l] = W[i][j] + D[j][minus(A, j)];
						l++;
					}
						D[i][A] = min(tmp[0], tmp[1]);
						if (tmp[1] > tmp[0]) {
							P[i][A] = index[0] + 1;
						}
						else {
							P[i][A] = index[1] + 1;
						}

					}

				}
	tmp[0] = W[0][1] + D[v2][v3v4];
	tmp[1] = W[0][2] + D[v3][v2v4];
	tmp[2] = W[0][3] + D[v4][v2v3];
	D[0][v2v3v4] = min(W[0][1] + D[v2][v3v4], W[0][2] + D[v3][v2v4], W[0][3] + D[v4][v2v3]);

	if (tmp[0] < tmp[1] && tmp[0] < tmp[2])
		P[0][v2v3v4] = 2;
	else if (tmp[1] < tmp[0] && tmp[1] < tmp[2])
		P[0][v2v3v4] = 3;
	else
		P[0][v2v3v4] = 4;
	minlength = D[0][v2v3v4];
}
int subset(int A, int sub)
{
	if (A == v2v3)
		if (sub == v2 || sub == v3)
			return 1;
		else
			return 0;

	else if (A == v2v4)
		if (sub == v2 || sub == v4)
			return 1;
		else
			return 0;

	else if (A == v3v4)
		if (sub == v3 || sub == v4)
			return 1;
		else
			return 0;

	else
		if (sub == A)
			return 1;
		else 
			return 0;
}

int minus(int A, int sub)
{
	if (A == v2v3v4)
		return A - sub + 1;
	else if (A >= v2v3)
		return A - sub - 1;
	else
		return Null;
}
int min(int i)
{
	return i;
}

int min(int i, int j)
{
	if (i < j)
		return i;
	else if(i > j)
		return j;
}

int min(int i, int j, int k)
{
	if (i < j && i < k)
		return i;
	else if (j < i && j < k)
		return j;
	else
		return k;
}

void print(int n, int P[][8])
{
	int* sol = new int[n + 1];
	int j = 0;
	sol[0] = 1;
	sol[1] = P[sol[0] - 1][v2v3v4];
	sol[2] = P[sol[1] - 1][v2v3v4 - (sol[1] - 1)];
	sol[3] = P[sol[2] - 1][v2v3v4 - (sol[1] - 1) - (sol[2])];
	sol[4] = 1;
	printf("Optimal Tour = [");
	for (int i = 0; i < n + 1; i++)
		printf(" %d ", sol[i]);
	printf("]\n");
}
