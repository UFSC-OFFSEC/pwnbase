<div align="center">
  <img src="https://tse1.mm.bing.net/th/id/OIP.-hHoxXiebtG0hp8a3BfS2QHaEK?rs=1&pid=ImgDetMain&o=7&rm=3" alt="WPScan" width="600"/>
</div>

➡️ [PDF da Aula](./pdf/WpScan.pdf) desenvolvido por [@rideckszz](https://github.com/rideckszz)

# WPScan

## O que é WordPress?

O WordPress é o Sistema de Gerenciamento de Conteúdo (CMS) mais difundido globalmente. Devido à sua vasta be de usuários e à dependência de componentes de terceiros, torna-se um alvo frequente para cibercriminosos.

---

## Introdução ao WPScan

O WPScan é uma ferramenta de varredura de vulneriabilidades, desenvolvida especificadamente para identificar falhas de segurança em ecossistemas WordPress. Ele opera analisando a estrutura de arquivos exposta e comparando as versões encontradas com bancos de dados de vulnerabilidades conhecidadas.

Entre suas principais características estão:

- CLI: executado via terminal.  
- Docker: possui imagens oficiais para execução em containers.  
- Versátil: pode realizar enumeração, checagem de vulnerabilidades conhecidas e até ataques de brute force.

## Como funciona?

O WPScan automatiza processos que seriam exaustivos manualmente, dividindo sua execução em três frentes:

1. Enumeração: Identifica plugins, temas e versões do WordPress em uso.
2. Identificação de Vulnerabilidades: Usa o banco de dados do WPScan, que contém informações atualizadas sobre falhas em WordPress, plugins e temas.
3. Descoberta de Usuários: Explora rotas de API e páginas de autor para listar nomes de usuários válidos, facilitando ataques direcionados.

### Exemplo básico:
```bash
wpscan --url https://target.com/ --enumerate u
```

## Comandos Comuns
Diferente de ferramentas genéricas, o WPScan utiliza sinalizadores específicos para focar em componentes vulneráveis.

### Varredura Inicial

Realiza uma análise geral do cabeçalho e metadados para identificar a versão do CMS.

```bash
wpscan --url http://example.com
```

### Enumeração de Plugins

A flag `--enumerate`aceita parâmetros para definir o alvo da busca.

- `vp`: Apenas plugins vulneráveis.
- `ap`: Todos os plugins.
- `vt`: Apenas temas vulneráveis
- `u`: IDs de usuários.
  
```bash
# Enumeração de plugins vulneráveis e usuários
wpscan --url http://example.com --enumerate vp,u
```

### Força Bruta
Após identificar usuários válidos, é possível testar credenciais contra a interface de login

```bash
wpscan --url http://example.com --brute --wordlist wordlist.txt
```

### Uso de API Token
Para que o WPScan exiba detalhes sobre as vulnerabilidades, é necessário um API Token gratuiro, obtido no site oficial do WPScan.

```bash
wpscan --url http://alvo.com.br --api-token SEU_TOKEN_AQUI
```

## Flags Úteis

|Flag       | Função |
|-----------|--------|
|`--plugins-detection`| Define a agressividade na busca por plugins|
|`--force`| Ignora o aviso de que o alvo não parece estar rodando WordPress |
|`-o`| Salva o relatório da varredura em um arquivo |
|`--random-user-agent`| Utiliza cabeçalhos de navegador aleatórios para dificultar o bloqueio por firewalls|

---

## Estratégia de Uso em CTFs

1. Rodar varredura inicial para descobrir versão e informações gerais.
2. Enumerar plugins/temas para identificar vulnerabilidades conhecidas.
3. Pesquisar vulnerabilidades no banco do WPScan ou no ExploitDB.
4. Se necessário, brute force para descobrir usuários ou senhas.
5. Explorar a falha encontrada para obter acesso.
