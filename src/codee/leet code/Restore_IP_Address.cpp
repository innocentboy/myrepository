/**
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

vector<string> restoreIpAddresses(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<string> col;
    string ip;
    partitionIP(s, 0, 0, ip, col);
    return col;
}

void partitionIP(string s, int startIndex, int partNum,
string resultIp, vector<string>& col)
{
    if(s.size() - startIndex > (4-partNum)*3) return;
    if(s.size() - startIndex < (4-partNum)) return;

    if(startIndex == s.size() && partNum ==4)
    {
        resultIp.resize(resultIp.size()-1);
        col.push_back(resultIp);
        return;
    }

    int num =0;
    for(int i = startIndex; i< startIndex +3; i++)
    {
        num = num*10 + (s[i]-'0');

        if(num<=255)
        {
            resultIp+=s[i];
            partitionIP(s, i+1, partNum+1, resultIp+'.', col);
        }
        if(num ==0)
        {
            break;
        }
    }
}

