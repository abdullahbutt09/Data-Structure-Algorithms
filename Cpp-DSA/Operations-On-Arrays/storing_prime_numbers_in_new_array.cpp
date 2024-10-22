#include<iostream>
using namespace std;
int main(){
	
	int k;
	int size = 10;
	int arr[size];
	int arr2[size] = {0};
	int index = 0;
	
	cout << "Enter elements: "<<endl;
	for(int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	
	for(int j = 0; j < size; j++)
	{
		for(k = 2; k < arr[j]; k++)
		{
			if(arr[j] % k == 0)
			{
				cout <<"";
				break;
			}
		}
		
		if(arr[j] == k)
		{
			arr2[index++] = k;
		}
	}
	
	cout << "Prime numbers are: ";
	for(int m = 0; m < size; m++)
	{
		if(arr2[m] != 0)
		{
			cout << arr2[m] << " ";
		}
	}
	
	return 0;
}