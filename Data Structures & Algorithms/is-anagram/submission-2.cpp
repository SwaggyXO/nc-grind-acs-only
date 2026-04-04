class Solution {
public:
    bool isAnagram(string s, string t) {
      //   Fixed size arr because a-z = 26 💡
      int map[26]={0};
      //   Add char val to freq arr   
      for(auto x:s ){
        map[x-'a']++;
      }
     //    Rem char val if it appears in t   
      for(auto x:t){
        map[x-'a']--;
      }
     //    Check if anything still has a freq   
      for(int i=0;i<26;i++){
        if(map[i])
          return false;
      }
     // GG   
      return true;
    }
};
