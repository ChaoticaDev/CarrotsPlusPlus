std::string mysql_res_json(std::string query){

	printf("\n\n");
	char tmpbuff[33];
	
	int index, num_fields;
	index = 0;
	
	Json::Value jsonObj;
	Json::Value jsonChildObj;
	
	std::string buf[999];
	
	MYSQL_ROW row;
	MYSQL_FIELD* field;
	MYSQL_RES* result;

	
	std::string mysql_host = "ubersnip.com";
	std::string mysql_user = "advoice";
	std::string mysql_pass = "advoicemusic";
	std::string mysql_db = "advoice_musicstore";
	MYSQL* conn = mysql_init(NULL);

	
	if ( mysql_real_connect(conn, mysql_host.c_str(), mysql_user.c_str(), mysql_pass.c_str(), mysql_db.c_str(), 0, NULL, 0) ) {
		printf(mysql_get_client_info());
		data["data"]["mysql_status"] = "Connection Successuful: MYSQL\n";
	}

	else {
		printf(mysql_get_client_info());
		data["data"]["mysql_status"] = "Connection Failed: MYSQL\n";
	}

	if ( mysql_query(conn, query.c_str()) ) {
		data["data"]["mysql_status"] = "QUERY Successful: MYSQL\n";
	}

	else {
		data["data"]["mysql_status"] = "QUERY Failed: MYSQL\n";
	}

	result = mysql_store_result(conn);
	if ( !mysql_query(conn, query.c_str()) ) {
		data["data"]["mysql_status"] = "QUERY succeded returning results: MYSQL\n";
	}

	num_fields = mysql_num_fields(result);
	if ( result == NULL ) {
		printf(mysql_error(conn));
	}

	while ( field = mysql_fetch_field(result) ) {
		buf[index] = field->name;
		data["fields"][field->name] = itoa(index, tmpbuff, 10);
		index = index+1;

		
	}

	index = 0;
	while ( (row = mysql_fetch_row(result)) ) {
		for ( int i = 0; i < num_fields; i++ ) {
			//printf(buf[i].c_str());
			//printf(sep.c_str());
			//printf(row[i]);
			//printf(newline.c_str());

			data["tracks"][data["fields"][buf[i].c_str()]] = row[i];
			//printf(data["fields"][buf[i].c_str()].c_str());
			jsonChildObj[buf[i].c_str()] = row[i];
			jsonObj["results"][index] = jsonChildObj;
		}

		index++;

	}

	Json::FastWriter fastWriter;
	std::string output = fastWriter.write(jsonObj);

	return output;
}
