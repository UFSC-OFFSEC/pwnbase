<div align="center">
  <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSMLGpXTKvHcejhKhbM1bdi2Hvyv-kBQV02UoOqWGJJcA&s=10" alt="Nmap" width="600"/>
</div>

# SQL

O SQL é uma linguagem de programação padronizada e específica de domínio usada para interagir com sistemas de gerenciamento de banco de dados relacionais.

As consultas realizadas permitem aos usuários adicionar, recuperar, atualizar, excluir, agregar e gerenciar dados com facilidade. Nesses sistemas, os dados são organizados em tabelas com linhas e colunas, que podem ser vinculados por meio de chaves primárias ou estrangeiras.

Diferente das linguagens padrões, o SQL é uma linguagem declarativa, ou seja, ela descreve o que o usuário deseja que o computador faça, ao invés de como fazer isso.

## Por que o SQL é importante?

Desde seu desenvolvimento, o SQL tornou-se a espinha dorsal dos sistemas de banco de dados. Por ser uma linguagem declarativa, o SQL é acessível até mesmo para usuários com pouca experiência.

No mundo da ciência de dados, o SQL é usado para criar bancos de dados que armazenam grandes conjuntos de dados necessário análises.

## Como funciona?

Um banco de dados relacional organiza os dados em forma de tabela e permite que os usuários escrevam consultas para manipular esses dados.

Um parser verifica a correção das instruções SQL e as converte em um formato que o banco consegue entender. Isso envolve a análise sintática e a verificação semântica. Ele também garante que o usuário que está realizando essas consultas esteja autorizado para tal.

Um motor de armazenamento que executará a instrução SQL e gerencia o armazenamento físico dos dados. Além disso, ele também retorna o resultado ao usuário/aplicativo. Esta etapa ajuda a garantir acesso e atualizações aos dados no disco.

## Principais componentes

- Banco de dados: repositórios digitais para armazenar, gerencia e organizar dados
- Tabelas: dados formatados em linhas e colunas
- Consultas SQL: instruções escritas em SQL usadas para manipular os dados.
- Restrições SQL: regras que controlam os dados.

## Tipos de comandos

### Linguagem de definição de dados (DDL)

Ela gerencia objetos do banco de dados e define a estrutura e a organização dos dados armazenados, bem como os relacionamento entre os itens.

**Comandos:** CREATE, ALTER, DELETE

### Linguagem de manipulação de dados (LMD)

Gerencia os dados dentro dos bancos de dados.
**Comandos:** SELECT, INSERT, DROP, UPDATE


## Comandos básicos

### **SELECT**

Recupera os dados de uma ou mais tabelas

```sql
SELECT nome, cpf FROM clientes WHERE cidade = 'Joinville' ;

-- recupera o nome e o cpf de todos os clientes que moram em Joinville
```

### **INSERT**

Adiciona novas linhas a uma tabela

```sql
INSERT INTO clientes (nome, cpf, cidade) VALUES ("João",111 , "Florianopolis") ;
-- adiciona uma nova linha à tabela de clientes
```

### **UPDATE**

Modifica os dados de uma tabela 
```sql
UPDATE clientes SET nome = 'novo nome' WHERE cpf 111;
-- atualiza o nome do cliente com cpf 111 na tabela clientes.
```

### **DELETE**

Remove linhas de uma tabela com base em uma condição
``` sql
DELETE FROM clientes WHERE cidade = "Ararangua";
-- remove todas as linhas da tabela de clientes onde a cidade é Ararangua
```

## Injeção SQL

Apesar das vantagens de segurança de muitos bancos de dados SQL, outras aplicações podem ser vulneráveis a problemas de segurança. Por conta disso a SQLi continua sendo uma ameaça real.