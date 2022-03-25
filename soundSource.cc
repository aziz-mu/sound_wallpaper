using namespace std;
#include <string>
#include <iostream>
#include <unistd.h>

#include "soundSource.h"


soundSource::soundSource(){

	static const int sample_rate = 44100;
	static const int channels = 2; // TODO: Put these settings as a settings struct attribute of this class

	// Set up new simple pulseaudio stream
	const char* application_name = "Sound Visualizer";
	const char* stream_name = "Sound Visualizer - Main";
	const pa_sample_spec sample_spec = {PA_SAMPLE_S16LE, sample_rate, channels};
	int error_code = 0;
	
	cout << "Connecting to PulseAudio" << "\n";
	pa_connection = pa_simple_new(nullptr, application_name, PA_STREAM_RECORD, 
					    nullptr, stream_name, &sample_spec, 
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
	int BUFFSIZE = 1024;
	uint8_t pcm_buffer[BUFFSIZE];
 
        /* Record some data ... */
        if (pa_simple_read(pa_connection, pcm_buffer, sizeof(pcm_buffer), &error) < 0) {
	    cerr << "pa_simple_read() failed: error " << pa_strerror(error) << "\n";
        }
	cout << pcm_buffer << "\n";
 
	usleep(10000);
}

soundSource::~soundSource(){}

