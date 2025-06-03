# Chess-with-GUI

A complete two player Chess game with a graphical user interface, built using C++ and SFML.

## Features

- Play chess with a clean GUI
- Built using SFML (Simple and Fast Multimedia Library)
- Cross-platform support (Linux and Windows)

## Requirements

- C++ Compiler (g++)
- [SFML 2.5.1+](https://www.sfml-dev.org/download.php)

## Compilation and Running

### Linux

1. **Install SFML:**  
   On Ubuntu/Debian:  
   ```sh
   sudo apt-get install libsfml-dev
   ```

2. **Compile and Run:**  
   ```sh
   g++ -c main.cpp
   g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
   ./sfml-app
   ```

### Windows (VS Code)

1. **Download and install SFML:**  
   Get the Windows version from [SFML Downloads](https://www.sfml-dev.org/download.php) and extract it (e.g., to `C:\SFML-2.5.1`).

2. **Compile and Run:**  
   ```sh
   g++ -IC:\SFML-2.5.1\include -c main.cpp 
   g++ -LC:\SFML-2.5.1\lib .\main.o -o app.exe -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main -mwindows
   ./app
   ```

3. **To enable terminal output in VS Code:**  
   ```sh
   g++ -IC:\SFML-2.5.1\include -c main.cpp 
   g++ -LC:\SFML-2.5.1\lib .\main.o -o app.exe -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main
   ./app
   ```

   > **Note:** The `-mwindows` flag disables the terminal. Remove it if you want terminal output.

## Usage

After compiling, run the executable as shown above. The chess GUI window should appear.
