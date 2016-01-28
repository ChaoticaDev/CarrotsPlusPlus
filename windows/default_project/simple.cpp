#include "mysql_connection.h"
#include "mysql_driver.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <my_global.h>
#include <mysql.h>
#include <json/value.h>
#include <json/writer.h>
#pragma comment(lib, "mysqlclient.lib")
#pragma comment(lib, "advapi32.lib")
std::map<std::string, std::map<std::string, std::string>> data;
#include "templating_engine.h"
#include "mysql_res_json.h"
char* getTitle(){
	return "Carrots v.0.0.1";
}

int main(int argc, char* argv[]){
	std::string hello;
	data["data"]["Kenneth->id"] = getTitle();;
	data["data"]["apptitle"] = "Hello World";
	program_template_code = argv[2];
	std::string query = "SELECT * FROM tracks";
	data["data"]["MYSQL->tracks"] = mysql_res_json(query).c_str();
	preg_template_contents();
	return 1;
}