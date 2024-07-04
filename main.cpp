#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


struct treeNode{
    treeNode* parent = nullptr;
    treeNode* childOne = nullptr;
    treeNode* childTwo = nullptr;
    int data;
};
typedef struct treeNode treeNode;
int noOfVertices(int height, int order){
    int result = 1;
    for(int i = 0;i<height;i++){
        result += (order+1)*pow((order),i);
    }
    return result;
}
treeNode *cayleyTree(int h, int o, int v){
    if (h == 0){return nullptr;}
    treeNode* root = new treeNode;
//    root->data = ar[0];

    root->parent = new treeNode;
    root->childOne = new treeNode;
    root->childTwo = new treeNode;
    root->childOne->parent = root;
    root->childTwo->parent = root;
    root->parent->parent = root;
    int idx = 3;
    vector<treeNode*> queue({&root->parent, &root->childOne, &root->childTwo});



    return root;
}
//treeNode* insertDataCayleyTree(int *H, int * ar){
//
//    return nullptr;
//}
int main(){
    int order = 2,height;
    cin>>height;
    int V = noOfVertices(height, order);
    int arr[V];
    for(int i = 0;i<V;i++){
        arr[i] = i;
    }

    treeNode* head = cayleyTree(height, order,V);
    delete head->childTwo;
    delete head->childOne;
    delete head->parent;
    delete head;
    return 0;
}