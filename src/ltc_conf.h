/**
   @file ltc.h
   @brief libltc - en+decode linear timecode

   Linear (or Longitudinal) Timecode (LTC) is an encoding of
   timecode data as a Manchester-Biphase encoded audio signal.
   The audio signal is commonly recorded on a VTR track or other
   storage media.

   libltc facilitates decoding and encoding of LTC from/to
   timecode, including SMPTE date support.

   @author Robin Gareus <robin@gareus.org>
   @copyright

   Copyright (C) 2006-2012 Robin Gareus <robin@gareus.org>

   Copyright (C) 2008-2009 Jan Weiß <jan@geheimwerk.de>

   Inspired by SMPTE Decoder - Maarten de Boer <mdeboer@iua.upf.es>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library.
   If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef LTC_CONF_H
#define LTC_CONF_H 1

#ifndef DOXYGEN_IGNORE

/*
 Configuration for LTC
 */
#define LTC_USE_DECODER 1
#define LTC_USE_ENCODER 0
#define LTC_STATIC_OBJECTS 1
#define LTC_HAVE_STDIO 0

/* libltc version */
#define LIBLTC_VERSION "1.1.2"
#define LIBLTC_VERSION_MAJOR  1
#define LIBLTC_VERSION_MINOR  1
#define LIBLTC_VERSION_MICRO  2

/* interface revision number
 * http://www.gnu.org/software/libtool/manual/html_node/Updating-version-info.html
 */
#define LIBLTC_CUR 11
#define LIBLTC_REV  1
#define LIBLTC_AGE  0

#define LTC_FRAME_BIT_COUNT	80

#ifndef LTC_SAMPLE_CENTER
#define LTC_SAMPLE_CENTER 128 /* unsigned 8 bit. */
#endif


#if LTC_STATIC_OBJECTS
	#define LTC_DECODE_QUEUE_LENGTH 32
#endif

#endif /* end DOXYGEN_IGNORE */

#endif /* DOXYGEN_IGNORE */
