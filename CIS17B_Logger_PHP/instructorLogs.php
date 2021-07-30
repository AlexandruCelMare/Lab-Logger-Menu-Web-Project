<?php
session_start();
require ("functions.php");
require ("index.php");
console_log($_SESSION['instructor']);
$q="SELECT `instructorHours`.`date`, `instructorHours`.`hours` FROM"
        . " `logger`.`instructor` AS"
        . " `instructor`, `logger`.`instructorHours` AS"
        . " `instructorHours` WHERE"
        . " `instructor`.`instructorID` = `instructorHours`.`instructorID`"
        . " AND instructor.instructorID='".$_SESSION['instructor']."'";

$rs=mysqli_query($conn, $q);
//session_close();
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
        SERVE-A
        </h1>
        <h2 style = "font-family:verdana;">
        Serving Before Surveying
        </h2>
<!--            <div class="vertical-menu">
            </div>-->
        <div class="takeReturn">
        <a href="userSurveyMenu.php" >Return</a>
        </div>
        <div class="takeSurveys">
        <?php
//        console_log($rs['Survey Name']);
        echo '<h5> instructorID: '.$_SESSION['instructor']. '</h5>';
        echo '<h5> instructorID: '.$_SESSION['instructor']. '</h5>';
        $row=mysqli_fetch_all($rs);
        $temp='';
        console_log($row);
        foreach($row as $r){
//            console_log($r['2']);
            if ($temp!==$r[0]){
                echo '<h6> '.$r['0']. '</h6>';
            }
            else{

            }
            
            echo '<input type="radio" value="'.$r['0']. '">'.$r['1'].'<br>';
            $temp=$r['0'];
        }
        ?>
        </div>
        <div class="rSubmit">        
        <input type = 'submit'  name = 'survey' />    
        </div>
    </body>
</html>
