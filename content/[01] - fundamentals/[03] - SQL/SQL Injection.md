# Fundamentos de SQL Injection - SQLi

A Injeção SQL é uma vulnerabilidade de aplicação web crítica que ocorre quando entradas fornecidas por usuários não são devidamente sanitizadas. Isso permite que a aplicação concatene dados arbitrários diretamente em consultas de banco de dados, falhando em distinguir entre os dados inseridos e sintaxe de comandos.

Quando o encapsulamento de uma _string_ é quebrado por caracteres especiais, o banco de dados executa a instrução modificada com os privilégios da aplicação.

## Bypass de Autenticação

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

## Categorias de Injeção SQL

A exploração é dividida primariamente pelo método de retorno das informações do banco de dados para o atacante:

- **SQLi In-Band:** O ataque e o retorno dos dados ocorrem no mesmo canal de comunicação.
    
    - Baseada em Erro: Força o banco de dados a gerar mensagens de erro explícitas que revelam informações sobre a estrutura interna.
        
    - Baseada em UNION: Utiliza o operador `UNION SELECT` para anexar os resultados de uma consulta forjada aos resultados da consulta legítima.
        
- **SQLi Blind:** A aplicação não exibe erros ou resultados na tela. A extração de dados exige a inferência observando o comportamento da aplicação.
    
    - Baseada em Booleano: Consiste em realizar perguntas de "Verdadeiro ou Falso" (ex: `AND 1=1` vs `AND 1=2`) e observar se o conteúdo da página ou o tamanho da resposta sofre alterações.
        
    - Baseada em Tempo: Utiliza funções de banco de dados para pausar a resposta caso uma condição seja verdadeira.
        
- **SQLi Out-of-Band (OOB):** Os dados são exfiltrados por um canal externo, como requisições DNS ou HTTP disparadas pelo próprio servidor de banco de dados para uma máquina controlada pelo atacante.
    
## Casos de Uso

- Bypass de Autenticação: Acesso não autorizado a painéis administrativos.
    
- Extração de Dados: Roubo de informações sensíveis e credenciais em texto claro ou hashes.
    
- Fingerprinting: Identificação do tipo e versão do SGBD para modelagem de ameaças.
    
- Execução de Código: Execução direta de comandos ou uploads de webshells no sistema operacional hospedeiro.

>[!Caution]
> Nenhuma técnica de prevenção única é infalível. Para a defesa, a implementação mais eficaz é o uso de Consultas Parametrizadas, onde o banco trata a entrada estritamente como dados, nunca como código executável. Além disso, a exploração ativa com ferramentas automatizadas só deve ser feita em ambientes autorizados.
    
## Identificação e Exploração Manual

A exploração manual é essencial para validar a vulnerabilidade e entender o comportamento da aplicação antes de utilizar a automação.

### Detecção Básica

A busca por pontos de injeção envolve testar todos os vetores de entrada (parâmetros GET/POST, Cookies, cabeçalhos HTTP):

1. Inserção de aspas: Adicionar `'` ou `"` e observar se a aplicação retorna um erro `HTTP 500` ou _stack trace_ do banco de dados.
    
2. Operações lógicas: Inserir `' OR '1'='1'` para verificar se ocorre a exibição de dados adicionais não previstos.
    
3. Atrasos de tempo:Injetar comandos de _sleep_ para analisar diferenças no tempo de carregamento.
    
### A Exploração Baseada em UNION

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
