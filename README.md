# CNN FPGA Accelerator

A high-performance FPGA accelerator implementation for Convolutional Neural Networks (CNN) using Xilinx Vivado and High-Level Synthesis (HLS).

## Repository Structure

```
CNN-FPGA-Accelerator/
│
├── README.md
│
├── Source_Code/
│   ├── conv1_hls.c
│   ├── conv1_hlstb.c
│   ├── weights.c
│   └── weights.h
│
├── Vivado/
│   ├── cnn_accelerator_architecture.png
│   └── axi_memory_interconnect.png
│
├── Results/
│   ├── Resource_Utilization.png
│   ├── Timing_Summary.png
│   └── Report_Power.png
│
└── Documentation/
```

## Setup & Implementation

1. **Source Code (`Source_Code/`)**: Contains Vivado HLS kernel functions (`conv1_hls.c`), testbenches (`conv1_hlstb.c`), and network weights (`weights.c`, `weights.h`).
2. **Vivado Architecture (`Vivado/`)**: Visual block diagrams showing IP integrator designs, including AXI memory interconnects and core CNN accelerator IP architecture.
3. **Synthesis & Implementation Results (`Results/`)**: FPGA hardware performance summaries including resource utilization (LUTs, FFs, BRAMs, DSPs), timing reports, and power analysis.
