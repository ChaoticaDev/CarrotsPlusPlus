<?php
    if ( file_exists ( "ubersnip_server.exe") ){
        //RECOMPILE THE APP ?
        
        $compile = isset($_GET['compile']) ? $_GET['compile'] : "1";
        $shellCode = shell_exec("ubersnip_server.exe ". $compile);
        
        $pos = strrpos($shellCode, "---");
        //echo $shellCode;
        echo substr($shellCode, $pos+4);
    }else{
    
        echo "no";
    }
?>