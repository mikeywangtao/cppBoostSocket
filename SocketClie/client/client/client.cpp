// client.cpp : 定义控制台应用程序的入口点。
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
//	cout << "Client Hello world" << endl;
//	getchar();
//	return 0;
//}



///*
//  client.cpp boost socket 客户端
//
//	通过tcp::socket类定义一个tcp client对象socket
//	通过connect函数连接服务器，打开socket连接。
//	通过read_some函数来读数据
//*/
//#include "stdafx.h"
//#include "cstdio"
//#include "iostream"
//#include "string"
//#include "boost/array.hpp"
//#include "boost/asio.hpp"
//
//using boost::asio::ip::tcp;
//
//int main(int argc, char* argv[]) {
//	try {
//		boost::asio::io_service io_service;
//		tcp::endpoint end_point(boost::asio::ip::address::from_string("127.0.0.1"), 3200);
//
//		tcp::socket socket(io_service);
//		socket.connect(end_point);
//
//		for (;;) {
//			boost::array<char, 128> buf;
//			boost::system::error_code error;
//
//			size_t len = socket.read_some(boost::asio::buffer(buf), error);
//
//			if (error == boost::asio::error::eof)
//				break; // Connection closed cleanly by peer.
//			else if (error)
//				throw boost::system::system_error(error); // Some other error.
//
//			std::cout.write(buf.data(), len);
//		}
//	} catch (std::exception& e) {
//		std::cerr << e.what() << std::endl;
//	}
//
//	return 0;
//}


///*
//  boost实现异步socket
//	测试 OK
//*/
//#include "stdafx.h"
//#include "iostream"
//#include "boost/shared_ptr.hpp"
//#include "boost/asio.hpp"
//#include "boost/asio/placeholders.hpp"
//#include "boost/system/error_code.hpp"
//#include "boost/bind/bind.hpp"
//
//using namespace std;
//using namespace boost::asio;
//
//class client {
//	typedef client this_type;
//	typedef ip::tcp::acceptor acceptor_type;
//	typedef ip::tcp::endpoint endpoint_type;
//	typedef ip::tcp::socket socket_type;
//	typedef ip::address address_type;
//	typedef boost::shared_ptr<socket_type> sock_ptr;
//	typedef vector<char> buffer_type;
//
//private:
//	io_service m_io;
//	buffer_type m_buf;
//	endpoint_type m_ep;
//public:
//	client() : m_buf(100, 0), m_ep(address_type::from_string("127.0.0.1"), 6688) {
//		start();
//	}
//
//	void run() {
//		m_io.run();
//	}
//
//	void start() {
//		sock_ptr sock(new socket_type(m_io));
//		sock->async_connect(m_ep, boost::bind(&this_type::conn_handler, this, boost::asio::placeholders::error, sock));
//	}
//
//	void conn_handler(const boost::system::error_code&ec, sock_ptr sock) {
//		if (ec) {
//			return;
//		}
//		cout << "Receive from " << sock->remote_endpoint().address() << ": " << endl;
//		sock->async_read_some(buffer(m_buf), boost::bind(&client::read_handler, this, boost::asio::placeholders::error, sock));
//	}
//
//	void read_handler(const boost::system::error_code&ec, sock_ptr sock) {
//		if (ec) {
//			return;
//		}
//		sock->async_read_some(buffer(m_buf), boost::bind(&client::read_handler, this, boost::asio::placeholders::error, sock));
//		cout << &m_buf[0] << endl;
//	}
//};
//
//int main() {
//	try {
//		cout << "Client start." << endl;
//		//client cl;
//		//cl.run();
//		for (int a = 10; a < 20; a = a + 1) {
//			cout << "a 的值：" << a << endl;
//			client cl;
//			cl.run();
//		}
//	} catch (std::exception &e) {
//		cout << e.what() << endl;
//	}
//	getchar();
//	return 0;
//}