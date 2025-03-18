unsigned char randomUnsignedCharMaximal(unsigned char maximal) {
    unsigned char number = (rand() % (maximal + 1));
    return number;
}

unsigned char randomUnsignedChar() {
    return randomUnsignedCharMaximal(254);
}
