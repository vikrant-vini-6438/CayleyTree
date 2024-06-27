#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

//constructing a Node
struct node{
    node* prev;
    int data;
    node* next;
};
typedef struct node N;

int noOfVertices(int order, int levels);
node* CayleyTree(int *arr, int o, int h,int v);
//node insertDataOfCayleyTree(void *root, int*arr, int o, int h);
int main(){
    int height, order = 2;
    cout<<"height:";
    cin>>height;

    // for finding the no. of vertices
    int V = noOfVertices(order, height);
    //taking data for each vertex of tree
    int arr[V];
    for (int i = 0;i<V;i++){
        cin>>arr[i];
    }
    //forming a Cayley Tree
    node* head = CayleyTree(arr, order, height, V);
//    insertDataOfCayleyTree(head, arr, order ,height);
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
//    N *root = nullptr;
//    N nodeArray[v];
//    for (int i = 0; i < v; i++) {
//        nodeArray[i].data = arr[i];
//    }
//    root = &nodeArray[0];
//    root->next = new node[o+1];
//    for (int i = 0; i < (o+1); ++i) {
//        root->next[i].prev = root;
//        root->next[i].data = arr[i + 1];
//        root->next[i].next = nullptr;
//    }
//    vector<node *> rootVector;
//    for (int i = 0; i < 3; ++i) {
//        rootVector.push_back(&root->next[i]);
//    }
//    delete [] root->next;

    int idx = 0;
    vector<node> queue;
    node *root = new node[1];
    root->data = arr[idx++];
    root->next = new node[3];
    for (int i = 0;i<3;i++){
        root->next[i].data = arr[idx++];
        root->next[i].prev = root;
        queue.push_back(root->next[i]);
    }
    int *height = new int;
    *height = h-1;
    vector<node> temp;
//    node tempVar;
    while(1)
    {
        if(*height == 0){break;}
        for (int i = 0;i<queue.size();i++){
          queue[i].next = new node[o];
//          queue[i].next[o];
//            tempVar = queue[i];
          for(int j = 0;j<o;j++){
//              queue[i].next[j].prev = &tempVar;
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

//    insertDataOfCayleyTree(root,arr, o, h);

    delete height;

    return root;
}


//node insertDataOfCayleyTree(node *head, int*arr, int o, int h)
//{
  //  vector<node> QQ;
   // QQ.push_back(*head);
   // i//nt idx = 0;
   // while(QQ.size()){
 //       QQ.begin()->data = arr[idx++];
//
//        }
//    }
//}

