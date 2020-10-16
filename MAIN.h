#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include<iostream>
#include "AVL.h"
using namespace std;

template<class T>
class avlTree
{
        avl<T>t;
        T key;

        public:
        bool Empty()
        {
            node<T>*p = t.getRoot();
            if(p == NULL)
                return true;
            return false;
        }

        void Clear()
        {
            node<T>*p = t.getRoot();
            t.deleteAll(p);
            t.setRoot(NULL);
        }

        bool Contain( T key)
        {
            node<T>*p=t.getRoot();
            node<T>*q = t.Isearch(p,key);
            if(q == NULL)
                return false;
            return true;
        }

        bool Recursive_Contain( T key)
        {
            node<T>*p=t.getRoot();
            node<T>*q = t.Rsearch(p,key);
            if(q == NULL)
                return false;
            return true;
        }

        void Insert(T key)
        {
            node<T>*p=t.getRoot();
            node<T>*q = t.Rinsert(p, key);
            t.setRoot(q);
        }

        void Delete(T key)
        {
            node<T>*p=t.getRoot();
            node<T>*q = t.Rdelete(p, key);
            t.setRoot(q);
        }


        int Tree_Height(){
            node<T>*p = t.getRoot();
            return t.Height(p);
        }

        vector<T> Preorder(){
           node<T>*p=t.getRoot();
           vector<T>res;
           t.preorder(p,res);
           return res;
        }

        vector<T> Postorder(){
           node<T>*p=t.getRoot();
           vector<T>res;
           t.postorder(p,res);
           return res;
        }

        vector<T> Inorder(){
           node<T>*p=t.getRoot();
           vector<T>res;
           t.inorder(p,res);
           return res;
        }

        int Count()
        {
            node<T>*p = t.getRoot();
            return t.countNode(p);
        }

        int Count_Internal_Node()
        {
            node<T>*p = t.getRoot();
            return t.countInternalNode(p);
        }

        int count_Leaf_Node()
        {
             node<T>*p = t.getRoot();
            return t.countLeafNode(p);
        }

        T tree_Sum()
        {
          node<T>*p = t.getRoot();
          return  t.treeSum(p);
        }

        int Count_Deg_One_Node()
        {
          node<T>*p = t.getRoot();
          return  t.countDegOneNode(p);
        }

        int Count_Deg_Two_Node()
        {
          node<T>*p = t.getRoot();
         return t.countDegTwoNode(p);
        }


        void Help()
        {

        cout<<"bool Empty()"<<endl;
        cout<<"void Clear()"<<endl;
        cout<<"bool Contain( T key)"<<endl;
        cout<<"bool Recursive_Contain( T key)"<<endl;
        cout<<"void Insert(T key)"<<endl;
        cout<<"void Delete(T key)"<<endl;
        cout<<"int Tree_Height()"<<endl;
        cout<<"vector<T> Postorder()"<<endl;
        cout<<"vector<T> Inorder()"<<endl;
        cout<<"int Count()"<<endl;
        cout<<"int Count_Internal_Node()"<<endl;
        cout<<"int count_Leaf_Node()"<<endl;
        cout<<"T tree_Sum()"<<endl;
        cout<<"int Count_Deg_One_Node()"<<endl;
        cout<<"int Count_Deg_Two_Node()"<<endl;



       }



};

#endif // MAIN_H_INCLUDED
