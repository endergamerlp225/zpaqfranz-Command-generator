#include <stdio.h>

int die(){              // here so i won't repeat that same code over and over again. D.R.Y Don't Repeat Yourself.
    printf("\n Invalid argument, closing program.");
    return 0;
}

int main(){
    int a, method, check, b;
    int fragment = 6;
    int buffer = 4;    // 4 is the default that zpaqfranz uses, its in kib btw.
    char Archive[100] = "Archive_name";
    char command[512] = "zpaqfranz a"; // 512 seems a bit much... wait thats bits, so it aint... or is it bytes? still, not much tbh.
    char *device;
    char *checks;
    char *ht_flag;

    printf("\nssd or hdd? 1 = ssd, 2 = hdd: ");
    scanf("%d", &a);

    if (a == 1) {       // ssd and ht set.
        device = "ssd";
        ht_flag = "-ht";
    } else if (a == 2)  {   // hdd
        device = "hdd";
    } else {
        die();
    }
    // archive name check below.
    printf("\narchive name? (Use _ or - instead of spaces) ");
    scanf("%s", Archive);

    // no/checksum check below.
    printf("\nchecksum or nochecksum? 1 = nochecksum, 2 = checksum: ");
    scanf("%d", &check);
    if (check == 1) {
        checks = "-nochecksum";
    } else if (check == 2){
        checks = "";
    } else {
        die();
    }
    printf("\nWhich method do you want? from 1 to 5 only: ");
    scanf("%d", &b);
    if (b < 1 || b > 5){    // if its below or above the specified range, die.
        die();
    } else {
        printf("\nfragments to use? 6 is set by default: ");
        scanf("%d", &fragment);         // no check needed, there aint no limit, or at least none that i know of.

        printf("\nbuffer size? (in kib) ");
        scanf("%d", &buffer);     // removed the check bcs even if you go above, it'll only give a command for 2147483647 anyway

        snprintf(command, sizeof(command),
            "zpaqfranz a %s-m%d_%s_frag%d.zpaq Directory -m%d %s -%s -verbose -hw %s -fragment %d -buffer %d",
            Archive,
            b,          // method used
            checks,     // checksum or no checksum
            fragment,   // fragments
            b,          // method used
            ht_flag,    // only turned on if ssd is.
            device,     // ssd or hdd
            checks,     // checksum
            fragment,
            buffer
        );
        printf("\nGenerated command:\n%s\n", command);
    }
    return 0;
}

// No directory checks you may ask?
// thats because i'm shit at C
// and can't seem to figure out
// how to assign it to a var
// without getting a SIGSEV
// or some other shit error.
