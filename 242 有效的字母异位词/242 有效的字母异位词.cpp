/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例?1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
说明:
你可以假设字符串只包含小写字母。

进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

bool isAnagram(string s, string t)
{
	int len1 = s.length();
	int len2 = t.length();
	if (len1 != len2)
		return false;
	map<char, int> m1;
	map<char, int> m2;
	for (int i = 0; i < len1; i++)
	{
		if (m1.find(s[i]) == m1.end())
			m1.insert(make_pair(s[i], 1));
		else
			m1[s[i]]++;
	}
	for (int i = 0; i < len2; i++)
	{
		if (m2.find(t[i]) == m2.end())
			m2.insert(make_pair(t[i], 1));
		else
			m2[t[i]]++;
	}
	if (m1 == m2)
		return true;
	return false;
}

int main()
{
	string s = "rat";
	string t = "cat";
	bool res = isAnagram(s, t);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}