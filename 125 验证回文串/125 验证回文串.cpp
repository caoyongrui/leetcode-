/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false
*/

#include <iostream>
#include <string>
using namespace std;

//双指针法
bool isPalindrome(string s)
{
	if (s.length() <= 1)
		return true;
	int i = 0;
	int j = s.length() - 1;
	while (i < j)
	{
		while (i < j && !isalnum(s[i]))
			i++;
		while (i < j && !isalnum(s[j]))
			j--;
		if (tolower(s[i++]) != tolower(s[j--]))
			return false;
	}
	return true;
}

int main()
{
	string s = "A man, a plan, a canal: Panama";
	bool res = isPalindrome(s);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}