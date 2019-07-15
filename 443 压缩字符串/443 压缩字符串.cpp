/*
给定一组字符，使用原地算法将其压缩。

压缩后的长度必须始终小于或等于原数组长度。

数组的每个元素应该是长度为1?的字符（不是 int 整数类型）。

在完成原地修改输入数组后，返回数组的新长度。

?

 进阶：
 你能否仅使用O(1) 空间解决问题？

  示例 1：

  输入：
  ["a","a","b","b","c","c","c"]

  输出：
  返回6，输入数组的前6个字符应该是：["a","2","b","2","c","3"]

  说明：
  "aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。
  示例 2：

  输入：
  ["a"]

  输出：
  返回1，输入数组的前1个字符应该是：["a"]

  说明：
  没有任何字符串被替代。
  示例 3：

  输入：
  ["a","b","b","b","b","b","b","b","b","b","b","b","b"]

  输出：
  返回4，输入数组的前4个字符应该是：["a","b","1","2"]。

  说明：
  由于字符"a"不重复，所以不会被压缩。"bbbbbbbbbbbb"被“b12”替代。
  注意每个数字在数组中都有它自己的位置。
  注意：

  所有字符都有一个ASCII值在[35, 126]区间内。
  1 <= len(chars) <= 1000。
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int compress(vector<char>& chars)
{
	int len = chars.size();
	if (len == 0 || len == 1)
		return len;
	vector<char> c;
	vector<string> num;
	int count = 0;
	for (int i = 0; i < len - 1; i++)
	{
		count = 1;
		int j = i + 1;
		while (j < len && chars[j] == chars[i])
		{
			count++;
			j++;
		}
		num.push_back(to_string(count));
		c.push_back(chars[i]);
		i = j - 1;
	}
	if (chars[len - 2] != chars[len - 1])
	{
		c.push_back(chars[len - 1]);
		num.push_back(to_string(1));
	}
	chars.clear();
	int numLen = num.size();
	int res = 0;
	for (int i = 0; i < numLen; i++)
	{
		chars.push_back(c[i]);
		res++;
		if (num[i] != "1")
		{
			for (int j = 0; j < num[i].size(); j++)
			{
				chars.push_back(num[i][j]);
				res++;
			}
		}
	}
	return res;
}

int compress1(vector<char>& chars)
{
	if (chars.size() <= 1)
		return chars.size();
	int index = 0;
	for (int i = 0; i < chars.size();)
	{
		chars[index++] = chars[i++];
		int count = 1;
		while (i < chars.size() && chars[i] == chars[i - 1])
		{
			count++;
			i++;
		}
		if (count != 1)
		{
			string s = to_string(count);
			for (int j = 0; j < s.length(); j++)
				chars[index++] = s[j];
		}
	}
	chars.erase(chars.begin() + index, chars.end());
	return chars.size();
}

int main()
{
	vector<char> chars = { 'a' };
	int res = compress1(chars);
	cout << res << endl;

	system("pause");
	return 0;
}