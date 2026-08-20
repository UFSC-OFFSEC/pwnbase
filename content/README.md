# Guia Inicial

## O que é um CTF (Capture The Flag)

É uma competição projetada para a prática de segurança ofensiva. O desafio consiste em invadir sistemas simulados com o objetivo final de conquistar flags, que funcionam como provas de que o sistema foi comprometido.

Existem três tipos de modalidades de CTF:
- **Jeopardy-style:** Desafios baseados em categorias;
- **Attack/Defense:** Cenários de ataque e defesa;
- **Pentest-based:** Simulações de testes de intrusão reias.
Para praticar essa habilidades, são utilizados laboratórios especializados em ambientes seguros, como o *HackTheBox* e o *TryHackMe*.

### **Workflow de Ataque**

A resolução de um CTF segue um fluxo lógico.
1. **Reconhecimento/Enumerations:** é o mapeamento inicial do sistema, o foco é descobrir os serviços ativos e endereços IP.
2. **Exploração/Exploitation:** após a identificação dos serviços, é feita uma coleta aprofundada de dados e a exploração de vulnerabilidades encontradas para conseguir o acesso inicial.
3. **Escalação de Privilégios/Privilege Escalation:** geralmente, o acesso inicial é obtido com privilégios limitados. O objetivo nessa fase é explorar configurações incorretas para obter o **root** do sistema.

> [!NOTE]
> Você pode ver mais detalhes de como começar em: [Guia Inicial](Guia%20Inicial%20-%20OFFSEC.pdf)
---

## Guia dos Conteúdos

Este diretório organiza o conteúdo didático do repositório de forma sequencial.

## Módulos

* [**[00] - Tools Setup**](%5B00%5D%20-%20setup/) $\rightarrow$ Configuração da máquina virtual e instalação de ferramentas.
* [**[01] - Fundamentals**](%5B01%5D%20-%20fundamentals/) $\rightarrow$  Revisão de sistemas operacionais e comandos no terminal do Linux.
* [**[02] - Enumeration**](%5B02%5D%20-%20recon/) $\rightarrow$ Enumeração, varredura de portas e mapeamento da superfície de ataque.
* [**[03] - Exploitation**](%5B03%5D%20-%20web-attacks/)$\rightarrow$  Identificação de vulnerabilidades comuns em sistemas web.
* [**[04] - Web Attacks**](%5B04%5D%20-%20exploitation/) $\rightarrow$ Exploits, comprometimento de serviços vulneráveis e ganho de acesso inicial.
* [**[05] - Privilege Escalation**](%5B05%5D%20-%20privesc/) $\rightarrow$ Escalação de privilégios. Técnicas de pós-exploração para obter acesso administrativo (root) no alvo.
* [**[06] - Useful Tools**] $\rightarrow$ 

## Instruções de Uso

1. **Siga a numeração** 
2. **Material de apoio:** Durante os estudos, utilize as pastas na raiz do repositório como suporte:
   * [/writups:](../writeups/) Para consultar resoluções de desafios apenas após tentar executar a prática por conta própria.
   * [/presentations:](../presentations/) Para consultar slides apresentações para referência.
