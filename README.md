# 🏆 SAAD: Sistema de Aquisição Automática de Dados em Secador Híbrido Solar-Elétrico

<p align="center">
  <img src="https://img.shields.io/badge/Vencedor-1%C2%BA%20Lugar%20CONBEA%202023-blue?style=for-the-badge&logo=award&labelColor=gold" alt="Projeto Vencedor no CONBEA 2023">
</p>
<p align="center">
  <img src="https://img.shields.io/badge/Tecnologia-IoT%20e%20Data%20Acquisition-red?style=for-the-badge&logo=iot-edge&logoColor=white" alt="IoT e Data Acquisition">
</p>

## 💡 Resumo Executivo e Impacto

Este projeto de **Internet das Coisas (IoT)** e **Automação** visa mitigar o desperdício de produtos agrícolas (um gargalo da agricultura brasileira) através da otimização do processo de secagem.

Desenvolvemos um **Sistema de Aquisição Automática de Dados (SAAD)** para monitorar em tempo real a **temperatura** e **umidade relativa do ar** dentro de um Secador Híbrido Solar-Elétrico (SHSE). O sistema garante o monitoramento contínuo e a coleta de dados, que são cruciais para a conservação e qualidade do produto final.

* **Validação:** O trabalho foi validado com sucesso e apresentado no **LII Congresso Brasileiro de Engenharia Agrícola (CONBEA 2023)**.

## ⚙️ Arquitetura e Stack de Tecnologia

A solução é baseada em uma arquitetura de nuvem (Cloud-Based) e embarcados (Embedded Systems), demonstrando a integração completa entre hardware, firmware e serviços web.

### 1. Embedded Software (Firmware)

* **Linguagem Principal:** C/C++ (Programação de baixo nível).
* **Microcontrolador:** **ESP32** (Utilizado por sua capacidade de processamento dual-core e conectividade Wi-Fi).
* **Ação:** O ESP32 realiza a leitura de **12 sensores DHT22** (Temperatura e Umidade Relativa) distribuídos em três pontos críticos do secador (entrada, saída do coletor solar e câmara de secagem).

### 2. Comunicação e Back-end (Cloud Services)

* **Protocolo de Transmissão:** O ESP32 utiliza a conectividade **Wi-Fi** para publicar os dados na nuvem.
* **Banco de Dados (NoSQL/Cloud):** **Google Firebase**.
    * **Firebase Realtime Database:** Utilizado para armazenamento temporário e de **baixa latência**, recebendo um fluxo de dados a cada **1 minuto**.
    * **Firebase Firestore Database:** Utilizado para armazenamento **permanente** dos dados, após compilação a cada **10 minutos**, suportando análise posterior e gerenciamento de informações.

### 3. Front-end (Aplicação Móvel)

* **Plataforma de Desenvolvimento:** **AppGyver** (Utilizado para o desenvolvimento *Low-Code/No-Code*).
* **Aplicação:** **GERAR Mobile App 2.0**.
* **Funcionalidades:** Tela de **Login/Autenticação** de usuário, visualização em tempo real dos valores de temperatura e umidade, e estado operacional do exaustor.

## 🚧 Desafios Técnicos e Ganhos de Habilidade

Este projeto foi uma experiência intensiva nas seguintes áreas, cruciais para um Desenvolvedor Júnior:

### 1. Desenvolvimento de Firmware e Otimização
* **Gerenciamento de Recursos:** Programação em C/C++ em um ambiente com recursos limitados de RAM e flash, exigindo código limpo e otimizado.
* **Handling de Sensores:** Implementação da lógica para a leitura estável e precisa de 12 sensores DHT22 simultaneamente.

### 2. Integração de Redes e Protocolos
* **Conectividade Wi-Fi:** Estabelecimento e manutenção da conexão Wi-Fi do ESP32 para garantir o envio contínuo dos dados para a nuvem.
* **Integração Firebase:** Uso da API do Google Firebase (serviço de back-end como serviço - BaaS) para autenticação e manipulação do Realtime Database e Firestore.

### 3. Validação e Confiabilidade
* **Controle de Qualidade de Dados:** O sistema de validação comparou as leituras do SAAD (DHT22) com instrumentos de precisão (termopares e termo-higrômetros), garantindo a **fidelidade** e **confiabilidade** dos dados coletados para fins de pesquisa e aplicação prática.

## 🔗 Código Fonte e Artigo Científico

* **Repositório do Firmware:** [Link para o repositório do seu código C/C++ do ESP32]
* **Artigo Completo (PDF):** <a 
        href="  https://github.com/ThiagoAltamirRC/SAAD-Secador-Hibrido/blob/main/docs/Coutinho_et_al_2023.pdf">
        SAAD-Secador-Hibrido
    </a>      

---
