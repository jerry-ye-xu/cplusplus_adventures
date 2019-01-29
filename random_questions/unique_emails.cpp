
#include <iostream>
// #include <set>
#include <unordered_set>
#include <vector>

using namespace std;

int unique_emails(vector<string>& emails);

int main(){

	// vector<string> emails = {"hi", "my", "name", "is", "jerry"};

	// number_unique_emails(emails);

	return 0;
}

int number_unique_emails(vector<string>& emails){
	// we use & as we pass through a pointer, because function parameters are pass by value. 
	// (A copy is created instead)

	set<string> unique_emails;

	for(string e: emails){
		cout << e << endl;
	}
}