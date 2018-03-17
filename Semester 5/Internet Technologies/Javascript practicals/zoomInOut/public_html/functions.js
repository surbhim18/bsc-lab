count = 0;

function func() {
    
    setInterval(function () {
        var x = count % 2;
        if (x == 0)
        {
            document.getElementById("imag").style.width = 304 + "px";
            document.getElementById("image").style.height = 228 + "px";
        }            
        else
        {
            document.getElementById("image").style.width = 204 +"px";
            document.getElementById("image").style.height = 128 + "px";
        }
            
        count++;
    }, 1000)
}



