compile:
	g++ -o build/main.exe src/entrypoint/main.cpp src/hello_world/hello_world.cpp -std=c++23 -l httpserver -l pqxx -l pq -iquote src/hello_world

run:
	build/main.exe
