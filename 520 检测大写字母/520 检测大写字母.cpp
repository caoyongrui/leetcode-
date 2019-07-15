/*
����һ�����ʣ�����Ҫ�жϵ��ʵĴ�дʹ���Ƿ���ȷ��

���Ƕ��壬���������ʱ�����ʵĴ�д�÷�����ȷ�ģ�

ȫ����ĸ���Ǵ�д������"USA"��
������������ĸ�����Ǵ�д������"leetcode"��
������ʲ�ֻ����һ����ĸ��ֻ������ĸ��д��?����?"Google"��
�������Ƕ����������û����ȷʹ�ô�д��ĸ��

ʾ�� 1:

����: "USA"
���: True
ʾ�� 2:

����: "FlaG"
���: False
ע��: �������ɴ�д��Сд������ĸ��ɵķǿյ��ʡ�
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