
// C++ program to implement
// the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to return the
// largest number possible
long long int maxnumber(long long int n, long long int k)
{
	// Generate the largest number
	// after removal of the least
	// K digits one by one
	for (long long int j = 0; j < k; j++) {

		long long int ans = 0;
		long long int i = 1;

		// Remove the least digit
		// after every iteration
		while (n / i > 0) {

			// Store the numbers formed after
			// removing every digit once
			long long int temp = (n / (i * 10))
						* i
					+ (n % i);
			i *= 10;

			// Compare and store the maximum
			ans = max(ans, temp);
		}

		// Store the largest
		// number remaining
		n = ans;
	}

	// Return the remaining number
	// after K removals
	return n;
}

// Driver code
 int main()
{
	long long int n = 44321;
	long long int k = 2;

	cout << maxnumber(n, k) << endl;
	return 0;
}
