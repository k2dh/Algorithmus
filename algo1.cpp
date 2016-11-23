#include <iostream>
#define N 500
#define Num 15
#define T 10

int number = 0;
int partition(int low, int high, int S[]) {
	
	int i, j, tmp;
	int pivotitem;
	pivotitem = S[low]; //pivotitem을 위한 첫번째 항목을 고른다
	j = low;
	for (i = low + 1; i <= high; i++)
	{
		
		if (S[i] < pivotitem) {
			
			j++;
			tmp = S[i];
			S[i] = S[j];
			S[j] = tmp;
			//exchange S[i] and S[j];
		}
	}
	tmp = S[low];
	S[low] = S[j];
	S[j] = tmp;
	return j;
	//exchange S[low] and S[pivotpoint]; // pivotitem 값을 pivotpoint에
}

void quicksort(int low, int high, int S[]) {
	number++;
	int pivotpoint;
	if (high > low) {
		pivotpoint = partition(low, high, S);
		quicksort(low, pivotpoint - 1, S);
		quicksort(pivotpoint + 1, high, S);
	}
}

void merge(int h, int m, int U[], int V[],
	int S[]) {
	
	number++;
	int i, j, k;
	i = 0; j = 0; k = 0;
	
	while (i < h && j < m) {
		
		if (U[i] < V[j]) {
			S[k] = U[i];
			i++;
		
		}
		else {
			S[k] = V[j];
			j++;
			
		}
		k++;
	}
	if (i >= h)
		for (; j < m; j++, k++)
			S[k] = V[j];

	else
		for (; i < h; i++, k++)
			S[k] = U[i];
}
void mergesort(int n, int S[]) {
	number++;
	if (n > 1) {
		int h = n / 2, m = n - h;
		int * U = new int[h];
		int * V = new int[m];
		for(int i = 0; i < h; i++)
		{
			U[i] = S[i];
			
		}
	
		for (int i = 0; i < m; i++)
		{
			V[i] = S[h + i];
		;
		}
		
		mergesort(h, U);
		mergesort(m, V);
		merge(h, m, U, V, S);
	}
}


int fib(int n) {
	number++;
	if (n <= 1)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}

int fib2(int n) {
	int i;
	int f[100000];
	f[0] = 0;
	if (n > 0) {
		f[1] = 1;
		number++;
		for (i = 2; i <= n; i++)
		{
			f[i] = f[i - 1] + f[i - 2];
			number++;
		}
	}
	return f[n];
}
void binsearch(int n, // 입력(1)
	int S[], // (2)
	int x // (3)
) { // 출력
	int low, high, mid;
	low = 1; high = n;
	int location = 0;
	int number = 0;
	while (low <= high && location == 0) {
		number++;
		mid = (low + high) / 2; // 정수나눗셈
		if (x == S[mid]) location = mid;
		else if (x < S[mid]) high = mid - 1;
		else low = mid + 1;
	}
	printf("Location : %d\n", location);

	printf("BinSearch Number : %d\n", number);
}
void seqsearch(int n, // 입력(1)
	int S[], // (2)
	int x) { // 출력
	int location = 1;
	int number=0;
	while (location <= n && S[location] != x) {
		number++;
		location++;
		if (location > n)
		{
			location = 0;
			break;
		}
	}
	printf("Location : %d\n", location);
	printf("SeqSearch Number : %d\n", number);
}
int main()
{
	int a[N];
	for (int i = 0; i < N; i++)
		a[i] = i;
	
	seqsearch(N, a, N);
	binsearch(N, a, N);
	fib(Num);
	printf("Fib Number : %d\n", number);
	number = 1;
	fib2(Num);
	printf("Fib2 Number : %d\n", number);
	number = 0;

	int b[T];
	for (int i = 0; i <T; i++)
		b[i] =  i;
	mergesort(T,b);
	printf("Mergesort Number : %d\n", number);

	
	number = 0;
	for (int i = 0; i < T;i++)
		b[i] = T- i;
	quicksort(0, T-1, b);
	printf("QuickSort Number : %d\n", number);
	number = 0;
	int c[8] = { 10,29,16,13,27,18,9,11 };
	number = 0;
	mergesort(8, c);
	printf("Merge Number : %d\n", number);
	quicksort(10,29, c);
	printf("QuickSort Number : %d\n", number);
	system("pause");
	return 0;

}