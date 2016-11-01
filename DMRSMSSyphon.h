/*
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *  (c) Simon Adlem (G7RZU) - simon@gb7fr.org.uk
 */
#if !defined(DMRSMSSyphon_H)
#define	DMRSMSSyphon_H
#endif


#include <string>
#include <sys/types.h>
#include <sys/select.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

class DMRSMSSyphon {
public:
      static bool init(std::string syphonFIFO);
      static void sywrite(const unsigned char* data);
      static void close();
  
private:
      static int m_fd;
      static std::string m_syphonFIFO;
      static int main();
  
};