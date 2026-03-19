# Sorting Algorithm Performance Analysis System

> Comparative analysis of sorting algorithms applied to real wildfire data from the state of Alagoas, Brazil (2023-2024)

[![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)]()
[![UNIP](https://img.shields.io/badge/UNIP-Computer_Science-red)]()

## 📖 About the Project

System developed as a Supervised Practical Activity (APS) for the Computer Science program at UNIP, implementing and comparing three classic sorting algorithms:

- **Bubble Sort** (O(n²))
- **Quick Sort** (O(n log n))
- **Heap Sort** (O(n log n))

### Objective

Analyze algorithm performance by counting iterations and swaps when sorting 512 wildfire hotspot records.

## 🔥 Dataset

- **Source**: National Institute for Space Research (INPE)
- **Period**: 2023-2024
- **Region**: State of Alagoas, Brazil
- **Total records**: 512 wildfire hotspots

## 📊 Results

### Performance Comparison

| Algorithm    | Criterion   | Iterations | Swaps   |
|--------------|-------------|------------|---------|
| Bubble Sort  | Biome       | 130,816    | 19,845  |
| Bubble Sort  | Municipality| 130,816    | 61,588  |
| Bubble Sort  | Date        | 130,816    | 51,329  |
| Quick Sort   | Biome       | 84,835     | 627     |
| Quick Sort   | Municipality| 7,500      | 2,268   |
| Quick Sort   | Date        | 44,960     | 44,332  |
| Heap Sort    | Biome       | 2,154      | 1,898   |
| Heap Sort    | Municipality| 4,428      | 4,172   |
| Heap Sort    | Date        | 4,653      | 4,397   |

**Conclusion**: Heap Sort delivered the best overall performance, followed by Quick Sort. Bubble Sort proved impractical for large datasets.

## 🚀 Getting Started

### Prerequisites

- C compiler (GCC, MinGW, or similar)
- Windows OS (required due to `windows.h`)

### Compilation
```bash
gcc APS2.c -o sorting_system
```

### Execution
```bash
./sorting_system
```

### Menu Options
```
1 - Sort by Biome (Quick Sort)
2 - Sort by Municipality (Quick Sort)
3 - Sort by Date (Quick Sort)
4 - Sort by Biome (Bubble Sort)
5 - Sort by Municipality (Bubble Sort)
6 - Sort by Date (Bubble Sort)
7 - Sort by Biome (Heap Sort)
8 - Sort by Municipality (Heap Sort)
9 - Sort by Date (Heap Sort)
0 - Exit
```

## 💻 Tech Stack

- **Language**: C
- **IDE**: Code::Blocks
- **Encoding**: UTF-8
- **OS**: Windows

## 📚 Code Structure
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

### Main Functions

- `bubble_sort()` - Bubble Sort implementation
- `quick_sort()` - Quick Sort implementation
- `heap_sort()` - Heap Sort implementation
- `carregar_csv()` - CSV file loader
- `exibir_focos()` - Formatted data display

## 👥 Team

- **Eric Takashi Katayama** - ID: G7553I7
- **José Ewerton Alves dos Santos** - ID: G70JCI9
- **Mariana Kobori Gabrielli** - ID: R192512
- **Gabriel Hamad Passos Andrade** - ID: G73GHC3

**Institution**: Universidade Paulista (UNIP)  
**Program**: Computer Science  
**Year**: 2025

## 📄 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## 📧 Contact

For questions or suggestions, reach out via GitHub.

---

⭐ If this project was helpful, consider giving it a star!
