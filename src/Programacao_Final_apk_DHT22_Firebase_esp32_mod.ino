// DESENVOLVIDO POR THIAGO ALTAMIR //

#include <WiFi.h> //Lib WiFi
#include <SimpleDHT.h> //Lib DHT
#include <IOXhop_FirebaseESP32.h> //Lib Firebase
#include <ArduinoJson.h> //Lib para a manipulação de Json


#define FIREBASE_HOST "URL" // URL da base de dados fornecido pelo Firebase para a conexão http
#define FIREBASE_AUTH "CHAVE" // Autenticação do Firebase

#define DHTPIN 15 //Pino onde o DHT estão ligado 
#define DHTPIN2 2 //Pino onde o DHT2 estão ligado
#define DHTPIN3 4 //Pino onde o DHT3 estão ligado
#define DHTPIN4 5 //Pino onde o DHT4 estão ligado
#define DHTPIN5 18 //Pino onde o DHT5 estão ligado
#define DHTPIN6 19 //Pino onde o DHT6 estão ligado
#define DHTPIN7 21 //Pino onde o DHT7 estão ligado
#define DHTPIN8 13 //Pino onde o DHT8 estão ligado
#define DHTPIN9 32 //Pino onde o DHT9 estão ligado
#define DHTPIN10 33 //Pino onde o DHT10 estão ligado
#define DHTPIN11 25 //Pino onde o DHT11 estão ligado
#define DHTPIN12 26 //Pino onde o DHT12 estão ligado
#define EXAUSTOR 27 // Pino do Relé do Exaustor
#define INTERVAL 60000 //Intervalo entre cada leitura do sensor em milisegundo

//SSID e senha da rede WiFi onde o esp32 irá se conectar 
#define SSID "NOME_DA_REDE"
#define PASSWORD "SENHA"

//Objeto que realiza a leitura da umidade e temperatura
SimpleDHT22 dht;
SimpleDHT22 dht2;
SimpleDHT22 dht3;
SimpleDHT22 dht4;
SimpleDHT22 dht5;
SimpleDHT22 dht6;
SimpleDHT22 dht7;
SimpleDHT22 dht8;
SimpleDHT22 dht9;
SimpleDHT22 dht10;
SimpleDHT22 dht11;
SimpleDHT22 dht12;

//Variáveis que vão guardar o valor da temperatura e umidade
bool status_apk = false;
bool exaustor = false;
float temperature, humidity;
float temperature2, humidity2;
float temperature3, humidity3;
float temperature4, humidity4;
float temperature5, humidity5;
float temperature6, humidity6;
float temperature7, humidity7;
float temperature8, humidity8;
float temperature9, humidity9;
float temperature10, humidity10;
float temperature11, humidity11;
float temperature12, humidity12;

//Marca quando foi feita a última leitura
uint32_t lastTimeRead = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(EXAUSTOR, OUTPUT); // Define como saída
  digitalWrite(EXAUSTOR, LOW);
  
  //Inicializa a conexão com a rede WiFi
  setupWiFi();

  //Inicializa a lib do Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

//Conexão com a rede WiFi
void setupWiFi()
{
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);

  //Tenta conectar à rede que possui este SSID e senha
  WiFi.begin(SSID, PASSWORD);
  Serial.println("");

  //Enquanto não estiver conectado à rede WiFi
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }

  //Se chegou aqui está conectado
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(SSID);

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  status_apk = true;
}

void loop()
{
  //Tempo em millissegundos desde o boot do Esp
  unsigned long now = millis();

  //Se passou o intervalo desde a última leitura
  if(now - lastTimeRead > INTERVAL)
  {

    Serial.print("Temperatura: ");              // imprime a Temperatura
    Serial.print(temperature);
    Serial.println(" *C");

    Serial.print("Umidade: ");                  // imprime a Umidade
    Serial.print(humidity);
    Serial.println("%");

    Serial.print("Temperatura12: ");              // imprime a Temperatura
    Serial.print(temperature12);
    Serial.println(" *C");

    Serial.print("Umidade12: ");                  // imprime a Umidade
    Serial.print(humidity12);
    Serial.println("%");
    
    //Faz a leitura do sensor
    readSensor();

    //Envia para o Firebase
    sendToFirebase();

    //Marca quando ocorreu a Ãºltima leitura
    lastTimeRead = now;
  }
}

