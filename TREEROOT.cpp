/*
 * Problem: https://www.codechef.com/problems/TREEROOT
 * Author: afchalla
 * Logic: Simple Math (Sum of ids - Sum of sums will always give us the root node)
 */

#include <iostream>
using namespace std;

const int ID = 0;
const int SUM = 1;

long nodes[1000][2];

 int main() {
 	int t, n;

 	cin>>t;

 	while(t--) {
 		cin>>n;

 		for(int i = 0; i < n; i++) {
 			cin>>nodes[i][ID]>>nodes[i][SUM];
 		}

 		if(n == 1) {
 			cout<<nodes[0][ID]<<endl;
 		} else {
 			long id_sum = 0;
 			long sum_sum = 0;

 			for(int i = 0; i < n; i++) {
 				id_sum += nodes[i][ID];
 				sum_sum += nodes[i][SUM];
 			}

 			cout<<(id_sum-sum_sum)<<endl;
 		}

 	}
 	return 0;
 }
