#ifndef _H_TYPE
#  define _H_TYPE
#  define BUFFER_LEN 16

struct s_buffer
{
  unsigned char buf[BUFFER_LEN] ;
  unsigned char index_read;
  unsigned char index_write;
  unsigned char len;
};

extern struct s_buffer tx_buffer;
extern struct s_buffer rx_buffer;

#endif
