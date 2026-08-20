
## O que é um Hash?

Um **hash** é o resultado da aplicação de um algoritmo matemático a um dado de entrada, produzindo uma saída de tamanho fixo.

```yaml
Exemplo:
- Senha: `offsec123`  
- Algoritmo: SHA-1  
- Hash: `0d10f487c7c223bb68002832c69880d129222d47`
```
Hashes são funções unidirecionais, ou seja, não é possível "desfazer" o processo, mas técnicas de força bruta e dicionários podem encontrar a entrada original.

---

## Principais Algoritmos de Hash

Existem inúmeros algoritmos e variações que são utilizados para a cifragem de dados, mas alguns dos mais importantes são:

```yaml
- MD5: 128 bits (32 caracteres). Muito rápido, mas fraco contra ataques.  
- SHA-1: 160 bits (40 caracteres). Mais seguro que MD5, mas hoje considerado inseguro.  
- SHA-256: 256 bits (64 caracteres). Mais robusto, usado em criptografia moderna.  
- NTLM: Usado em sistemas Windows para armazenamento de senhas.
```

Hashes podem conter um valor adicional chamado *salt*, que é um dado aleatório adicionado à senha antes de gerar o hash. Isso impede ataques com tabelas pré-computadas e dificulta ataques de dicionário.

---

## Casos de Uso

- **Auditoria de segurança**: verificar a força das senhas em um sistema.  
- **Recuperação de senhas esquecidas**: em ambientes corporativos ou pessoais.  
- **Identificação de vulnerabilidades de autenticação**: avaliando sistemas que armazenam hashes de forma insegura.

> [!CAUTION]
> Hashcat deve ser empregado apenas em ambientes de teste ou com autorização para auditoria.

---

##  Vantagens e Desvantagens

| ✅ Vantagens                                                           | ❌ Desvantagens                                                             |
| --------------------------------------------------------------------- | -------------------------------------------------------------------------- |
| Suporta uma ampla variedade de algoritmos                             | Exige **hardware potente** (GPUs fazem grande diferença)                   |
| Vários modos de ataque: **força bruta, dicionário, máscara, híbrido** | O tempo de quebra cresce exponencialmente conforme a complexidade da senha |
| Otimizado para CPU e GPU                                              | Maior complexidade de uso em comparação com ferramentas online             |

---

## Como identificamos o tipo de hash?

Para fazer a identificação da hash, usamos a ferramenta `hash-identifier` ou `hashid`. 

> [!IMPORTANT]
> Ferramentas como hash-identifier fornecem apenas possíveis tipos de hash. É comum que vários algoritmos tenham formatos semelhantes, sendo necessário testar diferentes opções no Hashcat.
