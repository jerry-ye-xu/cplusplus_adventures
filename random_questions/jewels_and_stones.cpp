
#include <iostream>
// #include <set>
#include <unordered_set>
#include <vector>

using namespace std;

int jewels_and_stones(string jewel, string stone);

int unique_emails(vector<string>& emails);

int main(){
	string jewel = "a";
	string stone = "aqrwewfwaewtregbarewrwerdaaaa";

	int ret = jewels_and_stones(jewel, stone);
	cout << ret << endl;

	// vector<string> emails = {"hi", "my", "name", "is", "jerry"};

	// number_unique_emails(emails);

	return 0;
}

int jewels_and_stones(string jewel, string stone){
	int jewel_count = 0;

	unordered_set<char> jewels(jewel.begin(), jewel.end()); // iterators for a vector/array
	for(char s: stone){
		if(jewels.count(s)){
			jewel_count++;
		}
	}
	return jewel_count;
}

/* 
can eliminate a few lines of code just by:
	for(char s: stone) if jewel.count(s) jewel_count++;
*/