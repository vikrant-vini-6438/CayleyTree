#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

//constructing a Node
struct node{
    node* prev;
    int data;
    vector<node> next;
};
typedef struct node N;

int noOfVertices(int order, int levels);
node* CayleyTree(int *arr, int o, int h,int v);
int main(){
    int height=2, order = 2;
    int V = noOfVertices(order, height);
    int arr[V]={0,1,2,3,4,5,6,7,8,9};
    node* head = CayleyTree(arr, order, height, V);
    return 0;
}

int noOfVertices(int order, int levels){
    int v = 1, d = order+1;
    for (int i = 0; i<=levels-1;i++)
    {
        v += 3 * pow((d-1), i);
    }
    return v;
}

node* CayleyTree(int *arr, int o, int h, int v) {
    int idx = 0;
    vector<node> queue;
    node *root = new node[1];
    root->prev = nullptr;
    root->data = arr[idx++];
    root->next.resize(3);
    for (int i = 0;i<3;i++){
        root->next[i].data = arr[idx++];
        root->next[i].prev = root;
        queue.push_back(root->next[i]);
    }
    int *height = new int;
    *height = h-1;
    vector<node> temp;
    while(1)
    {
        if(*height == 0){break;}
        for (int i = 0;i<queue.size();i++){
          queue[i].next.resize(2);
          for(int j = 0;j<o;j++){
                queue[i].next[j].data = arr[idx++];
              queue[i].next[j].prev = (&queue[i]);
              temp.push_back(queue[i].next[j]);
          }
        }
        queue.clear();
        for(node i:temp){
            queue.push_back(i);
        }
        *height -= 1;
    }
    for(node i:queue){
            cout<<"hi";
        }
    delete height;
    return root;
}
