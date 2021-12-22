class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size();
        if(n==0) return "";
        
        sort(begin(str), end(str));
        
        const string& a = str[0];
        const string& b = str[n-1];

        size_t i=0;
        for(; i < a.size(); i++){
            if(a[i] != b[i]) break;
        }
        
        return string {&a[0], i}; 
    }
};
