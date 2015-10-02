/*
 * Problem: https://www.codechef.com/SIMPLX15/problems/SLX04
 * Author: afchalla
 * Logic: Needed an efficient sorting algorithm. Used Radix sort 
 */


#include <iostream>
using namespace std;

const long MAX_INPUT_SIZE = 1000000;

long long input[MAX_INPUT_SIZE];

void clearInputs(long long n) {
	for(long long i = 0; i < n; i++) {
		input[i] = 0;
	}
}

void sort_radix(long long length) {

	if(length <= 1) {
		return;
	}
	
	struct node {
		long long value;
		node *link;
	} *list[10], *last[10];

	long long  divider = 1;
	bool breaker = false;

	while(!breaker) {

		for (long long i = 0; i < 10; i++) {
			list[i] = NULL;
			last[i] = NULL;
		}

		for (long long  i = 0 ; i < length; i++) {

			long long index = (input[i] / divider) % 10;
			
			node *temp = new node();
			temp->value = input[i];
			temp->link = NULL;
		
			if(list[index] == NULL) {
				list[index] = temp;
			} else {
				last[index]->link = temp;
			}

			last[index] = temp;
		}
	
		long long j = 0;

		for (long long i = 0; i < 10; i++) {
			while(list[i] != NULL) {
				input[j++] = list[i]->value;
				list[i] = list[i]->link;
			}
		}

		divider *= 10;
		breaker = true;
		for (long long i = 0 ; i < length; i++) {
			if(input[i] / divider != 0) {
				breaker = false;
			}
		}
	}

}


int main() {
	int t;
	long long n, k, count;

	cin>>t;

	while(t--) {
		count = 1;
		cin>>n>>k;

		clearInputs(n);

		for(long long i = 0; i < n; i++) {
			cin>>input[i];
		}

		sort_radix(n);

		long long prev = input[0];
		for(long long i = 1; i < n; i++) {
			if((input[i] - prev) <=  k) {
				count++;
			}
			prev = input[i];
		}

		cout<<count<<endl;
	}
}