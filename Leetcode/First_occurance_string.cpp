class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    return haystack.find(needle);
  }
};

/* class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
    int j;
        for(int i=0;i<=n-m ; i++){
            for(j = 0; j < m; j++){
                if(haystack[i+j] != needle[j])
                  break;
            }
            if(j == m)
            return i;
        }
        return -1;
    }
}; */

/*
class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.length();i++)
        {
                if(haystack.substr(i,needle.length())==needle)
                {
                    return i;
                }
        }
        return -1;
    }
};
*/