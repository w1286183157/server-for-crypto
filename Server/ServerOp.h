#pragma
#include <fstream>
#include <sstream>
#include <jsoncpp/json/json.h>
#include "../Hash/Hash.h"
#include"../SqlOP/MYSQLOP.h"
#include "../RsaCrypto/RsaCrypto.h"
#include "../TcpSocket/TcpSocket.h"
#include "../TcpServer/TcpServer.h"
#include "../factory/RequestCodec.h"
#include "../factory/RespondCodec.h"

// 处理客户端请求
class ServerOP
{
public:
	enum KeyLen {Len16=16, Len24=24, Len32=32};
	ServerOP(string json);
	// 启动服务器
	void startServer();
	// 线程工作函数 -> 推荐使用
	static void* working(void* arg);
	// 友元破坏了类的封装
	friend void* workHard(void* arg);
	// 秘钥协商
	string seckeyAgree(RequestMsg* reqMsg);
	~ServerOP();

private:
	string getRandKey(KeyLen len);

private:
	string m_serverID;	// 当前服务器的ID
	string m_dbUser;
	string m_dbPwd;
	string m_dbConnStr;
	string m_port;
	string m_dbset;
	map<pthread_t, TcpSocket*> m_list;
	TcpServer *m_server = NULL;
	// 创建数据库实例对象
	MYSQLOP m_mysql;
};

void* workHard(void* arg);