// class Solution {
// public:
//     string reverseWords(string s) {
//        stack< string> f;
//         string j=" ";
//         for(int i=0;i<s.size();i++)
//         {
//             string h=" ";
//             if(s[i]!=" ")
//             {
//               j+=s[i];
//             }
//               f.push(j);
//             f.push(" ");
//         }
//         while(!f.empty() )
//         {
//             // string p=f.top();
//            cout<< f.pop();
//         }
        
//     }
// };

class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        string word;

        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                if (!word.empty()) {
                    words.push(word);
                    word.clear();
                }
            } else {
                word += s[i];
            }
        }

        string result;
        while (!words.empty()) {
            result += words.top();
            words.pop();
            if (!words.empty()) {
                result += ' ';
            }
        }

        return result;
    }
};
