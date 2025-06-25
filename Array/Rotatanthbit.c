unsigned char rotate_left(unsigned char s, unsigned int n) {
    n %= 8;  // Ensure n is within 0-7
    return (s << n) | (s >> (8 - n));
}
