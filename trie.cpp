// implementing the trie data struture
#include<bits/stdc++.h>
using namespace std;

struct node
{
    struct node *character[26];
    bool isend;
};

struct node *getnode()
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    for(int i=0;i<26;i++){
        newnode->character[i] = NULL;
    }
    newnode->isend = false;
    return newnode;
}

void add(struct node *head,string s)
{
    struct node *temp = head;
    for(int i=0;i<s.length();i++){
        int index = s[i] - (int)'a';
        if(temp->character[index]==NULL){
            temp->character[index] = getnode();
        }
        temp = temp->character[index];
    }
    temp->isend = true;
}

void display(struct node *head,string s)
{
    if(head->isend == true){
        cout<<s<<endl;
    }

    for(int i=0;i<26;i++){
        if(head->character[i]!=NULL){
            char c = i+'a';
            display(head->character[i],s+c);
        }
    }
}

void cal(struct node *temp,string pre)
{
    if(temp->isend == true){
        cout<<pre<<endl;
    }

    for(int i=0;i<26;i++){
         if(temp->character[i]!=NULL){
            char c = i+'a';
            display(temp->character[i],pre+c);
        }
    }
}


void trie_search(struct node *head,string pre)
{
    struct node *temp = head;
    for(int i=0;i<pre.length();i++){
        int index = pre[i] - (int)'a';
        if(temp->character[index]==NULL){
            cout<<"Sorry !!! No such prefix is found in the trie "<<endl;
            return;
        }
        temp = temp->character[index];
    }

    cal(temp,pre);
}

void solve()
{
    int n;
    cout<<"please enter the number of strings :\n";
    cin>>n;

    struct node *head = getnode();
    while(n--){
        string s;
        cin>>s;
        add(head,s);
    }

    cout<<"Printing the trie elements here \n";
    string s = "";
    display(head,s);

    string pre;
    cout<<"Please enter the prefix for search : "<<endl;
    cin>>pre;

    trie_search(head,pre);
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
