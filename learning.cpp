#include<iostream>
#include<vector>
using namespace std;

struct node{
	  int data;
	    vector<node> next;
	      vector<node*> nextt;
};

int main(){
	node root;

	root.data = 5;
	root.next.resize(3);
	root.nextt.resize(4);
	return 0;
}
