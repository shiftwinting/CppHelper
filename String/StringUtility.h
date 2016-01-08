#ifndef STRING_UTILITY_H
#define STRING_UTILITY_H

/************************************************************************/
/* ˵��������std�ַ���������                                          */
/* ���ߣ�xjm															*/
/* ʱ�䣺2015��12��19�� 21:16:55										*/
/************************************************************************/
#include <string>

class StringUtility
{
public:
	static std::wstring		AToWString(std::string str);
	static std::string		WToAString(std::wstring str);
	static std::wstring		Utf8ToWString(std::string str);
	static std::string		Utf8ToString(std::string str);
	static std::string		WStringToUtf8(std::wstring str);

	static int				WSTringToInt(std::wstring str);
	static int				StringToInt(std::string str);
	static std::string		IToString(int n);
	static std::wstring		IToWString(int n);
};
#endif