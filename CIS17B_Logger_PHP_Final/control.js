var control = {
    menuReturn:function{
    //    char menuR = 0;
        var menuR = prompt("\nReturn to menu? (y/n)\n\n");
        if (menuR == 'y'){
            menu();
        }
        else if (menuR == 'n'){
            exit(0);
        }
        else {
            menuReturn();
        }

    }
}

