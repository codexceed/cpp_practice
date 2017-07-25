#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


//Function to split a string text into a vector of string values split by a specific delimiter(defaults to single whitespace)
vector<string> strSplit(string s, char del=' '){
	vector<string> out_arr;
	string word;
	int i=0;
	while(s[i]){
        if(s[i]==del){
	    if(word!=""){
            out_arr.push_back(word);
            word="";}
            i++;
            continue;
        }
        word+=s[i];
        i++;
	}
	out_arr.push_back(word);
	return out_arr;

}


//Structure to hold an hrml tag, with attributes stored in a string map and a vector of pointers to its children tags
struct textOb{
    map<string, string> attrib;
    vector<textOb*> subObs;
};


//Generates hrml objects using the above mentioned structure using string vector form of the hrml text as input
textOb* genObs(vector<string> inText){
    textOb *newTag = new textOb;
    newTag->attrib["id"] = strSplit(inText[0], '<')[0];
    int flag=0;
    string attName;
    for(vector<string>::iterator it=inText.begin()+1;it!=inText.end();it++){
        if(*it=="="){
           flag = 1;
           continue;
        }
        if(!flag)attName = *it;
        else{
            newTag->attrib[attName] = strSplit(strSplit(*it, '>')[0], '"')[0];
            flag = 0;
        }
    }
    return newTag;
}

textOb* genTree(vector<string> hrmlText, int head){
    textOb *parentOb, *childOb;
    int flag = 0;
    parentOb = genObs(strSplit(hrmlText[head]));
    string tagText;
    int i=head+1;
    while(hrmlText[i]!="</"+parentOb->attrib["id"]+">"){
        childOb = genTree(hrmlText, i);
        parentOb->subObs.push_back(childOb);
        while(hrmlText[i]!="</"+childOb->attrib["id"]+">")i++;
        i++;
    }
    return parentOb;
}

void printQuery(string query, textOb* parent){
    vector<string> tags = strSplit(query, '.');

    if(tags.size()==1){
        vector<string> elems = strSplit(query, '~');
        if(parent->attrib["id"]==elems[0]&&parent->attrib.count(elems[1])>0)cout<<parent->attrib[elems[1]]<<"\n";
        else cout<<"Not Found!\n";
    }

    else{
        string childID = tags[1];
        int j;
        for(j=0;j<parent->subObs.size();j++)if(parent->subObs[j]->attrib["id"]==strSplit(childID, '~')[0])break;
        if(j<parent->subObs.size())printQuery(query.substr(tags[0].size()+1), parent->subObs[j]);
        else cout<<"Not Found!\n";
    }
}

int main(){
    int n,q;
    cin>>n>>q;
    vector<string> hrml;
    string text;
    getline(cin, text);
    for(int i=0;i<n;i++){
        getline(cin, text);
        hrml.push_back(text);
    }
    textOb *data = genTree(hrml, 0);
    for(int j=0;j<q;j++){
        getline(cin, text);
        printQuery(text, data);
    }

    return 0;
}

