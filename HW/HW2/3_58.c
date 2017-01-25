long decode2(long x, long y, long z) {
    long tmp;
    y = y - z;
    x = y * x;
    tmp = y;
    tmp = (tmp << 63);
    tmp = (tmp >> 63);
    long ret = x ^ tmp;
    return ret;
}

int main() {
    long x = 12838;
    long y = 28183;
    long z = 2882837;
    long tmp1 = decode2(x,y,z);
    long tmp2 = decode2(y,z,x);
    long tmp3 = decode2(z,x,y);
    return decode2(tmp1,tmp2,tmp3);
}
