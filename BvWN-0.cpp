#include <iostream>
#include <algorithm>
using namespace std;

void createCode(int code[], int length);
void compare(int guesses[], int code[], int length);

int main(){
	int length;

	for(int i = 1;; i++){
		cin >> length;
		if(length < 1){break;}
		int code[length];
		createCode(code, length);
		cout << "Game " << i << ":" << endl;
		int guesses[length]; createCode(guesses, length);
		while(guesses[0] != 0){
			compare(guesses, code, length);
			createCode(guesses, length);
		}

	}

	return 0;
}

void createCode(int code[], int length){
	for(int s = 0; s < length; s++){
			cin >> code[s];
	}
}

void compare(int guesses[], int code[], int length){
	int A = 0;
	int B = 0;
	int temp[length];
	//compare the same position
	for(int i = 0; i < length; i++){
		if(code[i] == guesses[i]){
			A++;
			temp[i] = -1; guesses[i] = -1;
		}else{
			temp[i] = code[i];
		}
	}
	//compare not in same position but same
	for(int i = 0; i < length; i++){
		if(guesses[i] != -1){
			int *position = find(temp, temp + length, guesses[i]);
			if(position != temp + length){
				B++;
				*position = -1;
				guesses[i] = -1;
			}
		}
	}

	cout << "    (" << A << "," << B << ")" << endl;
}
