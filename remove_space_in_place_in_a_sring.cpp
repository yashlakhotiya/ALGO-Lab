#include <iostream>
#include <map>

using namespace std;

void frequency_find(map<char,int> &mp, string s){
	//count the frequency of each and every character
	for(char c: s){
		auto itr = mp.find(c);
		if(itr == mp.end()){
			mp.insert(make_pair(c,1));
		}
		else{
			(*itr.second)++;
		}
	}
}

void print_frequency(map<char,int> &mp){
	for(int i=0; i<mp.size(); i++){
		cout<<mp[i].first<<" : "<<mp[i].second;
	}
}

int main(){
	string s;
	cin>>s;
	map<char,int> mp;
	frequency_find(mp,s);
	print_frequency(mp);
	return 0;
}