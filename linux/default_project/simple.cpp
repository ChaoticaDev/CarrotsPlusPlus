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
std::map<std::string, std::map<std::string, std::string> > data;
#include "templating_engine.h"
#include "mysql_res_json.h"
char* getTitle(){
	return "Carrots v.0.0.1";
}

std::string session_id;
int main(int argc, char* argv[]){
	std::string hello = "Hi!";
	data["data"]["Kenneth->id"] = getTitle();;
	data["data"]["apptitle"] = "Hello World";
	program_template_code = argv[2];
	session_id = argv[3];
	std::string query = "SELECT * FROM tracks";
	data["data"]["MYSQL->tracks"] = mysql_res_json(query).c_str();
	engineTest();
	preg_template_contents();
	return 1;
}