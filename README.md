# winCapacitorSim
# (only with Windows 11)

This software performs calculations related to an RC (resistor-capacitor) circuit. It allows users to input various parameters and calculates the voltages during the charging and discharging phases of the circuit.

## Features

- **User Input Handling**: Prompts the user to input maximum voltage, capacitance, frequency, and resistance.
- **Standard Precision Calculations**: Uses standard C types and functions for calculations.
- **Exponential Decay Calculation**: Computes the exponential decay factor based on user inputs.
- **Charge and Discharge Functions**: Calculates the voltages during the charging and discharging phases of the RC circuit.

## Functions

### Main Function
- Declares and initializes variables using standard C types.
- Calculates the value of Euler's number (\(e\)).
- Calls the `lecture` function to get user inputs.
- Calculates the transient period and other necessary constants.
- Includes pause to keep the window open.

### Lecture Function
- Prompts the user to input:
  - Maximum voltage of the power supply (V)
  - Capacitance of the capacitor (F)
  - Frequency of the oscillation period (Hz)
  - Resistance in series with the capacitor (Ohm)
- Sets the user inputs to the corresponding variables.

### Trcharge Function
- Calculates the maximum voltage during the charging phase of the RC circuit.

### TrDischarge Function
- Calculates the minimum voltage during the discharging phase of the RC circuit.

### Partev Function
- Calculates the exponential decay factor based on the period and time constant of the RC circuit.

## Usage

1. Clone the repository:
   ```sh
   git clone https://github.com/Alexinom91/winCapacitorSim.git

2. Navigate to the project directory:
   ```sh
    cd winCapacitorSim
4. Compile the code:
   ```sh
    compile.bat
5. Run the executable:
    ```sh
    ./ciao.exe

