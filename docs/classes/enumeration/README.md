# Ferramentas para Enumeração (NMAP, goBuster e ffuf)

➡️ [PDF da Aula](./pdf/recon.pdf) de NMAP desenvolvido por [@rideckszz](https://github.com/rideckszz)\
➡️ [PDF da Aula](./pdf/goBuster.pdf) de goBuster desenvolvido por [@ITA-LOW](https://github.com/ITA-LOW)\
➡️ [PDF da Aula](./pdf/ffuf.pdf) de ffuf desenvolvido por [@rideckszz](https://github.com/rideckszz)

---

## 🌐 NMAP

O Nmap (Network Mapper) é uma das ferramentas mais utilizadas em pentests e CTFs. Ele permite identificar hosts ativos, portas abertas, serviços em execução, versões de software e até sistemas operacionais.

A enumeração com Nmap faz parte das primeiras etapas de um ataque, permitindo mapear a superfície de ataque do alvo.

### 🧭 Tipos de Enumeração

### 🔹 Passiva
- Busca informações públicas sem interagir com o alvo.
- Exemplos: registros de domínio, redes sociais, motores de busca (Shodan, Censys).

#### 🔹 Ativa
- Interage diretamente com o alvo.
- Exemplos: varredura de portas, identificação de serviços, coleta de banners e vulnerabilidades.

⚠️ A enumeração ativa pode gerar alertas no sistema de segurança do alvo.

### 🛠️ Comandos Básicos do Nmap

```bash
nmap <IP-ALVO>                      # Escaneio Simples
nmap -p- <IP-ALVO>                  # Escanear todas as portas
nmap -p 22,80,443 <IP-ALVO>         # Escanear portas específicas
nmap -sV <IP-ALVO>                  # Identificação de versão dos serviços em execução
nmap -O <IP-ALVO>                   # Identificação de SO
nmap -A <IP-ALVO>                   # Varredura completa
```

### 📜 Scripts NSE (Nmap Scripting Engine)
Scripts prontos para verificar vulnerabilidades e serviços específicos.

```bash
nmap -sC <IP-ALVO>
nmap --script=http-vuln* -p 80,443 <IP-ALVO>
nmap --script=smb-enum-shares,smb-enum-users -p 445 <IP-ALVO>
nmap --script=vuln <IP-ALVO>
```

### ⚡ Velocidade e Performance

- `-T4` → mais rápido, menos furtivo
- `-F` → escaneia apenas as portas mais comuns
- `-v` → modo verboso

```bash
nmap -T4 -F -v <IP-ALVO>
```

### 🔐 Tipos de Escaneio

```bash
nmap -sS <IP-ALVO>                  # SYN Scan (rápido e furtivo)
nmap -sU <IP-ALVO>                  # UDP Scan
nmap -f <IP-ALVO>                   # Firewall Evasion (fragmentação de pacotes)
nmap -sA <IP-ALVO>                  # Portas filtradas por firewall
```

### 📂 Saída de Resultados
Salvar resultados em arquivo:
```bash
nmap -oN resultado.txt <IP-ALVO>       # Normal
nmap -oX resultado.xml <IP-ALVO>       # XML
nmap -oA scan_completo <IP-ALVO>       # Todos formatos
```

---

## 🕵️‍♂️ goBuster

O GoBuster é uma ferramenta de enumeração muito usada em CTFs e pentests. Ele serve para descobrir diretórios, arquivos escondidos, subdomínios e outras estruturas de um alvo.

Por que é importante?
- Muitas vezes desenvolvedores deixam diretórios ocultos para manutenção.
- Alguns caminhos podem não ser documentados e acabar sendo vulnerabilidades sérias.
- A enumeração revela a "superfície de ataque" de um site.

### ⚙️ Instalação

O goBuster é uma ferramenta que não está incluída por padrão no Kali Linux, dessa forma para utilizá-la é necessário realizar a instalação primeiros:

```bash
sudo apt install gobuster
```

### 📂 Wordlists

O GoBuster não funciona sozinho — ele precisa das chamadas wordlists, que são arquivos de texto com palavras a serem testadas como nomes de diretórios, usuários ou senhas.

Exemplos:

- Diretórios comuns: [directory.txt](https://raw.githubusercontent.com/teamstealthsec/wordlists/master/directory.txt)
- Senhas populares: [rockyou.txt](https://github.com/teamstealthsec/wordlists/blob/master/rockyou.txt.gz)
- Diversas wordlistas encontradas no Kali em `/usr/share/wordlists`

### 📌 Modos de Uso

O GoBuster possui vários modos. Entre os mais usados:

- `dir` → Enumeração de diretórios e arquivos
- `dns` → Enumeração de subdomínios
- `fuzz` → Fuzzing (substitui FUZZ na URL, cabeçalhos e corpo da requisição)
- `vhost` → Descobre hosts virtuais em servidores web

```bash
gobuster -h                                                 # Ajuda geral da ferramenta
gobuster <modo> --help                                      # Ajuda no modo específico

gobuster dir -u https://exemplo.com -w wordlist.txt         # Descobrir diretórios e arquivos ocultos
gobuster dns -d exemplo.com -w domains.txt --wildcard       # Enumerar subdomínios
gobuster fuzz -u https://ex.com/login.php -w rockyou.txt    # Ataque com wordlist de senhas
```

### 🚩 Flags Úteis

|Flag|Função|
|---|---|
|`-u`|Define a URL ou domínio alvo|
|`-w`|Define a wordlist|
|`-o`|Salva resultados em arquivo|
|`-t`|Define número de threads (padrão: 10)|
|`--wildcard`|Trata páginas falsas de erro (comuns em 404 personalizados)|
|`-q`|Executa em modo silencioso|
|`-v`|Modo verboso, com saída detalhada|

---

## ⚡ 📖 O que é Web Fuzzing?

O Web Fuzzing é uma técnica de segurança que consiste em enviar várias entradas inesperadas para uma aplicação, observando como ela responde.

Principais objetivos:
- Descobrir diretórios e arquivos ocultos  
- Encontrar subdomínios e vhosts  
- Identificar parâmetros e extensões válidas  
- Detectar falhas de segurança exploráveis

### 🔑 Fuzzing vs Brute-Forcing

- Fuzzing → usa entradas variadas, inesperadas e wordlists mutadas para descobrir comportamentos ocultos.
- Brute-Forcing → testa sistematicamente todas as combinações possíveis até encontrar a correta.

Analogia:
- Fuzzing = tentar abrir a porta com chaves, grampos, cartões, clips.
- Brute-Forcing = testar cada chave do chaveiro uma por uma.

### 🛠️ Conceitos Essenciais

- Wordlist → lista de palavras/valores a serem testados  
- Payload → dado enviado ao alvo  
- Response Analysis → análise das respostas do servidor  
- Fuzzer → ferramenta que automatiza os testes (como o `ffuf`)  

## ⚡ Ffuf

- Ferramenta CLI: roda via terminal
- Alta performance: suporta multithreading
- Versátil: faz fuzzing em diretórios, subdomínios, parâmetros, vhosts e mais

### 📦 Instalação no Kali:
Assim como o goBuster, o ffuf não vem instalado por padrão no Kali. Para realizar a instalação:

```bash
sudo apt install ffuf
```

### 📂 Principais Modos de Uso

1. Fuzzing de Diretórios (Descobre pastas e arquivos escondidos):
```bash
ffuf -w /usr/share/seclists/Discovery/Web-Content/directory-list-2.3-small.txt:FUZZ -u http://SERVER_IP:PORT/FUZZ
```

2. Extension Fuzzing (Descobre extensões de arquivos aceitas):
```bash
ffuf -w /usr/share/seclists/Discovery/Web-Content/web-extensions.txt:FUZZ -u http://SERVER_IP:PORT/blog/indexFUZZ
```

3. Fuzzing Recursivo (Explora subdiretórios automaticamente):
```bash
ffuf -w /usr/share/seclists/Discovery/Web-Content/directory-list-2.3-small.txt:FUZZ -u http://SERVER_IP:PORT/FUZZ -recursion -recursion-depth 1 -e .php -v
```

4. Domain Fuzzing (Descobre subdomínios):
```bash
sudo sh -c 'echo "SERVER_IP dominio.site" >> /etc/hosts'
ffuf -w /usr/share/seclists/Discovery/DNS/subdomains-top1million-5000.txt:FUZZ -u https://FUZZ.dominio.site/
```

5. VHosts Fuzzing (Descobre virtual hosts):
```bash
ffuf -w /usr/share/seclists/Discovery/DNS/subdomains-top1million-5000.txt:FUZZ -u http://SERVER_IP/ -H "Host: FUZZ.dominio.site"
```

6. Parameter Fuzzing (Testa parâmetros escondidos em GET e POST) :
```bash
#GET
ffuf -w /usr/share/seclists/Discovery/Web-Content/burp-parameter-names.txt:FUZZ -u https://site.com/view.php?FUZZ=1

#POST
ffuf -w /usr/share/seclists/Discovery/Web-Content/burp-parameter-names.txt:FUZZ -u https://site.com/view.php -X POST -d "FUZZ=1" -H "Content-Type: application/x-www-form-urlencoded"
```

### 🚩 Flags Úteis

|Flag|Função|
|---|---|
|`-w`|Define a wordlist|
|`-u`|Define a URL alvo|
|`-o`|Salva resultados em arquivo|
|`-recursion`|Ativa fuzzing recursivo|
|`-recursion-depth`|Define profundidade máxima|
|`-H`|Define cabeçalho customizado (Host, Cookie, ...)|
|`-X`|Define método HTTP (GET, POST, etc.)|
|`-d`|Dados enviados no corpo da requisição|
`-e`|Define extensões de arquivos a testar|