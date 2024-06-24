class Solution {
public:
  int compareVersion(string v1, string v2) {
        //i will traverse v1 and j will traverse v2
        int i=0,j=0;
        //s1 will store v1's revision and s2 will store v2's revision
        string s1,s2;
        while(i<v1.length()||j<v2.length())
        {
            //initially let the revisions be 0
            s1="0";
            s2="0";
            //if there are characters in v1 then store untill we get a '.'
            while(i<v1.length()&&v1[i]!='.')
                s1+=v1[i++];
            //if there are characters in v2 then store the number untill we get '.'
            while(j<v2.length()&&v2[j]!='.')
                s2+=v2[j++];
            // compare the int of both the strings and return accordingly
            if(stoi(s1)>stoi(s2))
                return 1;
            else if(stoi(s1)<stoi(s2))
                return -1;
            //since we stopped at '.' increment iterator to get another revision
            i++;j++;
        }
        //for the last revision compare once again and return accordingly
        if(stoi(s1)>stoi(s2))
                return 1;
            else if(stoi(s1)<stoi(s2))
                return -1;
       //if not returned yet then both versions are equal hence return 0
        return 0;
    }
};