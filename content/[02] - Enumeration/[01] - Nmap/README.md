<div align="center">
  <img src="https://tse1.mm.bing.net/th/id/OIP.A2kR5CHYZUD5Ep6pPPsYbQHaEe?rs=1&pid=ImgDetMain&o=7&rm=3" alt="Nmap" width="600"/>
</div>


# NMAP

➡️ [PDF da Aula](recon.pdf) de NMAP desenvolvido por [@rideckszz](https://github.com/rideckszz)\

---

O Nmap (Network Mapper) é uma das ferramentas mais utilizadas em pentests e CTFs. Ele interage diretamente com os alvos, enviando pacotes customizados e analisando as respostar para mapear portas abertas, serviçes em execução, versões de software e potenciais vulnerabilidades.

A enumeração com Nmap faz parte das primeiras etapas de um ataque, permitindo mapear a superfície de ataque do alvo.


## Comandos Básicos do Nmap

A varredura inicial visa identificar a superfície de ataque disponível no alvo

```bash
nmap <IP-ALVO>                      # Escaneio Simples
nmap -p- <IP-ALVO>                  # Escanear todas as portas
nmap -p 22,80,443 <IP-ALVO>         # Escanear portas específicas
nmap -sV <IP-ALVO>                  # Identificação de versão dos serviços em execução
nmap -O <IP-ALVO>                   # Identificação de SO
nmap -A <IP-ALVO>                   # Varredura completa
```

### Comandos avançados

```bash
nmap -sS <IP-ALVO>                  # SYN Scan (rápido e furtivo)
nmap -sU <IP-ALVO>                  # UDP Scan
nmap -f <IP-ALVO>                   # Firewall Evasion (fragmentação de pacotes)
nmap -sA <IP-ALVO>                  # Portas filtradas por firewall
```

### Exemplo de Saída

Ao executar um comando como `nmap -sV -sC -v <IP-ALVO>`, a saída apresentará colunas fundamentais:

|Coluna   | Significado|
|---------|------------|
|`PORT`   | Identifica o número e o protocolo (TCP/UDP).|
|`STATE`  | `open`(aceita conexões), `closed`(rejeita conexões), `filtered`(um firewall está bloqueando).|
|`SERVICE`| O nome do serviço que está rodando naquela porta.|
|`VERSION`| A versão do serviço que está rodando.|


## Velocidade e Performance

Configurações para otimizar o tempo de execução e a visualização dos dados.

- `-T4`: Acelera a varredura (escala de 0 a 5)
- `-F`: Limita o escaneio às 100 portas mais frequentes.
- `-v`: Aumenta o nível de detalhes exibidos. O Nmpa imprime as portas encontradas em tempo real.



## Scripts NSE (Nmap Scripting Engine)

Scripts prontos para verificar vulnerabilidades e serviços específicos.

```bash
# Script padrão
nmap -sC <IP-ALVO>  

# Verifica se os serviços possuem vulnerabilidades críticas
nmap --script=vuln <IP-ALVO>

# Enumera compartilhamentos de rede em sistemas Windows
nmap --script=smb-enum-shares,smb-enum-users -p 445 <IP-ALVO>

```

## Saída de Resultados
Usando o Nmap, é possível fazer a exportação dos resultados em arquivos.

```bash
nmap -oN resultado.txt <IP-ALVO>       # Normal
nmap -oX resultado.xml <IP-ALVO>       # XML
nmap -oA scan_completo <IP-ALVO>       # Todos formatos
```
