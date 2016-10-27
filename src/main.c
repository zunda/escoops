/* escoops - run a command when ESC key is hit */
/* vim: set ts=2 sw=2 noet: */
/* usage: escoops 'tw --yes Oops I touched ESC key!' */
/*

Copyright (C) 2016 zunda <zundan@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

*/
#if HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <X11/extensions/XInput2.h>

#include <signal.h>

#define XI_RAWKEY_DETAIL_ESC 9

int continuing;
void sigint_handler(int signum);

void
sigint_handler(int signum)
{
	if (signum == SIGINT) continuing = 0;
}

int
main(int argc, char *argv[])
{
	Display *display = XOpenDisplay(NULL);
	if (!display)
		{
			perror("XOpenDisplay");
			return EXIT_FAILURE;
		}

	Window win = DefaultRootWindow(display);

	XIEventMask m;
	m.deviceid = XIAllMasterDevices;
	m.mask_len = XIMaskLen(XI_LASTEVENT);
	m.mask = calloc(m.mask_len, sizeof(char));
	XISetMask(m.mask, XI_RawKeyPress);

	XISelectEvents(display, win, &m, 1);
	XSync(display, False);

	free(m.mask);

	continuing = 1;
	signal(SIGINT, sigint_handler);

	XEvent ev;
	XGenericEventCookie *cookie;
	while(continuing)
		{
			cookie = (XGenericEventCookie*) &ev.xcookie;
			XNextEvent(display, (XEvent*) &ev);
			if (XGetEventData(display, cookie) &&
				cookie->type == GenericEvent &&
				cookie->evtype == XI_RawKeyPress &&
				((XIRawEvent *) cookie->data)->detail == XI_RAWKEY_DETAIL_ESC)
				{
					if (argc > 1)
						{
							int r = system(argv[1]);
							if (r != 0) continuing = 0;
						}
					else
						{
							fputc('!', stderr);
						}
				}
			XFreeEventData(display, cookie);
		}

	XDestroyWindow(display, win);
	XSync(display, False);
	XCloseDisplay(display);

	return EXIT_SUCCESS;
}
