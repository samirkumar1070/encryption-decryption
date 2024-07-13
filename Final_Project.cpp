#include<bits/stdc++.h>
using namespace std;
class endec{
	string message;
	map<char,char> keyMap;
	public:
		endec(string str):message(str){}
		string encrypt();
		string decrypt(string);
		int counter();
};

// ------------------------------------------<RANDOM FUNCTION>------------------------------------------
int endec:: counter() 
{   
    srand(time(0));
    return (rand() % 15) + 32;
}

// ---------------------------------------------<ENCRYPTION>---------------------------------------------

string endec::encrypt(){
    
    string alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ!><+*(){}[],.:;?/abcdefghijklmnopqrstuvwxyz@$%&*";
    string shuffled=alphabet;
    random_shuffle(shuffled.begin(),shuffled.end());
    for (long long unsigned int i=0;i<alphabet.length();i++) {
        keyMap[alphabet[i]] = shuffled[i];
    }
    string s = "";
    for (char c : message) {
        auto it = keyMap.find(c);
        if (it != keyMap.end()) {
            s += it->second;
        } else {
            s += c;
        }
    }
    /*cout << "Key Map:" << endl;
    for (auto it = keyMap.begin(); it != keyMap.end(); it++) {
        cout << it->first << " -> " << it->second << endl;
    }*/
	int n=s.length();
	string enc;
	char ch;
	int i,j;
	int k=counter()-32;
	for(i=0,j=k; i<n; i++,j++){
		switch(j)
		{
			case 1:ch=(s[i]-6);
			        break;
			case 2:ch=s[i]+3;
			        break;  
			case 3:ch=(s[i]+8);
			        break;
			case 4:ch=(s[i]+2);
			        break;
			case 5:ch=(s[i]+3);
			        break;
			case 6:ch=(s[i]-6);
			        break;
			case 7:ch=(s[i]+3);
			        break;
			case 8:ch=(s[i]+12);
			        break;
			case 9:ch=(s[i]-10);
			        break;
			case 10:ch=(s[i]+7);
			        break;
			case 11:ch=(s[i]+13);
			        break;
			case 12:ch=(s[i]-15);
			        break;
			case 13:ch=(s[i]-10);
			        break;
		    case 14:ch=(s[i]+18);
			        break;
		    case 15:ch=(s[i]-14);
			        break;		
		}
		enc+=ch;
		j=j%15;
	}
	return char(k+32)+enc;
}

// -------------------------------------------<DECRYPTION>--------------------------------------------------------

string endec::decrypt(string s){
	int n=s.length();
	string dec;
	char ch;
		int i,j;
		int k=int(s[0])-32;
	for(i=1,j=k; i<n; i++,j++){
		switch(j)
		{
			case 1:ch=(s[i]+6);
			        break;
			case 2:ch=(s[i]-3);
			        break; 
			case 3:ch=(s[i]-8);
			        break;
			case 4:ch=(s[i]-2);
			        break;
			case 5:ch=(s[i]-3);
			        break;
			case 6:ch=(s[i]+6);
			        break;
			case 7:ch=(s[i]-3);
			        break;
			case 8:ch=(s[i]-12);
			        break;
			case 9:ch=(s[i]+10);
			        break;
			case 10:ch=(s[i]-7);
			        break;
			case 11:ch=(s[i]-13);
			        break;
			case 12:ch=(s[i]+15);
			        break;
			case 13:ch=(s[i]+10);
			        break;
			case 14:ch=(s[i]-18);
			        break; 
			case 15:ch=(s[i]+14);
			        break;     
		}
		dec+=ch;
		j=j%15;
	}
	string decrypted = "";
    map<char, char> reverseKeyMap;
    for (auto it = keyMap.begin(); it != keyMap.end(); it++) {
        reverseKeyMap[it->second] = it->first;
    }
    for (char c : dec) {
        auto it = reverseKeyMap.find(c);
        if (it != reverseKeyMap.end()) {
            decrypted += it->second;
        } else {
            decrypted += c;
        }
    }
    return decrypted;
}

int main(){
	int ch;
	string text;
	cout<<"\n1.Encrypt\n2.Decrypt\n3.Exit\n";
	cout<<"Enter your messege : ";
	getline(cin,text);
	endec message(text);
	while(1){
	cout<<"\nEnter choice : ";
	cin>>ch;
		switch(ch){
			case 1:{
				cout<<"\nText Encrypted Successfuly!!!"<<endl;
				cout<<"Encrypted Text : "<<message.encrypt();
				break;
			}
			case 2:
				cout<<"Text Decrypted Successfully!!!"<<endl;
				cout<<"Decrypted text : ";
				cout<<message.decrypt(message.encrypt());
				break;
			case 3:
				exit(1);
			default:
				cout<<"Invalid Choice!";		
		}
	}
	return 0;
}
