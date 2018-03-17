count = 0;

function func() {

    setTimeout(function () {
        document.getElementById("p1").style.color = "red";
    }, 5000);

    setInterval(function () {
        var x = count % 4;
        if (x == 0)
            document.getElementById("img").style.left = 500 + "px";
        else if (x == 1)
            document.getElementById("img").style.top = 200 + "px";
        else if (x == 2)
            document.getElementById("img").style.left = "0";
        else
            document.getElementById("img").style.top = "0";

        count++;
    }, 2000)
}



