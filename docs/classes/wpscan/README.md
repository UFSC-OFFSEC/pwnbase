# WPScan

➡️ [PDF da Aula](./pdf/WpScan.pdf) desenvolvido por [@rideckszz](https://github.com/rideckszz)

---

## 📖 O que é WordPress?

O WordPress é um dos Content Management Systems (CMS) mais utilizados no mundo.  
Ele se destaca por sua popularidade, simplicidade e por sua interface No Code. Justamente por sua popularidade, o WordPress é um alvo recorrente em ataques.

---

## 🛠️ Introdução ao WPScan

O WPScan é uma ferramenta de linha de comando voltada para análise de segurança em sites WordPress. Entre suas principais características estão:

- CLI: executado via terminal.  
- Docker: possui imagens oficiais para execução em containers.  
- Versátil: pode realizar enumeração, checagem de vulnerabilidades conhecidas e até ataques de brute force.

## ⚙️ Como funciona?

1. Enumeração: Identifica plugins, temas e versões do WordPress em uso.
2. Verificação de vulnerabilidades conhecidas: Usa o banco de dados do WPScan, que contém informações atualizadas sobre falhas em WordPress, plugins e temas.
3. Outros testes opcionais: Incluem brute force contra usuários e senhas.

### Exemplo básico:
```bash
wpscan --url https://target.com/ --enumerate u
```

## 📌 Comandos Comuns

1. Varredura Inicial
```bash
wpscan --url http://example.com
```

2. Enumeração de Plugins
```bash
wpscan --url http://example.com --enumerate p
```

3. Enumeração de Temas
```bash
wpscan --url http://example.com --enumerate t
```

4. Enumeração de Usuários
```bash
wpscan --url http://example.com --enumerate u
```

5. Verificação de Vulnerabilidades
```bash
wpscan --url http://example.com --plugins-detection mixed
```

6. Enumeração Completa
```bash
wpscan --url http://example.com --enumerate ap,at,au
```

7. Força Bruta
```bash
wpscan --url http://example.com --brute --wordlist wordlist.txt
```

---

## 🧠 Estratégia de Uso em CTFs

1. Rodar varredura inicial para descobrir versão e informações gerais.
2. Enumerar plugins/temas para identificar vulnerabilidades conhecidas.
3. Pesquisar vulnerabilidades no banco do WPScan ou no ExploitDB.
4. Se necessário, brute force para descobrir usuários ou senhas.
5. Explorar a falha encontrada para obter acesso.