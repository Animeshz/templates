inline
void swapbit(unsigned int *A, unsigned int *B, unsigned int mask)
{
    unsigned char tmpA = *A, tmpB = *B;

    unsigned char bitdiff = tmpA ^ tmpB;
    bitdiff &= mask;
    *A = tmpA ^ bitdiff;
    *B = tmpB ^ bitdiff;
}
