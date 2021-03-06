/*
 * Problem: https://www.codechef.com/problems/PROPOSAL
 * Author: afchalla
 * Logic: Simple Math 
 */

#include <iostream>
using namespace std;

const int MAP_SIZE = 10;

int map[MAP_SIZE];

bool containsInput(int n) {
	int rem;
	while(n > 0) {
		rem = n % 10;
		if(map[rem] == 0) {
			return false;
		}
		n = n / 10;
	}
	return true;
}

int countValidMultiplePairs(int n) {
	int count = 0;
	for(int i = 10; i <= 99; i++) {
		if(n % i == 0 && (n/i > 100)) {
			if(containsInput(i) 
				&& containsInput(n/i) 
				&& ((n/i) * (i%10) < 1000) && containsInput((n/i) * (i%10)) 
				&& ((n/i) * (i/10) < 1000) && containsInput((n/i) * (i/10))) {
				count++;
			}
		}
	}
	return count;
}

int main() {
 	int n,v;
	int count = 0;

 	cin>>n;

	for(int i = 0; i < MAP_SIZE; i++) {
		map[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		cin>>v;
		map[v] = 1;
	}

	for (int i = 111; i <= 999; i++) {
		if(containsInput(i)) {
			for(int j = 11; j <= 99; j++) {
				if(containsInput(j)) {
					if((i * (j%10) < 1000) && containsInput(i * (j%10)) 
						&& (i * (j/10) < 1000) && containsInput(i * (j/10))
						&& ((i*j) < 10000) && containsInput(i*j)) {

/*
						//Snippet to display in the given form!								
						cout<<" " <<i<<endl;
						cout<<"x "<<j<<endl;
						cout<<"-----"<<endl;
						cout<<" "<<(i * (j%10))<<endl;
						cout<<(i * (j/10))<<endl;
						cout<<"-----"<<endl;
						cout<<(i*j)<<endl<<endl;
*/


						count++;
					}
				}
			}
		}
	}

	cout<<count<<endl;
	return 0;
 }
