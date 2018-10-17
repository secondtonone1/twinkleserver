// twinkleserver.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "./NetModel/server.hpp"
#include <boost/property_tree/ptree.hpp>  
#include <boost/property_tree/ini_parser.hpp>

int main(int argc, char* argv[])
{
	try
	{

		boost::property_tree::ptree pt,tag_setting;
		boost::property_tree::ini_parser::read_ini("./Data/config.ini",pt);	
		std::string serveraddress = pt.get<std::string>("config.address");
		std::string serverport = pt.get<std::string>("config.port");
		std::string docroot = pt.get<std::string>("config.docroot");
		// Check command line arguments.
		
		// Initialise the server.
		http::server::server s(serveraddress, serverport, docroot);

		// Run the server until stopped.
		s.run();
	}
	catch (std::exception& e)
	{
		std::cerr << "exception: " << e.what() << "\n";
	}

	return 0;
}

