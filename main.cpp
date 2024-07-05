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
    treeNode* root = new treeNode;

    if (h == 0){return root;}
    
    root->parent = new treeNode;
    root->childOne = new treeNode;
    root->childTwo = new treeNode;
    root->parent->parent = root;
    root->childOne->parent = root;
    root->childTwo->parent = root;
    v -= 3;
    vector<treeNode*> queue{root->parent,root->childOne,root->childTwo};
    while(v>0){
        queue[0]->childOne = new treeNode;
        queue[0]->childOne->parent = queue[0];
        queue[0]->childTwo = new treeNode;
        queue[0]->childTwo->parent = queue[0];
        queue.push_back(queue[0]->childOne);
        queue.push_back(queue[0]->childTwo);
        v-= 2;
    }
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