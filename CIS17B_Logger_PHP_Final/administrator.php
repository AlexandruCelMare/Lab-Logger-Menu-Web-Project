<?php 
session_start();
require ("functions.php");

?>


<html>
    <head>
        <link rel="stylesheet" href="StyleSheet.css">
        <title>Administrator Options</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
        <body>
        
                <div class="horizontal-menu">
        <a href="index.html" >Home</a>
        <a href="login.html" class="active">Login</a>
        <a href="about.html">About</a>
        </div>           
            
        <h1 style = "font-family:verdana;">
        LOG-SHEET 2.0
        </h1>
        <h2 style = "font-family:verdana;">
        The Lab Login Sheet, but Like Better
        </h2>
            <div class="vertical-menu">
            </div>
            
        <div class="vertical-menu">
            <a href="login.html" >Return</a>
            <a href="adminViewStudents.php?pName=adminDeleteStudent"> Delete Student</a>
        <a  href="adminViewInstructors.php?pName=adminDeleteInstructor" >Delete Instructor</a>
        <a href="adminViewStudents.php?pName=studentLogs"> View Student Logs</a>
        <a  href="adminViewInstructors.php?pName=adminViewInstructorLogs" > View Instructor Logs</a>
        </div>  
    </body>
</html>
