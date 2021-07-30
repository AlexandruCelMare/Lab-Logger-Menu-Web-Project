<?php

session_start();
if ($_SERVER['REQUEST_METHOD']=='POST'){
    require('functions.php');
    require('index.php');
    
    list($check, $data)= checkUserLogin($conn, $_POST['userID'], $_POST['password']);
    if ($check){
        echo 'login';
        $_SESSION['usernameID']=$data['usernameID'];
        $_SESSION['password']=$data['password'];
        $_SESSION['agent']=md5($_SERVER['HTTP_USER_AGENT']);
        redirect_user("studentOptions.html");
    }
    else{
        $errors[]=$data;
    }
    mysqli_close($conn);
    
}
//$page_title='login';
//if (isset($errors)&&!empty($errors)){
//    console_log($errors);
//    echo'<h3>ERROR</h3><p class="errors"> the following errors occur <br/>';
//    foreach ($errors as $msg){
//        echo "$msg<br/>\n";
//    }
//    echo '</p><p>Please try again </p>';
//}
redirect_user("loggingSuccessful.html");
?>


<!--<h1> login </h1>
    <form action = "login.php" method = "post">
    <input type="text" id="userID" name="userID">
    <input type="password" id="password" name="password" maxlength="50">
    <input type="submit" value="Submit">
    </form>-->