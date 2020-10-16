#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<class T>
class node
{
public:
 T data;
 int height;
 node*left;
 node*right;
};

template <class T>
class avl
{
 private:
            node<T>*root;
 public:

            avl(){root=nullptr;}
            node<T>*getRoot(){return root;}
            void setRoot(node<T>*p){root = p;}
            node<T>*Rsearch(node<T>*p,T key);
            node<T>*Isearch(node<T>*p,T key);
            node<T>*Rinsert(node<T>*p,T key);
            node<T>*InSucc(node<T>*p);
            node<T>*InPredsucc(node<T>*p);
            node<T>*Rdelete(node<T>*p, T key);
            int nodeHeight(node<T>*p);
            int BF(node<T>*p);//binary factor
            node<T>*LLrotation(node<T>*p);
            node<T>*RRrotation(node<T>*p);
            node<T>*LRrotation(node<T>*p);
            node<T>*RLrotation(node<T>*p);
            int Height(node<T>*p);
            void preorder(node<T>*p,vector<T>&pre);
            void inorder(node<T>*p,vector<T>&in);
            void postorder(node<T>*p,vector<T>&post);
            int countNode(node<T>*p);
            int countInternalNode(node<T>*p);
            int countLeafNode(node<T>*p);
            int countDegOneNode(node<T>*p);
            int countDegTwoNode(node<T>*p);
            node<T>*deleteAll(node<T>*p);
 };



 template<class T>
int avl<T>::countNode(node<T>*p)
{
     int x,y;
     if(p)
     {
        x=countNode(p->left);
        y=countNode(p->right);
        return x+y+1;
     }
     return 0;
}

template<class T>
int avl<T>::countInternalNode(node<T>*p)
{
    int x,y;
    if(p)
    {
    x=countInternalNode(p->left);
    y=countInternalNode(p->right);
    if(p->left!=nullptr || p->right!=nullptr)
    return x+y+1;
    else
    return x+y;
    }
    return 0;

}
template<class T>
int avl<T>::countLeafNode(node<T>*p)
{
   int x,y;
   if(p)
   {
    x=countLeafNode(p->left);
    y=countLeafNode(p->right);
    if(p->left==nullptr && p->right==nullptr)
    return x+y+1;
    else
    return x+y;
   }
   return 0;
}

template<class T>
int avl<T>::countDegOneNode(node<T>*p)
{
    int x,y;
    if(p)
    {
    x=countDegOneNode(p->left);
    y=countDegOneNode(p->right);
    if(p->left!=nullptr^p->right!=nullptr)
    return x+y+1;
    else
    return x+y;
    }
    return 0;

}
template<class T>
int avl<T>::countDegTwoNode(node<T>*p)
{
    int x,y;
    if(p)
    {
    x=countDegTwoNode(p->left);
    y=countDegTwoNode(p->right);
    if(p->left!=nullptr && p->right!=nullptr)
    return x+y+1;
    else
    return x+y;
    }
    return 0;

}

template<class T>
node<T>*avl<T>::Isearch(node<T>*p,T key)
{
  if(p==nullptr)
   return nullptr;
   while(p!=nullptr)
   {
   if(p->data==key)
   return p;
   else if(p->data>key)
   p=p->left;
   else
   p=p->right;
   }
   return nullptr;
}





 template<class T>
 int avl<T>::nodeHeight(node<T>*p)
 {
    int hr,hl;
    hl=p && p->left?p->left->height:0;
    hr=p && p->right?p->right->height:0;
    return hl>hr?hl+1:hr+1;

 }
 template<class T>
 int avl<T>::BF(node<T>*p)
 {
    int hr,hl;
    hl=p && p->left?p->left->height:0;
    hr=p && p->right?p->right->height:0;
    return hl-hr;
 }
 template<class T>
 node<T>*avl<T>::LLrotation(node<T>*p)
 {
 node<T>*pl=p->left;
 node<T>*plr=pl->right;
 pl->right=p;
 p->left=plr;

 p->height=nodeHeight(p);
 pl->height=nodeHeight(pl);
 if(root==p)
  root=pl;
  return pl;

 }
 template<class T>
 node<T>*avl<T>::RRrotation(node<T>*p)
 {
    node<T>*pr=p->right;
    node<T>*prl=pr->left;
    pr->left=p;
    p->right=prl;

    p->height=nodeHeight(p);
    pr->height=nodeHeight(pr);
    if(root==p)
    root=pr;
    return pr;

 }
 template<class T>
 node<T>*avl<T>::LRrotation(node<T>*p)
 {
   node<T>*pl=p->left;
   node<T>*plr=pl->right;
   pl->right=plr->left;
   p->left=plr->right;
   plr->left=pl;
   plr->right=p;

   p->height=nodeHeight(p);
   pl->height=nodeHeight(pl);
   plr->height=nodeHeight(plr);

   if(p==root)
   root=plr;
   return plr;
 }
 template<class T>
 node<T>*avl<T>::RLrotation(node<T>*p)
 {
    node<T>*pr=p->right;
    node<T>*prl=pr->left;
    p->right=prl->left;
    pr->left=prl->right;
    prl->left=p;
    prl->right=pr;

    p->height=nodeHeight(p);
    pr->height=nodeHeight(pr);
    prl->height=nodeHeight(prl);

    if(p==root)
    root=prl;
    return prl;

 }

