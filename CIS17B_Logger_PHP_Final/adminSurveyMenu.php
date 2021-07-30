<?php

require ("index.php");
$q="SELECT surveyID, surveyName FROM surveys";
$rs=mysqli_query($conn, $q);

?>

<html>
   
    <head>
        <link rel="stylesheet" href="StyleSheet.css">
        <title> Admin: View Surveys</title>
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
<!--            <div class="vertical-menu">
            </div>-->   
        <div class="viewSurveys">
        <a href="administrator.php" >Return</a>
        <?php
        while ($rsTemp=mysqli_fetch_array($rs)){
            echo "<a href='administrator.php'>".$rsTemp['surveyName']."</a>";
        }
        ?>
        </div>             
            
    </body>
</html>