function validate() {
    
    var a = document.getElementById("a").value;
    var b = document.getElementById("b").value;
    var regex = /^[0-9]+$/;

    if (regex.test(a) && regex.test(b))
        return true;
    else
        return false;
    
}

