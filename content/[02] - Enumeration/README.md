# Ferramentas para Enumeração

A enumeração contitui a fase primária e mais importante de um Pentest. Seu objetivo é o mapeamento metódico e exaustivo da superfície de ataque do alvo. Através desta coleta sistemática de dados, é que fundamenta-se todas as etapas subsequentes de exploração.


## Tipos de Enumeração

A obtenção de dados sobre uma infraestrutura é categorizada pelo seu nível de interação e rastreabilidade:

###  Passiva
Coleta de informações sem comunicação direta com os ativos do alvo. É um processo silencioso, focado em fontes abertas, registros DNS e motores de busca de dispositivos.
- Exemplos: registros de domínio, redes sociais, motores de busca (Shodan, Censys), OSINT.

#### Ativa
Interação direta com os servidores e aplicações do alvo
- Exemplos: varredura de portas, identificação de serviços, coleta de banners e vulnerabilidades.

>[!CAUTION]
> A enumeração ativa gera tráfego anômalo e deixa assinaturas nos logs do servidor, sendo facilmente detectável por mecanismos de defesa (Firewalls e IDS/IPS).


## Web Fuzzing

O Web Fuzzing é uma técnica ofensiva essencial para a exploração da camada de aplicação web. Baseia-se no envio automatizado e massivo de entradas customizadas para um servidor, visando analisar o comportamento das respostas e mapear estruturas não indexadas.

Principais objetivos:
- Descobrir diretórios e arquivos ocultos  
- Encontrar subdomínios e vhosts  
- Identificar parâmetros e extensões válidas  
- Detectar falhas de segurança exploráveis

### Fuzzing vs Brute-Forcing

- Fuzzing: usa entradas variadas, inesperadas e wordlists mutadas para descobrir comportamentos ocultos.
- Brute-Forcing: testa sistematicamente todas as combinações possíveis até encontrar a correta.

### Conceitos Essenciais

- Wordlist: Arquivo contendo o dicionário de diretórios, subdomínios ou parâmetros que serão testados contra o alvo. 
- Payload: Dado específico injetado diretamente na requisição.
- Response Analysis: Análise das respostas do servidor. 
- Fuzzer: Ferramenta que automatiza os testes (como o `ffuf` ou `GoBuster`).

## Trilha de Aprendizado

A estrutura deste módulo obedece a uma progressão lógica. Siga a ordem dos diretórios abaixo:

* 📁 **[[01] - Nmap](./[01]%20-%20Nmap/)**: Mapeamento de infraestrutura, identificação de portas TCP/UDP e detecção de serviços.
* 📁 **[[02] - GoBuster](./[02]%20-%20goBuster/)**: Introdução à enumeração web e descoberta automatizada de subdomínios e diretórios.
* 📁 **[[03] - Ffuf](./[03]%20-%20Ffuf/)**: Aprofundamento técnico em *Web Fuzzing* e exploração de parâmetros não documentados.
* 📁 **[[04] - Burp Suite](./[04]%20-%20Burpsuite/)**: Configuração de *proxies* para interceptação, inspeção e manipulação manual do tráfego HTTP.
* 📁 **[[05] - WPScan](./[05]%20-%20WPScan/)**: Auditoria direcionada e automatizada, focada especificamente no ecossistema WordPress.




