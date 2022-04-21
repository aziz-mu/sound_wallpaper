#ifndef __SOUND_SOURCE_H
#define __SOUND_SOURCE_H
#endif

#include <pulse/error.h>
#include <pulse/pulseaudio.h>
#include <pulse/simple.h>

class soundSource{
	
	static const int sample_rate = 44100;
	static const int channels = 2;


	pa_simple *pa_connection;
	uint8_t* pcm_buffer;
	int pcm_buffer_length;

	public:
	soundSource();
	void read_stream();
	int get_pcm_buffer_length() const;
	uint8_t* get_pcm_buffer() const;
	~soundSource();

};


