class Solution {
  public:
  
  void rotateclockwise(string &s1){
      char c = s1[s1.size()-1];
      int index = s1.size()-2;
      while(index>=0){
          s1[index+1]=s1[index];
          index--;
      }
      s1[0]=c;
  }
  
  void rotateanticlockwise(string &s1){
      char r = s1[0];
      int index = 1;
      while(index<=s1.size()-1){
          s1[index-1]=s1[index];
          index++;
      }
      s1[s1.size()-1]=r;
  }
  
  
    bool isRotated(string& s1, string& s2) {
        // code here
        if(s1.size() != s2.size())
        return 0;
        
        string clockwise;
        string anticlockwise;
        
        clockwise = s1;
        rotateclockwise(clockwise);
        rotateclockwise(clockwise);
        if(clockwise==s2)
        return 1;
        
        anticlockwise = s1;
        rotateanticlockwise(anticlockwise);
        rotateanticlockwise(anticlockwise);
        if(anticlockwise==s2)
        return 1;
        
        return 0;
    }
};
