#include <iostream>
using namespace std;

// 1. Concatenate one string to another string
void concatenate(char str1[], const char str2[]) {
    int i = 0;
    while (str1[i] != '\0') i++; // find end of str1
    int j = 0;
    while (str2[j] != '\0') {
        str1[i++] = str2[j++];
    }
    str1[i] = '\0';
}

// 2. Reverse a string
void reverse(char str[]) {
    int n = 0;
    while (str[n] != '\0') n++;
    for (int i = 0; i < n / 2; ++i) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// 3. Delete all vowels from the string
void removeVowels(char str[]) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        char ch = str[i];
        ch = (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch; // lowercase
        if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

// 4. Sort strings in alphabetical order
void sortStrings(char arr[][100], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int k = 0;
            while (arr[i][k] == arr[j][k] && arr[i][k] != '\0' && arr[j][k] != '\0') k++;
            if (arr[i][k] > arr[j][k]) {
                char temp[100];
                int l = 0;
                while (arr[i][l] != '\0') { temp[l] = arr[i][l]; l++; }
                temp[l] = '\0';
                l = 0;
                while (arr[j][l] != '\0') { arr[i][l] = arr[j][l]; l++; }
                arr[i][l] = '\0';
                l = 0;
                while (temp[l] != '\0') { arr[j][l] = temp[l]; l++; }
                arr[j][l] = '\0';
            }
        }
    }
}

// 5. Convert char from uppercase to lowercase
char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') return ch + 32;
    return ch;
}

int main() {
    // Part (a) Concatenate
    char str1[200], str2[100];
    cout << "Enter first string: ";
    cin.getline(str1, 200);
    cout << "Enter second string: ";
    cin.getline(str2, 100);
    concatenate(str1, str2);
    cout << "Concatenated string: " << str1 << endl;

    // Part (b) Reverse
    char str3[100];
    cout << "Enter a string to reverse: ";
    cin.getline(str3, 100);
    reverse(str3);
    cout << "Reversed string: " << str3 << endl;

    // Part (c) Remove vowels
    char str4[100];
    cout << "Enter a string to delete vowels: ";
    cin.getline(str4, 100);
    removeVowels(str4);
    cout << "String without vowels: " << str4 << endl;

    // Part (d) Sort strings
    int n;
    cout << "Enter number of strings to sort: ";
    cin >> n; cin.ignore();
    char arr[n][100];
    for (int i = 0; i < n; ++i) {
        cout << "Enter string " << i+1 << ": ";
        cin.getline(arr[i], 100);
    }
    sortStrings(arr, n);
    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << endl;

    // Part (e) Uppercase to lowercase
    char ch;
    cout << "Enter an uppercase character to convert: ";
    cin >> ch;
    cout << "Lowercase character: " << toLower(ch) << endl;

    return 0;
}
