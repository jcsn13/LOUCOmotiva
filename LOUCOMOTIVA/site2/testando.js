'use strict';
var numberOfItems = $('#page .list-group').length; 
var limitPerPage = 1; 
$('#page .list-group:gt(' + (limitPerPage - 1) + ')').hide(); 
var totalPages = Math.round(numberOfItems / limitPerPage); 
$(".pagination").append("<li style class='current-page active'> + 1 + <a href='javascript:void(0)'></a></li>"); 

for (var i = 2; i <= totalPages; i++) {
  $(".pagination").append("<li  class='current-page'><a href='javascript:void(0)'></a></li>"); 
}

$(".pagination").append("<li id='next-page'><a href='javascript:void(0)' ><span aria-hidden=true>Continuar</span></a></li>");


$("#next-page").on("click", function next() {
  //if (confirm('Deseja continuar')) {
  var currentPage = $(".pagination li.active").index(); 
  if (currentPage === totalPages) {
    return false; 
  } else {
    currentPage++; 
    $(".pagination li").removeClass('active'); 
    $("#page .list-group").hide(); 
    var grandTotal = limitPerPage * currentPage;

    
    for (var i = grandTotal - limitPerPage; i < grandTotal; i++) {
      $("#page .list-group:eq(" + i + ")").show(); 
    }

    $(".pagination li.current-page:eq(" + (currentPage - 1) + ")").addClass('active'); 
  }
//}
 // else {
//}
  
});




$("#previous-page").on("click", function() {
  var currentPage = $(".pagination li.active").index(); 
  if (currentPage === 1) {
    return false; 
  } else {
    currentPage--;
    $(".pagination li").removeClass('active'); 
    $("#page .list-group").hide(); 
    var grandTotal = limitPerPage * currentPage; 

    for (var i = grandTotal - limitPerPage; i < grandTotal; i++) {
      $("#page .list-group:eq(" + i + ")").show(); 
    }

    $(".pagination li.current-page:eq(" + (currentPage - 1) + ")").addClass('active');
  }
});


var VPE1 = $("#VPE1");
VPE1.hide();
var VPE2 = $("#VPE2");
VPE2.hide();
var VPE3 = $("#VPE3");
VPE3.hide();
var VPE4 = $("#VPE4");
VPE4.hide();
var VSE1 = $("#VSE1");
VSE1.hide();
var VSE2 = $("#VSE2");
VSE2.hide();
var VSE3 = $("#VSE3");
VSE3.hide();
var VSE4 = $("#VSE4");
VSE4.hide();
var VTE1 = $("#VTE1");
VTE1.hide();
var VTE2 = $("#VTE2");
VTE2.hide();
var VTE3 = $("#VTE3");
VTE3.hide();
var VTE4 = $("#VTE4");
VTE4.hide();
var VQE1 = $("#VQE1");
VQE1.hide();
var VQE2 = $("#VQE2");
VQE2.hide();
var VQE3 = $("#VQE3");
VQE3.hide();
var VQE4 = $("#VQE4");
VQE4.hide();
var cont = [0,0,0,0]
function pegar1(vet){
  if (confirm('quer selecionar essa imagem?')) {
      if (vet == 0){ cont[vet]++;  VPE1.show();}
      if (vet == 1){ cont[vet]++;  VPE2.show();}
      if (vet == 2){ cont[vet]++;  VPE3.show()}
      if (vet == 3){ cont[vet]++;  VPE4.show()}
      alert(" clikar no botão continuar \n se escolher mais de uma opção reinicie")
}
else{
  alert("escolha outra imagem \n ou aperte continuar")
}
}
function pegar2(vet){
  if (confirm('quer selecionar essa imagem?')) {
      if (vet == 0){ cont[vet]++; VSE1.show(); }
      if (vet == 1){ cont[vet]++; VSE2.show(); }
      if (vet == 2){ cont[vet]++; VSE3.show(); }
      if (vet == 3){ cont[vet]++; VSE4.show();}
      alert(cont)
}
else{
  alert("escolha outra")
}
}
function pegar3(vet){
  if (confirm('quer selecionar essa imagem?')) {
      if (vet == 0){ cont[vet]++;VTE1.show();}
      if (vet == 1){ cont[vet]++;VTE2.show();}
      if (vet == 2){ cont[vet]++;VTE3.show();}
      if (vet == 3){ cont[vet]++;VTE4.show();}
      alert(cont)
}
else{
  alert("escolha outra")
}
}
function pegar4(vet){
  if (confirm('quer selecionar essa imagem?')) {
      if (vet == 0){ cont[vet]++;VQE1.show();}
      if (vet == 1){ cont[vet]++;VQE2.show();}
      if (vet == 2){ cont[vet]++;VQE3.show();}
      if (vet == 3){ cont[vet]++;VQE4.show();}
      alert(cont)
}
else{
  alert("escolha outra")
}
}


var resultado1 = $("#resultado1");
resultado1.hide();
var resultado2 = $("#resultado2");
resultado2.hide();
var resultado3 = $("#resultado3");
resultado3.hide();
var resultado4 = $("#resultado4");
resultado4.hide();


function resultado(){
  
  function largestIndex(array){
    var counter = 1;
    var max = 0;
  
    for(counter; counter < array.length; counter++){
      if(array[max] < array[counter]){
          max = counter;
      }
    }
    return max;
  }
  if(largestIndex(cont) == 0){
    resultado1.show();
  }
  if(largestIndex(cont) == 1){
    resultado2.show();
  }
  if(largestIndex(cont) == 2){
    resultado3.show();
  }
  if(largestIndex(cont) == 3){
    resultado4.show();
  }
  
}




