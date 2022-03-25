#include <iostream>
#include <string>
#include "soundSource.h"

int main(){
	// Set up sound
	soundSource* main_sound_stream = new soundSource(); // Make Unique Pointer
	std::cout << "Initialized sound stream connection" << "\n";
		// In cli_visualizer, this setup is done in PulseAudioSource::read where m_pulseaudio_simple == nullptr


	// Loop and Read from sound
	bool shutdown = false;
	int counter = 0;

	std::cout << "Displaying raw pcm data: " << "\n";
	while (!shutdown){
		counter++;
		main_sound_stream->read_stream();
	}	
}