//Realiza a leitura da temperatura e umidade
void readSensor()
{
  float t, h, t2, h2, t3, h3, t4, h4, t5, h5, t6, h6;
  float t7, h7, t8, h8, t9, h9, t10, h10, t11, h11, t12, h12;
  
  //Coloca o valor lido da temperatura em t e da umidade em h
  int status = dht.read2(DHTPIN, &t, &h, NULL);
  int status2 = dht2.read2(DHTPIN2, &t2, &h2, NULL);
  int status3 = dht3.read2(DHTPIN3, &t3, &h3, NULL);
  int status4 = dht4.read2(DHTPIN4, &t4, &h4, NULL);
  int status5 = dht5.read2(DHTPIN5, &t5, &h5, NULL);
  int status6 = dht6.read2(DHTPIN6, &t6, &h6, NULL);
  int status7 = dht7.read2(DHTPIN7, &t7, &h7, NULL);
  int status8 = dht8.read2(DHTPIN8, &t8, &h8, NULL);
  int status9 = dht9.read2(DHTPIN9, &t9, &h9, NULL);
  int status10 = dht10.read2(DHTPIN10, &t10, &h10, NULL);
  int status11 = dht11.read2(DHTPIN11, &t11, &h11, NULL);
  int status12 = dht12.read2(DHTPIN12, &t12, &h12, NULL);
 
  //Se a leitura foi bem sucedida
  if (status == SimpleDHTErrSuccess) {
    //Os valores foram lidos corretamente, então colocar nas variaveis
    temperature = t;
    humidity = h;
    temperature2 = t2;
    humidity2 = h2;
    temperature3 = t3;
    humidity3 = h3;
    temperature4 = t4;
    humidity4 = h4;
    temperature5 = t5;
    humidity5 = h5;
    temperature6 = t6;
    humidity6 = h6;
    temperature7 = t7;
    humidity7 = h7;
    temperature8 = t8;
    humidity8 = h8;
    temperature9 = t9;
    humidity9 = h9;
    temperature10 = t10;
    humidity10 = h10;
    temperature11 = t11;
    humidity11 = h11;
    temperature12 = t12;
    humidity12 = h12;
  }
}

//Envia os valores de temperatura e umidade para o Firebase
void sendToFirebase()
{

 // Colocar valores no Banco de dados
 // Coletor e Conexão com o apk
  Firebase.setBool("/Monitoramento/status_apk", status_apk);
  Firebase.setFloat("/Monitoramento/coletor/sensor1/temp", temperature);
  Firebase.setFloat("/Monitoramento/coletor/sensor1/umi", humidity);
  Firebase.setFloat("/Monitoramento/coletor/sensor2/temp", temperature2);
  Firebase.setFloat("/Monitoramento/coletor/sensor2/umi", humidity2);
  Firebase.setFloat("/Monitoramento/coletor/sensor3/temp", temperature3);
  Firebase.setFloat("/Monitoramento/coletor/sensor3/umi", humidity3);
  Firebase.setFloat("/Monitoramento/coletor/sensor4/temp", temperature4);
  Firebase.setFloat("/Monitoramento/coletor/sensor4/umi", humidity4);
  Firebase.setFloat("/Monitoramento/coletor/sensor5/temp", temperature5);
  Firebase.setFloat("/Monitoramento/coletor/sensor5/umi", humidity5);
  Firebase.setFloat("/Monitoramento/coletor/sensor6/temp", temperature6);
  Firebase.setFloat("/Monitoramento/coletor/sensor6/umi", humidity6);
  Firebase.setFloat("/Monitoramento/coletor/sensor7/temp", temperature7);
  Firebase.setFloat("/Monitoramento/coletor/sensor7/umi", humidity7);
  Firebase.setFloat("/Monitoramento/coletor/sensor8/temp", temperature8);
  Firebase.setFloat("/Monitoramento/coletor/sensor8/umi", humidity8);
  Firebase.setFloat("/Monitoramento/coletor/sensor9/temp", temperature9);
  Firebase.setFloat("/Monitoramento/coletor/sensor9/umi", humidity9);
  
  // Estufa e Exaustor
  Firebase.setFloat("/Monitoramento/estufa/sensor10/temp", temperature10);
  Firebase.setFloat("/Monitoramento/estufa/sensor10/umi", humidity10);
  Firebase.setFloat("/Monitoramento/estufa/sensor11/temp", temperature11);
  Firebase.setFloat("/Monitoramento/estufa/sensor11/umi", humidity11);
  Firebase.setFloat("/Monitoramento/estufa/sensor12/temp", temperature12);
  Firebase.setFloat("/Monitoramento/estufa/sensor12/umi", humidity12);

 // Controle do exaustor por meio da temp. do sensor12
    if (temperature12 >= 45){
  Firebase.setBool("/Monitoramento/estufa/exaustor", true);
  digitalWrite(EXAUSTOR, HIGH);
  }
    else{
  Firebase.setBool("/Monitoramento/estufa/exaustor", false);
  digitalWrite(EXAUSTOR, LOW);
  }
}
 
  
