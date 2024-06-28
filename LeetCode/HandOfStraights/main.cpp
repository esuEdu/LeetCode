//
//  main.cpp
//  HandOfStraights
//
//  Created by Eduardo on 06/06/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        unsigned long int size = hand.size();
        
        if (size % groupSize != 0) {
            return false;
        }else if (groupSize == 1) {
            return true;
        }
        
        sort(hand.begin(), hand.end());
                
        int temp;
        int index;
        int sizeChange = 1;
        auto it = hand.begin() + 0;
        
        while(size != 0) {
            temp = 0;
            index = 1;
            temp = hand[0];
            
            if (sizeChange != 0) {
                it = hand.begin() + 0;
                hand.erase(it);
                
                size = hand.size();
                sizeChange = 0;
            }else {
                return false;
            }

            for (int z = 0; z < size; z++) {
                
                if ((temp + 1) == hand[z]) {
                    temp = hand[z];
                    it = hand.begin() + z;
                    hand.erase(it);
                    size = hand.size();
                    z--;
                    sizeChange = 1;
                    if (index++ >= groupSize) {
                        break;
                    }
                }
            }
        }
        
        if (size == 0) {
            return  true;
        }
        return false;
    }
    
    bool isNStraightHand2(std::vector<int>& hand, int groupSize) {
         if (hand.size() % groupSize != 0) {
             return false;
         }else if(groupSize == 1) {
             return true;
         }
         
         std::map<int, int> count;
         for (int card : hand) {
             count[card]++;
         }
         
         while (!count.empty()) {
             
             int start = count.begin()->first;
             
             for (int i = 0; i < groupSize; i++) {
                 
                 if (count[start + i] == 0) {
                     return false;
                 }
                 
                 if (--count[start + i] == 0) {
                     count.erase(start + i);
                 }
                 
             }
         }

         return true;
     }
    
};

int main() {
    Solution solution;
    vector<int> hand = {1,2,3,8,5,6,7,8};
    int groupSize = 4;

    if (solution.isNStraightHand(hand, groupSize)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}


