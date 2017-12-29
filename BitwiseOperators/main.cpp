#include <iostream>

// For bitset method, don't need it for first method:
#include <bitset>

int main()
{
    /*unsigned char option_viewed = 0x01;
    unsigned char option_edited = 0x02;
    unsigned char option_favorited = 0x04;
    unsigned char option_shared = 0x08;
    unsigned char option_deleted = 0x80;

    unsigned char myArticleFlags = 0;

    // Set article as viewed:
    myArticleFlags |= option_viewed;

    // Check whether article was deleted:
    bool wasDeleted = myArticleFlags & option_deleted;

    // Clear article as favourite:
    myArticleFlags &= ~option_favorited;*/

    // Using bitset:
    unsigned char option_viewed = 0;
    unsigned char option_edited = 1;
    unsigned char option_favorited = 2;
    unsigned char option_shared = 3;
    unsigned char option_deleted = 7;

    std::bitset<8> bits;

    // Set article as viewed:
    bits.set(option_viewed);

    bits.set(option_deleted);
    bits.flip(option_deleted);
    bits.flip(option_deleted);
    bits.reset(option_deleted);

    // Check whether article was deleted:
    std::cout << bits.test(option_deleted) << "\n";

    std::cout << bits;


    return 0;
}
