#include <iostream>
#include <thread>

static bool s_Finished = false;

// Just print a line of text
void DoWork() {

	using namespace std::literals::chrono_literals;

	std::cout << "Function thread id=" << std::this_thread::get_id() << std::endl;

	while(!s_Finished) {
		// \n is performance wise better than endl, unless flushing of stream is required
		std::cout << "Working...\n";

		// Prevent the thread to be CPU Usage 100% (if it print as fast as he can)
		std::this_thread::sleep_for(1s); 
	}
}

int main() {
	std::cout << "Main thread id=" << std::this_thread::get_id() << std::endl;
	// This worker will just print Working as fast as it can until we press Enter
	std::thread worker(DoWork);

	// When whe press Enter, set s_Finished to true and stop the function printing by the otehr thread
	std::cin.get();
	s_Finished = true;
	
	// Tell the main thread to wait that the thread worker finish his task before it run the next ones
	worker.join();

	std::cout << "Finished." << std::endl;
	// Dont do cin.get() while the otehr thread is running
	std::cin.get();

	return 0;
}