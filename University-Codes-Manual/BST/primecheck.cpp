#include<iostream>
using namespace std;

bool isPrime(int num)
{
    if (num <= 1) return false; // 0 and 1 are not prime
    for (int i = 2; i <= num / 2; i++) // Check divisors up to num / 2
    {
        if (num % i == 0)
            return false; // Not a prime number
    }
    return true; // Prime number
}

int main(){
    cout << isPrime(11)<<endl;
    return 0;
}