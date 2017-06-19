All:
	@echo "Compiling Snaze..."
	@g++ -std=c++11 src/manager.cpp src/main.cpp src/game.cpp src/snake.cpp -I include -o bin/snake
	#@echo "Running Snaze..."
	#@./bin/snake data/tab1
clean:
	@echo "Cleaning..."
	@rm bin/*