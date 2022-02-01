setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("liretemperature").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/liretemperature", true);
  xhttp.send();
}, 2000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("lirehumidity").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/lirehumidity", true);
  xhttp.send();
}, 2000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("lirevitesse").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/lirevitesse", true);
  xhttp.send();
}, 2000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("lireroute").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/lireroute", true);
  xhttp.send();
}, 2000 ) ;

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


setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("lirealt").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/lirealt", true);
  xhttp.send();
}, 2000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("lireele").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/lireele", true);
  xhttp.send();
}, 2000 ) ;
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("lirenbsat").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/lirenbsat", true);
  xhttp.send();
}, 2000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("liretime").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/liretime", true);
  xhttp.send();
}, 2000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("lireminute").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/lireminute", true);
  xhttp.send();
}, 2000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("lireseconde").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/lireseconde", true);
  xhttp.send();
}, 2000 ) ;
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("lirelng").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/lirelng", true);
  xhttp.send();
}, 2000 ) ;

function toggleCheckbox(element) {
                var xhr = new XMLHttpRequest();
                if(element.checked){ xhr.open("GET", "/update?relay="+element.id+"&state=1", true); xhr.send();
                    setTimeout(function(){ xhr.open("GET", "/update?relay="+element.id+"&state=0", true); document.getElementById(element.id).checked = false; xhr.send(); }, 1000);}  
                }

