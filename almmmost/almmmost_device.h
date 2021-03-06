/* almmmost_device.h, the kernel device driver interface module for Almmmost.
 *
 * Almmmost is a modern replacement for the TeleVideo MmmOST network 
 * operating system used on the TeleVideo TS-8xx Zilog Z80-based computers 
 * from the early 1980s.
 *
 * This software uses the tvi_sdlc kernel module to interface with a
 * Zilog Z85C30 chip for the hardware interface to the TeleVideo Z-80
 * computers over an 800K baud RS-422 SDLC interface.
 *
 * Copyright (C) 2019 Patrick Finnegan <pat@vax11.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _ALMMMOST_DEVICE_H
#define _ALMMMOST_DEVICE_H

extern int alm_dev_ports;


/* Initialize variables */
int alm_dev_init();

/* Process config file */
int alm_dev_ini(struct INI *ini, const char *buf, size_t buflen);

/* Free allocated memory/clear variables */
int alm_dev_exit();

/* Reset user serial port */
int alm_dev_reset(int portnum);

/* Return true if CTS is recieved on port */
int alm_dev_check_cts(int portnum);

/* Read size bytes from portnum */
int alm_dev_read(void *buf, size_t size, int portnum);

/* Write size bytes to portnum */
int alm_dev_write(void *buf, size_t size, int portnum);

#endif /* _ALMMMOST_DEVICE_H */
