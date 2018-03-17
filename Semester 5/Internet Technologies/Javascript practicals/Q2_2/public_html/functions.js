
function chkPassword()
{
    var passwd = prompt("Please enter password: ");
    
    if(passwd == "surbhi")
        return true;
    else
        return chkPassword();
}

