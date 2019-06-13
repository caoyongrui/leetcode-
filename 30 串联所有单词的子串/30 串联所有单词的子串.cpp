/*
给定一个字符串?s?和一些长度相同的单词?words。找出 s 中恰好可以由?words 中所有单词串联形成的子串的起始位置。

注意子串要与?words 中的单词完全匹配，中间不能有其他字符，但不需要考虑?words?中单词串联的顺序。

?

 示例 1：

 输入：
 s = "barfoothefoobarman",
 words = ["foo","bar"]
 输出：[0,9]
 解释：
 从索引 0 和 9 开始的子串分别是 "barfoor" 和 "foobar" 。
 输出的顺序不重要, [9,0] 也是有效答案。
 示例 2：

 输入：
 s = "wordgoodgoodgoodbestword",
 words = ["word","good","best","word"]
 输出：[]
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words)
{
	if (s.empty() || words.empty() || s.length() < words.size() * words[0].length())
	{
		return{};
	}
	int lenOfWord = words[0].length();
	int numOfWord = words.size();
	int lenOfSubstr = lenOfWord * numOfWord;
	vector<int> res;
	map<string, int> m;
	map<string, int> temp;
	for (int i = 0; i < words.size(); i++)
	{
		if (m.find(words[i]) == m.end())
		{
			m.insert(make_pair(words[i], 1));
		}
		else
		{
			m[words[i]]++;
		}
	}
	for (int i = 0; i <= s.length() - lenOfSubstr; i++)
	{
		string substr = s.substr(i, lenOfSubstr);
		for (int j = 0; j < lenOfSubstr; j += lenOfWord)
		{
			string word = substr.substr(j, lenOfWord);
			if (m.find(word) == m.end())
			{
				break;
			}
			else
			{
				if (temp.find(word) == temp.end())
				{
					temp.insert(make_pair(word, 1));
				}
				else
				{
					temp[word]++;
				}
			}
		}
		if (temp == m)
		{
			res.push_back(i);
		}
		temp.clear();
	}
	return res;
}

int main()
{
	string s = "wordgoodgoodgoodbestword";
	vector<string> words;
	words.push_back("word");
	words.push_back("good");
	words.push_back("best");
	words.push_back("good");
	vector<int> res = findSubstring(s, words);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}