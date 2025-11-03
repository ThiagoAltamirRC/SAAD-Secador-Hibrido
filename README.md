# 🏆 SAAD: Sistema de Aquisição Automática de Dados em Secador Híbrido Solar-Elétrico

<p align="center">
  <img src="https://img.shields.io/badge/Vencedor-1%C2%BA%20Lugar%20CONBEA%202023-blue?style=for-the-badge&logo=award&labelColor=gold" alt="Projeto Vencedor no CONBEA 2023">
</p>

## 💡 Sobre o Projeto

[cite_start]Este projeto consiste no desenvolvimento e validação de um **Sistema de Aquisição Automática de Dados (SAAD)** [cite: 6] [cite_start]para monitorar em tempo real [cite: 40] [cite_start]os parâmetros críticos (temperatura e umidade relativa do ar [cite: 17, 39][cite_start]) de um Secador Híbrido Solar-Elétrico (SHSE)[cite: 6, 7].

[cite_start]A automação do monitoramento é vital para garantir a qualidade e a vida útil do produto final agrícola [cite: 39] [cite_start]e mitigar perdas[cite: 35]. [cite_start]O projeto foi apresentado no **LII Congresso Brasileiro de Engenharia Agrícola (CONBEA) em 2023**[cite: 2, 3].

## 🛠️ Stack de Tecnologia e Arquitetura de Software

Este projeto demonstrou proficiência em integração de hardware, redes, banco de dados e desenvolvimento de aplicações móveis (Low-Code/No-Code).

### Componentes Chave

| Categoria | Tecnologia | Função no Sistema | Palavra-chave para Recrutadores |
| :--- | :--- | :--- | :--- |
| **Microcontrolador** | [cite_start]**ESP32** [cite: 19, 27] | [cite_start]Coleta de dados e conexão Wi-Fi com o Banco de Dados[cite: 50]. | C/C++, IoT, Redes, Firmware |
| **Sensores** | [cite_start]**DHT22** (12 unidades) [cite: 47] | [cite_start]Medição de Temperatura e Umidade Relativa do Ar[cite: 47]. | Lógica de Programação, Depuração (Debugging) |
| **Banco de Dados (Back-end)** | [cite_start]**Google Firebase** [cite: 50, 53] | [cite_start]Armazenamento temporário (Realtime Database) [cite: 51] [cite_start]e permanente (Firestore Database) [cite: 53] dos dados coletados. | Cloud Computing, NoSQL, APIs de Serviço |
| **Aplicação (Front-end)** | [cite_start]**GERAR Mobile App 2.0** [cite: 19, 23, 56] | [cite_start]Aplicativo desenvolvido na plataforma **AppGyver** [cite: 56] [cite_start]para monitoramento remoto em tempo real [cite: 41, 40][cite_start], com tela de login e informações do exaustor[cite: 58]. | Low-Code/No-Code, UI/UX, Telas de Login/Autenticação |

### Fluxo de Dados e Comunicação

[cite_start]O SAAD opera em um ciclo robusto de aquisição e transmissão[cite: 52]:

1.  [cite_start]O **ESP32** [cite: 48] [cite_start]coleta os dados de **12 sensores DHT22** distribuídos no secador[cite: 47, 49].
2.  [cite_start]A cada minuto [cite: 51][cite_start], o microcontrolador se conecta via **Wi-Fi** para enviar os dados ao **Realtime Database do Firebase**[cite: 50, 51].
3.  [cite_start]O **GERAR Mobile App 2.0** compila os dados do Realtime Database a cada 10 minutos [cite: 53] [cite_start]e os armazena permanentemente no **Firestore Database**[cite: 53].

## 🎯 Desafios de Engenharia de Software

O desenvolvimento deste sistema exigiu atenção a aspectos cruciais de engenharia:

* **Otimização e Gerenciamento de Memória (C/C++):** Garantir o funcionamento eficiente do código do firmware no ambiente restrito do ESP32, lidando com múltiplas leituras de sensores e mantendo a conexão de rede.
* [cite_start]**Confiabilidade de Dados e Redes:** Implementar a lógica de conexão e envio de dados a cada minuto [cite: 51][cite_start], garantindo a integridade dos dados coletados[cite: 54].
* [cite_start]**Validação e Calibração:** O SAAD validou os dados comparando as leituras do DHT22 com equipamentos de precisão convencionais (termopares e termo-higrômetros), demonstrando boa correlação nas leituras de Entrada/Saída do coletor[cite: 21, 29, 63].

## 📂 Repositório e Próximos Passos

Este projeto valida minha competência na união de **Programação de Baixo Nível (`C/C++`)**, **Protocolos de Comunicação (`Wi-Fi`)** e **Serviços de Nuvem (`Firebase`)** para a criação de soluções robustas.

* [cite_start]**Próximos Passos:** Melhorar a metodologia de coleta de dados no ponto da câmara de secagem [cite: 93] e explorar a implementação do sistema em plataformas de desenvolvimento Web (ex: *React/Next.js* ou *Python/Django*) para criar um dashboard de monitoramento mais robusto.

---
