long switch_prob(long x, long n)
{
    long result = x;
    switch (n)
    {
        case 0x3c:
        case 0x3e:
            result = 0x08 * x;
            break;
        case 0x3f:
            result = result >> 0x03;
            break;
        case 0x40:
            result = result << 4;
            x = result - x;
        case 0x41:
            x = x * x;
        default:
            result = x + 75;
            break;
    }
    return result;
}

int main() {
    long x = switch_prob(241,132);
    long y = switch_prob(927,103);
    long z = switch_prob(x,y);
    return switch_prob(x,z/40);
}
