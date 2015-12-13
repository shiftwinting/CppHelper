#ifndef INIHELPER_H
#define INIHELPER_H

/************************************************************************/
/* ˵�����ṩ��ini�ļ���д�ӿ�                                        */
/* ���ߣ�xjm                                                            */
/* ʱ�䣺2015��11��30�� 14:41:51                                        */
/************************************************************************/

#include <string>

class CINIFile
{
public:
    CINIFile(std::wstring strPath);
    ~CINIFile();


    std::wstring		GetString(std::wstring strSection,std::wstring strKey);
    int			        GetInt(std::wstring strSection,std::wstring strKey);
    LONGLONG	        GetInt64(std::wstring strSection,std::wstring strKey);

    BOOL		        SetString(std::wstring strSection,std::wstring strKey,std::wstring strValue);
    BOOL		        SetInt(std::wstring strSection,std::wstring strKey,LONG iValue);
    BOOL		        SetInt64(std::wstring strSection,std::wstring strKey,LONGLONG iValue);

private:
    std::wstring        m_strFilePath;
};
#endif