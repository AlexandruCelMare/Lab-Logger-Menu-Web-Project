<?php
session_start();
require ("functions.php");
require ("index.php");
console_log($_SESSION['student']);
$q="DELETE FROM student WHERE studentID ='".$_SESSION['student']."'";
$rs=mysqli_query($conn, $q);
$q="DELETE FROM studentHours WHERE studentID ='".$_SESSION['student']."'";
$rs=mysqli_query($conn, $q);
//session_close();
redirect_user('adminViewStudents.php?pName='.$_SESSION['pName']);
?>


