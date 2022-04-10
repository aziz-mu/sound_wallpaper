#include <iostream>
#include <string>
#include <unistd.h>
#include <fftw3.h>
#include "soundSource.h"

int main(){
	// Set up sound
	soundSource* main_sound_stream = new soundSource(); // Make Unique Pointer
	std::cout << "Initialized sound stream connection" << "\n";

	// Loop and Read from sound
	bool shutdown = false;
	int counter = 0;

	std::cout << "Displaying raw pcm data: " << "\n";

	fftw_complex *out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * 100);
	fftw_complex *in;
	fftw_plan *p;
	while (!shutdown){
		counter++;
		main_sound_stream->read_stream();
		std::cout << "Output: " << main_sound_stream->get_pcm_buffer() << "\n";
		usleep(10000);
		// Do DFT using fftw library
		fftw_complex *in = (fftw_complex*) main_sound_stream->get_pcm_buffer();
		fftw_plan p = fftw_plan_dft_1d(100, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
		fftw_execute(p);
		
		std::cout << "After DFT: " << out << std::endl;
		  // Change main_sound_stream->get_pcm_buffer() to fftw-friendly array
		  // Create fft plan to do fast (maybe outside loop ??)
		  // Do FFT !
		// Visualize! 
	}
	fftw_free(in);
	fftw_free(out);
}
