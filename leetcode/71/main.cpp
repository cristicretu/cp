class Solution {
public:
    string simplifyPath(string path) {
      stack<string> st;
      string answer;
      
      for (unsigned i = 0, n = path.size(); i < n; ++i) {
        if (path[i] == '/') continue;
        
        string str;
        
        // navigate between dirs
        while (i < n && path[i] != '/') {
          str += path[i];
          ++i;
        }
        
        if (str == ".") continue;
        else if (str == "..") {
          if (!st.empty()) {
            st.pop();
          }
        } else {
          st.push(str);
        }
      }
      
      // place the items in reverse order (stack)
      while (!st.empty()) {
        answer = "/" + st.top() + answer;
        st.pop();
      }
      
      if (answer.size() == 0) return "/";
      return answer;
    }
};
