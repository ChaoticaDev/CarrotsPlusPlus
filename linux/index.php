<?php
    if ( file_exists ( "ubr") ){
        //RECOMPILE THE APP ?
        
        $compile = isset($_GET['compile']) ? $_GET['compile'] : "1";
        $shellCode = shell_exec("./ubr ". $compile);
        
        $pos = strrpos($shellCode, "---");
        //echo $shellCode;
        echo substr($shellCode, $pos+4);
    }else{
    
        echo "no";
    }
?>