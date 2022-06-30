#include "TrieNode.h"
#include<string>
#include<iostream>
using namespace std;

class trie{

  TrieNode*root;
  
  public:
  trie(){
    root=new TrieNode('\0');
  }
 
  private:
  void insertWordHelper(TrieNode*root,string word){
     if (word.size()==0)
     {
        root->isTerminal=true;
        return;
     }
     int index=word[0]-'a';
     if (root->child[index]==nullptr)
     {
        root->child[index]=new TrieNode(word[0]);
     }
     
     insertWordHelper(root->child[index],word.substr(1));
  }
  bool searchHelper(TrieNode*root,string word){
    if (word.size()==0)
    {
        if (root->isTerminal)
        {
           return true;
        }
        
        return false;
    }

    int index=word[0]-'a';
    
    if (root->child[index]==nullptr)
    {
       return false;
    }
    return searchHelper(root->child[index],word.substr(1));
  }
  void removeWordHelper(TrieNode*root,string word){
    if (word.size()==0)
    {
        root->isTerminal=false;
        return;
    }
    int index=word[0]-'a';
    if(root->child[index]==nullptr){
        return;
    }
    removeWordHelper(root->child[index],word.substr(1));
    if (root->child[index]->isTerminal==false)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->child[index]->child[i]!=nullptr)
            {
                return;
            }
            
        }
        root->child[index]=nullptr;
        delete root->child[index];
    }
    
  }
 
  public:
  void insertWord(string word){
    return insertWordHelper(root,word);
  }
  bool search(string word){
    return searchHelper(root,word);
  }
  void removeWord(string word){
   return  removeWordHelper(root,word);
  }


};