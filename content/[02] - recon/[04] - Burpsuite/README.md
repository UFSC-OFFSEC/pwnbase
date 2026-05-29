<div align="center">
  <img src="https://th.bing.com/th/id/OIP.4_Yg_PdN6XHWlQcr4rd6qAHaBJ?w=324&h=59&c=7&r=0&o=7&dpr=1.1&pid=1.7&rm=3" alt="GoBuste" width="600"/>
</div>

# Burpsuite

➡️ [PDF da Aula](./pdf/http_burpsuite.pdf) desenvolvido por [@EduardoPanizzon](https://github.com/EduardoPanizzon)

---

>[!WARNING]
>**Pré-requisito:**
>O Burp Suite é uma ferramenta avançada de manipulação de tráfego. Para compreender e utilizar esta plataforma corretamente, é obrigatório o domínio sobre a arquitetura cliente-servidor.

---

## O que é

O Burp Suite é uma plataforma integrada de testes de segurança para aplicações web. Diferente de ferramentas comuns, o Burp atua como um proxy de interceptação, seguindo o Man-in-the-Middle, localizado entre o navegador e o servidor alvo.

Ele permite capturar, inspecionar, modificar e retransmitir todo o tráfego HTTP/HTTPS antes que ele chegue ao seu destino final.

---


## Edições
- **Community** (gratuita)
- **Professional** (paga, com automações e recursos avançados)

---

## Estrutura da Comunicação HTTP

A organização da transferência de dados na web segue um modelo direto de cliente e servidor. A requisição inicia obrigatoriamente através da especificação de portas lógicas de rede, utilizando a porta 80 para tráfego aberto e a porta 443 para conexões seguras e criptografadas.

O protocolo HTTP possui uma natureza sem estado, tratando cada requisição de maneira isolada e independente. Para viabilizar sistemas que exigem autenticação contínua, os servidores utilizam identificadores de sessão em formato de texto, chamados cookies, para rastrear a atividade do usuário. O roubo destes identificadores permite o sequestro de sessão, falha crítica na qual um atacante assume a identidade da vítima sem a necessidade de possuir credenciais de acesso.

Para fins de compreensão, apresentam-se os métodos de requisição principais que compõem essa estrutura:

|Método|Função|
|:--|:--|
|**GET**|Solicita a leitura de uma página e obtém dados web.|
|**POST**|Envia dados sensíveis e extensos para processamento no banco de dados do servidor.|
|**HEAD**|Solicita exclusivamente a devolução dos cabeçalhos da página ocultando o corpo da mensagem.|
|**PUT**|Atua na substituição direta de recursos contidos no servidor.|
|**DELETE**|Aciona a exclusão de arquivos e recursos alocados no servidor.|

---

### Navegação e Gestão de Respostas

A base de operação das respostas do servidor assenta-se em códigos numéricos de status. O navegador do cliente processa esses números para exibir a interface correspondente.

Diante disso, os principais códigos de navegação são:

|Código|Função|
|:--|:--|
|**2xx**|Indica sucesso na ação solicitada apontando um processamento concluído sem erros.|
|**3xx**|Indica redirecionamento informando que a página foi movida para uma nova rota.|
|**4xx**|Aponta erros do cliente decorrentes de má formatação, falta de permissão ou páginas inexistentes.|
|**5xx**|Revela falhas e erros de processamento originados pelo próprio sistema do servidor web.|

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

### Ferramentas do Burp Suite

No Burp Suite, a análise de vulnerabilidades não ocorre de forma passiva. O sistema opera com base em um proxy de interceptação posicionado exatamente entre o navegador de internet e a aplicação web alvo. Este posicionamento confere o poder de manipular o tráfego antes que validações de interface bloqueiem ações não autorizadas.

Para fazer a gestão dos pacotes e executar testes profundos, utiliza-se as ferramentas abaixo:

|Ferramenta|Função|
|:--|:--|
|**Proxy**|Retém, inspeciona e manipula pacotes HTTP em trânsito pela rede.|
|**Target**|Mapeia a estrutura de rotas do site e define os limites exatos de escopo de teste.|
|**Intruder**|Dispara ataques customizados e realiza injeções em larga escala de forma automatizada.|
|**Repeater**|Submete modificações manuais de um pacote repetidas vezes para avaliação de comportamento.|
|**Sequencer**|Analisa matematicamente a aleatoriedade e entropia de tokens de segurança.|
|**Decoder**|Realiza conversões encadeadas para decodificar dados ofuscados em diversos formatos.|
|**Comparer**|Compara solicitações visualmente e devolve as diferenças em bytes ou palavras entre elas.|

---

### Modificações e Controles

A arquitetura do Burp gerencia as requisições através de controles diretos de trânsito.

A funcionalidade central da plataforma reside na capacidade de pausar o tráfego em tempo real. Para isso:

1. Ative **Intercept is on** no Burp, assim todas as requisições geradas pelo navagador ficam retidas na interface do Burp.
2. Navegue até o alvo no browser.

Com a interceptação ativa, operam-se as seguintes modificações em tempo real:

- **Forward:** Libera a requisição manipulada para alcançar o seu destino final no servidor.
- **Drop:** Destrói a requisição imediatamente e descarta o pacote de dados completamente.
- **Match and Replace:** Substitui padrões de texto em tempo real burlando validações, como forjar a identidade do navegador alterando o cabeçalho User-Agent para emular dispositivos móveis.
- **HTML Modification:** Remove limites de tamanho de campos de texto e inativa validações em linguagens de script aplicadas superficialmente no navegador do usuário.

O sistema permite enviar as requisições em trânsito para outros módulos utilizando atalhos de contexto:

|Comando|Função|
|:--|:--|
|**Change request method**|Modifica a instrução de envio convertendo dados de método POST para GET ou vice-versa.|
|**Send to Repeater**|Encaminha a mensagem para o ambiente de manipulação meticulosa.|
|**Send to Intruder**|Transfere o pacote para a ferramenta de testes automatizados e força bruta.|
|**Don't intercept requests**|Cria regras de exclusão de tráfego para limpar ruídos de domínios irrelevantes.|

---

### Tratamento de Dados no Intruder

O módulo Intruder possibilita o encadeamento de métodos de ataque e filtragens robustas para o tratamento intenso de vulnerabilidades.

A definição de alvos de injeção ocorre de forma rápida e direta através de marcadores visuais. Dessa forma, cada área de uma requisição possui um potencial de exploração distinto. Para definir os pontos de injeção de cargas úteis, basta cercar a variável escolhida utilizando o símbolo dedicado `§`. Exemplo prático de marcação: `usuario=admin&senha=§lista_de_senhas§`

O comportamento das injeções obedece a quatro tipos de ataque estruturais:

|Tipo|Função|
|:--|:--|
|**Sniper**|Dispara uma carga útil por vez em cada alvo marcado iterando palavra por palavra através de uma única lista.|
|**Battering ram**|Insere a mesma palavra simultaneamente em todas as posições marcadas de uma só vez.|
|**Pitchfork**|Utiliza múltiplas listas testando apenas as linhas correspondentes de forma paralela e conjunta.|
|**Cluster bomb**|Combina todas as linhas disponíveis cruzando os dados e gerando testes exaustivos de força bruta total.|

Para refinar o enorme volume de resultados obtidos após milhares de requisições, aplicam-se regras automáticas de análise diretamente nas respostas do servidor:

| Recurso                | Função                                                                                                        |
| :--------------------- | :------------------------------------------------------------------------------------------------------------ |
| **Grep - Match**       | Vasculha as respostas do servidor destacando expressões específicas informando o sucesso ou falha da injeção. |
| **Grep - Extract**     | Extrai informações sigilosas ou tokens de segurança recebidos invisivelmente no código-fonte das respostas.   |
| **Payload Processing** | Executa codificações avançadas nas palavras da lista momentos antes do envio final burlando firewalls web.    |


