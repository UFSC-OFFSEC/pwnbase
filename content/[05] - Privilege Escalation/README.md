# Escalação de Privilégios

Todos os sistemas operacionais atuais implementam modelos de segurança baseados em níveis de privilégio, nos quais diferentes usuários e processos possuem diferentes níveis de autorização para executar operações específicas.

Dessa forma, a escalação de privilégios é a fase do ataque em que um usuário com permissões limitadas consegue adquirir níveis de acesso superiores. O objetivo final dessa etapa é obter o controle total da máquina, adquirindo o **root** ou o **Administrator**. Isso permite a execução irrestrita de comandos, manipulação de arquivos críticos, etc.

## Tipos de Escalação

Existem duas abordagens principais para a escalação de privilégios:

### Escalação Vertical

Ocorre quando o atacante consegue obter privilégios de nível superior dentro do mesmo sistema. Ou seja, quando um usuário de baixo privilégio consegue obter os direitos de um usuário com privilégios superiores.

### Escalação Horizontal

Ocorre quando o atacante consegue acessar recursos ou informações de outros usuários do mesmo nível de privilégio. Um exemplo seria um atacante que, após comprometer uma conta de usuário, consegue acessar arquivos, emails ou aplicações de outros usuários com o mesmo nível de privilégio. Isso pode resultar na exposição de informações confidenciais, propriedade intelectual ou dados pessoais.

## Principais Meios de Ataque 

### 1. Privilégios Sudo

Configurações no arquivo `/etc/sudoers` que permitem a usuários comuns executar determinados comandos ou binários como **root** sem a necessidade de autenticação. 

```bash
# Comando para achar o comando/binários
sudo -l

# Exemplo de output
user <name> may run the following commands on:
	(root) /bin/tar
```

### 2. Permissões SUID

Binários que possuem o bit SUID (Set Owner User ID) ativado. Quando executados, esses programas rodam com os privilégios do proprietário do arquivo, e não com os privilégios de quem iniciou o processo.

```bash
# comando utilizado
find / -perm -4000 2>/dev/null

# Exemplo de output

/usr/bin/chage                              # saída comum
/usr/bin/gpasswd                            # saída comum
/usr/bin/su                                 # saída comum 
/usr/bin/reset_root                         # saída incomum
/usr/bin/crontab                            # saída comum
```

### 3. Cron Jobs

Scripts automatizados executados pelo **root** em intervalos regulares. Se as permissões dos arquivos executados pelo Cron estiverem incorretas, um atacante pode sobrescrever o script original com um código malicioso que será executado com privilégios máximos.

### 4. Linux Capabilities

Recurso do kernel que fragmenta os privilégios absolutos do root. A atribuição de capabilities específicas a binários comuns permite que eles executem ações críticas, frequentemente viabilizando a abertura de shells privilegiados.

### 5. Senhas em Texto Plano

O armazenamento inseguro de credenciais em arquivos de configuração, logs, históricos de terminal `.bash_history` ou arquivos de backup. Essas credenciais podem permitir o acesso direto a outras contas locais ou serviços internos.

```bash
ls -al

cat .bash_history
```

### 6. Vulnerabilidades de Kernel

Exploração de falhas intrínsecas na versão do kernel do sistema operacional. Costuma ser o último recurso em testes de invasão devido ao risco de instabilidade ou kernel panic no servidor alvo.

>[!NOTE]
> Não é comum encontrar em CTF's


## Ferramentas e Recursos

Para automatizar a detecção desses meios de ataque e facilitar a exploração, existem duas ferramentas fundamentais:

- LinPEAS: Consulte esse material para entende como utilizar o *Linux Privilege Escalation Awesome Script*
- [GTFOBins](https://gtfobins.org/): Sempre que você encontrar um binário com permissão SUID, Sudo ou Capabilities, pesquise no GTFOBins para encontrar o comando exato para a escalação