//
//  main.cpp
//  LongestPalindrome
//
//  Created by Eduardo on 07/06/24.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        
        for (char character : s) {
            count[character]++;
        }

        int result = 0;
        bool hasOdd = false;

        for (const auto& pair : count) {
            if (pair.second % 2 == 0) {
                result += pair.second;
            } else {
                result += pair.second - 1;
                hasOdd = true;
            }
        }

        if (hasOdd) {
            result += 1;
        }

        return result;
    }
};



int main(int argc, const char * argv[]) {
    
    string input = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    
    Solution solution;
    
    
    int output = solution.longestPalindrome(input);
    
    std::cout << output << endl;
    return 0;
}
