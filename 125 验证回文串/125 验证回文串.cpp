/*
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��

˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���

ʾ�� 1:

����: "A man, a plan, a canal: Panama"
���: true
ʾ�� 2:

����: "race a car"
���: false
*/

#include <iostream>
#include <string>
using namespace std;

//˫ָ�뷨
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