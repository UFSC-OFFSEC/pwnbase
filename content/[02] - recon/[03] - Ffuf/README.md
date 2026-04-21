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
