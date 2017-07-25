//Let 1 represent ‘A’, 2 represents ‘B’, etc. Given a digit sequence, count the number of possible decodings of the given digit sequence.

//Examples:

//Input:  digits[] = "121"
//Output: 3
// The possible decodings are "ABA", "AU", "LA"

//Input: digits[] = "1234"
//Output: 3
// The possible decodings are "ABCD", "LCD", "AWD"

#include<iostream>
#include<string>
#include<map>
using namespace std;

map<int, char> alphadict;

int charToInt(char x){return x-'0';}

void createDict(map<int, char> &dict){
    for(int i=65;i<=91;i++)dict[i-64] = char(i);
}

void printPossibleDecode(string code, string decode=""){
    if(code == "")cout<<decode<<" ";
    else{
        if(code[1]=='\0'){  //marks end of code string
            printPossibleDecode("", decode+alphadict[charToInt(code[0])]);
        }
        else{
            if(code[0]=='1'||(code[0]=='2'&&code[1]<'7')){   //check for 2 digit key values in the dictionary
                printPossibleDecode(code.substr(2), decode+alphadict[charToInt(code[0])*10+charToInt(code[1])]);
            }
            printPossibleDecode(code.substr(1), decode+alphadict[charToInt(code[0])]);
        }
    }
}

int main(){

    string inp;
    cout<<"Given decoding dictionary : {1:A 2:B 3:C 4:D 5:E 6:F 7:G 8:H 9:I 10:J 11:K 12:L 13:M 14:N 15:O 16:P 17:Q 18:R 19:S 20:T 21:U 22:V 23:W 24:X 25:Y 26:Z}\n Enter valid code string of integers to be decoded:";
    cin>>inp;
    createDict(alphadict);
    cout<<"The possible decoded values are:\n";
    printPossibleDecode(inp);
    return 0;
}
