#include <sqlite3.h> 
#include <map>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>      // std::ifstream
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <cerrno>

std::map<std::string, std::string> _GET;
std::map<std::string, std::string> _POST;
std::map<std::string, std::string> _REQUEST;
std::map<std::string, std::string> _FILE;
extern std::string session_id;

using namespace std;

void split(const string &s, const char* delim, vector<string> & v, std::string PARAM_T){
    // to avoid modifying original string
    // first duplicate the original string and return a char pointer then free the memory
	if(s.length() < 1 ){return;}
    char * dup = strdup(s.c_str());
    char * token = strtok(dup, delim);
	std::map<int, std::string> tokens;
	int index = 0;
    while(token != NULL){
        v.push_back(string(token));
        // the call is treated as a subsequent calls to strtok:
        // the function continues from where it left in previous invocation
		printf(token);

		tokens[index] = token;
		index++;
        token = strtok(NULL, delim);
    }
	
	if ( PARAM_T.compare("URL_GET") == 0 ){
		_GET[tokens[0]] = tokens[1];
	}else if ( PARAM_T.compare("URL_POST") == 0){
		_POST[tokens[0]] = tokens[1];
	}else if ( PARAM_T.compare("URL_FILE") == 0){
		_FILE[tokens[0]] = tokens[1];
	}else if ( PARAM_T.compare("URL_REQUEST") == 0){
		_REQUEST[tokens[0]] = tokens[1];
	}
    free(dup);
}

bool isSet ( std::string method, std::string value ){
	if ( method.compare("URL_GET") == 0 ){
		return !_GET[value].empty();
	}else if ( method.compare("URL_POST") == 0){
		//return _POST[value];
	}else if ( method.compare("URL_FILE") == 0){
		//return _FILE[value];
	}else if ( method.compare("URL_REQUEST") == 0){
		//return _REQUEST[value];
	}else{
		return !_GET[value].empty();
	}
}

static int callback(void *data, int argc, char **argv, char **azColName){
	int i;

	for(i=0; i<argc-1; i++){
		std::string PARAM_T = azColName[i];
		std::string PARAM_GET = argv[i];
		vector<string> _PARAMS;

		
		std::size_t found = PARAM_GET.find("$$:");
		if ( found != string::npos ){
			split(argv[i], "$$:", _PARAMS, PARAM_T);
		}
	}

	return 0;
}

std::map<std::string, std::string> getURLPARAMData(std::string _pd = "GET")
{
   sqlite3 *db;
   char *zErrMsg = "";
   int rc;
   char *sql;
   const char* data = "Callback function called";

   rc = sqlite3_open("default_project/db.db", &db);

   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }
   
   /* Create SQL statement */
   std::string tS = "SELECT * from session_data WHERE SESSION_ID = '"+ session_id + "' order by -ID LIMIT 1";
   sql = (char*)tS.c_str();

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db);

   if ( _pd.compare("GET") == 0 ){
	   return _GET;
   }else if ( _pd.compare("POST") == 0 ){
	   return _POST;
   }if ( _pd.compare("REQUEST") == 0 ){
	   return _REQUEST;
   }else{
	   return _GET;
   } 

	std::map<std::string, std::string> dd;
	return dd;

   return _GET;
}
