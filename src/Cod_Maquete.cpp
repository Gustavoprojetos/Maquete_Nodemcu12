#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

//Definições de variáveis
const int andasup = D0;
const int garagem = D1;
const int sala  = D2;
const int jardim  = D3;


// Porta de comunicacao (normalmente se utiliza a 80 ou 8080)
WiFiServer server(80);

void setup() {
  // Autoconexão com WiFi
   WiFiManager wifiManager;
   wifiManager.autoConnect("AutoConnectAP");

  // Para o node mcu esp8266 a velocidade do monitor serial e 115200
  Serial.begin(115200);
  delay(10);

  // inicializado luzes desligadas
  pinMode(andasup, OUTPUT);
  digitalWrite(andasup, 0);

  pinMode(garagem, OUTPUT);
  digitalWrite(garagem, 0);

  pinMode(sala, OUTPUT);
  digitalWrite(sala, 0);

  pinMode(jardim, OUTPUT);
  digitalWrite(jardim, 0);


  // Mostra no monitor serial informacoes de conexao da rede
  Serial.println();
  Serial.println();
  Serial.print("conectando em ");


  /* Enquanto nao conseguir conectar
    imprime um ponto na tela (dá a ideia de que esta carregando) */

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connectado");

  // Inicializa o servidor (nesse caso o proprio esp8266)
  server.begin();
  Serial.println("Servidor inicializado");

  // Mostra o IP do servidor
  Serial.println(WiFi.localIP());
}

void loop() {

  // Guarda o status do servidor
  WiFiClient client = server.available();
  if ( ! client) {
    return;
  }

  // Quando estiver alguem acessando
  Serial.println("novo cliente");

  // Enquanto nao tiver cliente
  while ( ! client.available()) {
    delay(1);
  }

  // Lê caracteres do buffer serial
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  // Andarsuperior
  if (req.indexOf("andarsuperior_on") != -1) {
    digitalWrite(andasup, 1);
    Serial.println(req.indexOf("andarsuperior_on"));

  } else if (req.indexOf("andarsuperior_off") != -1) {
    digitalWrite(andasup, 0);
    Serial.println(req.indexOf("andarsuperior_off"));
  }
  // Garagem
  if (req.indexOf("garagem_on") != -1) {
    digitalWrite(garagem, 1);
    Serial.println(req.indexOf("garagem_on"));

  } else if (req.indexOf("garagem_off") != -1) {
    digitalWrite(garagem, 0);
    Serial.println(req.indexOf("garagem_off"));
  }

  // Sala
  if (req.indexOf("sala_on") != -1) {
    digitalWrite(sala, 1);
    Serial.println(req.indexOf("sala_on"));

  } else if (req.indexOf("sala_off") != -1) {
    digitalWrite(sala, 0);
    Serial.println(req.indexOf("sala_off"));
  }

  // Jardim
  if (req.indexOf("jardim_on") != -1) {
    digitalWrite(jardim, 1);
    Serial.println(req.indexOf("jardim_on"));

  } else if (req.indexOf("jardim_off") != -1) {
    digitalWrite(jardim, 0);
    Serial.println(req.indexOf("jardim_off"));
  }



  Serial.println("Cliente desconectado");
}
