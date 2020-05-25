//implementing the trie solution here
#include<bits/stdc++.h>
using namespace std;

struct node
{
    struct node *character[26];
    bool isend;
};

struct node* getnode()
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->isend = false;
    for(int i=0;i<26;i++){
        newnode->character[i] = NULL;
    }
    return newnode;
}

void add(struct node *root,string s)
{
    struct node *temp = root;
    for(int i=0;i<s.length();i++){
        int index = (int)s[i] - (int)'a';
        if(temp->character[index]==NULL)
            temp->character[index] = getnode();
        temp = temp->character[index];
        temp->isend = false;
    }
    temp->isend = true;
}

void display(struct node *root,char s[],int index)
{
    if(root->isend == true){
        s[index] = '\0';
        cout<<s<<endl;
        return;
    }

    for(int i=0;i<26;i++){
        if(root->character[i]!=NULL){
            char c = i + 'a';
            s[index] = c;
            display(root->character[i],s,index+1);
        }
    }
    return;
}

void see(struct node *root,string s)
{
    struct node *temp = root;
    for(int i=0;i<s.length();i++){
        int index = (int)s[i] - (int)'a';
        if(temp->character[index] == NULL){
            cout<<"\n Sorry !!! no relevant prefix matches found :( \n";
            return;
        }
        temp = temp->character[index];
    }
    char ss[100];
    for(int i=0;i<s.length();i++){
        ss[i] = s[i];
    }
    int n = s.length();
    display(temp,ss,n);
}

int main()
{
    int nooftestcases;
    cin>>nooftestcases;

    while(nooftestcases--){

        struct node *root = getnode();
        for(int i=0;i<5;i++){
            string temp;
            cin>>temp;
            add(root,temp);
        }
        printf("\n printing the trie data structure here \n");
        char s[100];
        display(root,s,0);

        printf("\n please enter the prefix computation string \n");
        string pre;
        cin>>pre;
        see(root,pre);
        printf("\n printing the results according to the prefix's :\n");
        free(root);
    }
}
