#include <iostream>
#include <thread>

using namespace std;

void cpp(){
	cout << "hey";
}

int main(){

	thread t(cpp);
	t.join();
	return 0;
}

