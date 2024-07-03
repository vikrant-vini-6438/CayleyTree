#include<iostream>
#include<cmath>
using namespace std;

//int *order = new int;

struct treeNode{
    treeNode* parent = nullptr;
    treeNode* childOne = nullptr;
    treeNode* childTwo = nullptr;
    int data;
};
int noOfVertices(int height, int order){
    int result = 1;
    for(int i = 0;i<height;i++){
        result += (order+1)*pow((order),i);
    }
    return result;
}
treeNode *cayleyTree(int h, int o){
    treeNode* root = new treeNode;
//    root->data = ar[0];
    
    return root;
}
treeNode* insertDataCayleyTree(int *H, int * ar){
    return nullptr;
}
int main(){
    int order = 2,height;
    cin>>height;
    int V = noOfVertices(height, order);
    int arr[V];
    for(int i = 0;i<V;i++){
//        cin>>arr[i];
        arr[i] = i;
    }

    treeNode* head = cayleyTree(height, order, arr);
//    delete order;
    return 0;
}