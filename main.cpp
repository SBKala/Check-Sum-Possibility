#include <iostream>

using namespace std;

int CheckSumPossibility(int num, int arr[], int size)
{
	int subset[size+1][num+1];

	for (int i = 0; i <= size; i++)
		subset[i][0] = true;

	for (int i = 1; i <= num; i++)
		subset[0][i] = false;

	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= num; j++) {
			if (j < arr[i - 1])
				subset[i][j] = subset[i - 1][j];
			if (j >= arr[i - 1])
				subset[i][j] = subset[i - 1][j]
							 ||  subset[i - 1][j - arr[i - 1]];
		}
		
	
	}

	return subset[size][num];
}

int main(int argc, char** argv) {
	int MAX_SIZE = 8;
	int arr[MAX_SIZE];
	int arraySize = sizeof(arr) / sizeof(arr[0]);
	int num = 129;
	int returnVal;
	int i;
	
	for(i = 0; i < arraySize; ++i)
	{
		cin >> arr[i];
	}

    
    if (CheckSumPossibility(num, arr, arraySize) == true)
	 {
	 	returnVal == 1;
	 }
	 else
	 {
	 	returnVal == 0;
	 }
	 
	returnVal = CheckSumPossibility(num, arr, arraySize);
	
	if(returnVal ==1)
	{
		cout << "Possible!" << endl;
	}
	else
	{
		cout << "Not possible!" << endl;
	}
	return 0;
}
