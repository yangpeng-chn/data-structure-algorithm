#include "iostream"
#include "string"
using namespace std;

/*
firstNonRepeatedChar
Remove Specified Characters
Reverse words
*/
//https://www.geeksforgeeks.org/given-a-string-find-its-first-non-repeating-character/
void firstNonRepeatedChar(string s){ // O(n)
	int array[26]={0}; // the value is random without initialization
	// for (int i = 0; i < 26; ++i)
	// {	
	// 	cout << array[i];//26 0s
	// }

	for (int i = 0; i < s.size(); ++i)
	{
		array[s[i]-'a']++;
	}

	for (int i = 0; i < s.size(); ++i)
	{
		if (array[s[i]-'a'] == 1){
			cout << s[i] << endl;
			return;
		}
	}
	cout << "-1" << endl;
	return;
}

//where any character existing in remove must be deleted from str. 
//For example, given a str of "Battle of the Vowels: Hawaii vs. Grozny" 
//and a remove of "aeiou", the function should 
//transform str to “Bttl f th Vwls: Hw vs. Grzny”. 
string removeChars(string s, string remove){ // O(n)
	bool array[128] = {false};
	for (int i = 0; i < remove.size(); ++i)
	{
		array[remove[i]] = true;
	}

	int dest = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (!array[s[i]])
		{
			s[dest++] = s[i];
		}
	}
	return s.substr(0, dest);
}

//reverse words
//https://www.geeksforgeeks.org/reverse-words-in-a-given-string/
void reverseString(char str[], int start, int end){
	while(start < end){
		char tmp = str[start];
		str[start++] = str[end];
		str[end--] = tmp;
	}
}
void reverseWord(char str[]){
	int start = 0, end = 0, length = strlen(str);// strlen(str) == sizeof(str) - 1
	reverseString(str, 0, length - 1);
	while( end < length ){
        if( str[end] != '.' ){ /* Skip non-word characters */
            /* Save position of beginning of word */
            start = end;
            /* Scan to next non-word character */
            while( end < length && str[end] != '.' )
                end++;
            /* Back up to end of word */
            end--;
            /* Reverse word */
            reverseString( str, start, end );
        }
        end++; /* Advance to next token */
    }
}

int main(){
	// string str = "Battle of the Vowels: Hawaii vs. Grozny";
	// string remove = "aeiou";
	// cout << removeChars(str, remove) << endl;
	char str[] = "geeks quiz practice code";
	reverseWord(str);
	cout << str << endl;
	return 0;
}