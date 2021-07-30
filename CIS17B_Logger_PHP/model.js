    function userLogin(form){
//        var username = document.getElementById("usernameID").value;
//        var password = document.getElementById("passwordID").value;
        var username = form.username.value;     
        document.getElementById("itDoesntMatter").innerHTML = username;
        console.log(username);
 
//        var username = prompt("Please enter username: \n\n");
        return false;

    };

