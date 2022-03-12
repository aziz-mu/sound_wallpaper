#ifndef __SOUND_SOURCE_H
#define __SOUND_SOURCE_H
#endif

#include <pulse/error.h>
#include <pulse/pulseaudio.h>
#include <pulse/simple.h>

class soundSource{
	pa_mainloop* pulseaudio_mainloop;

	void pa_server_info_callback();
	void pa_context_state_callback();

	public:
	soundSource();
	void read_stream();
	~soundSource();

};


