#include <stdio.h>
#include <stdlib.h>

void die(void){              // here so i won't repeat that same code over and over again. D.R.Y Don't Repeat Yourself.
    printf("\nInvalid argument, closing program.");
    exit(1);
}

int main(){
    int a, check, m, hashC;
    int fragment = 6;
    int buffer = 4;    // 4 is the default that zpaqfranz uses, its in kib btw.
    char Archive[100] = "Archive_name";
    char command[512] = "zpaqfranz a";
    char *device;
    char *hw;
    const char *checks;
    const char *hashes[] = {
    "-crc32", "-xxhash", "-sha1", "-sha256", "-xxh3", "-blake3", "-sha3", "-md5", "-whirlpool", "-highway64", "-highway128", "-highway256", "-xxhashb", "-md5b", "-blake3b", "-sha256b", "-sha3b", "-xxh3b", "-sha1b"
};

    printf("\nssd or hdd? 1 = ssd, 2 = hdd: ");
    scanf("%d", &a);

    if (a == 1) {       // ssd and ht set.
        device = "-ssd -ht";
    } else if (a == 2)  {   // hdd
        device = "-hdd";
    } else {
        die();
    }
    // archive name check below.
    printf("\narchive name, (Use _ or - instead of spaces): ");
    scanf("%s", Archive);

    // no/checksum check below.
    printf("\nchecksum or nochecksum? 1 = nochecksum, 2 = checksum: ");
    scanf("%d", &check);
    if (check == 1) {
        checks = "-nochecksum";
        hw = "-hw";
    } else if (check == 2){
        printf("\nwhich algorithm do you want?");
        printf("\n-crc32 -xxhash -sha1 -sha256 -xxh3 -blake3 -sha3 -md5 -whirlpool -highway64 -highway128 -highway256 -xxhashb -md5b -blake3b -sha256b -sha3b -xxh3b -sha1b");
        printf("\n 1      2       3     4       5     6       7     8    9          10         11          12          13       14    15       16       17     18     19\n");
        scanf("%d", &hashC);

        if (hashC < 1 || hashC > 19) {
            die();
        }
        hw = "";
        checks = hashes[hashC - 1];
    } else {
        die();
    }
    printf("\nMethod from 1-5: ");
    scanf("%d", &b);
    if (b < 1 || b > 5){    // if its below or above the specified range, die.
        die();
    } else {
        printf("\nfragments to use? 6 is set by default: ");
        scanf("%d", &fragment);         // no check needed

        printf("\nbuffer size? (in kib) ");
        scanf("%d", &buffer);     // no check needed

        snprintf(command, sizeof(command),
            "zpaqfranz a %s-m%d_%s-frag%d.zpaq Directory -m%d %s -verbose %s -fragment %d -buffer %d %s",
            Archive,
            m,          // method used
            checks,     // checksum or no checksum
            fragment,   // fragments
            m,          // method used
            device,     // ssd or hdd. ht only on if ssd is
            checks,     // checksum
            fragment,
            buffer,
            hw
        );
        printf("\nGenerated command:\n%s\n", command);
    }
    return 0;
}
