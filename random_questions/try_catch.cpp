
#include <iostream>

using namespace std;

int main(){
	
	try{
		int num1;
		cout << "Enter a number" << endl;
		cin >> num1;

		int num2;
		cout << "Enter a number" << endl;
		cin >> num2;

		if(num2 == 0){
			throw num2;
		} 

		return num1/num2;
	} catch(int x){
		cout << "You can't divide by " << x << endl;
	}

	return 0;
}