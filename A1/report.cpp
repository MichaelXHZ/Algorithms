i#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printmax(vector <int> &heap, int len, int index, int input){
	if (index >= len || heap[index] < input)
	{
		return;
	}
	else 
	{
		cout << heap[index] << endl;
		printmax(heap, len, 2*index+1, input); //recursively call left node of the current node
		printmax(heap, len, 2*index+2, input); //recursively call right node of the current node
	}
}

int main(int argc, char *argv[]) {
	//tree size
	int n;
	cin >> n;
	if (n == 0) return 0;
	
	//insert input elements to maxheap array
	vector <int> maxheap;
	int e;
	for (int i = 0; i < n; i++)
	{
		cin >> e;
		maxheap.push_back(e);
	}
	
	//The integer needs to be compared
	int c;
	cin >> c;
	
	//helper
	printmax(maxheap, n, 0, c);
	
	return 0;
}