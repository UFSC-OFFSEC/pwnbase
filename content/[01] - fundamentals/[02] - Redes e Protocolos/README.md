# Redes de Computadores e Protocolos

A rede de computadores é uma infraestrutura que interconecta dispositivos para estabelecer um sistema de comunicação, recursos e troca de dados. Tais dispositivos dependem de protocolos de comunicação que permitem o compartilhamento de informações entre diferentes meios.

## Principais componentes

### *Endereço IP*

É um número exclusivo atribuído a cada dispositivo de rede em uma de de **Internet Protocol**. Cada IP identifica a rede do dispositivo e sua localização na rede. 

Quando dados são enviados de um dispositivo para outro, incluem um cabeçalho que contém os endereços IP dos dispositivos de envio e de recepção.

### *MAC*

É um número que identifica o adaptador de rede no nível de hardware.

### *Nós*

É um ponto de conexão da rede que pode receber, enviar, criar ou armazenar dados. Resumindo, é qualquer dispositivo de rede que é capaz de reconhecer, processar e transmitir dados para outro nó.

Utilizam alguma identificação, IP ou MAC, para ter acesso à rede 

### *Roteadores*

É um dispositivo que envia pacotes de dados entre redes. Eles analisam as informações de dentro dos pacotes para determinar o caminho de transmissão.

### *Comutadores*

É um dispositivo que conecta dispositivos de rede e gerencia a comunicação nó a nó em uma rede, garantindo a chegado dos pacotes no destino.

### *Portas*

Indica uma conexão específica com um número exclusivo. Os computadores usam esse número para determinar qual aplicação, serviço ou processo deve receber quais mensagens.

- **20:** File Transfer Protocol (FTP)
- **22:** Secure Shell (SSH)
- **53:** Domain Name System (DNS)
- **80:** Hypertext Transfer Protocol (HTTP)
- **443:** HTTP Secure (HTTPS)
### *Gateways*

Dispositivos de hardware que facilitam a comunicação entre duas redes diferentes.

## Tipos de Redes

As redes podem variar em termos de tamanho, forma e uso.

- **PAN:** é uma rede pessoal que atende às necessidades de rede de um indivíduo. É quando um celular se conecta a outro e compartilha dados sem que seja necessária uma conexão com um ponto de acesso ou com outros serviços. Normalmente, as redes PAN usam o Bluetooth para se comunicar.
- **LAN:** é uma rede locar que fornece as necessidades de rede em relação a um só local. Normalmente, ela é de propriedade privada e exige autenticação para ser acessada.
- **MAN:** rede metropolitana, fornece funcionalidades de rede entre locais de uma cidade, fornecendo uma rede extensiva. Na maioria das vezes, requer uma conexão segura entre cada LAN ingressada nela.
- **WAN:** rede de longa distância, fornece funcionalidades de rede entre localizações geográficas diferentes. Ou seja, para, por exemplo, conectar a matriz de uma empresa com as filiais. Essa rede vincula várias LANs, e normalmente requer uma VPN (rede virtual privada) para gerenciar as conexões.

## VPN

Uma VPN é uma conexão segura, ponto a ponto, entre dois endpoints de rede. Ela estabelece um canal criptografado que mantém a identidade do usuário e as credenciais de acesso inacessíveis para atacantes.

---
## Protocolos

### **Protocolos de comunicação de rede**

Eles se concentram em estabelecer e manter uma conexão entre dispositivos.
- **Protocolo TCP (Transmission Control Protocol):** divide os dados em pacotes que podem ser enviados de maneira segura e rápida, minimizando a chance de perda de dados.
- **Protocolo IP:** é responsável pelo endereçamento de um pacote de dados. Ele encapsula o pacote e adiciona um cabeçalho de endereço que contém os endereços IP do remetente e do destinatário. Não garante que um pacote seja entregue, apenas o endereço.
- **Protocolo UDP (User Datagram Protocol):** é um protocolo sem conexão que oferece baixa latência e tolerância as perdas. Usado em processo que não precisam verificar se o dispositivo final recebeu os dados.
Outros protocolos:
- **Protocolo HTTP:** usa o TCP/IP para fornecer conteúdo de página da web de um servidor para seu navegador.
- **Protocolo FTP:** usado para transmitir arquivos entre diferentes computadores. Normalmente, é utilizado para carregar arquivos de forma remota para o servidor.

### **Protocolos de segurança de rede**

Têm a finalidade de manter a segurança de dados em toda a rede. Esses protocolos criptografam mensagens em transmissão entre usuários e serviços.
- **Protocolo SSL:** é um protocolo de criptografia e segurança padrão. Fornece uma conexão segura e criptografada entre o seu dispositivo e o de destino.
- **Protocol TLS:** é o sucesso do SSL, fornecendo um protocolo de criptografia mais forte e mais robusto. Ajuda a prevenir a falsificação, adulteração e escuta de mensagens.
- **Protocolo HTTPS:** fornece uma versão mais segura do protocolo HTTP usando criptografia TLS ou SSL. Isso garante que os dados transmitidos entre o servidor e o navegador da Web sejam criptografados e protegidos.
- **SSH:** é um protocolo de segurança de rede criptográfico que fornece uma conexão de dados segura em uma rede. Ele da suporte à execução de instruções de linha de comando, incluindo a autenticação remota.

### **Protocolos de gerenciamento de rede**

Foca na sustentabilidade da rede e no seu desempenho.
- **Protocolo ICMP:** permite que dispositivos conectados à rede enviem mensagens de aviso e de erro, bem como informações de operação sobre o sucesso/falha de uma solicitação de conexão.