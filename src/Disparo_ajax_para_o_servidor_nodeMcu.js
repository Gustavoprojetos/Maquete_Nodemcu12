// Realiza um disparo via Ajax para o endereço do meu NodeMcu
var led_controle = function(status) {
  var xmlhttp = new XMLHttpRequest();
  var set_status = "http://192.168.0.102/?function=" + status;
  xmlhttp.open("POST", set_status);
  xmlhttp.send();
}

// Acessa os botões e passando as nossas diretivas de ligar ou desligar o led
var andarsuperior = function() {
  var andarsuperior_on = document.querySelector(".andarsuperior_on");
  andarsuperior_on.onclick = function() {
    led_controle("andarsuperior_on");
  }

  var Andarsuperior_off = document.querySelector(".andarsuperior_off");
  Andarsuperior_off.onclick = function() {
    led_controle("andarsuperior_off");
  }
}

var garagem = function() {
  var garagemLigar = document.querySelector(".garagemLigar");
  garagemLigar.onclick = function() {
    led_controle("garagem_on");
  }

  var garagemDesligar = document.querySelector(".garagemDesligar");
  garagemDesligar.onclick = function() {
    led_controle("garagem_off");
  }
}

var sala = function() {
  var sala_on = document.querySelector(".sala_on");
  sala_on.onclick = function() {
    led_controle("sala_on");
  }

  var sala_off = document.querySelector(".sala_off");
  sala_off.onclick = function() {
    led_controle("sala_off");
  }
}

var Jardim = function() {
  var jardim_on = document.querySelector(".jardim_on");
  jardim_on.onclick = function() {
    led_controle("jardim_on");
  }

  var jardim_off = document.querySelector(".jardim_off");
  jardim_off.onclick = function() {
    led_controle("jardim_off");
  }
}

window.onload = function() {
  // Chama as funçôes
  andarsuperior();
  garagem();
  sala();
  Jardim();
}
