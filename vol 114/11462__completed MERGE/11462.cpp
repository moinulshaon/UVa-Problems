#include <cstdio>
#include <algorithm>

using namespace std;

struct node{


    node(node* p,int v){
        parent=p;
        val=v;
        height=1;

        leftChild=rightChild=NULL;
    }

    int val;
    int height;

    node* leftChild;
    node* rightChild;
    node* parent;

};

node *root;


int heightFunc(node *n){
    if (n==NULL)return 0;
    else return n->height;
}


void singleRotateRight(node *z){

    node *y=z->leftChild;

    z->leftChild=y->rightChild;
    if (z->leftChild!=NULL)
        z->leftChild->parent=z;

    if (z->parent!=NULL && z->parent->leftChild== z){
        z->parent->leftChild=y;
    }
    else if ( z->parent!=NULL ){
        z->parent->rightChild=y;
    }
    else{
        root=y;
    }
    y->parent=z->parent;

    y->rightChild=z;
    z->parent=y;

    z->height=max( heightFunc( z->leftChild),heightFunc( z->rightChild) ) + 1;
    y->height=max( heightFunc( y->leftChild),heightFunc( y->rightChild) ) + 1;
}

void singleRotateLeft(node *z){



    node *y=z->rightChild;

    z->rightChild=y->leftChild;
    if (z->rightChild!=NULL)
        z->rightChild->parent=z;

    if (z->parent!=NULL && z->parent->leftChild== z){
        z->parent->leftChild=y;
    }
    else if ( z->parent!=NULL ){
        z->parent->rightChild=y;
    }
    else{
        root=y;
    }
    y->parent=z->parent;

    y->leftChild=z;
    z->parent=y;

    z->height=max( heightFunc( z->leftChild),heightFunc( z->rightChild) ) + 1;
    y->height=max( heightFunc( y->leftChild),heightFunc( y->rightChild) ) + 1;
}


void doubleRotateRight(node *z){
    singleRotateLeft(z->leftChild);
    singleRotateRight(z);
}

void doubleRotateLeft(node *z){
    singleRotateRight(z->rightChild);
    singleRotateLeft(z);
}

void insertion(node *now,int v){

    if (v < now->val){

        if (now->leftChild!=NULL){
            insertion(now->leftChild,v);
        }
        else{
            now->leftChild=new node(now,v);
        }

        if ( heightFunc(now->leftChild) - heightFunc(now->rightChild)==2 ){
            if (v <now->leftChild->val)
                singleRotateRight(now);
            else
                doubleRotateRight(now);

        }
    }
    else if (v >= now->val){

        if (now->rightChild!=NULL){
            insertion(now->rightChild,v);
        }
        else{
            now->rightChild=new node(now,v);
        }
        if ( heightFunc(now->rightChild) - heightFunc(now->leftChild)==2 ){
            if (v > now->rightChild->val)
                singleRotateLeft(now);
            else
                doubleRotateLeft(now);
        }
    }

    now->height=max( heightFunc( now->leftChild),heightFunc( now->rightChild) ) + 1;

}

bool on;
void inorderTraversal(node *now)
{
    if ( now->leftChild!=NULL )
        inorderTraversal(now->leftChild);
    if (on)
        printf("%d",now->val);
    else
        printf(" %d",now->val);
    on=false;
    if ( now->rightChild !=NULL )
        inorderTraversal(now->rightChild);
    delete now;
}



int main(){

    freopen("in.txt","r",stdin);

    int tmp,a;



    while (scanf("%d",&tmp)==1 && tmp){
        for (bool r=true;tmp--;r=false){
            scanf("%d",&a);
            if (r)
                root=new node(NULL,a);
            else
                insertion(root,a);
        }
        on=true;
        inorderTraversal(root);
        printf("\n");
        delete root;

    }

    return 0;

}
