class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int maxLength = 0;
        int startIndex = 0;
        int size = s.length();
        
        //map to store found elements
        //key:char found, value:index
        unordered_map<char, int> myMap;
        
        for(int i=0; i<size; i++)
        {
            auto itr = myMap.find(s[i]);
            if(itr != myMap.end())
            {
                //element found, end of substring with that char
                //when a char is repeated we shift the window start(startIndex)
                //find the length of the substring
                //check if it is greater than previous
                maxLength = max(maxLength, i - startIndex);
                
                //we don't want to go back. 
                if(itr->second+1 >= startIndex)
                    startIndex = itr->second + 1;
            }
            
            //update or insert map
            myMap[s[i]] = i;
        }
        
        //after loop, evaluate the max length again.
        maxLength = max(maxLength, size - startIndex);        
        return maxLength;
    
    }
};
