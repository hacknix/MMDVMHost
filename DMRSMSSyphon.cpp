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
 *    (c) Simon Adlem (G7RZU) - simon@gb7fr.org.uk
 */

#include "DMRSMSSyphon.h"
#include "Log.h"

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

int m_fd;
std::string m_syphonFIFO;

//using namespace std;

bool DMRSMSSyphon::init(std::string syphonFIFO) 
{
  m_syphonFIFO = syphonFIFO;
  int fd;
  
  mkfifo(syphonFIFO.c_str(), 0600); 
  fd = open(syphonFIFO.c_str(), O_WRONLY ); //open(myfifo, O_WRONLY | O_NONBLOCK);
  if (fd == -1) {
     LogError("DMRSMSSyphon: Cannot open fifo %s",syphonFIFO.c_str());
     return false;
  m_fd = fd;
 } 
  
};

void DMRSMSSyphon::write(unsigned char *data)
{
    int fd = m_fd;
    ::write(fd,data,sizeof(data));
}

void DMRSMSSyphon::close()
{
    unlink(m_syphonFIFO.c_str());
    LogMessage("DMRSMSSyphon: fifo %s unlinked",m_syphonFIFO.c_str());
}
