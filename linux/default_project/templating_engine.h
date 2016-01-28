std::string program_template_code;
#define _string std::string

char* f(int& argc, char** const& argv){
    std::cout << argv[0] << std::endl; // a

	return argv[2];
}

int preg_template_contents(){
	int yy = 0;
	printf(program_template_code.c_str());
	while ( yy >= 0 ){
		char* ptr;
		int pos = -1;
		int pos2 = -1;

		ptr=strstr((char*)program_template_code.c_str(),"{{");
		pos = ptr - program_template_code.c_str();

		yy= pos;

		if ( pos < 0 ){
			break;
		}
	
		ptr=strstr((char*)program_template_code.c_str(),"}}");
		pos2 = ptr - program_template_code.c_str();
	
		_string ss;
		if ( pos >= 0 ){ 
			for ( int i = pos+2; i < pos2; i++ ){
				ss += program_template_code[i];
				//printf((char*)program_template_code[i]);
			}
		}
	
		char *str = (char*)ss.c_str();
		char *str2 = (char*) malloc ( sizeof (char*) );
		char * pch;
		//printf ("Splitting string \"%s\" into tokens:\n",str);
		pch = strtok (str,".");

		int xx = 0;
		while (pch != NULL)
		{
			str2 = pch;
			pch = strtok (NULL, ".");
			xx++;
		}

		_string testg = data[str][str2];
		program_template_code = program_template_code.replace(pos, (pos2+2)-pos, data[str][str2]);
	}

	printf("\n---\n");
	printf((char*)program_template_code.c_str());
	return 1;
}
