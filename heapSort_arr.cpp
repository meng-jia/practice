#include<bits/stdc++.h>

using namespace std;



void heapify(int arr[], int n, int i) {
	// Your Code Here
	int largest = i;
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	if (left<n && arr[left] > arr[largest])// here is arr[largest], not arr[i]
	{
		largest = left;
	}
	if (right<n && arr[right] > arr[largest])// here is arr[largest], not arr[i]
	{
		largest = right;
	}
	if (largest != i)
	{
		swap(arr[largest], arr[i]);
		heapify(arr, n, largest);
	}
}
// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n) {
	// Your Code Here
	for (int i = n / 2 - 1; i >= 0; i--)// here is i = n/2-1, i = (n-1)/2
	{
		heapify(arr, n, i);
	}
}
void heapSort(int arr[], int n) {
	buildHeap(arr, n);
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
int main()
{
	const int n = 65536; //注意 int 不能超过 
	int T, N, t, arr[n];//注意这个要设置为局部变量
	cin >> T;
	//scanf("%d", &T);
	while (T--)
	{
		cin >> N;
		//scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
			// 			cin >> t;
			// 			arr[i] = t;
		}
		heapSort(arr, N); //是heapsort(arr, N); 不是	heapsort(arr, n);
		for (int i = 0; i < N; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
	}
	system("pause");

	return 0;
}

