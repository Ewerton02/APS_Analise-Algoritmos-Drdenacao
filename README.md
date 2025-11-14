# Sistema de Análise de Performance de Algoritmos de Ordenação

> Análise comparativa de algoritmos de ordenação aplicados a dados reais de queimadas no estado de Alagoas (2023-2024)

[![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)]()
[![UNIP](https://img.shields.io/badge/UNIP-Ciência_da_Computação-red)]()

## 📖 Sobre o Projeto

Sistema desenvolvido como Atividade Prática Supervisionada (APS) do curso de Ciências da Computação da UNIP, implementando e comparando três algoritmos clássicos de ordenação:

- **Bubble Sort** (O(n²))
- **Quick Sort** (O(n log n))
- **Heap Sort** (O(n log n))

### Objetivo

Analisar a performance dos algoritmos através da contagem de iterações e trocas ao ordenar 512 registros de focos de incêndio.

## 🔥 Dados Utilizados

- **Fonte**: Instituto Nacional de Pesquisas Espaciais (INPE)
- **Período**: 2023-2024
- **Região**: Estado de Alagoas
- **Total de registros**: 512 focos de queimadas

## 📊 Resultados

### Comparação de Performance

| Algoritmo    | Critério    | Iterações | Trocas  |
|--------------|-------------|-----------|---------|
| Bubble Sort  | Bioma       | 130.816   | 19.845  |
| Bubble Sort  | Município   | 130.816   | 61.588  |
| Bubble Sort  | Data        | 130.816   | 51.329  |
| Quick Sort   | Bioma       | 84.835    | 627     |
| Quick Sort   | Município   | 7.500     | 2.268   |
| Quick Sort   | Data        | 44.960    | 44.332  |
| Heap Sort    | Bioma       | 2.154     | 1.898   |
| Heap Sort    | Município   | 4.428     | 4.172   |
| Heap Sort    | Data        | 4.653     | 4.397   |

**Conclusão**: O Heap Sort apresentou o melhor desempenho, seguido pelo Quick Sort. O Bubble Sort mostrou-se inviável para grandes volumes de dados.

## 🚀 Como Executar

### Pré-requisitos

- Compilador C (GCC, MinGW ou similar)
- Sistema operacional Windows (devido ao `windows.h`)

### Compilação
```bash
gcc APS2.c -o sistema_ordenacao
```

### Execução
```bash
./sistema_ordenacao
```

### Menu de Opções
```
1 - Ordenar por Bioma (Quick Sort)
2 - Ordenar por Município (Quick Sort)
3 - Ordenar por Data (Quick Sort)
4 - Ordenar por Bioma (Bubble Sort)
5 - Ordenar por Município (Bubble Sort)
6 - Ordenar por Data (Bubble Sort)
7 - Ordenar por Bioma (Heap Sort)
8 - Ordenar por Município (Heap Sort)
9 - Ordenar por Data (Heap Sort)
0 - Sair
```

## 💻 Tecnologias Utilizadas

- **Linguagem**: C
- **IDE**: Code::Blocks
- **Codificação**: UTF-8
- **Sistema**: Windows

## 📚 Estrutura do Código
```c
typedef struct {
    int id_bdq;
    char foco_id[MAX_STRING];
    float lat, lon;
    char data_pas[MAX_STRING];
    char pais[MAX_STRING];
    char estado[MAX_STRING];
    char municipio[MAX_STRING];
    char bioma[MAX_STRING];
} Foco;
```

### Principais Funções

- `bubble_sort()` - Implementação do Bubble Sort
- `quick_sort()` - Implementação do Quick Sort
- `heap_sort()` - Implementação do Heap Sort
- `carregar_csv()` - Leitura dos arquivos CSV
- `exibir_focos()` - Exibição formatada dos dados

## 👥 Equipe

- **Eric Takashi Katayama** - RA: G7553I7
- **José Ewerton Alves dos Santos** - RA: G70JCI9
- **Mariana Kobori Gabrielli** - RA: R192512
- **Gabriel Hamad Passos Andrade** - RA: G73GHC3

**Instituição**: Universidade Paulista (UNIP)  
**Curso**: Ciências da Computação  
**Ano**: 2025

## 📄 Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

## 📧 Contato

Para dúvidas ou sugestões, entre em contato através do GitHub.

---

⭐ Se este projeto foi útil, considere dar uma estrela!
