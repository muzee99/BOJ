// BOJ1068_트리
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, E, root, count=0;
int parentInfo[55];
struct Node
{
    int data;
    int isErase;
    vector<Node*> child;
};
Node Tree[55];

void findLeaf() {
    for(int i=0; i<N; i++) {
        int j=0;
        for(j=0; j<Tree[i].child.size(); j++) {
            if(!Tree[i].child[j]->isErase) break;
        }
        if((j==Tree[i].child.size() || Tree[i].child.empty()) && !Tree[i].isErase) count++;
    }
}

void eraseNode(int e) {
    queue<int> q;
    q.push(e);
    Tree[e].isErase = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i=0; i<Tree[x].child.size(); i++) {
            if(!Tree[x].child[i]->isErase) {
                q.push(Tree[x].child[i]->data);
                Tree[x].child[i]->isErase=true;
            }
        }
    }
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> parentInfo[i];
    }
    cin >> E;

    for(int i=0; i<N; i++) {
        Tree[i].data = i;
        if(parentInfo[i]==-1) root = i;
        else {
            Tree[parentInfo[i]].child.push_back(&Tree[i]);
        }
    }
    eraseNode(E);
    findLeaf();
    cout << count;
    return 0;
}