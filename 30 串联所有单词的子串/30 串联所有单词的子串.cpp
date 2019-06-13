/*
����һ���ַ���?s?��һЩ������ͬ�ĵ���?words���ҳ� s ��ǡ�ÿ�����?words �����е��ʴ����γɵ��Ӵ�����ʼλ�á�

ע���Ӵ�Ҫ��?words �еĵ�����ȫƥ�䣬�м䲻���������ַ���������Ҫ����?words?�е��ʴ�����˳��

?

 ʾ�� 1��

 ���룺
 s = "barfoothefoobarman",
 words = ["foo","bar"]
 �����[0,9]
 ���ͣ�
 ������ 0 �� 9 ��ʼ���Ӵ��ֱ��� "barfoor" �� "foobar" ��
 �����˳����Ҫ, [9,0] Ҳ����Ч�𰸡�
 ʾ�� 2��

 ���룺
 s = "wordgoodgoodgoodbestword",
 words = ["word","good","best","word"]
 �����[]
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