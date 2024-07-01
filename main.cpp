#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

struct node{
    node* prev;
    int data;
    node* next;
};
typedef struct node N;

int noOfVertices(int order, int levels);
node* CayleyTree(int *arr, int o, int h,int v);
int main(){
    int height, order = 2;
    cin>>height;

    int V = noOfVertices(order, height);
    int arr[V];
    for (int i = 0;i<V;i++){
        // cin>>arr[i];
        arr[i] = i;
    }
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
    vector<node*> queue;
    node *root = new node[1];
    root->data = arr[idx++];
    root->next = new node[3];
    for (int i = 0;i<3;i++){
        root->next[i].data = arr[idx++];
        root->next[i].prev = root;
        queue.push_back(&root->next[i]);

    }
    int *height = new int;
    *height = h-1;
    vector<node*> temp;
    while(1)
    {
        if(*height == 0){break;}
        for (int i = 0;i<queue.size();i++){

            queue[i]->next = new node[o];
            for(int j = 0;j<o;j++)
            {
                queue[i]->next[j].data = arr[idx++];
                queue[i]->next[j].prev = (queue[i]);
                temp.push_back(&queue[i]->next[j]);
            }
        }
        queue.clear();
        queue = temp;
        *height -= 1;
    }

    delete height;
    return root;
}
