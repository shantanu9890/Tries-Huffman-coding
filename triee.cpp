#include <iostream>
#include <string>
#include"trie.h"

using namespace std;

int main()
{
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
cin.tie(NULL);

trie t;
t.insertWord("shantanu");
t.insertWord("joshi");
t.insertWord("iitm");
t.insertWord("ep");
t.insertWord("snvp");
t.insertWord("bt");
cout<<t.search("shantanu")<<endl;
cout<<t.search("joshi")<<endl;
cout<<t.search("ap")<<endl;
cout<<t.search("ep")<<endl;
cout<<t.search("iitm")<<endl;
cout<<endl;
t.removeWord("ep");
t.removeWord("snvp");
t.removeWord("ap");
cout<<t.search("iitm")<<endl;
cout<<t.search("joshi")<<endl;
cout<<t.search("ep")<<endl;
cout<<t.search("snvp")<<endl;





return 0;
}