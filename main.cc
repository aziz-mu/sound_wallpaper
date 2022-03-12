#include <iostream>
#include "soundSource.h"

int main(){
	// Set up sound
	soundSource* main_sound_stream = new soundSource(); // Make Unique Pointer
	std::cout << "Initialized sound stream connection" << "\n";
	std::cout << "Nothing implemented currently: exiting. " << "\n";
		// In cli_visualizer, this setup is done in PulseAudioSource::read where m_pulseaudio_simple == nullptr


	// Loop and Read from sound

		// read is done using pa_simple_read
	
}
