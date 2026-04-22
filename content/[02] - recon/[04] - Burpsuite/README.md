<div align="center">
  <img src="https://th.bing.com/th/id/OIP.4_Yg_PdN6XHWlQcr4rd6qAHaBJ?w=324&h=59&c=7&r=0&o=7&dpr=1.1&pid=1.7&rm=3" alt="GoBuste" width="600"/>
</div>

# Burpsuite

➡️ [PDF da Aula](./pdf/http_burpsuite.pdf) desenvolvido por [@EduardoPanizzon](https://github.com/EduardoPanizzon)

---

>[!WARNING]
>**Pré-requisito:**
>O Burp Suite é uma ferramenta avançada de manipulação de tráfego. Para compreender e utilizar esta plataforma corretamente, é obrigatório o domínio sobre a arquitetura cliente-servidor. Recomenda-se concluir o estudo do módulo de **Fundamentos de Redes e Protocolo HTTP** antes de prosseguir.

---

## O que é

O Burp Suite é uma plataforma integrada de testes de segurança para aplicações web. Diferente de ferramentas comuns, o Burp atua como um proxy de interceptação, seguindo o Man-in-the-Middle, localizado entre o navegador e o servidor alvo.

Ele permite capturar, inspecionar, modificar e retransmitir todo o tráfego HTTP/HTTPS antes que ele chegue ao seu destino final.

---


## Edições
- **Community** (gratuita)
- **Professional** (paga, com automações e recursos avançados)

---

## Configurando o Burp

Para que o Burp Suite possa capturar o tráfego, o navegador do usuário deve ser configurado para rotear suas requisições através do endereço local da ferramenta.

### Utilizando o Navegador Integrado (Recomendado)

A plataforma possui um navegador interno pré-configurado, que já possui os certificados necessários. Basta acessá-lo pela aba `Proxy > Intercept > Open Browser`.

### Configuração de Proxy Externo

Caso opte por utilizar um navegador externo, siga os parâmetros de configuração manual:

1. Abra o Burp Suite e vá até **Proxy**, confirme se o Proxy Listener está ativo.
2. Verifique a porta (geralmente **80** ou **8080**).
3. Nas configurações de rede do navegador, defina o servidor Proxy HTTP/HTTPS apontando para `127.0.0.1:8080`.

#### Instalando o Certificado SSL (Para tráfego HTTPS) (Opcional)

Para interceptar requisições seguras sem gerar alertas de segurança no navegador:

1. Com o proxy configurado, acesse `http://burp`no navegador.
2. Faça o download do certificado CA.
3. Importe o arquivo nas configurações de Autoridades de Certificações Confiáveis (Trusted Root Certification Authorities) do seu navegador.
4. Reinicie o navegador.

---

## Interceptando Requisições

A funcionalidade central da plataforma reside na capacidade de pausar o tráfego em tempo real.

1. Ative **Intercept is on** no Burp, assim todas as requisições geradas pelo navagador ficam retidas na interface do Burp.
2. Navegue até o alvo no browser.
3. Examine e modifique parâmetros ocultos, cookies ou dados de formulário (injetando payloads como SQL e XSS)., se necessário.
4. Após a manipulação, **Forward** (encaminhar) ou **Drop** (descartar) a requisição.

### Modificando Requisições

O Burp Suite permite alterar os parâmetros e cabeçalhos, inserir payloads para SQL Injection e testar bypass de autenticação.

---

## Outras Ferramentas do Burp Suite

| Ferramenta | Função |
|------------|--------|
| **Proxy**  | Intercepta, visualiza e altera requisições e respostas HTTP/HTTPS em tempo real| 
| **Target** | Mapeia superfície de ataque, registrando a estrutura de diretórios. |
| **Repeater** | Envia requisições manualmente com modificações, ideal para modificar parâmetros pontuais e observar as mudanças na resposta do servidor. |
| **Intruder** | Automatiza ataques de força bruta e fuzzing. |
| **Scanner** | (Apenas na versão Profissional) Identifica vulnerabilidades automaticamente . |

---