template<class T>
node<T>* avl<T>::Rsearch(node<T>*p,T key)
{
   if(p==nullptr)
   return nullptr;
   if(p->data==key)
   return p;
   else if(p->data>key)
   return Rsearch(p->left,key);
   else
   return Rsearch(p->right,key);
   return nullptr;
}
 template<class T>
 node<T>* avl<T>::Rinsert(node<T>*p,T key)
 {
   node<T>*t;
   node<T>*r=Isearch(p,key);
   if(r!=nullptr) return p;
       if(p==nullptr)
       {
        t=new node<T>;
        t->data=key;
        t->left=t->right=nullptr;
        t->height=1;
        p=t;
        return p;
       }
       else if(p->data>key)
       p->left=Rinsert(p->left,key);
       else
       p->right=Rinsert(p->right,key);

       p->height=nodeHeight(p);
       if(BF(p)==2 && BF(p->left)==1)
       return LLrotation(p);

       else if(BF(p)==-2 && BF(p->right)==-1)
       return RRrotation(p);

       else if(BF(p)==2 && BF(p->left)==-1)
       return LRrotation(p);

       else if(BF(p)==-2 && BF(p->right)==1)
       return RLrotation(p);

       return p;

 }

 template<class T>
 node<T>*avl<T>::Rdelete(node<T>*p, T key)
 {
     node<T>*r;
    if(p==NULL)
    return nullptr;
    node<T>*t=Isearch(p,key);
    if(t == nullptr) return p;
    if(p->left==nullptr && p->right==nullptr && p->data==key)
    {
      if(p==root)
       root=nullptr;
      delete p;
      return nullptr;

    }
    if(p->data>key)
    p->left=Rdelete(p->left,key);
    else if(p->data<key)
    p->right=Rdelete(p->right,key);
    else
    {
      if(Height(p->left)>Height(p->right))
      {
        r=InPredsucc(p->left);
        p->data=r->data;
        p->left=Rdelete(p->left,r->data);
      }
      else
      {

        r=InSucc(p->right);
        p->data=r->data;
        p->right=Rdelete(p->right,r->data);
      }
    }
    p->height=nodeHeight(p);
     if(BF(p)==2 && BF(p->left)==1)
       return LLrotation(p);
     else  if(BF(p)==2 && BF(p->left)==-1)
       return LRrotation(p);
      else if(BF(p)==2 && BF(p->left)==0)
       return LLrotation(p);
        else if(BF(p)==-2 && BF(p->left)==-1)
       return RRrotation(p);
        else if(BF(p)==-2 && BF(p->left)==1)
       return RLrotation(p);
        else if(BF(p)==-2 && BF(p->left)==0)
       return RRrotation(p);


    return p;
 }

 template<class T>
 int avl<T>::Height(node<T>*p)
 {
    int x,y;
    if(p)
    {
     x=Height(p->left);
     y=Height(p->right);
     if(x>y)
     return x+1;
     else
     return y+1;
    }
    return 0;

 }

 template<class T>
node<T>*avl<T>::InSucc(node<T>*p)
{
   while(p&& p->left!=nullptr)
   p=p->left;
   return p;

}
template<class T>
node<T>*avl<T>::InPredsucc(node<T>*p)
{
    while(p && p->right!=nullptr)
    p=p->right;
    return p;

}

template<class T>
void avl<T>::inorder(node<T>*p, vector<T>&in)
{
  if(p)
  {
    inorder(p->left,in);
    in.push_back(p->data);
    //cout<<"\t"<<p->data<<" ";
    inorder(p->right,in);
  }
}
template<class T>
void avl<T>::preorder(node<T>*p, vector<T>&pre)
{
  if(p)
  {

  //cout<<"\t"<<p->data<<" ";
  pre.push_back(p->data);
  preorder(p->left,pre);
  preorder(p->right,pre);
  }
}
template<class T>
void avl<T>::postorder(node<T>*p, vector<T>&post)
{
  if(p)
  {
    postorder(p->left,post);
    postorder(p->right,post);
    post.push_back(p->data);
    //cout<<"\t"<<p->data<<" ";
  }
}
template<class T>
node<T>* avl<T>::deleteAll(node<T>*p)
{
            queue<node<T>*>q;
            q.push(p);
            while(!q.empty())
            {
                node<T>* temp = q.front();
                q.pop();
                if(temp->right != nullptr)
                    q.push(temp->right);
                if(temp->left != nullptr)
                    q.push(temp->left);
                delete temp;

            }
            return nullptr;

}


#endif // AVL_H_INCLUDED

