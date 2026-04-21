# Ferramentas para Enumeração (NMAP, goBuster e ffuf)

➡️ [PDF da Aula](./pdf/recon.pdf) de NMAP desenvolvido por [@rideckszz](https://github.com/rideckszz)\
➡️ [PDF da Aula](./pdf/goBuster.pdf) de goBuster desenvolvido por [@ITA-LOW](https://github.com/ITA-LOW)\
➡️ [PDF da Aula](./pdf/ffuf.pdf) de ffuf desenvolvido por [@rideckszz](https://github.com/rideckszz)

---

### 🧭 Tipos de Enumeração

### 🔹 Passiva
- Busca informações públicas sem interagir com o alvo.
- Exemplos: registros de domínio, redes sociais, motores de busca (Shodan, Censys).

#### 🔹 Ativa
- Interage diretamente com o alvo.
- Exemplos: varredura de portas, identificação de serviços, coleta de banners e vulnerabilidades.

⚠️ A enumeração ativa pode gerar alertas no sistema de segurança do alvo.


## ⚡ 📖 O que é Web Fuzzing?

O Web Fuzzing é uma técnica de segurança que consiste em enviar várias entradas inesperadas para uma aplicação, observando como ela responde.

Principais objetivos:
- Descobrir diretórios e arquivos ocultos  
- Encontrar subdomínios e vhosts  
- Identificar parâmetros e extensões válidas  
- Detectar falhas de segurança exploráveis

### 🔑 Fuzzing vs Brute-Forcing

- Fuzzing → usa entradas variadas, inesperadas e wordlists mutadas para descobrir comportamentos ocultos.
- Brute-Forcing → testa sistematicamente todas as combinações possíveis até encontrar a correta.

Analogia:
- Fuzzing = tentar abrir a porta com chaves, grampos, cartões, clips.
- Brute-Forcing = testar cada chave do chaveiro uma por uma.

### 🛠️ Conceitos Essenciais

- Wordlist → lista de palavras/valores a serem testados  
- Payload → dado enviado ao alvo  
- Response Analysis → análise das respostas do servidor  
- Fuzzer → ferramenta que automatiza os testes (como o `ffuf`)  
