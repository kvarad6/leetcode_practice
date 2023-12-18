#include <bits/stdc++.h> 

void solve(string output, vector<string>& ans, int index, string str){
	//base case
	if(index>=str.length())
		{
			if(output.length()>0){
				ans.push_back(output);
			}
			return;
		}
	
	//exclude
	solve(output, ans, index+1, str);
	//include
	char element = str[index];
	output.push_back(element);
	solve(output, ans, index+1, str);
	
}
vector<string> subsequences(string str){
	vector<string> ans;
	string output = "";
	int index = 0;
	solve(output, ans, index, str);
	return ans;
}
