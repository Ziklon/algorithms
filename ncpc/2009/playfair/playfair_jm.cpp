#include <iostream>
#include <string>
#include <set>
#include <cassert>

using namespace std;

string removeSpaces(string s)
{
	string t = "";
	for(int i=0; i<s.size(); i++)
		if (s[i] != ' ')
			t += s[i];
	return t;
}

int main()
{
	string keyphrase, plaintext;
	
	getline(cin, keyphrase);
	getline(cin, plaintext);
	
	assert(keyphrase.size() >= 1 && keyphrase.size() <= 1000);
	assert(plaintext.size() >= 1 && plaintext.size() <= 1000);
	assert(keyphrase[0] != ' ' && keyphrase[keyphrase.size()-1] != ' ');
	assert(plaintext[0] != ' ' && plaintext[plaintext.size()-1] != ' ');
	assert(plaintext[plaintext.size()-1] != 'x');
	
	keyphrase = removeSpaces(keyphrase);
	plaintext = removeSpaces(plaintext);
	
	// Verify input	
	for(int i=0;i<keyphrase.size();i++) {
		assert(keyphrase[i] >= 'a' && keyphrase[i] <= 'z' && keyphrase[i] != 'q');
	}
	for(int i=0;i<plaintext.size();i++) {
		assert(plaintext[i] >= 'a' && plaintext[i] <= 'z' && plaintext[i] != 'q');
		assert(plaintext[i] != 'x' || i+1==plaintext.size() || plaintext[i+1] != 'x');
	}
	
	for(char c='a'; c<='z'; c++)
		if (c != 'q')
			keyphrase += c;
	
	set<char> used;
	char matrix[5][5];
	int col[128], row[128];
	
	for(int i=0, j=0;i<keyphrase.size();i++) {
		char c = keyphrase[i];
		if (used.count(c) == 0) {
			used.insert(c);
			matrix[row[c] = j/5][col[c] = j%5] = toupper(c);
			j++;
		}
	}
	
	for(int i=0;i<plaintext.size();) {
		char c1 = plaintext[i++], c2;
		if (i==plaintext.size() || c1 == plaintext[i])
			c2 = 'x';
		else
			c2 = plaintext[i++];
		if (row[c1] == row[c2]) {
			cout << matrix[row[c1]][(col[c1]+1)%5];
			cout << matrix[row[c2]][(col[c2]+1)%5];
		}
		else if (col[c1] == col[c2]) {
			cout << matrix[(row[c1]+1)%5][col[c1]];
			cout << matrix[(row[c2]+1)%5][col[c2]];
		}
		else {
			cout << matrix[row[c1]][col[c2]];
			cout << matrix[row[c2]][col[c1]];
		}			
	}
	
	cout << endl;
	
	return 0;
}