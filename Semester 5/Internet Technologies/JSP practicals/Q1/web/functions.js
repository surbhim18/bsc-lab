function validate() {
    
    var num = document.getElementById("num").value;
    var regex = /^[0-9]+$/;

    if (regex.test(num))
        return true;
    else
        return false;
    
}

