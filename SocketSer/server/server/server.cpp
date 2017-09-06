// server.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
//#include "cstdio"
//#include "iostream"
//#include "boost\lexical_cast.hpp"
//
//using namespace std;
//
//int main()
//{
//	//测试 boost
//	int i = 8848;
//	char *mystr = "2013";
//	i = boost::lexical_cast<int>(mystr);
//	cout << "boost TypeTre:" << i << endl;
//
//	cout << "Server Hello world" << endl;
//	getchar();
//	return 0;
//}


/*
  server.cpp Boost socket server 控制台入口

	通过tcp::acceptor类创建一个tcp server对象，并绑定端口（也可以不在构造器中自动绑定，而通过bind函数手动绑定）
	通过accept函数获取远端连接
	通过远端连接的write_some函数将数据发往客户端
*/
#include "stdafx.h"
#include "ctime"
#include "iostream"
#include "string"
#include "boost\asio.hpp"

using namespace boost;
using boost::asio::ip::tcp;

int main() {
	try {
		asio::io_service io_service;
		tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 3200));

		for (;;) {
			tcp::socket socket(io_service);
			acceptor.accept(socket);

			time_t now = time(0);
			std::string message = ctime(&now);

			system::error_code ignored_error;
			socket.write_some(asio::buffer(message), ignored_error);
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

