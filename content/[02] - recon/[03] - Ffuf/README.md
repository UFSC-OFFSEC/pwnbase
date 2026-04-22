<div align="center">
  <img src="https://github.com/ffuf/ffuf/blob/master/_img/ffuf_run_logo_600.png?raw=true" alt="Ffuf" width="600"/>
</div>

# Ffuf (Fuzz Faster U Fool)

O ffuf é uma ferramenta de linha de comando, reconhecida pela sua alta perfomance em tarefas de fuzzing web. Sua versatilidade permite realizar desde a descoberta de diretórios até a identificação de parâmetros ocultos em requisições POST.

## Instalação no Kali:

Assim como o goBuster, o ffuf não vem instalado por padrão no Kali. Para realizar a instalação:

```bash
sudo apt install ffuf
```

## Principais Modos de Uso

A principal característica da ferramente é a utilização da palavra-chave FUZZ no ponto exato onde os termos da wordlist devem ser inseridos.

1. Fuzzing de Diretórios:
   
   Descobre pastas e arquivos escondidos
   
    ```bash
    ffuf -w /usr/share/seclists/Discovery/Web-Content/directory-list-2.3-small.txt:FUZZ -u http://SERVER_IP:PORT/FUZZ
    ```

3. Extension Fuzzing:
   
   Descobre extensões de arquivos aceitas.
   
    ```bash
    ffuf -w /usr/share/seclists/Discovery/Web-Content/web-extensions.txt:FUZZ -u http://SERVER_IP:PORT/blog/indexFUZZ
    ```

5. Fuzzing Recursivo:
   
   Explora subdiretórios automaticamente.
   
    ```bash
    ffuf -w /usr/share/seclists/Discovery/Web-Content/directory-list-2.3-small.txt:FUZZ -u http://SERVER_IP:PORT/FUZZ -recursion -recursion-depth 1 -e .php -v
    ```

7. Domain Fuzzing:
   
   Descobre subdomínios.
   
    ```bash
    sudo sh -c 'echo "SERVER_IP dominio.site" >> /etc/hosts'
    ffuf -w /usr/share/seclists/Discovery/DNS/subdomains-top1million-5000.txt:FUZZ -u https://FUZZ.dominio.site/
    ```

5. VHosts Fuzzing:
   
   Descobre virtual hosts.
   
    ```bash
    ffuf -w /usr/share/seclists/Discovery/DNS/subdomains-top1million-5000.txt:FUZZ -u http://SERVER_IP/ -H "Host: FUZZ.dominio.site"
    ```

6. Parameter Fuzzing:
   
   Testa parâmetros escondidos em GET e POST.
   
    ```bash
    #GET
    ffuf -w /usr/share/seclists/Discovery/Web-Content/burp-parameter-names.txt:FUZZ -u https://site.com/view.php?FUZZ=1
    
    #POST
    ffuf -w /usr/share/seclists/Discovery/Web-Content/burp-parameter-names.txt:FUZZ -u https://site.com/view.php -X POST -d "FUZZ=1" -H "Content-Type: application/x-www-form-urlencoded"
    ```

## Flags Úteis

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
