# Configurando o Ambiente

Este guia fornece os passos essenciais para configurar seu ambiente local e começar os estudos práticos de segurança ofensiva.

---

## 🐧 1. Instalar o Kali Linux

Kali Linux é uma distribuição do sistema operacional Linux voltada para testes de penetração, análise de vulnerabilidades e segurança ofensiva. Ela vem pré-instalada com uma série de ferramentas para hacking ético, como Nmap, Burp Suite, Metasploit, Wireshark, John the Ripper, entre outras.

**Opção recomendada**: Executar o Kali como uma máquina virtual via VirtualBox.

➡️ [Download Kali Linux](https://www.kali.org/get-kali/#kali-virtual-machines).

**Versão sugerida**: `Kali Linux 64-bit VirtualBox`

---

## 📦 2. Instalar o VirtualBox

VirtualBox é o software de virtualização gratuito que utilizamos para rodar o Kali Linux.

➡️ [Download VirtualBox](https://www.virtualbox.org/wiki/Downloads)

Após a instalação, você pode adicionar a imagem do Kali baixada anteriormente com **`Acrescentar > (selecione o arquivo .vbox baixado)`** e já deve funcionar.
Você pode testar a instalação com a opção de **`Iniciar (T)`**. Se forem seguidos os todos os passos corretamente, as credenciais padrões do sistema serão  **`Usuário: kali e Senha: kali`**.

---

## 🌐 3. Configurar a rede da VM (Modo Bridge)

Para que sua máquina Kali seja acessível na mesma rede do seu computador:

1. Com a VM desligada, vá até `Configurações > Rede`
2. Altere o **Conectado a:** de `NAT` para `Placa em modo Bridge`
3. Escolha sua interface de rede (geralmente `wlan0` ou `eth0`)

Isso permite que o sistema rodando na máquina virtual tenha acesso a outras máquinas na rede local e permite a conexão com VPNs como TryHackMe.

---

## 🧠 4. Criar uma Conta no TryHackMe

TryHackMe é a principal plataforma prática de labs e CTFs utilizadas pela UFSC - OFFSEC. Recomendamos criar um conta gratuita para ter acesso aos desafios abordados ao longo da atuação do projeto.

➡️ [TryHackMe](https://tryhackme.com)

---

## 🔐 5. Baixar e Configurar a VPN do TryHackMe

Para acessar os labs via Kali, é preciso configurar uma VPN:

1. Vá em [https://tryhackme.com/access](https://tryhackme.com/access)
2. Selecione o servidor `US-East-Regular-1`
3. Gere e baixe o arquivo `.ovpn` personalizado
3. No Kali, abra um terminal e execute:

```bash
sudo apt update         # Opcional
sudo apt upgrade        # Opcional
sudo apt install openvpn
sudo openvpn ~/Downloads/seuarquivo.ovpn
```
Com isso, tudo já deve estar devidamente configurado e você pode seguir os [Primeiros Passos](../get_started/) para iniciar os estudos sobre Segurança Ofensiva.