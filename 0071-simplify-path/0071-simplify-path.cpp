class Solution {
public:
    string simplifyPath(string path) {
        // //an absolute path is given and convert it into canonical path.
        // . represent current
        //     .. represent to directory up a level
        //     multiple slashes considered as single slashes
        stack<string> st;
        int i = 0;
        string cur = "";
        path += '/';
        // loop path and construct stack
        while (i < path.size()) {
            if (path[i] == '/') {
                if (!cur.empty()) {
                    if (cur == ".") {
                        // do nothing
                    }
                    else if (cur == "..") {
                        // remove the last dir
                        if (!st.empty()) {
                            st.pop();
                        }
                    }
                    else {
                        // append the cur dir
                        st.push(cur);
                    }
                }
                cur.clear();
                i += 1;
            }
            else {
                cur += path[i];
                i += 1;
            }
        }
        // construct result string from stack
        string rst = "";
        while (!st.empty()) {
            rst = "/" + st.top() + rst;
            st.pop();
        }
        if (rst.empty()) rst += '/';
        return rst;
        
    }
};