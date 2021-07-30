<?php
session_start();
require ("index.php");
require ("functions.php");
$q="SELECT studentID FROM student";
$rs=mysqli_query($conn, $q);
if ($_SERVER['REQUEST_METHOD']=='POST'){
    $_SESSION['student']=$_POST['student'];
    redirect_user('adminDeleteStudent.php?pName='.$_SESSION['pName']);
}
?>



<html>
   
    <head>
        <link rel="stylesheet" href="StyleSheet.css">
        <title>User: Survey Menu</title>
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
        SERVE-A
        </h1>
        <h2 style = "font-family:verdana;">
        Serving Before Surveying
        </h2>
<!--            <div class="vertical-menu">
            </div>-->
            
        <div class="viewSurveys">
        <form action = "adminViewStudents.php" method = "post">
        <a href="administrator.php" >Return</a>
        <?php
        while ($rsTemp=mysqli_fetch_array($rs)){
            echo "<input type = 'submit' value=".$rsTemp['studentID']." name = 'student' />";
        }
        ?>
        </form>
        </div>       
    </body>
</html>