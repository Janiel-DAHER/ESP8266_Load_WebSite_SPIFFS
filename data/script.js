 
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("liregas").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/liregas", true);
  xhttp.send();
}, 2000 ) ;
