<div align="center">
  <img src="https://miro.medium.com/v2/resize:fit:646/0*0ePcgWIW7tlD4Cwp.png" alt="GoBuste" width="600"/>
</div>

# GoBuster

➡️ [PDF da Aula](./pdf/goBuster.pdf) de goBuster desenvolvido por [@ITA-LOW](https://github.com/ITA-LOW)

---

O GoBuster é uma ferramenta projetada para automatizar o processo de descoberta de recursos ocultos em servidores. Ele utiliza uma técnidade de brute force baseada em listas de dicionários (wordlists) para identificar diretórios, arquivos e subdomínios que não estão acessíveis por meio de links públicos. Para isso, o GoBuster realiza milhares de requisições para testar a existência de caminhos específicos, permitindo mapear a estrutura interna de uma aplicação.

Com isso o GoBuster se torna uma ferramenta essencial para a etapa de enumeração em CTF's e pentestes.

## Por que é importante?
- Muitas vezes desenvolvedores deixam diretórios ocultos para manutenção.
- Alguns caminhos podem não ser documentados e acabar sendo vulnerabilidades sérias.
- A enumeração revela a "superfície de ataque" de um site.

## Instalação

O goBuster é uma ferramenta que não está incluída por padrão no Kali Linux, dessa forma para utilizá-la é necessário realizar a instalação primeiros:

```bash
sudo apt install gobuster
```
---

## Wordlists

O GoBuster não funciona sozinho, ele precisa das chamadas wordlists, que são arquivos de texto com palavras a serem testadas como nomes de diretórios, usuários ou senhas. Dessa forma, ele verifica sistematicamente se cada termo contido na lista de texto resulta em uma resposta válida do servidor.

No Kali Linux, o diretório padrão para essas listas é `/usr/share/wordlists/`, no qual, as listas mais utilizadas para enumeração web encontram-se em `/dirb` e `/dirbuster/`.

Exemplos:

- Diretórios comuns: [directory.txt](https://raw.githubusercontent.com/teamstealthsec/wordlists/master/directory.txt)
- Senhas populares: [rockyou.txt](https://github.com/teamstealthsec/wordlists/blob/master/rockyou.txt.gz)

## Modos de Uso

O GoBuster é dividido em subcomandos que definem o alvo da varredura:

- `dir`: Enumeração de diretórios e arquivos em um endereço web
- `dns`: Enumeração de subdomínios (`dev.alvo.com`)
- `vhost`: Descobre hosts virtuais em servidores web

### Exemplos de Uso

```bash
gobuster -h                                                 # Ajuda geral da ferramenta
gobuster <modo> --help                                      # Ajuda no modo específico

gobuster dir -u https://exemplo.com -w wordlist.txt         # Descobrir diretórios e arquivos ocultos
gobuster dns -d exemplo.com -w domains.txt --wildcard       # Enumerar subdomínios
```

## Análise de Resultados
Um comando típico para busca de diretórios e arquivos específicos utiliza a seguinte sintaxe:

```bash
gobuster dir -u http://10.10.10.1 -w /usr/share/wordlists/dirb/common.txt -t 50 -x php,txt
```

A análise dos resultados deve focar nos códigos de status retornados depois de cada tentativa:

- `200`: (OK) O recurso foi encontrado e está acessível para leitura
- `301/302`: (Redirect) O recurso existe, mas redireciona o usuário para outro endereço
- `403`: (Forbidden) O recurso existe, mas o acesso é negado pelas permissões do servidor
- `404`: (Not Found) O recurso não existe


## Flags Úteis

|Flag|Função|
|---|---|
|`-u`|Define a URL ou domínio alvo|
|`-w`|Define a wordlist|
|`-o`|Salva resultados em arquivo|
|`-t`|Define número de threads (padrão: 10)|
|`--wildcard`|Trata páginas falsas de erro (comuns em 404 personalizados)|
|`-q`|Executa em modo silencioso|
|`-v`|Modo verboso, com saída detalhada|
|`-x`| Adiciona extensões de arquivo ao final de cada termo da wordlist |
|`-b`| Oculta códigos de status indesejados |
|`-k`| Ignora verificações de certifiacados SSL/TLS inválidos

---
