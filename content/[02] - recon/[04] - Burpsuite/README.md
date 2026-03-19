# HTTP e Burpsuite

➡️ [PDF da Aula](./pdf/http_burpsuite.pdf) desenvolvido por [@EduardoPanizzon](https://github.com/EduardoPanizzon)

---

## 📖 Protocolo HTTP

O **HTTP** (*HyperText Transfer Protocol*) é a espinha dorsal da web. Ele permite a troca de dados entre navegadores e servidores, com comunicação baseada no modelo cliente-servidor.

### Características principais
- Sem Estado — cada requisição é independente.
- Porta padrão: 80
- Modelo: requisição → resposta

### Cabeçalhos HTTP

Os cabeçalhos HTTP são campos de metadados enviados junto com uma requisição (request) ou resposta (response). Eles não fazem parte do corpo da mensagem, mas carregam informações cruciais para o funcionamento e interpretação do conteúdo.

Na prática, são pares (chave: valor) que descrevem aspectos da transação HTTP, como:

- Tipo de conteúdo transferido (Content-Type)
- Tamanho do corpo da mensagem (Content-Length)
- Informações de autenticação (Authorization)
- Preferências do cliente (Accept, Accept-Language)
- Controle de cache (Cache-Control)

```makefile
EXEMPLO DE HEADER

<metodo> <recurso> HTTP/<versao>
Host: exemplo.com
User-Agent: Mozilla/5.0
Accept: text/html
```

### Métodos de Requisição HTTP

| Método  | Descrição |
|---------|-----------|
| **GET** | Solicita dados de um recurso (ex.: buscar página ou API). |
| **POST** | Envia dados para processamento (ex.: envio de formulário). |
| **PUT** | Atualiza um recurso existente (substitui todo o conteúdo). |
| **DELETE** | Solicita a remoção de um recurso específico. |

### 📡 Códigos de Resposta HTTP

| Código | Categoria | Significado |
|--------|-----------|-------------|
| **200 OK** | 2xx Sucesso | Requisição processada com sucesso |
| **201 Created** | 2xx Sucesso | Recurso criado com sucesso |
| **301 Moved Permanently** | 3xx Redirecionamento | URL movida permanentemente |
| **304 Not Modified** | 3xx Redirecionamento | Conteúdo não alterado |
| **401 Unauthorized** | 4xx Erro Cliente | Acesso negado |
| **404 Not Found** | 4xx Erro Cliente | Recurso não encontrado |
| **501 Not Implemented** | 5xx Erro Servidor | Funcionalidade não implementada |

---

## 🛠️ Burp Suite

**Burp Suite** é uma plataforma integrada para testes de segurança em aplicações web.

### Edições
- **Community** (gratuita)
- **Professional** (paga, com automações e recursos avançados)

### Funcionalidade principal
- **Proxy de Interceptação**: Captura e modifica requisições e respostas HTTP.

### Interceptando Requisições

1. Ative **Intercept is on** no Burp.
2. Navegue até o alvo no browser.
3. Examine e modifique parâmetros, se necessário.
4. **Forward** (encaminhar) ou **Drop** (descartar) a requisição.

### Modificando Requisições

Permite:

- Alterar parâmetros e cabeçalhos.
- Inserir payloads para SQL Injection.
- Testar bypass de autenticação.

## 🔧 Outras Ferramentas do Burp Suite

| Ferramenta | Função |
|------------|--------|
| **Target** | Mapeia superfície de ataque. |
| **Repeater** | Envia requisições manualmente com modificações. |
| **Intruder** | Automatiza ataques de força bruta e fuzzing. |
| **Scanner** | Identifica vulnerabilidades automaticamente (Pro). |

---

### Configurando o Proxy (Opcional)

É possível usar o próprio navegador integrado ao Burpsuite, ou configurar o proxy para utilizá-lo em qualquer navegador, de acordo com os seguintes passos:

1. Abra o Burp Suite e vá até **Proxy**.
2. Verifique a porta (geralmente **80** ou **8080**).
3. Configure o navegador para usar `127.0.0.1:8080` como proxy.

#### Instalando o Certificado SSL (Opcional)

Somente necessário para interceptar tráfego HTTPS:

1. No navegador, acesse `http://burp` e baixe o certificado CA.
2. Importe para o armazenamento de certificados confiáveis.
3. Reinicie o navegador.