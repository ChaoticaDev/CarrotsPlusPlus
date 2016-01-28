# Carrots++
Native C/C++ Web Applications || via Visual Studio

This is my attempt (@MontrayDavis Twitter) to create native C/C++ Web Applications! Especially great for extremely heaving database management, or Big Data processing -- and everything in between. While this service is better suited for large back-end projects, the templating engine makes it possible to create visually stunning applications that can easily take advantage of native code.

Additionally, I will add libraries to make things `easier` -- without losing much speed, of course.

# CarrotEngine UIX
The templating engine is very simple, and allows you to display variable data on the DOM. For Carrots++, we use double curly brackets as follows:

    Syntax: {{name.class}}
    
    {{data.MYSQL->tracks}}
    
    <div class="string" name="query" value="SELECT * FROM tracks" /> : defines a string named variable
    
    <data name="data" class="MYSQL->tracks" data-value="mysql_res_json(query).c_str()" /> : stores json response from database^
    
With three lines of HTML Markup code, we are able to extract an entire database, and return the entries (JSON format), and save as an object to the document. 

# Required Libraries/Headers 
# ( Visual Studio include Path )

  *Boost : http://www.boost.org/
  
  *MYSQLConnector/C (If you plan on using MYSQL) : https://dev.mysql.com/downloads/connector/c/
  
  *JsonCPP : https://github.com/open-source-parsers/jsoncpp (If you plan on using JSON)
  
  *PHP : https://php.net/ : This project is a PHP plugin (sort of, but not realy?).
 
If you use a version of Visual Studio (which is required) other than 2010, you should set the correct path in `cmd.ubr`, which is normally in the root directory.

# ( Linux Dependencies )
 *MYSQL: apt-get install mysql
 
 *g++: apt-get install g++
 
 gcc: apt-get install gcc

## Carrots++ Markup Language
  Carrots, in it's current state supports two flavors. The second thing, next to performance that we had in mind was simplicity. Should you choose not to, Carrots++ Markup Language allows you to easily harness the power of C++ -- without losing any performance. Our code is compiled to native C++ code. Especially great for those who are not up to coding/scripting. Now, you don't really have to.... Our Markup is so similar to HTML that you'll hardly know the difference. That means more output (with less work) from front-end developers. :D -- Documentation will be added as time allows via Wiki : https://github.com/UberSnip/CarrotsPlusPlus/wiki
  
## Hello World : `code.html`

 The `Hello World` project is simply named `simple`. The initial base code utilizes Carrots++. Expanding to c++ is as simple as adding the commonly known `<link />` HTML element. Simply link an external header, or one in the project directory, and `<execute />` the function -- and the magic begins. Examples provided in file `code.html`.
 
 You should note that if you make changes to `code.html`, you need to recompile the code by passing 2 to `$_GET['compile']`.
 
` https://domain.com/cppprog1/index.php?compile=2`

LINUX RUNS AT 2X THE SPEED OF WINDOWS.

LINUX:PHP=60x

WINDOWS:PHP=30x -- Windows will be up to speed very soon!

Checkout the sample code!
