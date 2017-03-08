#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class node {
	public:
	int x, y;
		node(int m,int n){
			x = m; 
			y = n;
		};
		void print(){
			cout << x << " " << y << " ";
		}
};

vector <node*> sublist(int from, int to, vector <node*> vec){
    vector <node*> sub;
    for(int i = from; i < to; i++) {
         sub.push_back(vec[i]);
    }
    return sub;
}

vector <node*> partitionR(node* nd, vector<node*> vec, string str){
	vector <node*> after;
	if (str == "x")
	{
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i]->x > nd->x)
			{
				after.push_back(vec[i]);
			}
		}
	}
	else {
		for (int i = 0; i< vec.size(); i++)
		{
			if (vec[i]->y > nd->y)
			{
				after.push_back(vec[i]);
			}
		}
	}
	return after;
}

vector <node*> partitionL(node* nd, vector<node*> vec, string str){
	vector <node*> after;
	if (str == "x")
	{
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i]->x < nd->x)
			{
				after.push_back(vec[i]);
			}
		}
	}
	else {
		for (int i = 0; i< vec.size(); i++)
		{
			if (vec[i]->y < nd->y)
			{
				after.push_back(vec[i]);
			}
		}
	}
	return after;
}

void printKD(vector <node*> X, vector <node*> Y, int dir){
	if (X.size() == 0){
		return;
	}
	else if (X.size() == 1){
		X[0]->print();
		return;
	}
	else if (dir%2 != 0)
	{
		node* middleY = Y[Y.size()/2];
		vector <node*> uphalf = partitionR(middleY, X, "y");
		vector <node*> downhalf = partitionL(middleY, X, "y");
		printKD(downhalf, sublist(0,Y.size()/2, Y), dir+1);
		middleY->print();
		printKD(uphalf, sublist(Y.size()/2+1, Y.size(), Y), dir+1);
	}
	else if (dir%2 == 0)
	{
		node* middleX = X[X.size()/2];
		vector <node*> uphalf = partitionR(middleX, Y, "x");
		vector <node*> downhalf = partitionL(middleX, Y, "x");
		printKD(downhalf, sublist(0,X.size()/2, X), dir+1);
		middleX->print();
		printKD(uphalf, sublist(X.size()/2+1, X.size(), X), dir+1);
	}
}

bool compX(node* n1, node* n2){
	return (n1->x < n2->x);
}

bool compY(node* n1, node* n2){
	return (n1->y < n2->y);
}

int main(int argc, char *argv[]) {
	int num;
	cin >> num;
	if (num < 0){
		cout << "wrong number of nodes" << endl;
		return 1;
	}
	if (num == 0){
		return 0;
	}
	
	vector <node*> vecX;
	
	for (int i = 0; i<num; i++){
		int x, y;
		cin >> x >> y;
		node *current = new node(x,y);
		vecX.push_back(current);
	}
	
	vector <node*> vecY = vecX;
	
	sort(vecX.begin(), vecX.end(), compX);
	sort(vecY.begin(), vecY.end(), compY);
	
	printKD(vecX, vecY, 0);
	
	return 0;
}