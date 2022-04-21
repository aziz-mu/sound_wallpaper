using namespace std;
#include <string>
#include <iostream>

#include "soundSource.h"

#define BUFFSIZE 1024

soundSource::soundSource():pcm_buffer{(uint8_t*) malloc(sizeof(uint8_t)*BUFFSIZE)}, pcm_buffer_length{BUFFSIZE}{

	// Set up new simple pulseaudio stream
	const char* application_name = "Sound Visualizer";
	const char* stream_name = "Sound Visualizer - Main";
	string source_name = "alsa_output.pci-0000_00_1f.3.analog-stereo.monitor"; // TODO: Make this detect automatically

	const pa_sample_spec sample_spec = {PA_SAMPLE_S16LE, sample_rate, channels};
	int error_code = 0;
	
	cout << "Connecting to PulseAudio" << "\n";
	pa_connection = pa_simple_new(nullptr, application_name, PA_STREAM_RECORD, 
					    source_name.c_str(), stream_name, &sample_spec, 
					    nullptr, NULL, &error_code);

	// If connecting didn't work, try again with a common device name
	if (error_code != 0){
		error_code = 0;
		cout << "Automatic connection didn't work, trying again with common device name" << "\n";
		pa_connection = pa_simple_new(nullptr, application_name, PA_STREAM_RECORD, 
						    "0", stream_name, &sample_spec, 
						    nullptr, NULL, &error_code);	
	}
	
	if (error_code != 0){
		cout << "Connection didn't work at all. Fix this. " << "\n";
	}

	// TODO: Throw error if connection didn't work at all at this point. 

	
}

void soundSource::read_stream(){
	int error;
 
        /* Record some data ... */
        if (pa_simple_read(pa_connection, this->pcm_buffer, sizeof(pcm_buffer), &error) < 0) {
	    cerr << "pa_simple_read() failed: error " << pa_strerror(error) << "\n";
        }
}

uint8_t* soundSource::get_pcm_buffer() const{
	return pcm_buffer;
}

int soundSource::get_pcm_buffer_length() const{
	return pcm_buffer_length;
}
