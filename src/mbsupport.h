/* mbsupport.h --- Localize determination of whether we have multibyte stuff.

   Copyright (C) 2004, 2005 Free Software Foundation, Inc.
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
   02111-1307, USA.  */


/* This file is needed so that we test for i18n support in just one place.
   This gives us a consistent definition for all uses of MBS_SUPPORT. This
   follows the ``Don't Repeat Yourself'' principle from "The Pragmatic
   Programmer".
  
   The tests should be *all* the ones that are needed for an individual
   application.  */

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#if    defined(HAVE_ISWCTYPE) \
    && defined(HAVE_LOCALE_H) \
    && defined(HAVE_MBRLEN) \
    && defined(HAVE_MBRTOWC) \
    && defined(HAVE_WCHAR_H) \
    && defined(HAVE_WCRTOMB) \
    && defined(HAVE_WCSCOLL) \
    && defined(HAVE_WCTYPE) \
    && defined(HAVE_WCTYPE_H) \
    && (defined(HAVE_STDLIB_H) && defined(MB_CUR_MAX)) \
/* We can handle multibyte strings.  */
# define MBS_SUPPORT 1
#else
# undef MBS_SUPPORT
#endif