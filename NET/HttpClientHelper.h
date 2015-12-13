/************************************************************************/
/* ˵����HTTP Client ��������ķ�װ                                     */
/* ʱ�䣺2015��12��9�� 22:37:07											*/
/* ���ߣ�xjm															*/
/************************************************************************/

/*
Ĭ�϶����ӣ�������Ҫʹ�ö�Ӧ�����غ���
*/
#ifndef	HTTPCLIENTHELPER_H
#define	HTTPCLIENTHELPER_H


#include "Wininet.h"
#include <string>
#include <map>
#include <vector>


class HttpClientHelper
{
public:
	typedef std::map<std::string,std::string> HeadItems;
	typedef HeadItems::const_iterator HeadItemsIt;
	typedef std::vector<char>	ByteArray;
	
class HttpClientRepond;

public:
	HttpClientHelper(std::string host,int port = 80);
	~HttpClientHelper();

	bool Connect();
	void Close();

	bool Post(std::string requestObj, const HeadItems* headItems = NULL, const char* data = NULL, int len = 0);
	bool Get(std::string requestObj = "", const HeadItems* headItems = NULL, const char* data = NULL, int len = 0);
	bool Head(std::string requestOb = "");

	
	bool Get(std::string requestObj, HttpClientRepond* repond , const HeadItems* headItems = NULL, const char* data = NULL, int len = 0);

	//��ȡ��תurl,��Ϊwininet��Ĭ���Զ���ת����ʱ��������Ҫ��ת��URL��ַ������һЩ��������
	std::string GetLocationUrl();

	std::string GetRequestObj();

private:
	bool Action(std::string type,std::string requestObj, HttpClientRepond* repond , const HeadItems* headItems = NULL, const char* data = NULL, int len = 0);

public:
	class HttpClientRepond
	{
		
	public:
		HttpClientRepond() { m_statuCode = 0; }
		~HttpClientRepond() {}

		void SetStatuCode(int code);
		void SetHeads(const HeadItems& heads);
		void SetBody(const ByteArray& body);

		void GetBody(ByteArray& body);
		int  GetStatuCode() {return m_statuCode;}

		std::string GetHeadItem(std::string name);
		std::string operator[](std::string name);

	private:
		int			m_statuCode;
		HeadItems	m_heads;
		ByteArray	m_bodys;
	};

private:
	void InitInternet();

	std::string	GetHeardItems(const HeadItems* headItems);

	//��ȡHead
	void ReadHead(HINTERNET hRequest, HeadItems& heads, int& statuCode);

	//��ȡBODY����
	void ReadData(HINTERNET hRequest,ByteArray& bodyData);

	//�ͷź���
	void CloseRequestInfo(HINTERNET hRequest);

	//��ȡ������
	std::string GetRequestLine(const std::string& head);

private:
	void ParseHead(const std::string& head, HeadItems& heads);

	bool ParseLineText(const std::string& line, std::string& name, std::string& value);

	//����������

	void ParsRequestLine(std::string line,std::string& obj);

private:
	HINTERNET		m_hInternetRoot;
	HINTERNET		m_hInternetConnect;
	HINTERNET		m_hSession;				//����ṹ����Ҫ
	std::string		m_host;
	int				m_port;
	std::string		m_agent;
};





#endif


