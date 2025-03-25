#include<iostream>
using namespace std; 

int main() {
    int size = 10;
    int count1 = 0, count2 = 0, index1 = 0, index2 = 0; 
    int sum1 = 0, sum2 = 0;

    int arr1[size];               
    int arr2[size] = {0};
    int arr3[size] = {0};
    
    cout << "Enter " << size << " elements for the array: "<< endl;
    
    for(int i = 0; i < size; i++){
        cin >> arr1[i];
    }
    
    for(int j = 0; j < size; j++)
	{
        if(arr1[j] % 2 == 0)
		{
            sum1 += arr1[j];
            arr2[index1++] = arr1[j];
            count1++;
        }
        else 
		{
            sum2 += arr1[j]; 
            arr3[index2++] = arr1[j];
            count2++;
        }
    }
    
    cout << "\t \t \t \tThe total even numbers in the array: " << count1 << endl;
    cout << "\t \t \t \tThe sum of even numbers in the array: " << sum1 << endl;
    cout << "\t \t \t \tThe even numbers in the array: ";
    
    for(int k = 0; k < size; k++)
	{
        if(arr2[k] != 0)
		{
            cout << arr2[k] << " ";
        }
    }
    
    cout << endl;
    
    cout << "\n\t \t \t \tThe total odd numbers in the array: " << count2 << endl;
    cout << "\t \t \t \tThe sum of odd numbers in the array: " << sum2 << endl;
    cout << "\t \t \t \tThe odd numbers in the array: ";
    
    for(int p = 0; p < size; p++)
	{
        if(arr3[p] != 0)
		{
            cout << arr3[p] << " ";
        }
    }
    return 0;
}