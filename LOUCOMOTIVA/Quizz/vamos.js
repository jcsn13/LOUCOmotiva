var cont = [0,0,0,0]
function add(vet){
      if (vet == 0){ cont[vet]++;}
      if (vet == 1){ cont[vet]++;}
      if (vet == 2){ cont[vet]++;}
      if (vet == 3){ cont[vet]++;}
      alert(cont)
}
function myFunction(){
    document.getElementById('imagem').style="border:5px solid #021a4;"
}
var modal = document.getElementById("myModal");

function abrir(){
    if (confirm("deseja continuar") == true)
        modal.style.display = "block";
    else
        modal.style.display = "none";
}

