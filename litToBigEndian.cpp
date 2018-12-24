// little endian -last byte of binary representation of the multi-byte data is stored first (normal)
// big endian - first byte stored last

(((x>>24) & 0x000000ff) | ((x>>8) & 0x0000ff00) | ((x<<8) & 0x00ff0000) | ((x<<24) & 0xff000000));