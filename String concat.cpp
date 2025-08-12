#include <iostream>
using namespace std;

void Reverse(string &s) {
    int n = s.size();
    for(int i = 0; i < n / 2; i++) {
        swap(s[i], s[n - 1 - i]);
    }
}

void Vowels(string &s){
	int j = 0;
    for (int i = 0; i < s.size(); i++) {
        char lower = tolower(s[i]); 
        if (lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u') {
            s[j++] = s[i];  
        }
    }
    s.resize(j);
	}

int main() {
    string a = "Rudraksh";
    string b = "chugh";
    string c = a + b;
    cout << c << endl; 

    Reverse(c);
    cout << c << endl;  
    
    Vowels(c);
    cout << c << endl;  
    return 0;
}

