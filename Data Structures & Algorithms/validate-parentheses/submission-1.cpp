class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int> brackets = { {'(',1},{')',-1},{'[',2},{']',-2},{'{',3},{'}',-3}}; //hard coded the brackets for poping and checking
        
        if(s.empty()) return false;

        stack<char> symbols;

        for(char c: s){
            if(brackets[c]>0) symbols.push(c);
            else{
                if(symbols.empty()) return false;
                char top = symbols.top();
                symbols.pop();
                if(brackets[top]+brackets[c]!=0) return false;
            }
        }

        return symbols.empty();

    }
};
