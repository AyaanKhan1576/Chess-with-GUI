Commands for compiling and running the sfml code Linux
g++ -c main.cpp
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app


Compile VS Code
g++ -IC:\SFML-2.5.1\include -c main.cpp 
g++ -LC:\SFML-2.5.1\lib .\main.o -o app.exe -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main -mwindows
./app


To compile in a way that terminal works in VS Code:
g++ -IC:\SFML-2.5.1\include -c main.cpp 
g++ -LC:\SFML-2.5.1\lib .\main.o -o app.exe -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main
./app