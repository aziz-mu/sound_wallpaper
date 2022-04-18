#include <iostream>
#include <string>
#include <unistd.h>
#include <fftw3.h>
#include "soundSource.h"

int main(){
	// Set up sound
	soundSource* main_sound_stream = new soundSource(); // Make Unique Pointer
	std::cout << "Initialized sound stream connection" << std::endl;
	std::cout << "Note: currently just visualizing raw pcm data" << std::endl;

	// Set up variables for running visualizer
	bool shutdown = false;
	int b_length = main_sound_stream->get_pcm_buffer_length();
	fftw_complex *out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*b_length);

	// Main Loop
	while (!shutdown){
		// Read Stream
		main_sound_stream->read_stream();

		// Set up arrays for DFT
		double *in = new double[b_length];
		for(int i=0; i<b_length; i++){
			in[i] = (double) main_sound_stream->get_pcm_buffer()[i];
		}

		// Do DFT using fftw library
		fftw_plan p = fftw_plan_dft_r2c_1d(b_length, in, out, FFTW_ESTIMATE);
		if (p == NULL){
			std::cout << "DFT Failed\n";
			exit(1);
		}
		fftw_execute(p);
		
		// Visualization - Not implemented (yet)
		for (int i=0; i<b_length; i++){
			std::cout << in[i] << " ";
		}
		std::cout << std::endl;
		
		// Sleep - wait for next loop
		usleep(1000);
	}
	fftw_free(out);
}
