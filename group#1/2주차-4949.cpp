#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    while (1)
    {
        string str;
        getline(cin, str);
        if (str[0] == '.')
            break;

        stack<char> st;
        bool flag = true;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(' || str[i] == '[')
            {
                st.push(str[i]);
            }
            else if (str[i] == ')')
            {
                if (st.empty() || st.top() == '[')
                {
                    flag = false;
                    break;
                }
                else if (st.top() == '(')
                {
                    st.pop();
                }
            }
            else if (str[i] == ']')
            {
                if (st.empty() || st.top() == '(')
                {
                    flag = false;
                    break;
                }
                else if (st.top() == '[')
                {
                    st.pop();
                }
            }
        }

        if (flag && st.empty())
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}