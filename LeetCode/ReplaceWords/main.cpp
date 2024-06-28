//
//  main.cpp
//  ReplaceWords
//
//  Created by Eduardo on 07/06/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>


using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string result;
        
        sort(dictionary.begin(), dictionary.end(), [] (const std::string& first, const std::string& second){
                 return first.size() < second.size();
             });
        
        vector<string> words = removeDupWord(sentence);
        
        for (int i = 0; i < words.size(); i++)  {
            for(int j = 0; j < dictionary.size(); j++){
                
                if (words[i].substr(0, dictionary[j].length()).compare(dictionary[j]) == 0) {
                    words[i] = dictionary[j];
                    break;
                }
                
            }
            if (i == 0) {
                result = words[i];
            }else {
                result += " " + words[i];
            }
            
        }
        return result;
    }
    
    vector<std::string> removeDupWord(const std::string &str) {
        vector<std::string> result;
        stringstream sentence(str);
        string word;
        
        while (getline(sentence, word, ' ')) {
            result.push_back(word);
        }

        return result;
    }
};

int main(int argc, const char * argv[]) {

    Solution solution;
    vector<string> imput = {"cat","bat","ratt"};
    string sentence = "the cattle was rattled by the battery";
    
    string result = solution.replaceWords(imput, sentence);
    std::cout << "result:" << endl;
    std::cout << result << endl;
    return 0;
}
