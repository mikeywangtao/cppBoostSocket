// server.cpp : �������̨Ӧ�ó������ڵ㡣
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
//	//���� boost
//	int i = 8848;
//	char *mystr = "2013";
//	i = boost::lexical_cast<int>(mystr);
//	cout << "boost TypeTre:" << i << endl;
//
//	cout << "Server Hello world" << endl;
//	getchar();
//	return 0;
//}


///*
//  server.cpp Boost socket server ����̨���
//
//	ͨ��tcp::acceptor�ഴ��һ��tcp server���󣬲��󶨶˿ڣ�Ҳ���Բ��ڹ��������Զ��󶨣���ͨ��bind�����ֶ��󶨣�
//	ͨ��accept������ȡԶ������
//	ͨ��Զ�����ӵ�write_some���������ݷ����ͻ���
//*/
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


///* 
//  boost ʵ���첽socket
//	���� OK 
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
//class server {
//	typedef server this_type;
//	typedef ip::tcp::acceptor acceptor_type;
//	typedef ip::tcp::endpoint endpoint_type;
//	typedef ip::tcp::socket socket_type;
//	typedef ip::address address_type;
//	typedef boost::shared_ptr<socket_type> sock_ptr;
//
//private:
//	io_service m_io;
//	acceptor_type m_acceptor;
//
//public:
//	server() : m_acceptor(m_io, endpoint_type(ip::tcp::v4(), 6688)) {
//		accept();
//	}
//
//	void run() { m_io.run(); }
//
//	void accept() {
//		sock_ptr sock(new socket_type(m_io));
//		m_acceptor.async_accept(*sock, boost::bind(&this_type::accept_handler, this, boost::asio::placeholders::error, sock));
//	}
//
//	void accept_handler(const boost::system::error_code& ec, sock_ptr sock) {
//		if (ec) {
//			return;
//		}
//
//		cout << "Client:";
//		cout << sock->remote_endpoint().address() << endl;
//		sock->async_write_some(buffer("hello asio"), boost::bind(&this_type::write_handler, this, boost::asio::placeholders::error));
//		// ������Ϻ��������������io_service����Ϊû���¼��������������
//		accept();
//	}
//
//	void write_handler(const boost::system::error_code&ec) {
//		cout << "send msg complete" << endl;
//	}
//};
//
//int main() {
//	try {
//		cout << "Server start." << endl;
//		server srv;
//		srv.run();
//	} catch (std::exception &e) {
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}


/*
  boost ͬ��socket
	��֤ OK
*/
#include "stdafx.h"
#include "iostream"
#include "string"
#include "boost/asio.hpp"
#include "windows.h"

using namespace std;
using namespace boost::asio;

int main() {
	try {
		typedef ip::tcp::acceptor acceptor_type;
		typedef ip::tcp::endpoint endpoint_type;
		typedef ip::tcp::socket socket_type;
		
		boost::system::error_code ec;

		string sd = "Hello asio ";
		std::cout << "Server start." << endl;
		io_service io;
		acceptor_type acceptor(io, endpoint_type(ip::tcp::v4(), 6688));
		std::cout << acceptor.local_endpoint().address() << endl;
		char buf[512];
		
		int i = 0;

		for (;;) {
			i = 0;
			std::cout << "Server Ouput." << endl;
			socket_type sock(io);
			acceptor.accept(sock, ec);
			if (ec) 
			{
				cerr << "acc.accept(): An error occurred: " << ec.message() << '\n';
				continue;
			}

			std::cout << "Client";
			std::cout << sock.remote_endpoint().address() << endl;

			socket_type *a = &sock;
			std::cout << "Client XX : " << a << endl;

			std::size_t len = boost::asio::read(sock,
				boost::asio::buffer(buf, sizeof buf), 
				boost::asio::transfer_at_least(1), ec);
			if (ec) {
				if (ec != boost::asio::error::eof)
					cerr << "sock.read_some(): An error occurred: "
					<< ec.message() << '\n';
				break;
			}

			std::cout << "in : " << buf << endl;

			int i = 0;
			while (i < 8) 
			{
				i = i + 1;
				Sleep(2000);
				std::stringstream ss;
				std::string str;

				ss << i;
				ss >> str;
				str = sd + str + "\n";
				std::cout << "Ser Send ----: " << str << endl;
				sock.send(buffer(str));
				//sock.send(buffer("Hello asio\n"));
				//sock.send(buffer(str));
			}
		}
			//std::cout << "Server Ouput." << endl;
			//socket_type sock(io);
			//acceptor.accept(sock);

			//std::cout << "Client";
			//std::cout << sock.remote_endpoint().address() << endl;
			//sock.send(buffer("Hello asio"));
	} catch (std::exception &e) {
		std::cout << e.what() << endl;
		std::cout << "Server Error" << endl;
	}
	getchar();
	return 0;
}