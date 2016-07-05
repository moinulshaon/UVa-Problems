#include <iostream>
#include <string>
using namespace std;

string preorder,inorder,postorder;
struct node
{
      char info;
      node *left;
      node *right;
};
int pre;

node* construct_tree(int inStart, int inFinal)
{
    if(inStart>inFinal)
    {
        return NULL;
    }
    int i,inIndex;
    node *temp=new node;
    temp->info=preorder[pre++];
    for(i=inStart;i<=inFinal;i++)
    {
         if(inorder[i]==temp->info)
         {
              inIndex=i;
         }
    }
    temp->left=construct_tree(inStart,inIndex-1);
    temp->right=construct_tree(inIndex+1,inFinal);
    return temp;
}

void postorder_traversal(node *r) {

    if(r==NULL)
         return;
    postorder_traversal(r->left);

    postorder_traversal(r->right);
    cout<<r->info;
} int main() {


   while(cin>>preorder>>inorder)
   {
         int len_in=inorder.length();
         pre=0;
         node *root=construct_tree(0,len_in-1);
         postorder_traversal(root);
         cout<<endl;
   }

   return 0;
}
