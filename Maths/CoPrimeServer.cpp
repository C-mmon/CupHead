Method	                  Preprocessing	            Per Query	  Worst Case for Large x
Brute force  O(x​)	           None	                 O(x​)	           O(1e3) for x≈1e6
SPF Factorization  O(logx)	  O(NloglogN)	        O(logx)	        O(20) for x≈1e6


if you try printing the spf(smallest prime factor) array, it looks like the following
0 0 2 3 2 5 2 7 2 3 2 11 2 13 2 3 2 17 2 19 2 3 2 23 2 5 2 3 2 29....

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int spf[MAXN]; // Smallest prime factor

// O(loglog(n))
void sieve() {
    //Every Number is assumed to be its own smallest prime factor
    // this is required to fill the spf array with smallest prime factor
	for (int i = 2; i < MAXN; i++) spf[i] = i;

    // Sieve of Eratosthenes to fill spf array
	for (int i = 2; i * i < MAXN; i++) {
        // this condition is required to check if i is prime or not
        // if spf[i] == i then it means i is prime
		if (spf[i] == i) {
			for (int j = i * i; j < MAXN; j += i) {
				if (spf[j] == j) {
					// this if is required to fill spf[j] with smallest prime factor
					// by this condition if its already updated then we
					// dont touch it
					spf[j] = i;
				}
			}
		}
	}
}

// O(log(n))
unordered_set<int> get_prime_factors(int x) {
	unordered_set<int> factors;
	// calculates prime factors in log(n)
	// A number can have atmost log(n) prime factors
	// Here instead of iterating over all factors (i->n)
	// we just iterate over prime factors making it faster
	while (x > 1) {
		factors.insert(spf[x]);
		x /= spf[x];
	}
	return factors;
}

// O(N*(logM)) M -> is the element of array
int find_split(vector<int>& tasks) {
	int n = tasks.size();

	vector<unordered_set<int>> prefix(n), suffix(n);
	unordered_set<int> left_factors, right_factors;

	// Compute prefix prime factors
	for (int i = 0; i < n; i++) {
		unordered_set<int> pf = get_prime_factors(tasks[i]);
		for (int p : pf) left_factors.insert(p);
		prefix[i] = left_factors;
	}

	// Compute suffix prime factors
	for (int i = n - 1; i >= 0; i--) {
		unordered_set<int> pf = get_prime_factors(tasks[i]);
		for (int p : pf) right_factors.insert(p);
		suffix[i] = right_factors;
	}

	// Iterate over split points
	for (int i = 0; i < n - 1; i++) {
		bool has_common = false;
		for (int p : prefix[i]) {
			if (suffix[i + 1].count(p)) {
				has_common = true;
				break;
			}
		}

		if (!has_common) return i;
	}

	return -1;
}

int main() {
	sieve();
	vector<int> tasks = {4, 7, 8, 15, 3};
	cout << find_split(tasks) << endl;
	return 0;
}