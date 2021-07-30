<?php

session_start();
if ($_SERVER['REQUEST_METHOD']=='POST'){
    require('functions.php');
    require('index.php');
    
    list($check, $data)= checkAdminLogin($conn, $_POST['adminID'], $_POST['adminPassword']);
    if ($check){
        echo 'login';
        $_SESSION['username']=$data['username'];
        $_SESSION['password']=$data['password'];
        $_SESSION['agent']=md5($_SERVER['HTTP_USER_AGENT']);
        redirect_user("administrator.php");
    }
    else{
        $errors[]=$data;
    }
    mysqli_close($conn);
    
}
redirect_user("adminLoginError.html");

?>