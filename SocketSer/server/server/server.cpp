// server.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "cstdio"
#include "iostream"
//#include "boost\asio.hpp"
#include "boost\lexical_cast.hpp"

using namespace std;

int main()
{
	////测试 boost
	//int i = 8848;
	//char *mystr = "2013";
	//i = boost::lexical_cast<int>(mystr);
	//cout << "boost TypeTre:" << i << endl;

	cout << "Server Hello world" << endl;
	getchar();
	return 0;
}

//#include "stdafx.h"
//#include "ctime"
//#include "iostream"
//#include "string"
//#include "boost\asio.hpp"
//
//using namespace boost;
//using boost::asio::ip::tcp;
//
//int main() {
//	try {
//		asio::io_service io_service;
//		tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 3200));
//
//		for (;;) {
//			tcp::socket socket(io_service);
//			acceptor.accept(socket);
//
//			time_t now = time(0);
//			std::string message = ctime(&now);
//
//			system::error_code ignored_error;
//			socket.write_some(asio::buffer(message), ignored_error);
//		}
//	} catch (std::exception& e) {
//		std::cerr << e.what() << std::endl;
//	}
//
//	return 0;
//}

