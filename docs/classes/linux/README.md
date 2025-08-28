# Comandos Linux Básicos e SSH

➡️ [PDF da Aula](./pdf/linux1.pdf) desenvolvido por [@Getdit](https://github.com/Getdit)
➡️ [PDF da Aula](./pdf/linux2.pdf) desenvolvido por [@NicovrauG](https://github.com/NicovrauG)

---

## 📖 Por que aprender Linux?

- 96,3% dos um milhão de servidores da web utilizam Linux.  
- 100% dos 500 supercomputadores mais rápidos do mundo rodam em Linux.  
- Base de conhecimento essencial para CTFs, pentests e administração de servidores.

## 📂 Estrutura de Diretórios

O Linux segue o padrão FHS (Filesystem Hierarchy Standard):

- `/home` → diretórios dos usuários
- `/bin` → binários essenciais do sistema
- `/etc` → arquivos de configuração
- `/var` → logs e dados variáveis
- `/usr` → programas e bibliotecas de usuário

## 🔑 Permissões de Arquivos

Permissões seguem o formato: `drwxrwxr-x (0775)`

- `d` = identificação de diretório
- `r` = leitura (4)
- `w` = escrita (2)
- `x` = execução (1)

É possícel alterar o dono de um arquivo ou suas permissões:

```bash
sudo chown user:group arquivo.txt
sudo chmod 770 arquivo.txt
```

Uma boa forma de praticar permissões de arquivos é através do [Chmod Calculator](https://chmod-calculator.com/).

---

## 🧭 Comandos de Navegação

| Comando | Função |
|---------|--------|
| `ls` | Lista arquivos |
| `ls -a` | Lista incluindo ocultos |
| `ls -la` | Lista detalhada |
| `pwd` | Mostra diretório atual |
| `cd ..` | Volta um nível |
| `cd nome_pasta` | Entra em pasta |
| `cd ../../outra_pasta` | Sobe e entra em outra pasta |
| `cd` | Volta ao diretório home |

## 📂 Gerenciamento de Arquivos

| Comando | Função |
|---------|--------|
| `mkdir nome` | Cria diretório |
| `nano arquivo.txt` | Cria/edita arquivo |
| `wget <url> -O nome` | Baixa arquivo |
| `mv origem destino` | Move/renomeia arquivo |
| `cat arquivo.txt` | Exibe conteúdo |
| `rm arquivo.txt` | Remove arquivo |
| `rm -r pasta` | Remove pasta e conteúdo |

### ⚠️ Nunca rode `rm -rf /` — apaga todo o sistema!

---

## 👤 Usuários e Grupos

- Usuários → entidades que interagem com o sistema.  
- Grupos → conjuntos de usuários.  

### Comandos úteis:
```bash
whoami                       # Usuário atual
cat /etc/passwd              # Lista de usuários
groups                       # Mostra grupos
groups user                  # Grupos de um usuário específico
sudo comando                 # Executa comando como root
```

---

## 📦 Gerenciamento de Pacotes (Debian/Ubuntu)

```bash
sudo apt update              # Atualiza lista de pacotes
sudo apt upgrade             # Atualiza pacotes instalados
sudo apt install <pacote>    # Instala pacote
sudo apt remove <pacote>     # Remove pacote
sudo apt purge <pacote>      # Remove com configs
```

---

## 🔍 Comandos Úteis e Avançados

1. grep → busca texto em arquivos
```bash
grep -i "password" arquivo.txt
grep -r "config" /etc
```
- `-i` = ignora diferença entre maiúsculo e minúsculo
- `-r` = busca recursivamente por uma palavra
- `-c` = conta quantas vezes a palavra aparece no arquivo
- `-o` = mostra somente a palavra buscada

2. pipe (|) → encadeia comandos
```bash
cat settings.txt | grep "config" | sort
```

3. diff → compara arquivos
```bash
diff arquivo1.txt arquivo2.txt
```

4. strings → extrai texto de arquivos binários
```bash
strings arquivo.bin
```

5. su → troca de usuário
```bash
su - user
```

---

## 🔐 SSH (Secure Shell)

SSH é um protocolo para comunicação segura e criptografada entre dispositivos. A autenticação no SSH é baseada em: Senha (usuário + senha) ou chaves criptográficas (ssh-keygen).

Dificilmente é utilizado em CTFs, mas com as credenciais de usuário é possível acessar máquinas remotas facilmente.

### Conexões
```bash
ssh usuario@host                # conecta via SSH ao host remoto usando usuário e porta padrão (22)
ssh usuario@host -p 2222        # conecta via SSH especificando a porta (neste caso, 2222)
ssh -i chave.pem usuario@host   # conecta via SSH usando uma chave privada para autenticação
```

### Transferência de Arquivos com SCP
```bash
scp arquivo.txt usuario@host:/destino      # copia um arquivo local para um diretório no host remoto
scp usuario@host:/arquivo.txt /destino     # copia um arquivo do host remoto para o diretório local
scp -R pasta/ usuario@host:/destino        # copia recursivamente uma pasta local para o host remoto
```