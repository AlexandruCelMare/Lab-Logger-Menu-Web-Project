<?php

if ($_SERVER['REQUEST_METHOD']=='POST'){
    require('index.php');
    require('functions.php');
    $errors=array();
    
//    if (empty($_POST['username'])){
//        
//    }
    
    $q=mysqli_query($conn, "SELECT instructorID FROM instructor WHERE instructorID=".$_POST['instructorID']);
    console_log($q);
    if (!$q || mysqli_num_rows($q)==0){
        $username= mysqli_real_escape_string($conn, trim($_POST['instructorID']));
    }
    else{
        $errors[]='This username already exists';
    }
//    if (rExpression($_POST['password'])){
         $password= mysqli_real_escape_string($conn, trim($_POST['password']));
//    }
//    else {
//        $error[]= 'min length 6, max length 20, and must contain: at least one digit, one lowercase letter,'
//                . 'one uppercase letter, and one special symbol(@#$%)';
//    }
    $courseID= mysqli_real_escape_string($conn, trim($_POST['courseID']));    
    $firstName= mysqli_real_escape_string($conn, trim($_POST['firstName']));
    $lastName= mysqli_real_escape_string($conn, trim($_POST['lastName']));
    console_log($errors);
    if (empty($errors)){
        $q="INSERT INTO instructor (instructorID, password, firstName, lastName, course) VALUES ('$username', '$password', '$firstName', '$lastName', '$courseID')";
        console_log($q);
        if ($conn->query($q)===TRUE){
        redirect_user("instructorOptions.html");
        }
        else {
            echo "Error".$q."<br>".$conn->error;
        }
        mysqli_close($conn);
        exit();
    }
}
/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */