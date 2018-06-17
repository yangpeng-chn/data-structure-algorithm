
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

string urlDecode(string &SRC) {
    string ret;
    char ch;
    int i, ii;
    for (i=0; i<SRC.length(); i++) {
        if (int(SRC[i])==37) {
            sscanf(SRC.substr(i+1,2).c_str(), "%x", &ii);
            ch=static_cast<char>(ii);
            ret+=ch;
            i=i+2;
        } else {
            ret+=SRC[i];
        }
    }
    return (ret);
}

int mainte() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string url;
    cin >> url;
    unordered_map<string, vector<string> > result;
    vector<string> vKeys;
    int keyStart = -1;
    int keyEnd = -1;
    int valueStart = -1;
    int valueEnd = -1;
    for (int i = 0; i < url.size(); ++i)
    {
    	if(url[i] == '?'){
    		keyStart = i+1;
    	}else if(url[i] == '='){
    		keyEnd = i-1;
    		valueStart = i+1; //39 2
    	}
    	else if(url[i] == '&' || i == url.size()-1){
    		valueEnd = i-1;
    		if (i == url.size()-1)
    		{
    			valueEnd = i;
    		}
    		string key = url.substr(keyStart, keyEnd-keyStart+1);
    		string value = url.substr(valueStart, valueEnd - valueStart+1);
    		value = urlDecode(value);
    		if (!result.count(key))
    			vKeys.push_back(key);
    		result[key].push_back(value);
    		keyStart = i+1;
    		keyEnd = -1;
    		valueStart = valueEnd = -1;
    	}
    }

    string resultStr = "{";
    for (int i = 0; i < vKeys.size(); ++i)
    {
    	resultStr += "\"";
    	resultStr += vKeys[i];
    	resultStr += "\":";
    	if (result[vKeys[i]].size() == 1)
    	{
    		resultStr += "\"";
    		resultStr += result[vKeys[i]][0];
    		resultStr += "\"";
    	}else{
    		resultStr += "[";
    		for (int j = 0; j < result[vKeys[i]].size(); ++j)
	    	{
    			resultStr += "\"";
    			resultStr += result[vKeys[i]][j];
    			resultStr += "\"";
    			if (j != result[vKeys[i]].size()-1)
    			{
    				resultStr += ",";
    			}
	    	}
    		resultStr += "]";
    	}
    	resultStr += ",";
    }
   
    resultStr = resultStr.substr(0, resultStr.size()-1);
    resultStr += "}";
    if (vKeys.size() == 0)
    	resultStr = "";
  	cout << resultStr << endl;
    return 0;
}

int main(){
	vector<string> codes;
    string result = "";
	unordered_map<string, string> codeMap;
	codes.push_back("a	100100");
	codes.push_back("b	100101");
	codes.push_back("c	110001");
	codes.push_back("d	100000");
	codes.push_back("[newline]	111111");
	codes.push_back("p	111110");
	codes.push_back("q	000001");
	string encoded = "111110000001100100111111100101110001111110";
	for (int i = 0; i < codes.size(); ++i)
	{
		for (int j = 0; j < codes[i].size(); ++j)
		{
			if (codes[i][j] == '\t'){
				cout << j << endl;
                string key = codes[i].substr(j+1);
                string value = codes[i].substr(0, j);
                cout << key << " " << value << endl;
                if (value == "[newline]") value = "\n";
                codeMap[key] = value;
            }
		}
	}

	string str = "";
	for (int i = 0; i < encoded.size(); ++i)
	{
		str += encoded[i];
		if (codeMap.end() != codeMap.find(str))
		{
			result += codeMap[str];
			str = "";
		}
	}

    result += codeMap["test"];
    cout << result;
}