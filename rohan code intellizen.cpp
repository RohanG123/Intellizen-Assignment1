#include<iostream>
#include<string>

using namespace std;

int main(){
	int numTestCases;
	string pattern, textLine;
	cin>>numTestCases;
	while(numTestCases--){
		cin>>pattern>>textLine;
		int cntAlphabetsPattern[26]={0};
		int cntAlphabetsText[26]={0};
		int patternLen = pattern.size();
		int textLineLen = textLine.size();

		if(textLineLen < patternLen){
			cout<<"NO"<<endl;
			continue;
		} 

		// counts the occurrence of each letter in the pattern
		for(int idx=0; idx<patternLen; idx++)
			cntAlphabetsPattern[pattern[idx]-'a']++;


		// counts the occurrence of each letter in the first patternLen characters in textLine
		for(int idx=0; idx<patternLen; idx++)
			cntAlphabetsText[textLine[idx]-'a']++;

		//check if the count matches.
		// if the count matches, it means that a permutation exists.
		bool exists = true;
		for(int idx=0; idx<26; idx++){
			if(cntAlphabetsText[idx] != cntAlphabetsPattern[idx])
			{
				exists = false;
				break;
			}
		}
		if(exists){
			cout<<"YES"<<endl;
			continue;
		}

		//if the permutation does not exist,
		// remove one letter from the beginning and add one letter from the currentIdx
		// check if that is a permutation
		for(int idx=patternLen; idx<textLineLen; idx++){
			exists = true;
			cntAlphabetsText[textLine[idx - patternLen] - 'a']--;
			cntAlphabetsText[textLine[idx] - 'a']++;
			
			// /check if the count matches.
			// if the count matches, it means that a permutation exists.
			for(int i=0; i<26; i++){
				if(cntAlphabetsText[i] != cntAlphabetsPattern[i])
				{
					exists = false;
					break;
				}
			}
			if(exists){
				cout<<"YES"<<endl;
				break;
			}
		}
		if(!exists)
			cout<<"NO"<<endl;
	}
	return 0;
}