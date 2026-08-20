GTFOBins

[GTFOBins](https://gtfobins.github.io/) é um repositório de binários Linux que podem ser explorados quando existem más configurações em sistemas operacionais (ex. permissões incorretas no sudo).

Esses binários podem ser abusados para:

- Escalada de privilégios
- Bypass de restrições
- Execução de comandos arbitrários
- Leitura/alteração de arquivos

### Exemplo prático em CTF

1. Ao encontrar alguma forma de acessar o sistema (ex. através de shell reversa)", rodar:
```bash
sudo -l                         # Listar os comandos que o usuário pode executar com sudo.
#OU
find / -perm -u=s 2>/dev/null   # Procura por arquivos que rodam com permissão elevada
```
2. Encontrar algo como:
```bash
(ALL) NOPASSWD: /usr/bin/vim
```
3. Pesquisar no GTFOBins:
```yaml
Nesse caso: https://gtfobins.github.io/gtfobins/vim/
```
4. Usar a técnica documentada para obter uma shell como root.