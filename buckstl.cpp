// C++ program to sort an array using bucket sort
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// Function to sort arr[] of size n using bucket sort
void bucketSort(float arr[], int n)
{
	// 1) Create n empty buckets
	vector<float> b[n];
	
	// 2) Put array elements in different buckets
	for (int i = 0; i < n; i++) 
	{	
		// Index in bucket
		int bi = n * arr[i];
		b[bi].push_back(arr[i]);
	}
	
	// 3) Sort individual buckets
	for (int i = 0; i < n; i++)
	{
		for (auto it = b[i].begin(); it != b[i].end(); it++) 
		{         
			// Searching the upper bound, i.e., first element greater than *it from beginning 
			auto const insertion_point = std::upper_bound(b[i].begin(), it, *it);	
			// Shifting the unsorted part 
			std::rotate(insertion_point, it, it+1);         
		} 
		
	}
	// 4) Concatenate all buckets into arr[]
	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

// Driver program to test above function
int main()
{
	float arr[]
	= { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bucketSort(arr, n);
	
	cout << "Sorted array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}

