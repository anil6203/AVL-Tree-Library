#include <iostream>
#include "MAIN.h"

using namespace std;

// call method Help() to know all methods

int main()
{

  avlTree <int> tree;
  tree.Insert(5);
  tree.Insert(4);
  tree.Insert(6);
  tree.Insert(3);
  tree.Delete(3);
  tree.Insert(2);
  tree.Insert(4);


  cout<<" contain : "<<tree.Contain(3)<<endl;

  cout<<tree.count_Leaf_Node()<<endl;
  cout<<tree.Count_Internal_Node()<<endl;
  cout<<tree.Count_Deg_One_Node()<<endl;
  cout<<tree.Count_Deg_Two_Node()<<endl;
  cout<<tree.Tree_Height()<<endl;


  cout<<tree.Empty()<<endl;
  vector<int>res = tree.Inorder();
  for(auto x : res)
  cout<<x<<" ";
  cout<<endl;
  res.clear();
  res = tree.Preorder();
  for(auto x : res)
        cout<<x<<" ";
  cout<<endl;
  res.clear();
  res = tree.Postorder();
  for(auto x : res)
        cout<<x<<" ";
  cout<<endl;


 return 0;

}
