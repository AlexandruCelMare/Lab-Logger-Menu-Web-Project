<?php
session_start();
require ("functions.php");
require ("index.php");
console_log($_SESSION['instructor']);
$q="DELETE FROM instructor WHERE instructorID ='".$_SESSION['instructor']."'";
$rs=mysqli_query($conn, $q);
$q="DELETE FROM instructorHours WHERE instructorID ='".$_SESSION['instructor']."'";
$rs=mysqli_query($conn, $q);
//session_close();
redirect_user('adminViewInstructors.php?pName='.$_SESSION['pName']);
?>


