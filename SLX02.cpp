/*
 * Problem: https://www.codechef.com/SIMPLX15/problems/SLX02
 * Author: afchalla
 * Logic: Problem is more about handling the edge cases - General Math
 * Unsubmitted
 */


#include <iostream>
#include <stdlib.h>
using namespace std;

const long MAX_INPUT_SIZE = 123;

long long input[MAX_INPUT_SIZE];

void clearInputs() {
	for(long long i = 0; i < MAX_INPUT_SIZE; i++) {
		input[i] = 0;
	}
}

int main() {
	int t;
	long long n, k, count;
	string a;

	cin>>t;

	while(t--) {
		clearInputs();

		cin>>a;
		
		for(long long i = 0; a[i] != '\0'; i++) {
			input[int(a[i])]++;
		}

		long long max = 0;
		long long max_count = 0;
		long long min = 0;
		long long min_count = 0;

		for(long long i = 0; i < MAX_INPUT_SIZE; i++) {
			if(input[i] >= max) {
				max = input[i];
			}
		}

		min = max;
		for(long long i = 0; i < MAX_INPUT_SIZE; i++) {
			if(input[i] != 0 && input[i] < min) {
				min = input[i];
			}
		}

		if(min == max) {
			cout<<"SAFE"<<endl;
		} else {
			if((max - min) > 1) {
				cout<<"NOT POSSIBLE"<<endl;

			} else {

				for(long long i = 0; i < MAX_INPUT_SIZE; i++) {
					if(input[i] == min) {
						min_count++;
					} else if (input[i] == max) {
						max_count++;
					}
				}

				if(min_count == 1) {
					cout<<"INCREMENT"<<endl;
				} else if (max_count == 1) {
					cout<<"DECREMENT"<<endl;
				} else {
					cout<<"NOT POSSIBLE"<<endl;
				}
			}
		}

	}

}
