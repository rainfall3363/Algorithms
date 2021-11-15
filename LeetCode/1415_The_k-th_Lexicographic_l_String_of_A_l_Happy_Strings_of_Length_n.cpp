void recursiveHappy(int n, int k, vector<string> &pouch, char ch, string str) {
    str += ch;
    if (pouch.size() >= k) {
        return;
    }
    else if (str.length() == n) {
        pouch.push_back(str);
        return;
    }
    
    if (ch == 'a') {
        recursiveHappy(n, k, pouch, 'b', str);
        recursiveHappy(n, k, pouch, 'c', str);
    }
    else if (ch == 'b') {
        recursiveHappy(n, k, pouch, 'a', str);
        recursiveHappy(n, k, pouch, 'c', str);
    }
    else if (ch == 'c') {
        recursiveHappy(n, k, pouch, 'a', str);
        recursiveHappy(n, k, pouch, 'b', str);        
    }
}

class Solution {
public:
    string getHappyString(int n, int k) {
        string result = "";
        string str = "";
        vector<string> pouch;
        
        recursiveHappy(n, k, pouch, 'a', str);
        recursiveHappy(n, k, pouch, 'b', str);
        recursiveHappy(n, k ,pouch, 'c', str);
                
        if (pouch.size() == k) {
            result =  pouch.back();
        }
        
        return result;
    }
};
