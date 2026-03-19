# Quebra de Hash com HashCat

➡️ [PDF da Aula](./pdf/hashcat.pdf) desenvolvido por [@ITA-LOW](https://github.com/ITA-LOW)

---

## 🧩 O que é um Hash?

Um **hash** é o resultado da aplicação de um algoritmo matemático a um dado de entrada, produzindo uma saída de tamanho fixo.

```yaml
Exemplo:
- Senha: `offsec123`  
- Algoritmo: SHA-1  
- Hash: `0d10f487c7c223bb68002832c69880d129222d47`
```
Hashes são funções unidirecionais, ou seja, não é possível "desfazer" o processo, mas técnicas de força bruta e dicionários podem encontrar a entrada original.

### 🔑 Principais Algoritmos de Hash

Existem inúmeros algoritmos e váriações que são utilizados para a cifragem de dados, mas alguns dos mais importantes são:

```yaml
- MD5: 128 bits (32 caracteres). Muito rápido, mas fraco contra ataques.  
- SHA-1: 160 bits (40 caracteres). Mais seguro que MD5, mas hoje considerado inseguro.  
- SHA-256: 256 bits (64 caracteres). Mais robusto, usado em criptografia moderna.  
- NTLM: Usado em sistemas Windows para armazenamento de senhas.
```

### 🎯 Casos de Uso

- **Auditoria de segurança**: verificar a força das senhas em um sistema.  
- **Recuperação de senhas esquecidas**: em ambientes corporativos ou pessoais.  
- **Identificação de vulnerabilidades de autenticação**: avaliando sistemas que armazenam hashes de forma insegura.  

⚠️ *Uso ético*: Hashcat deve ser empregado apenas em ambientes de teste ou com autorização para auditoria.

### ⚖️ Vantagens e Desvantagens

| ✅ Vantagens                                                          | ❌ Desvantagens                                                              |
|-----------------------------------------------------------------------|-------------------------------------------------------------------------------|
| Suporta uma ampla variedade de algoritmos                             | Exige **hardware potente** (GPUs fazem grande diferença)                      |
| Vários modos de ataque: **força bruta, dicionário, máscara, híbrido** | O tempo de quebra cresce exponencialmente conforme a complexidade da senha    |
| Otimizado para CPU e GPU                                              | Maior complexidade de uso em comparação com ferramentas online                |

### 💻 Exemplos de Uso

É sugerido que se utilize do comando `hashcat -h` para visualizar as instruções, flags e identificadores da ferrameta.

#### 1. Ataque de Dicionário

```bash
hashcat -m 0 -a 0 hashes.txt wordlist.txt

# -m 0 → Algoritmo MD5
# -a 0 → Ataque de dicionário
# hashes.txt → Arquivo contendo hashes
# wordlist.txt → Lista de senhas para testar
```

#### 2. Ataque de Força Bruta

```bash
hashcat -m 100 -a 3 hashes.txt ?a?a?a?a

# -m 100 → Algoritmo SHA1
# -a 3 → Ataque de força bruta
# hashes.txt → Arquivo contendo hashes
# ?a → Qualquer caractere (cada ?a é uma posição testada)
```

#### 3. Ataque Híbrido (dicionário + máscara)

```bash
# Testa cada palavra do dicionário adicionando dois dígitos ao final.
hashcat -m 1000 -a 6 hashes.txt wordlist.txt ?d?d

# -m 1000 → Algoritmo NTLM
# -a 6 → Ataque híbrido
# hashes.txt → Arquivo contendo hashes
# wordlist.txt → Lista de senhas para testar
# ?d → Dígito entre 0 e 9 (cada ?d é uma posição testada)
```