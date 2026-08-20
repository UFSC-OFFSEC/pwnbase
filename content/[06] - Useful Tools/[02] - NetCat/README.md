<div align="center">
  <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRhSvOeKglDrdme3V-OLTmWMEhEfnW8eeGiY2I8gObdlA&s=10" alt="GoBuste" width="600"/>
</div>
# Netcat

O **Netcat** é uma ferramenta que permite a leitura e escrita de dados em conexões de rede via protocolos TCP ou UDP. Pensando na parte de segurança ofensiva, ele é utilizado para manipular fluxos de entrada e saída, sendo a ferramenta base para o estabelecimento de Reverse Shells e Bind Shells.
É amplamente usado para depuração, transferência de arquivos e, no contexto da segurança ofensiva, para criar conexões de shell reversa.

## Comandos Básicos

**Listener:** Configura a máquina para aguardar conexões de entrada.

```bash
# Escutar conexões na porta 4444
nc -lvnp 4444
# -l: coloca em modo de escuta
# -v: exibe o status da conexão
# -n: desativa a resolução de nomes DNS
# -p: especifica a porta local utilizada para  a escuta
```

