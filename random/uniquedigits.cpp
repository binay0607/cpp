// to check if digits of a number are unique or not

#include<iostream>
using namespace std;

// This function returns true if n is lucky
bool isLucky(int n)
{
	
	bool arr[10];
	for (int i=0; i<10; i++)
		arr[i] = false;

	
	while (n > 0)
	{
		
		int digit = n%10;

		// If digit is already seen, return false
		if (arr[digit])
		return false;

		// Mark this digit as seen
		arr[digit] = true;

		
		n = n/10;
	}
	return true;
}


int main()
{
	int n;cin>>n;
	isLucky(n)? cout << n << " is Lucky \n":
				cout << n << " is not Lucky \n";
	return 0;
}
