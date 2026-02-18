#include <stdio.h>
#include <stdlib.h>

void die(void){
    printf("\nInvalid argument, closing program.");
    exit(1);
}

int main(){
    int a, c, m, hc, f, b;
    char Ar[100] = "tmp-name";
    char command[512] = "zpaqfranz a";
    char *device;
    char *hw;
    const char *ch;
    const char *h[] = {
    "crc32", "xxhash", "sha1", "sha256", "xxh3", "blake3", "sha3", "md5", "whirlpool", "highway64", "highway128", "highway256", "xxhashb", "md5b", "blake3b", "sha256b", "sha3b", "xxh3b", "sha1b"
};

    printf("\nssd = 1, hdd = 2: ");
    scanf("%d", &a);

    if (a == 1) {
        device = "-ssd -ht";
    } else if (a == 2)  {
        device = "-hdd";
    } else {
        die();
    }

    printf("\narchive name (Use _ or - instead of spaces): ");
    scanf("%s", Ar);


    printf("\nnochecksum = 1, checksum = 2: ");
    scanf("%d", &c);
    if (c == 1) {
        ch = "nochecksum";
        hw = "-hw";
    } else if (c == 2){
        printf("\nwhich algorithm: ");
        printf("\ncrc32 xxhash sha1 sha256 xxh3 blake3 sha3 md5 whirlpool highway64 highway128 highway256 xxhashb md5b blake3b sha256b sha3b xxh3b sha1b");
        printf("\n 1      2      3    4     5     6     7    8     9         10         11          12      13     14    15      16     17     18   19\n");
        scanf("%d", &hc);

        if (hc < 1 || hc > 19) {
            die();
        }
        hw = "";
        ch = h[hc - 1];
    } else {
        die();
    }
    printf("\nmethod from 1-5: ");
    scanf("%d", &m);
    if (m < 1 || m > 5){
        die();
    } else {
        printf("\nfragments, 6 is default: ");
        scanf("%d", &f);

        printf("\nbuffer size in kib: ");
        scanf("%d", &b);

        snprintf(command, sizeof(command),
            "zpaqfranz a %s-m%d_%s-frag%d.zpaq tmp_dir -m%d %s -verbose -%s -fragment %d -buffer %d %s",
            Ar,m,ch,f,m,device,ch,f,b,hw
        );
        printf("\nGenerated command:\n%s\n", command);
    }
    return 0;
}
