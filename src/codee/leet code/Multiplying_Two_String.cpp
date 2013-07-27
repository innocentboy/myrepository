/**
Given two numbers represented as strings, return multiplication of the numbers as a string.
Note: The numbers can be arbitrarily large and are non-negative.

*/

class Solution {
public:
    string multiply(string num1, string num2) {
        char result[num1.size() + num2.size()];
        for(int i = 0; i < num1.size() + num2.size(); ++i)
            result[i] = '0';
        for(int i = num1.size() - 1; i >= 0; --i) {
            int index = num1.size() + num2.size() - 1 - (num1.size() - 1 - i);
            int digit1 = num1[i] - '0';
            for(int j = num2.size() - 1; j >= 0; --j) {
                int digit2 = num2[j] - '0';
                int temp = digit1 * digit2;
                int previous = result[index] - '0';
                result[index] = (char) ((previous + temp) % 10 + '0');
                int carry = (previous + temp) / 10;
                int m = index - 1;
                while(carry != 0 && m >= 0) {
                    int rm = result[m] - '0';
                    result[m] = (char)((rm + carry) % 10 + '0');
                    carry = (rm + carry) / 10;
                    m--;
                }

                index--;
            }
        }
        string candidate = string(result, num1.size() + num2.size());
        size_t i = candidate.find_first_not_of('0');
        return i ==  string::npos ? "0" : candidate.substr(i);
    }
};
