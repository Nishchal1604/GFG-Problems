//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}


// } Driver Code Ends


//return the address of the string
char* reverse(char *S, int len)
{
   
    stack<char> st;

    // Push all characters of the string into the stack
    for(int i = 0; i < len; i++)
    {
        st.push(S[i]);
    }

    // Pop characters from the stack and place them back into the string
    for(int i = 0; i < len; i++)
    {
        S[i] = st.top();
        st.pop();
    }

    // Return the address of the reversed string
    return S;

}