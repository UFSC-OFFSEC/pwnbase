<div align="center">
  <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQtZE_Toisy_sQtGvGD4eVXHl30ylX8_gRslGEwAmo8yg&s=10" alt="Nmap" width="600"/>
</div>
# Configurando o Ambiente

Este guia fornece os passos essenciais para configurar seu ambiente local e começar os estudos práticos de segurança ofensiva.

---

## 1. Instalar o Kali Linux

Kali Linux é uma distribuição do sistema operacional Linux voltada para testes de penetração, análise de vulnerabilidades e segurança ofensiva. Ela vem pré-instalada com uma série de ferramentas para hacking ético, como Nmap, Burp Suite, Metasploit, Wireshark, John the Ripper, entre outras.

➡️ [Download Kali Linux](https://www.kali.org/get-kali/#kali-virtual-machines).

**Opção recomendada**: Executar o Kali como uma máquina virtual via VirtualBox.

**Versão sugerida**: `Kali Linux 64-bit VirtualBox`

---

## 2. Instalar o VirtualBox

VirtualBox é o software de virtualização gratuito que utilizamos para rodar o Kali Linux.

➡️ [Download VirtualBox](https://www.virtualbox.org/wiki/Downloads)


Após a instalação, você pode adicionar a imagem do Kali baixada anteriormente com **`Acrescentar > (selecione o arquivo .vbox baixado)`** e já deve funcionar.

---

## 3. Configurar a rede da VM

Para que sua máquina Kali seja acessível na mesma rede do seu computador:

1. Com a VM desligada, vá até `Configurações > Rede`
2. Altere o **Conectado a:** de `NAT` para `Placa em modo Bridge`
3. Escolha sua interface de rede (geralmente `wlan0` ou `eth0`)

Caso a internet não funcione na sua máquina Kali, tente:

1. Com a VM desligada, vá até `Configurações > Rede`
2. Altere o **Conectado a:** de `Placa em modo Bridge` para `NAT`

Isso permite que o sistema rodando na máquina virtual tenha acesso a outras máquinas na rede local e permite a conexão com VPNs como TryHackMe.

Você pode testar a instalação com a opção de **`Iniciar (T)`**. Se forem seguidos os todos os passos corretamente, as credenciais padrões do sistema serão  **`Usuário: kali`** e **` Senha: kali`**.

---

### 3.1. Configurar o Teclado da VM

Por padrão, o Kali vem com o teclado em inglês, para mudar:

1. No canto superior esquerdo, você deve encotrar a logo do kali (um quadrado azul com um dragão), clique;
2. Vá em **`Usual Applications`**;
3. Em seguida, vá em **`Settings`** e, depois, em **`Keyboard`**;
4. Em **`Layout`**, coloque o idioma `Portuguese (Brazil)`;
5. Em **`Layout Model`**, coloque `Generic 105-key PC`.

---

### 3.2 Atualização

Diferente de outros sistemas operacionais, no Linux a maioria dos programas não se atualiza silenciosamente em segundo plano. Por isso, é uma boa prática manter o sistema em dia manualmente. Recomendamos executar os comandos abaixo logo após a primeira instalação e com certa frequência:

```bash
sudo apt update        
sudo apt upgrade       
```

---


## 4. Criar uma Conta no TryHackMe

TryHackMe é a principal plataforma prática de labs e CTFs utilizadas pela UFSC - OFFSEC. Recomendamos criar um conta gratuita para ter acesso aos desafios abordados ao longo da atuação do projeto.

➡️ [TryHackMe](https://tryhackme.com)

---

## 5. Baixar e Configurar a VPN do TryHackMe

Para acessar os labs via Kali, é preciso configurar uma VPN que se conecte com o TryHackMe:

1. Vá em [https://tryhackme.com/access](https://tryhackme.com/access)
2. Na parte `OpenVPN (Advanced)` baixe a VPN em `Download configuration file`
3. No Kali, abra um terminal e execute:

```bash
sudo apt install openvpn
sudo openvpn ~/Downloads/seuarquivo.ovpn
```

---

## 6. Conclusão

Tudo pronto! Com o sistema devidamente configurado e atualizado você pode avançar para o próximo passo e começar a explorar os [comandos essenciais do Linux.](../%5B01%5D%20-%20fundamentals/%5B01%5D%20-%20Linux/)
