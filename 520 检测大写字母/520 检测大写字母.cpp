/*
给定一个单词，你需要判断单词的大写使用是否正确。

我们定义，在以下情况时，单词的大写用法是正确的：

全部字母都是大写，比如"USA"。
单词中所有字母都不是大写，比如"leetcode"。
如果单词不只含有一个字母，只有首字母大写，?比如?"Google"。
否则，我们定义这个单词没有正确使用大写字母。

示例 1:

输入: "USA"
输出: True
示例 2:

输入: "FlaG"
输出: False
注意: 输入是由大写和小写拉丁字母组成的非空单词。
*/

#include <iostream>
#include <string>
using namespace std;

bool detectCapitalUse(string word)
{
	int len = word.length();
	if (len <= 1)
		return true;
	int i = 0;
	int j = 1;
	while (i < len && isupper(word[i]))
		i++;
	while (j < len && islower(word[j]))
		j++;
	if (i == len || j == len)
		return true;
	return false;
}

int main()
{
	string s = "saG";
	bool res = detectCapitalUse(s);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}