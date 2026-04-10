![CI](https://github.com/JujuCesar/C14---NP1-Testes-CI-CD-/actions/workflows/ci.yml/badge.svg)

## 📡 WanderLust Firmware

Este projeto consiste no desenvolvimento de firmware embarcado para um sistema de aquisição e transmissão de dados ambientais, utilizando sensores e comunicação via LoRa.

O sistema é responsável por coletar dados de temperatura, pressão e outros sensores, estruturá-los em um formato de telemetria e transmiti-los remotamente.

## ⚙️ Tecnologias

- Linguagem: C / C++
- Arquitetura: Sistemas Embarcados
- Framework de testes: Ceedling + Unity
- Gerenciador de dependências: Ruby Gems (Ceedling)
- Compilador: GCC
- Ambiente de desenvolvimento: PlatformIO

## 🧪 Testes

O projeto utiliza testes unitários para validar o comportamento dos módulos principais:

- Telemetry (estrutura e inicialização)
- BMP280 (leitura e validação de dados)
- LoRa (envio de dados)

Foram implementados 20 testes cobrindo:

- Fluxos normais (casos válidos)
- Fluxos de exceção (valores inválidos, limites e erros)

Mocks foram utilizados para simular hardware (sensores e comunicação), permitindo testes sem dependência física dos dispositivos.

## 🔁 Pipeline CI/CD

O projeto possui um pipeline automatizado utilizando GitHub Actions.

### 🔹 Etapas:

1. **Build**
   - Compilação do projeto
   - Geração de artifact

2. **Test**
   - Execução dos testes unitários com Ceedling
   - Geração de relatório de testes
   - Execução em paralelo com o build

3. **Deploy**
   - Executado apenas após sucesso no build e testes
   - Publicação de artifacts do projeto
   - Simulação de etapa de entrega contínua (CI/CD)

4. **Notificação**
   - Envio de e-mail automático ao final do pipeline
   - Utilização de secrets para segurança (sem dados hardcoded)



## 🤖 Uso de Inteligência Artificial (IA)

Durante o desenvolvimento do projeto, foi utilizadas as IA's (ChatGPT e Gemini) como ferramentas de apoio para compreensão de conceitos, depuração de erros e estruturação do pipeline CI/CD.

Abaixo estão alguns exemplos de prompts utilizados e seus respectivos resultados:


### 📁 Problema: Testes com float falhando no Unity

**Prompt utilizado:**

"Estou utilizando Ceedling com Unity para testes unitários em C, mas ao usar TEST_ASSERT_EQUAL_FLOAT estou recebendo o erro 'Unity Floating Point Disabled'. Como habilitar suporte a float corretamente no Unity?"

**Resultado:**

A IA sugeriu:
- Adicionar `UNITY_INCLUDE_FLOAT` e `UNITY_INCLUDE_DOUBLE` no `project.yml`
- Garantir que as flags de compilação também incluíssem essas definições
- Executar `ceedling clobber` para limpar o cache

**Avaliação:**

✔ Solução correta e eficaz  
✔ Problema resolvido completamente  
✔ Aplicável diretamente no projeto  


### 📁 Problema: Paths não encontrados no Ceedling

**Prompt utilizado:**

"O Ceedling está retornando erro dizendo que o path '../firmware/src' não existe, mesmo ele estando correto. Como configurar corretamente os paths no project.yml?"

**Resultado:**

A IA explicou:
- Que os paths são relativos à pasta onde o Ceedling está sendo executado
- A importância de validar a estrutura real de diretórios
- Como ajustar corretamente para `../../src/**`

**Avaliação:**

✔ Ajudou a entender o funcionamento interno do Ceedling  
✔ Problema resolvido após correção do caminho relativo  


### 🔌 Problema: Testar código dependente de hardware

**Prompt utilizado:**

"Como posso testar um driver de sensor BMP280 em C sem ter o hardware físico disponível usando Ceedling?"

**Resultado:**

A IA sugeriu:
- Criar um mock da biblioteca `Adafruit_BMP280`
- Simular funções como leitura de temperatura e pressão
- Utilizar variáveis globais para controlar o comportamento do mock

**Avaliação:**

✔ Permitiu testar o código sem hardware real  
✔ Introduziu conceito importante de mocking  
✔ Extremamente útil para sistemas embarcados  


### 🔐 Problema: Secrets retornando null no GitHub Actions

**Prompt utilizado:**

"Meu GitHub Actions não está reconhecendo secrets (EMAIL_FROM, EMAIL_TO, EMAIL_PASSWORD), retornando null. O que pode ser?"

**Resultado:**

A IA identificou que:
- Os secrets haviam sido criados incorretamente (todos dentro de um único secret)
- Era necessário criar secrets separados para cada variável

**Avaliação:**

✔ Identificação precisa do problema  
✔ Solução direta e funcional  
✔ Pipeline passou a funcionar corretamente  


### 📌 Conclusão sobre o uso de IA

A IA foi utilizada como ferramenta de apoio técnico e educacional, auxiliando na resolução de problemas e na compreensão de conceitos.

As soluções propostas foram validadas na prática e integradas ao projeto com sucesso.

A utilização da IA contribuiu significativamente para a produtividade e qualidade do desenvolvimento.



Estrutura do projeto WanderLust:

WanderLust/
│
├── firmware/
│   │
│   ├── include/
│   │   └── README
│   │
│   ├── services/
│   │   ├── telemetry.c
│   │   └── telemetry.h
│   │
│   ├── src/
│   │   ├── main.cpp
│   │   │
│   │   └── drivers/
│   │       ├── barometer/
│   │       │   ├── bmp280.c
│   │       │   └── bmp280.h
│   │       │
│   │       ├── imu/
│   │       │   ├── mpu6050.c
│   │       │   └── mpu6050.h
│   │       │
│   │       └── lora/
│   │           ├── rfm95.c
│   │           └── rfm95.h
│   │
│   └── test/
│       └── tests/
│           ├── project.yml
│           │
│           ├── src/
│           │   └── unity_config.h
│           │
│           └── test/
│               ├── support/ (CMock's)
│               │   ├── Adafruit_BMP280.h
│               │   ├── SPI.h
│               │   └── LoRa.h
│               │
│               ├── test_telemetry.c
│               ├── test_bmp280.c
│               └── test_lora.c
│
├── .github/
│   └── workflows/
│       └── ci.yml
│
├── platformio.ini
├── .gitignore
└── README.md