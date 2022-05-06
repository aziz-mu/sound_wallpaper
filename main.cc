#include <iostream>
#include <string>
#include <unistd.h>
#include <fftw3.h>
#include "soundSource.h"

static ssize_t loop_write(int fd, const void* data, size_t size){
	// Helper function taken from the PulseAudio Example file - will
	// be removed once I get the sound working correctly. 
	ssize_t ret = 0;

	while (size > 0){
		ssize_t r;
		if ((r = write(fd, data, size)) < 0)
			return r;

		if (r==0) break;

		ret += r;
		data = (const uint8_t*) data+r;
		size -= (size_t) r;
	}
	
	return ret;
}

int main(){
	// Set up sound
	soundSource* main_sound_stream = new soundSource(); // Make Unique Pointer

	// Set up variables for running visualizer
	bool shutdown = false;

	// Main Loop
	while (!shutdown){
		// Read Stream
		main_sound_stream->read_stream();
		loop_write(STDOUT_FILENO, main_sound_stream->get_pcm_buffer(), sizeof(main_sound_stream->get_pcm_buffer()));

	}
}
