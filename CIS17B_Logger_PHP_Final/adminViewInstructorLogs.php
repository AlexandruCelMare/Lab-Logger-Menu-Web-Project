<?php
session_start();
require ("index.php");
require ("functions.php");
$q="SELECT instructorID FROM instructor";
$rs=mysqli_query($conn, $q);
if ($_SERVER['REQUEST_METHOD']=='POST'){
    $_SESSION['instructor']=$_POST['instructor'];
    redirect_user('adminDeleteInstructor.php?pName='.$_SESSION['pName']);
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
        <form action = "adminViewInstructors.php" method = "post">
        <a href="administrator.php" >Return</a>
        <?php
        while ($rsTemp=mysqli_fetch_array($rs)){
            echo "<input type = 'submit' value=".$rsTemp['instructorID']." name = 'instructor' />";
        }
        ?>
        </form>
        </div>       
    </body>
</html>