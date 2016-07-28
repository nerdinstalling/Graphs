#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
	vector<vector<int> > V;
//	for (int i = 0; i <= 5; i++) {
//		for (int j=1; j <= 5; j++) {
//			V[i].push_back(j);
//			cout << "in here";
//		}
//	}
	vector<int> my;
	for (int i = 0; i < 5; i++) {
		my.push_back(i);
	}
	V.push_back(my);
	
	for (int i = 0; i < V.size(); i++) {
		for (int j=0; j < V[i].size(); j++) {
			cout << V[i][j] << "\t";
		}
		cout << endl;
	}
	
	
	
	return 0;
}
