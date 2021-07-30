<?php
function checkStudentLogin($connect, $studentID, $password){
    $errors = array();
    if (empty($studentID)){
        $errors[]= "You forgot to enter your email address!";
    }
    else {
        $e= mysqli_real_escape_string($connect, trim($studentID));
    }
    if (empty($password)){
        $errors[]= "You forgot to enter your email address!";
    }
    else {
        $p= mysqli_real_escape_string($connect, trim($password));
    }
    

    if (empty($errors)){
        $q="SELECT studentID, password FROM student WHERE studentID = '$e' AND password = '$p'";
        $r=mysqli_query($connect, $q);
        if (mysqli_num_rows($r)){
            $row = mysqli_fetch_array($r,MYSQLI_ASSOC);
            return array(true, $row);
        }
        else{
            $errors[] = "ERROR!";
        }
    }
    
}

function checkInstructorLogin($connect, $instructorID, $password){
    $errors = array();
    if (empty($instructorID)){
        $errors[]= "You forgot to enter your email address!";
    }
    else {
        $e= mysqli_real_escape_string($connect, trim($instructorID));
    }
    if (empty($password)){
        $errors[]= "You forgot to enter your email address!";
    }
    else {
        $p= mysqli_real_escape_string($connect, trim($password));
    }
    

    if (empty($errors)){
        $q="SELECT instructorID, password FROM instructor WHERE instructorID = '$e' AND password = '$p'";
        $r=mysqli_query($connect, $q);
        if (mysqli_num_rows($r)){
            $row = mysqli_fetch_array($r,MYSQLI_ASSOC);
            return array(true, $row);
        }
        else{
            $errors[] = "ERROR!";
        }
    }
    
}

function checkAdminLogin($connect, $adminID, $adminPassword){
    $errors = array();
    if (empty($adminID)){
        $errors[]= "You forgot to enter your email address!";
    }
    else {
        $e= mysqli_real_escape_string($connect, trim($adminID));
    }
    if (empty($adminPassword)){
        $errors[]= "You forgot to enter your email address!";
    }
    else {
        $p= mysqli_real_escape_string($connect, trim($adminPassword));
    }
    

    if (empty($errors)){
        $q="SELECT username, password FROM admin WHERE username = '$e' AND password = '$p'";
        $r=mysqli_query($connect, $q);
        if (mysqli_num_rows($r)){
            $row = mysqli_fetch_array($r,MYSQLI_ASSOC);
            return array(true, $row);
        }
        else{
            $errors[] = "ERROR!";
        }
    }
    
}

function redirect_user($page){
    $url='http://'.$_SERVER['HTTP_HOST'].dirname($_SERVER['PHP_SELF']);
    $url= rtrim($url,'/\\');
    $url.='/'.$page;
    header("Location:$url");
    console_log('url='.$url);
    exit();
}

function console_log( $data ) {
  $output  = "<script>console.log( 'PHP debugger: ";
  $output .= json_encode(print_r($data, true));
  $output .= "' );</script>";
  echo $output;
}

//function rExpression($pass) {
//    $re = '((?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[@#$%]).{6,20})';
//    return preg_match($re, $pass);
//}
